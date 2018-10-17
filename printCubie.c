//#include "functions.h"
#include "cubieStruct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

/**
*printCubie - prints out all the cubies from the importing cube
*cube *c- pointer c is the pointer to the importing cube
*/
void printCube(struct cube **c){
	//variables for going through for loop
	int wid;
	int row;
	int col;
	int i;
	
		for(wid = 0; wid < 3; wid++){
			for(row = 0; row < 3; row++){
				for(col = 0; col < 3; col++){
					printf("*CurrentLocation: %d%d%d", wid, row, col);
					printf(" *HomeLocation: %d%d%d", (**c).aCubie[wid][row][col]->homeLocation[0], (**c).aCubie[wid][row][col]->homeLocation[1], (**c).aCubie[wid][row][col]->homeLocation[2]);
					printf(" *Color Orientation: "); 
					for(i = 0; i < 6; i++){
						if((**c).aCubie[wid][row][col]->currentOrientation[i] != 'B'){  		//prints out the colors in the order UFDBLR
							printf("%c ", (**c).aCubie[wid][row][col]->currentOrientation[i]);
						}
					}
					printf(" *Current Orientation: ");
					for(i = 0; i < 6; i++){
						if((**c).aCubie[wid][row][col]->currentOrientation[i] != 'B'){ 		//prints out UFDBLR
							printf("%c ", (**c).aCubie[wid][row][col]->orientationNames[i]);
						}
					}
					printf("\n\n");		
				}
			}
		}


	//print left
	/*
	for(wid = 0; wid < 3; wid++){
			for(row = 0; row < 3; row++){
				printf("currentLocation %d%d%d\n ", wid, row, 0);
				printf("HomeLocation %d%d%d\n ", (**c).aCubie[wid][row][0]->homeLocation[0], (**c).aCubie[wid][row][0]->homeLocation[1], (**c).aCubie[wid][row][0]->homeLocation[2]);
				//for(col = 0; col < 3; col++){
						printf("Colors: "); 
						for(i = 0; i < 6; i++){
							int col;
							//printf("%d ", (**c).aCubie[wid][row][0]->homeLocation[1]);
							//printf("%d \n", (**c).aCubie[wid][row][0]->homeLocation[2]);
							if((**c).aCubie[wid][row][0]->currentOrientation[i] != 'B'){  		//prints out the colors in the order UFDBLR
								printf("%c ", (**c).aCubie[wid][row][0]->currentOrientation[i]);
								}
						}
						printf("\nCubie Orientation: ");
						for(i = 0; i < 6; i++){
							if((**c).aCubie[wid][row][0]->currentOrientation[i] != 'B'){ 		//prints out UFDBLR
								printf("%c ", (**c).aCubie[wid][row][0]->orientationNames[i]);
								}
							}
						printf("\n");	
						printf("\n");					
					//}
				}
			}

				*/		//printf("colors: %s\n", (**c).aCubie[0][0][0]->colors);


			//print right
	




	/*	for(wid = 0; wid < 3; wid++){
			for(row = 0; row < 3; row++){
				printf("currentLocation %d%d%d\n ", wid, row, 2);
				printf("HomeLocation %d%d%d\n ", (**c).aCubie[wid][row][2]->homeLocation[0], (**c).aCubie[wid][row][2]->homeLocation[1], (**c).aCubie[wid][row][2]->homeLocation[2]);
				//for(col = 0; col < 3; col++){
						printf("Colors: "); 
						for(i = 0; i < 6; i++){
							int col;
							//printf("%d ", (**c).aCubie[wid][row][0]->homeLocation[1]);
							//printf("%d \n", (**c).aCubie[wid][row][0]->homeLocation[2]);
							if((**c).aCubie[wid][row][2]->currentOrientation[i] != 'B'){  		//prints out the colors in the order UFDBLR
								printf("%c ", (**c).aCubie[wid][row][2]->currentOrientation[i]);
								}
						}
						printf("\nCubie Orientation: ");
						for(i = 0; i < 6; i++){
							if((**c).aCubie[wid][row][2]->currentOrientation[i] != 'B'){ 		//prints out UFDBLR
								printf("%c ", (**c).aCubie[wid][row][2]->orientationNames[i]);
								}
							}
						printf("\n");	
						printf("\n");					
					//}
				}
			}

	*/

			
			//print up
			

/*
		for(wid = 0; wid < 3; wid++){
			for(row = 0; row < 3; row++){
				printf("currentLocation %d%d%d\n ", wid, row, 2);
				printf("HomeLocation %d%d%d\n ", (**c).aCubie[wid][row][2]->homeLocation[0], (**c).aCubie[wid][row][2]->homeLocation[1], (**c).aCubie[wid][row][2]->homeLocation[2]);
				//for(col = 0; col < 3; col++){
						printf("Colors: "); 
						for(i = 0; i < 6; i++){
							int col;
							//printf("%d ", (**c).aCubie[wid][row][0]->homeLocation[1]);
							//printf("%d \n", (**c).aCubie[wid][row][0]->homeLocation[2]);
							if((**c).aCubie[wid][row][2]->currentOrientation[i] != 'B'){  		//prints out the colors in the order UFDBLR
								printf("%c ", (**c).aCubie[wid][row][2]->currentOrientation[i]);
								}
						}
						printf("\nCubie Orientation: ");
						for(i = 0; i < 6; i++){
							if((**c).aCubie[wid][row][2]->currentOrientation[i] != 'B'){ 		//prints out UFDBLR
								printf("%c ", (**c).aCubie[wid][row][2]->orientationNames[i]);
								}
							}
						printf("\n");	
						printf("\n");					
					//}
				}
			}*/


						






						/*printf("homeLocation: %d ", (**c).aCubie[2][1][0]->homeLocation[0]);
						printf("homeLocation: %d ", (**c).aCubie[2][1][0]->homeLocation[1]);
						printf("homeLocation: %d \n", (**c).aCubie[2][1][0]->homeLocation[2]);
											

						for(i = 0; i < 6; i++){
							//if((**c).aCubie[1][0][0]->currentOrientation[i] != 'B'){  		//prints out the colors in the order UFDBLR
								printf("%s\n ", (**c).aCubie[2][1][0]->currentOrientation);
							//	}
						}
						printf("Orientation: ");
						for(i = 0; i < 6; i++){
							if((**c).aCubie[2][1][0]->currentOrientation[i] != 'B'){ 		//prints out UFDBLR
								printf("%c ", (**c).aCubie[2][1][0]->orientationNames[i]);
								}
							}
						printf("\n");	*/





	
	return;
}

void printSide(struct cube **c, char side){

	int wid;
	int row;
	int col;
	int i = 0;
	int j = 0;
	int counter = 0;
	char flag;
//UP: row = 2
//DOWN: row = 0
//FRONT: width = 0
//BACK: width = 2
	if(side == 'l')
	{
		col = 0;
		flag = 'c';//column
	}

	else if(side == 'r')
	{
		col = 2;
		flag = 'c';//column
	}
	else if(side == 'u')
	{
		row = 2;
		flag = 'r';//row
	}
	else if(side == 'd')
	{
		row = 0;
		flag = 'r';//row
	}
	else if(side == 'f')
	{
		wid = 0;
		flag = 'w';//row
	}
	else if(side == 'b')
	{
		wid = 2;
		flag = 'w';//row
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(flag == 'c')
			{	
				wid = i;
				row = j;
			}
			else if(flag == 'r')
			{
				wid = i;
				col = j;
			}
			else if(flag == 'w')
			{
				row = i;
				col = j;
			}
		
			printf("*CurrentLocation: %d%d%d", wid, row, col);
			printf(" *HomeLocation: %d%d%d", (**c).aCubie[wid][row][col]->homeLocation[0], (**c).aCubie[wid][row][col]->homeLocation[1], (**c).aCubie[wid][row][col]->homeLocation[2]);
			printf(" *Color Orientation: "); 
			for(counter = 0; counter < 6; counter++){
				if((**c).aCubie[wid][row][col]->currentOrientation[counter] != 'B'){  		//prints out the colors in the order UFDBLR
					printf("%c ", (**c).aCubie[wid][row][col]->currentOrientation[counter]);
				}
			}
			printf(" *Current Orientation: ");
			for(counter = 0; counter < 6; counter++){
				if((**c).aCubie[wid][row][col]->currentOrientation[counter] != 'B'){ 		//prints out UFDBLR
					printf("%c ", (**c).aCubie[wid][row][col]->orientationNames[counter]);
				}
			}
		printf("\n");					

		}		
	}
}



//try one line 
