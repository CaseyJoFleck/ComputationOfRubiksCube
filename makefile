#This is a makefile that will contain all rubiks_cube files
#-g is debugging info
#-Wall turns on most compiler warnings
#-I says only to look in this directory
CC = gcc
CFLAGS = -g -Wall 

#rubiks: target entry - name that will be compiled folder
default: trubik 

#object files: machine code for each file - not directly executable
#$ sets these files to a variable so they can be easily changed
trubik:	rubiks.o faceTurn.o initialization.o printCubie.o unsolved.o mixedCube.o solvedStateSearcher.o
	$(CC) $(CFLAGS) -o trubik rubiks.o faceTurn.o initialization.o printCubie.o unsolved.o mixedCube.o solvedStateSearcher.o -lm



rubiks.o: rubiks.c faceTurn.c initialization.c printCubie.c mixedCube.c unsolved.c solvedStateSearcher.c cubieStruct.h functions.h 
	$(CC) $(CFLAGS) -c rubiks.c
faceTurn.o:	faceTurn.c cubieStruct.h functions.h
	$(CC) $(CFLAGS) -c faceTurn.c
initialization.o: initialization.c cubieStruct.h functions.h
	$(CC) $(CFLAGS) -c initialization.c
printCubie.o: printCubie.c cubieStruct.h functions.h
	$(CC) $(CFLAGS) -c printCubie.c
unsolved.o: unsolved.c cubieStruct.h functions.h
	$(CC) $(CFLAGS) -c unsolved.c
mixedCube.o: mixedCube.o cubieStruct.h functions.h
	$(CC) $(CFLAGS) -c mixedCube.c
solvedStateSearcher.o: solvedStateSearcher.o cubieStruct.h functions.h initializeFunctionForSolvedStateSolver.h
	$(CC) $(CFLAGS) -c solvedStateSearcher.c 
clean:
	rm -f *.o core* trubik

