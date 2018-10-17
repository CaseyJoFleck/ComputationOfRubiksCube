#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "cubieStruct.h"

//initializing pointer to cube

/**
*rUnsolved - function that reads in an unsolved cube and initializes colors, homeLocation, homeOrientation, currentOrientation and orientationNames for each 
*	      cubie in solved positions (red in front). Initializes cube1 struct. Pointer to array of cubies located inside cube1 struct.  Initializes the array of cubies. 
* NOTE: txt file read 
#include <string.h>
#include <stdlib.h>  
#include "cubieStruct.h"

//initializing pointer to cube
//struct cube *cube1; //can't declare this in main

/**
*initialize - function that initializes homeLocation, homeOrientation, currentOrientation and orientationNames for each 
*	      cubie in solved positions (red in front). Initializes cube1 struct. Pointer to array of cubies located inside cube1 struct.  Initializes the array of cubies. 
*/ 
   
/*void initialize(struct cube **cube1){

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
					printf("malloc failed\n");//in as [w][r][c] with w:front/back colors, r:up/down colors, c:left/right colors

				}
			}
		}
	}
}*/
void rUnsolved(struct cube **cube1){

	FILE *pf;
	
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
	
	pf = fopen("cube.txt","r");
	if( pf == 	NULL ){
		printf("Unable to open the file\n");
		}
	else{
		for(w = 0; w < 3; w++){
			for(r = 0; r < 3; r++){
				for(c = 0; c < 3; c++){
					(**cube1).aCubie[w][r][c] = malloc (sizeof(struct cubies));
					
					if((**cube1).aCubie[w][r][c] == NULL)
					{
						printf("malloc failed\n");
						exit(1);
					}
					strcpy((**cube1).aCubie[w][r][c]->homeOrientation, "BBBBBB");
					strcpy((**cube1).aCubie[w][r][c]->currentOrientation, "BBBBBB");
					strcpy((**cube1).aCubie[w][r][c]->colors, "BBB");
					strcpy((**cube1).aCubie[w][r][c]->orientationNames, "ufdblr");
					fscanf(pf, "%s\n", (**cube1).aCubie[w][r][c]->colors);			
					if(c == 0){ //col == 0 left
						(**cube1).aCubie[w][r][c]->currentOrientation[4] = (**cube1).aCubie[w][r][c]->colors[2]; //left spot 
					}
					else if(c == 2){
						(**cube1).aCubie[w][r][c]->currentOrientation[5] = (**cube1).aCubie[w][r][c]->colors[2]; //right
					}
					if(r == 0){ 
						(**cube1).aCubie[w][r][c]->currentOrientation[2] = (**cube1).aCubie[w][r][c]->colors[1]; //down 
					}
					else if(r == 2){ 
						(**cube1).aCubie[w][r][c]->currentOrientation[0] = (**cube1).aCubie[w][r][c]->colors[1]; //up
					}
					if(w == 0){
						(**cube1).aCubie[w][r][c]->currentOrientation[1] = (**cube1).aCubie[w][r][c]->colors[0]; //front
					}
					else if(w == 2){
						(**cube1).aCubie[w][r][c]->currentOrientation[3] = (**cube1).aCubie[w][r][c]->colors[0]; //back
					}
					for(int i = 0; i<6; i++){	
						if((**cube1).aCubie[w][r][c]->currentOrientation[i] == 'g'){
							(**cube1).aCubie[w][r][c]->homeOrientation[4]='g';
							(**cube1).aCubie[w][r][c]->homeLocation[2] = 0;
						}
						else if((**cube1).aCubie[w][r][c]->currentOrientation[i] == 'b'){
							(**cube1).aCubie[w][r][c]->homeOrientation[5]='b';
							(**cube1).aCubie[w][r][c]->homeLocation[2] = 2;
						}
						if((**cube1).aCubie[w][r][c]->currentOrientation[i] == 'y'){
							(**cube1).aCubie[w][r][c]->homeOrientation[2]='y';
							(**cube1).aCubie[w][r][c]->homeLocation[1] = 0;
						}
						else if((**cube1).aCubie[w][r][c]->currentOrientation[i] == 'w'){
							(**cube1).aCubie[w][r][c]->homeOrientation[0]='w';
							(**cube1).aCubie[w][r][c]->homeLocation[1] = 2;
						}
						if((**cube1).aCubie[w][r][c]->currentOrientation[i] == 'r'){
							(**cube1).aCubie[w][r][c]->homeOrientation[1]='r';
							(**cube1).aCubie[w][r][c]->homeLocation[0] = 0;
						}
						else if((**cube1).aCubie[w][r][c]->currentOrientation[i] == 'o'){
							(**cube1).aCubie[w][r][c]->homeOrientation[3]='o';
							(**cube1).aCubie[w][r][c]->homeLocation[0] = 2;
						}
					}		
				}
			}
		}
		fclose(pf);
	}
}
/**
*wUnsolved - function that writes a txt file of unsolved cube and initializes colors, homeLocation, homeOrientation, currentOrientation and orientationNames for each 
*	      cubie in solved positions (red in front). Initializes cube1 struct. Pointer to array of cubies located inside cube1 struct.  Initializes the array of cubies. 
* NOTE: txt file read in as [w][r][c] with w:front/back colors, r:up/down colors, c:left/right colors
*/

void wUnsolved(struct cube **cube1, char textFile[10]){

	FILE *pf;

	pf = fopen(textFile, "w+");
	for(int w = 0; w < 3; w++){
			for(int r = 0; r < 3; r++){
				for(int c = 0; c < 3; c++){
					fprintf(pf, "%s\n", (**cube1).aCubie[w][r][c]->colors);
				}
			}
		}
		fclose(pf);
}
