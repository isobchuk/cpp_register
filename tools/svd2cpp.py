
from bs4 import BeautifulSoup
import sys
from array import *
from collections import namedtuple 
import os

if len(sys.argv) <= 1:
    print('Provide specific *.svd file for your chip and/or peripheral you want to extract!\r')
    sys.exit()

file_name = sys.argv[1]
 
with open(file_name, 'r') as f:
    data = f.read()

Bs_data = BeautifulSoup(data, "xml")
b_peripheral = Bs_data.find_all('peripheral')


if 2 == len(sys.argv):
    list  = ['']
    inList = False
    for group in b_peripheral:
        name = group.find('groupName')
        if name is not None:
            for i in list:
                if i == name.string:
                    inList = True
            if False == inList:
                print('\t' + name.string)
            list.append(name.string)
            inList = False
    list.clear()
    sys.exit()

os.mkdir(Bs_data.find('name').string.lower())

paramCounter = 2
while paramCounter < len(sys.argv):
    currentGroupName = sys.argv[paramCounter]

    paramCounter+=1
    f = open(Bs_data.find('name').string.lower() + '/' + currentGroupName.swapcase() + '.hpp', "w")

    f.write("#pragma once\r\n")
    f.write("#include \"register.hpp\"\r\n")
    f.write("namespace " + Bs_data.find('name').string.lower() + "::" + currentGroupName.lower()  + " {\r\n")
    f.write("using namespace peripheral;\r\n")

    
    if 'NVIC' == currentGroupName:
        interrupts = Bs_data.find_all('interrupt')
        interrupt_list = {}

        f.write("namespace interrupt {\n")
        f.write("enum class Number {\n")

        isIntrptDescrpt = False

        for i in interrupts:
            name = i.find('name').string
            description = i.find('description')
            if description is not None:
                interrupt_list[int(i.find('value').string)] = (name, description.string)
                isIntrptDescrpt = True
            else:
                interrupt_list[int(i.find('value').string)] = name

        interrupt_list = dict(sorted(interrupt_list.items()))

        for i in interrupt_list:
            if isIntrptDescrpt:
                description = str(interrupt_list[i][1]).replace('\n', '').replace('\r', '').replace('    ', ' ')
                f.write('\t' + interrupt_list[i][0] + '= '.rjust(32 - len(str(interrupt_list[i][0]))) + str(i) + ', //' + description + '\r')
            else:
                f.write('\t' + interrupt_list[i] + '= '.rjust(32 - len(str(interrupt_list[i]))) + str(i) + ',\r')
            
        f.write("};\n")
        f.write("}\n\n")


    cosnt_access_mode = { 'read-write' : 'RW', 'read-only' : 'R', 'write-only' : 'W', 'read-writeonce' : 'RWO'}
    const_size = { '0x8' : 'uint8_t', '0x10' : 'uint16_t', '0x20' : 'uint32_t', '8' : 'uint8_t', '16' : 'uint16_t', '32' : 'uint32_t'}

    groups = namedtuple('groups', ('baseName', 'baseAddress', 'groupName'))
    groups_list = [ ]

    list_peripheral = ['']
    list_field = [' ']

    for i in b_peripheral:
        if i.find('groupName') is not None:       
            if i.find('groupName').string == currentGroupName:
                groups.baseName = i.find('name').string
                groups.baseAddress = i.find('baseAddress').string

                isRepeated = False
                for gr in groups_list:
                    if i.find('groupName').string == gr.groupName:
                        isRepeated = True
                        break

                if True == isRepeated : 
                    list_peripheral.append('inline constexpr ' + groups.groupName + '_T<' + groups.baseAddress + '> const *' + groups.baseName + '{};\r')
                    continue
                
                groups.groupName = i.find('groupName').string
                regisers = i.find_all('register')

                if regisers is not None:
                    f.write('template <const RegisterAddress address> struct ' + groups.groupName + '_T {\r')
                    for j in regisers:
                        name = j.find('name').string
                        offset = j.find('addressOffset').string
                        size = j.find('size').string if j.find('size') else '0x20'
                        access = j.find('access').string
                        f.write('\tstatic constexpr Register<address + ' + offset + ', AccessMode::' + cosnt_access_mode[access] + ', ' + const_size[size] + ', struct ' + name + '> ' + name + '{};\r')
                        
                        fields = j.find_all('field')
                        
                        list_field.append('struct ' + groups.groupName + '_' + name + ' {\r')
                        skip = 0
                        for k in fields:
                            if skip:
                                skip -= 1
                                continue

                            field_name = k.find('name').string
                            field_offset = k.find('bitOffset').string
                            #field_access = k.find('access').string
                            field_size = k.find('bitWidth').string

                            result_string = ''
                            ch = len(field_name) - 1
                            while field_name[ch].isdigit():
                                result_string = field_name[ch] + result_string
                                ch-=1

                            if result_string != '':
                                field_number = int(result_string) + 1
                                field_offset = str(int(field_offset) + int(field_size) - (int(field_number) * int(field_size)))
                                list_field.append('\tstatic constexpr Field<decltype(' + groups.baseName + '->' + name + '), (1UL << ' + field_offset + '), AccessMode::'
                                + cosnt_access_mode[access] + ', ' + field_size +', ' + str(field_number) + '> ' + field_name[0: (ch + 1)] + '{};\r')
                                skip = field_number - 1
                                continue

                            list_field.append('\tstatic constexpr Field<decltype(' + groups.baseName + '->' + name + '), (1UL << ' + field_offset + '), AccessMode::'
                            + cosnt_access_mode[access] + ', ' + field_size + '> ' + field_name + '{};\r')
                        list_field.append('};\r\r')
                    f.write('};\r\r')
                    groups_list.append(groups)
                    list_peripheral.append('inline constexpr ' + groups.groupName + '_T<' + groups.baseAddress + '> const *' + groups.baseName + '{};\r')
        else:
            derivedFrom = i.attrs['derivedFrom']

            #groups.baseName = i.find('name').string
            #groups.baseAddress = i.find('baseAddress').string
            elems = 0
            while elems < len(groups_list):
                if groups_list[elems].baseName == derivedFrom:
                    list_peripheral.append('inline constexpr ' + groups_list[elems].groupName + '_T<' + i.find('baseAddress').string + '> const *' + i.find('name').string + '{};\r')
                elems+=1

    for elem in list_peripheral:
        f.write(elem)

    f.write('\r\r')

    for field in list_field:
        f.write(field)

    list_field.clear()
    list_peripheral.clear()
    groups_list.clear()
    f.write("}\n")