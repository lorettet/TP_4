RM=rm
COMP=g++
EDL=g++
RMFLAGS=-f
COMPFLAGS = -ansi -pedantic  -Wall -std=c++11 -g
#retirez yes pour compiler en release
DEBUG=no
EXE=analog
EXEPATH=./bin/
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

ifeq ($(DEBUG),yes)
	DEFINE=-D MAP	
else
	DEFINE=
endif

all:$(EXE)

$(EXE): $(OBJ)
	$(EDL) -o $(EXEPATH)$(EXE) $(OBJ)

%.o: %.cpp
	$(COMP) -c $< $(COMPFLAGS) $(DEFINE)
	
.PHONY:clean

clean:
	$(RM) $(RMFLAGS) *.o $(EXEPATH)$(EXE)
	
