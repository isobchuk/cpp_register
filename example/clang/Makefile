
SYSTEM	=llvm-
APP		=embedded_compile_time

CC		=clang
CXX		=clang++
OBJCOPY	=$(SYSTEM)objcopy
SIZE	=$(SYSTEM)size
LD		=$(SYSTEM)ld
OBJDUMP	=$(SYSTEM)objdump


OPTIMIZE	=-Oz
WARNINGS	=-Werror -Wall -Wextra -Wpedantic -Weverything -pedantic-errors
WARNINGS_DISABLED =-Wno-c++98-compat -Wno-main

DEFINE =-DCORTEX_M_BIT_BAND
INCLUDE =-Istm32f407 -I..\..\

COMMONFLAGS	=-ggdb --target=thumbv7em-none-eabihf -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(OPTIMIZE) $(WARNINGS) $(WARNINGS_DISABLED) $(DEFINE) $(INCLUDE)
CFLAGS=
CXXFLAGS 	=-std=c++17 -fdata-sections -ffunction-sections -fno-rtti -fno-builtin -fno-exceptions -fno-threadsafe-statics
LDFLAGS		=-nostdlib

LDSCRIPT	=linker.ld

OBJ			=main.o


all: $(APP).elf
	$(OBJDUMP) -d -z -S $(APP).elf > $(APP).dis
	$(OBJCOPY) -O ihex $(APP).elf $(APP).hex
	$(OBJCOPY) -O binary $(APP).elf $(APP).bin
	$(SIZE) $(APP).elf

$(APP).elf: $(OBJ)
	$(CXX) -Wl,-gc-sections -T$(LDSCRIPT) $(OBJ) $(COMMONFLAGS) $(CXXFLAGS) $(LDFLAGS) -Wl,-Map=$(APP).map -o $(APP).elf

.cpp.o:
	$(CXX) $(COMMONFLAGS) $(CXXFLAGS) -c $^ 

clean:
	del -rf *.ii *.s *.o *.elf *.bin *.hex *.map *.dis


# target = "thumbv6m-none-eabi"        # Cortex-M0 and Cortex-M0+
# target = "thumbv7m-none-eabi"        # Cortex-M3
# target = "thumbv7em-none-eabi"       # Cortex-M4 and Cortex-M7 (no FPU)
# target = "thumbv7em-none-eabihf"     # Cortex-M4F and Cortex-M7F (with FPU)
# target = "thumbv8m.base-none-eabi"   # Cortex-M23
# target = "thumbv8m.main-none-eabi"   # Cortex-M33 (no FPU)
# target = "thumbv8m.main-none-eabihf" # Cortex-M33 (with FPU)