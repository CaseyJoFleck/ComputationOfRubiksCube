#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "cubieStruct.h"

//initializing pointer to cube
//struct cube *cube1; //can't declare this in main

/**
*initialize - function that initializes homeLocation, homeOrientation, currentOrientation and orientationNames for each 
*	      cubie in solved positions (red in front). Initializes cube1 struct. Pointer to array of cubies located inside cube1 struct.  Initializes the array of cubies. 
*/ 
   
void initialize(struct cube **cube1){

	//variables for going through for loop
	int w;//width
	int r;//row
	int c;//column

	//initialzing and allocating memory for cube1 struct in heap
	*cube1 = malloc (sizeof(struct cube));
	if(*cube1 == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}


	for(w = 0; w < 3; w++){
		for(r = 0; r < 3; r++){
			for(c = 0; c < 3; c++){
				//initializing and allocating memory for each cubie in cubie array
				// (**cube1).aCubie[w][r][c] = (struct cubies *) malloc (sizeof(struct cubies)); //don't need the extra cast of (struct cubies *)
				(**cube1).aCubie[w][r][c] = malloc (sizeof(struct cubies));

				if((**cube1).aCubie[w][r][c] == NULL)
				{
					printf("malloc failed\n");
					exit(1);
				}
				(**cube1).aCubie[w][r][c]->homeLocation[0]=w;	
				(**cube1).aCubie[w][r][c]->homeLocation[1]=r;	
				(**cube1).aCubie[w][r][c]->homeLocation[2]=c;

				
				strcpy((**cube1).aCubie[w][r][c]->homeOrientation, "BBBBBB");
				strcpy((**cube1).aCubie[w][r][c]->currentOrientation, "BBBBBB");
				strcpy((**cube1).aCubie[w][r][c]->colors, "BBB");
 				strcpy((**cube1).aCubie[w][r][c]->orientationNames, "ufdblr");

				if(c == 0){							//LEFT
					(**cube1).aCubie[w][r][c]->homeOrientation[4]='g';
					(**cube1).aCubie[w][r][c]->currentOrientation[4]='g';
					(**cube1).aCubie[w][r][c]->colors[2]='g';
				}
				else if(c == 2){						//RIGHT
					(**cube1).aCubie[w][r][c]->homeOrientation[5] = 'b';
					(**cube1).aCubie[w][r][c]->currentOrientation[5] = 'b';
					(**cube1).aCubie[w][r][c]->colors[2]='b';
				}
				if(r == 0){							//DOWN
					(**cube1).aCubie[w][r][c]->homeOrientation[2] = 'y';
					(**cube1).aCubie[w][r][c]->currentOrientation[2] = 'y';
					(**cube1).aCubie[w][r][c]->colors[1]='y';
					}
				else if(r == 2){						//UP
					(**cube1).aCubie[w][r][c]->homeOrientation[0] = 'w';
					(**cube1).aCubie[w][r][c]->currentOrientation[0] = 'w';
					(**cube1).aCubie[w][r][c]->colors[1]='w';
				}
				else if(r == 1){						//MIDDLE
					
				}
				if(w == 0){							//FRONT
					(**cube1).aCubie[w][r][c]->homeOrientation[1] = 'r';
					(**cube1).aCubie[w][r][c]->currentOrientation[1] = 'r';
					(**cube1).aCubie[w][r][c]->colors[0]='r';
				}
				else if(w == 2){						//BACK	
					(**cube1).aCubie[w][r][c]->homeOrientation[3] = 'o';
					(**cube1).aCubie[w][r][c]->currentOrientation[3] = 'o';
					(**cube1).aCubie[w][r][c]->colors[0]='o';
				}
				else if(w == 1){						//MIDDLE

				}
			}

		}
	}
		
	return;
}


