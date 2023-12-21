# Compiler system
CXX		=clang++
COMMONFLAGS = -std=c++20 -Oz

# Warnings configuration
WARNINGS		= -Wall -Werror -Wextra -Wduplicated-branches -Wduplicated-cond -Wfloat-equal -Wshadow=compatible-local -Wcast-qual -Wconversion -Wsign-conversion -Wlogical-op
WARNINGS_CPP 	= -Wctor-dtor-privacy -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wextra-semi -Wnon-virtual-dtor

OBJ			= cpp_register_ut
DOCTEST 	= ../doctest/doctest
INCLUDE		= ../../

all: $(OBJ).o
	$(CXX) $(COMMONFLAGS) $(OBJ).o -o $(OBJ).exe
	$(OBJ).exe

$(OBJ).o:
	$(CXX) $(COMMONFLAGS) -I$(INCLUDE) -I$(DOCTEST) -c $(OBJ).cpp -o $(OBJ).o

clean:
	$(shell del -rf *.o *.exe *.ilk *.pdb)