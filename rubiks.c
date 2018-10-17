#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <getopt.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#include "cubieStruct.h"
#include "functions.h"
/**
*main - this is the main where I call functions in order to modify my cube
*/
//try algorithm I found on facebook on cube
//struct cube *cube1;
//struct cube *cube2;
/*
 * prototypes
 */
 //check the stars/ pointers with sequence -- check 
double get_wctime(void);

/*
 * get_wctime() - returns wall clock time as double
 */
double get_wctime(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec*1E6 + tv.tv_usec);
}

int main(){
	//initialize(cube1); memory leak function gets a copy of cube bc it is declared in main so copied version of pointer would be freed
	//initialize(); memory leak main gets a copy of the cube bc it was declared in initialize so copied version of pointer would be freed
	
	//initialize(&cube1); //initializes a solved cube
	//initialize(&cube2); 
	//printCube(&cube1); //prints whole cube
	//printf("here1");
	//printf("Test:\n");
	
	//divide process into threads
	//thread or fork
	//try fork first
	//make flow chart of code
	//post on github
	double start, end;
	start = get_wctime();
	
	int length=16;
	int sequence[16];
	

	
	for(int i = 0; i < length;i++){sequence[i] = 0;}
	int index = -1;
	
	clearFile(length);
	cubePermutation(length, sequence, index);
	//printf("here");
	end = get_wctime();
	double sec = (end - start)/CLOCKS_PER_SEC;
	 printf("\n1 %f\n",sec);
	writeTime(sec, length);
	
	return(0);
}



