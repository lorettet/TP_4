RM=rm
COMP=g++
EDL=g++
RMFLAGS=-f
COMPFLAGS = -ansi -pedantic  -Wall -std=c++11 -g
#retirez yes pour compiler en release
DEBUG=yes
EXE=analog
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

ifeq ($(DEBUG),yes)
	DEFINE=-D MAP	
else
	DEFINE=
endif

all:$(EXE)

$(EXE): $(OBJ)
	$(EDL) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(COMP) -c $< $(COMPFLAGS) $(DEFINE)

main.o: main.cpp 
	$(COMP) -c $< $(COMPFLAGS)
	
.PHONY:clean

clean:
	$(RM) $(RMFLAGS) *.o $(EXE)
