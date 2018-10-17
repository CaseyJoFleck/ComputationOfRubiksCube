#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "cubieStruct.h"

//temporary pointer
struct cubies *ptr;
struct cubies *edgePtr;
void reorient(char a[3], int b[3], char tempOrientation[6], int aNum);
/**
*left - function that turns the cube left inverse
* **c - pointer to the cube we are modifying
*/
void left(struct cube **c) {
	
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColor0;
	char tempColors[3];
	char tempColor1;
	char tempColor2;

	int w;//width
	int num[3];
	int r;//row 
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	//printf("colors: %s\n", (**c).aCubie[2][1][0]->colors);
	ptr = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = ptr;

	edgePtr = (**c).aCubie[0][1][0];
	(**c).aCubie[0][1][0] = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = (**c).aCubie[2][1][0];
	(**c).aCubie[2][1][0] = (**c).aCubie[1][0][0];
	(**c).aCubie[1][0][0] = edgePtr;

	//printf("Old orientation: %s\n", (**c).aCubie[2][1][0]->currentOrientation);
	for(w = 0; w < 3; w++){
		for(r = 0; r < 3; r++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = r;
				num[2] = 0;
				tempColor0 = (**c).aCubie[w][r][0]->colors[1];
				tempColor1 = (**c).aCubie[w][r][0]->colors[0];
				tempColor2 = (**c).aCubie[w][r][0]->colors[2]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][r][0]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				(**c).aCubie[w][r][0]->colors[0] = tempColors[0];
				(**c).aCubie[w][r][0]->colors[1] = tempColors[1];
				(**c).aCubie[w][r][0]->colors[2] = tempColors[2];
			//	printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy(cube1->aCubie[w][r][0]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);			//HOW IS THIS FUNCTION - REORIENT - CHANGING THE VALUE OF THE ACTUAL VARIABLE -tempOrientation - IF I AM PASSING BY VALUE?? #ASK 					//HOFFMAN
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy(cube1->aCubie[w][r][0]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", cube1->aCubie[w][r][0]->currentOrientation);
		}
	}

	return;
}

/**
*left - function that turns the cube left inverse
* **c - pointer to the cube we are modifying
*/
void leftI(struct cube **c) {
	
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColor0;
	char tempColors[3];
	char tempColor1;
	char tempColor2;

	int w;//width
	int num[3];
	int r;//row 
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	//printf("colors: %s\n", (**c).aCubie[2][1][0]->colors);
	ptr = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0]=(**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = ptr;

	edgePtr = (**c).aCubie[0][1][0];
	(**c).aCubie[0][1][0] = (**c).aCubie[1][0][0];
	(**c).aCubie[1][0][0] = (**c).aCubie[2][1][0];
	(**c).aCubie[2][1][0] = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = edgePtr;

	//printf("Old orientation: %s\n", (**c).aCubie[2][1][0]->currentOrientation);
	for(w = 0; w < 3; w++){
		for(r = 0; r < 3; r++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = r;
				num[2] = 0;
				tempColor0 = (**c).aCubie[w][r][0]->colors[1];
				tempColor1 = (**c).aCubie[w][r][0]->colors[0];
				tempColor2 = (**c).aCubie[w][r][0]->colors[2]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][r][0]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				(**c).aCubie[w][r][0]->colors[0] = tempColors[0];
				(**c).aCubie[w][r][0]->colors[1] = tempColors[1];
				(**c).aCubie[w][r][0]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy(cube1->aCubie[w][r][0]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);			//HOW IS THIS FUNCTION - REORIENT - CHANGING THE VALUE OF THE ACTUAL VARIABLE -tempOrientation - IF I AM PASSING BY VALUE?? #ASK HOFFMAN
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy(cube1->aCubie[w][r][0]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", cube1->aCubie[w][r][0]->currentOrientation);
		}
	}

	return;
}
///look at github and see what did differently


//right
void right(struct cube **c) {
	
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColor0;
	char tempColors[3];
	char tempColor1;
	char tempColor2;

	int w;//width
	int num[3];
	int r;//row 
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	ptr = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = ptr;

	edgePtr = (**c).aCubie[0][1][2];
	(**c).aCubie[0][1][2] = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = (**c).aCubie[2][1][2];
	(**c).aCubie[2][1][2] = (**c).aCubie[1][0][2];
	(**c).aCubie[1][0][2] = edgePtr;
	//(**c).aCubie[0][0][2]->colors[  = (**c).aCubie[0][2][2];


	for(w = 0; w < 3; w++){
		for(r = 0; r < 3; r++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = r;
				num[2] = 2;
				tempColor0 = (**c).aCubie[w][r][2]->colors[1];
				tempColor1 = (**c).aCubie[w][r][2]->colors[0];
				tempColor2 = (**c).aCubie[w][r][2]->colors[2]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][r][2]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				
				(**c).aCubie[w][r][2]->colors[0] = tempColors[0];
				(**c).aCubie[w][r][2]->colors[1] = tempColors[1];
				(**c).aCubie[w][r][2]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy(cube1->aCubie[w][r][2]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy(cube1->aCubie[w][r][2]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", cube1->aCubie[w][r][2]->currentOrientation);
		}
	}	
		

//UFDBLR
//wryogb

	

	return;
}

void rightI(struct cube **c) {
	
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColor0;
	char tempColors[3];
	char tempColor1;
	char tempColor2;

	int w;//width
	int num[3];
	int r;//row 
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	ptr = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = ptr;

		edgePtr = (**c).aCubie[0][1][2];
	(**c).aCubie[0][1][2] = (**c).aCubie[1][0][2];
	(**c).aCubie[1][0][2] = (**c).aCubie[2][1][2];
	(**c).aCubie[2][1][2] = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = edgePtr;
	//(**c).aCubie[0][0][2]->colors[  = (**c).aCubie[0][2][2];


	for(w = 0; w < 3; w++){
		for(r = 0; r < 3; r++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = r;
				num[2] = 2;
				tempColor0 = (**c).aCubie[w][r][2]->colors[1];
				tempColor1 = (**c).aCubie[w][r][2]->colors[0];
				tempColor2 = (**c).aCubie[w][r][2]->colors[2]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][r][2]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				
				(**c).aCubie[w][r][2]->colors[0] = tempColors[0];
				(**c).aCubie[w][r][2]->colors[1] = tempColors[1];
				(**c).aCubie[w][r][2]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy(cube1->aCubie[w][r][2]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy(cube1->aCubie[w][r][2]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", cube1->aCubie[w][r][2]->currentOrientation);
		}
	}	
		

//UFDBLR
//wryogb

	

	return;
}
	//LEFT: col = 0
	//RIGHT: col = 2
	//UP: row = 2
	//DOWN: row = 0
	//FRONT: width = 0
	//BACK: width = 2
void up(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = ptr;

	edgePtr = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = edgePtr;
//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;
				tempColor0 = (**c).aCubie[w][2][col]->colors[2];
				tempColor1 = (**c).aCubie[w][2][col]->colors[1];
				tempColor2 = (**c).aCubie[w][2][col]->colors[0]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}
	
void upI(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2]=(**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0]=(**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0]=(**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = ptr;

	edgePtr = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = edgePtr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;
				tempColor0 = (**c).aCubie[w][2][col]->colors[2];
				tempColor1 = (**c).aCubie[w][2][col]->colors[1];
				tempColor2 = (**c).aCubie[w][2][col]->colors[0]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);

		}
	}	
	
	return;
}

	/*ptr = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2]to here = (**c).aCubie[2][2][2];here
	(**c).aCubie[2][2][2] = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = ptr;

	edgePtr = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = edgePtr;	
*/



void down(struct cube **c) {
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = ptr;

	edgePtr = (**c).aCubie[0][0][1];
	(**c).aCubie[0][0][1] = (**c).aCubie[1][0][0];
	(**c).aCubie[1][0][0] = (**c).aCubie[2][0][1];
	(**c).aCubie[2][0][1] = (**c).aCubie[1][0][2];
	(**c).aCubie[1][0][2] = edgePtr;
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 0;
				num[2] = col;
				tempColor0 = (**c).aCubie[w][0][col]->colors[2];
				tempColor1 = (**c).aCubie[w][0][col]->colors[1];
				tempColor2 = (**c).aCubie[w][0][col]->colors[0]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				(**c).aCubie[w][0][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][0][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][0][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][0][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][0][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
		}
	}	

		return;
	}

void downI(struct cube **c) {
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = ptr;

	edgePtr = (**c).aCubie[0][0][1];
	(**c).aCubie[0][0][1] = (**c).aCubie[1][0][2];
	(**c).aCubie[1][0][2] = (**c).aCubie[2][0][1];
	(**c).aCubie[2][0][1] = (**c).aCubie[1][0][0];
	(**c).aCubie[1][0][0] = edgePtr;

	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 0;
				num[2] = col;
				tempColor0 = (**c).aCubie[w][0][col]->colors[2];
				tempColor1 = (**c).aCubie[w][0][col]->colors[1];
				tempColor2 = (**c).aCubie[w][0][col]->colors[0]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[w][0][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][0][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][0][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][0][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][0][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
		}
	}	

		return;
	}

void front(struct cube **c) {
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int r;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	ptr = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = ptr;
	
	edgePtr = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = (**c).aCubie[0][1][0];
	(**c).aCubie[0][1][0] = (**c).aCubie[0][0][1];
	(**c).aCubie[0][0][1] = (**c).aCubie[0][1][2];
	(**c).aCubie[0][1][2] = edgePtr;

	for(r = 0; r < 3; r++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = 0;
				num[1] = r;
				num[2] = col;
				tempColor0 = (**c).aCubie[0][r][col]->colors[0];
				tempColor1 = (**c).aCubie[0][r][col]->colors[2];
				tempColor2 = (**c).aCubie[0][r][col]->colors[1]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				(**c).aCubie[0][r][col]->colors[0] = tempColors[0];
				(**c).aCubie[0][r][col]->colors[1] = tempColors[1];
				(**c).aCubie[0][r][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//for(int
				//strcpy((**c).aCubie[0][r][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[0][r][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
		}
	}	
		return;
	}

void frontI(struct cube **c) {
	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int r;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	ptr = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = ptr;
	
	edgePtr = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = (**c).aCubie[0][1][2];
	(**c).aCubie[0][1][2] = (**c).aCubie[0][0][1];
	(**c).aCubie[0][0][1] = (**c).aCubie[0][1][0];
	(**c).aCubie[0][1][0] = edgePtr;

	for(r = 0; r < 3; r++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = 0;
				num[1] = r;
				num[2] = col;
				tempColor0 = (**c).aCubie[0][r][col]->colors[0];
				tempColor1 = (**c).aCubie[0][r][col]->colors[2];
				tempColor2 = (**c).aCubie[0][r][col]->colors[1]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[0][r][col]->colors[0] = tempColors[0];
				(**c).aCubie[0][r][col]->colors[1] = tempColors[1];
				(**c).aCubie[0][r][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[0][r][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[0][r][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
		}
	}	
		return;
	}


void back(struct cube **c){
//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int r;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	ptr = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = ptr;
	
	edgePtr = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = (**c).aCubie[2][1][2];
	(**c).aCubie[2][1][2] = (**c).aCubie[2][0][1];
	(**c).aCubie[2][0][1] = (**c).aCubie[2][1][0];
	(**c).aCubie[2][1][0] = edgePtr;

	for(r = 0; r < 3; r++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = 2;
				num[1] = r;
				num[2] = col;
				tempColor0 = (**c).aCubie[2][r][col]->colors[0];
				tempColor1 = (**c).aCubie[2][r][col]->colors[2];
				tempColor2 = (**c).aCubie[2][r][col]->colors[1]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[2][r][col]->colors[0] = tempColors[0];
				(**c).aCubie[2][r][col]->colors[1] = tempColors[1];
				(**c).aCubie[2][r][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[2][r][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[2][r][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
		}
	}	
	return;

}

void backI(struct cube **c){
//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int r;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array

	ptr = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = ptr;
	
	edgePtr = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = (**c).aCubie[2][1][0];
	(**c).aCubie[2][1][0] = (**c).aCubie[2][0][1];
	(**c).aCubie[2][0][1] = (**c).aCubie[2][1][2];
	(**c).aCubie[2][1][2] = edgePtr;

	for(r = 0; r < 3; r++){
		for(col = 0; col < 3; col++){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = 2;
				num[1] = r;
				num[2] = col;
				tempColor0 = (**c).aCubie[2][r][col]->colors[0];
				tempColor1 = (**c).aCubie[2][r][col]->colors[2];
				tempColor2 = (**c).aCubie[2][r][col]->colors[1]; 
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[2][r][col]->colors[0] = tempColors[0];
				(**c).aCubie[2][r][col]->colors[1] = tempColors[1];
				(**c).aCubie[2][r][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[2][r][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[2][r][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
		}
	}	
	return;

}
//Two Turns////////////////////////////////////////////////


/**
*
*/
void up2(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = ptr;

	ptr = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = ptr;

	ptr = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = ptr;
	
	ptr = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = ptr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;

				tempColor0 = (**c).aCubie[w][2][col]->colors[0]; 
				tempColor1 = (**c).aCubie[w][2][col]->colors[1]; 
				tempColor2 = (**c).aCubie[w][2][col]->colors[2];
				
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}

/**
*
*/
void down2(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][0][1];
	(**c).aCubie[0][0][1] = (**c).aCubie[2][0][1];
	(**c).aCubie[2][0][1] = ptr;

	ptr = (**c).aCubie[1][0][2];
	(**c).aCubie[1][0][2] = (**c).aCubie[1][0][0];
	(**c).aCubie[1][0][0] = ptr;

	ptr = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = ptr;
	
	ptr = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = ptr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;

				tempColor0 = (**c).aCubie[w][2][col]->colors[0]; 
				tempColor1 = (**c).aCubie[w][2][col]->colors[1]; 
				tempColor2 = (**c).aCubie[w][2][col]->colors[2];
				
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}

/**
*
*/
void front2(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][2][1];
	(**c).aCubie[0][2][1] = (**c).aCubie[0][0][1];
	(**c).aCubie[0][0][1] = ptr;

	ptr = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = ptr;

	ptr = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = ptr;
	
	ptr = (**c).aCubie[0][1][0];
	(**c).aCubie[0][1][0] = (**c).aCubie[0][1][2];
	(**c).aCubie[0][1][2] = ptr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;

				tempColor0 = (**c).aCubie[w][2][col]->colors[0]; 
				tempColor1 = (**c).aCubie[w][2][col]->colors[1]; 
				tempColor2 = (**c).aCubie[w][2][col]->colors[2];
				
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}

/**
*
*/
void back2(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = ptr;

	ptr = (**c).aCubie[2][0][1];
	(**c).aCubie[2][0][1] = (**c).aCubie[2][2][1];
	(**c).aCubie[2][2][1] = ptr;

	ptr = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = ptr;
	
	ptr = (**c).aCubie[2][1][2];
	(**c).aCubie[2][1][2] = (**c).aCubie[2][1][0];
	(**c).aCubie[2][1][0] = ptr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;

				tempColor0 = (**c).aCubie[w][2][col]->colors[0]; 
				tempColor1 = (**c).aCubie[w][2][col]->colors[1]; 
				tempColor2 = (**c).aCubie[w][2][col]->colors[2];
				
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}
/**
*
*/
void left2(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6; //size of array


	ptr = (**c).aCubie[0][1][0];
	(**c).aCubie[0][1][0] = (**c).aCubie[2][1][0];
	(**c).aCubie[2][1][0] = ptr;

	ptr = (**c).aCubie[2][0][0];
	(**c).aCubie[2][0][0] = (**c).aCubie[0][2][0];
	(**c).aCubie[0][2][0] = ptr;

	ptr = (**c).aCubie[2][2][0];
	(**c).aCubie[2][2][0] = (**c).aCubie[0][0][0];
	(**c).aCubie[0][0][0] = ptr;
	
	ptr = (**c).aCubie[1][2][0];
	(**c).aCubie[1][2][0] = (**c).aCubie[1][0][0];
	(**c).aCubie[1][0][0] = ptr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;

				tempColor0 = (**c).aCubie[w][2][col]->colors[0]; 
				tempColor1 = (**c).aCubie[w][2][col]->colors[1]; 
				tempColor2 = (**c).aCubie[w][2][col]->colors[2];
				
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}
/**
*
*/
void right2(struct cube **c) {

	//initializing a variable ptr that *ptr is pointing to
	//variables for going through for loop
	char tempColors[3];
	int w;//width
	int col;//column
	int num[3]; 
	char tempColor0;
	char tempColor1;
	char tempColor2;
	char tempOrientation[6];
	//printf("a: %c", tempOrientation[5]);
	int aNum = 6;//size of array


	ptr = (**c).aCubie[1][0][2];
	(**c).aCubie[1][0][2] = (**c).aCubie[1][2][2];
	(**c).aCubie[1][2][2] = ptr;

	ptr = (**c).aCubie[0][0][2];
	(**c).aCubie[0][0][2] = (**c).aCubie[2][2][2];
	(**c).aCubie[2][2][2] = ptr;

	ptr = (**c).aCubie[2][0][2];
	(**c).aCubie[2][0][2] = (**c).aCubie[0][2][2];
	(**c).aCubie[0][2][2] = ptr;
	
	ptr = (**c).aCubie[0][1][2];
	(**c).aCubie[0][1][2] = (**c).aCubie[2][1][2];
	(**c).aCubie[0][1][2] = ptr;

//UFDBLR
//wryogb
	for(w = 0; w < 3; w++){
		for(col = 0; col < 3; col++){
			//if(w != 1 && col != 1){
				strcpy(tempOrientation, "BBBBBB");
				strcpy(tempColors, "");
				num[0] = w;
				num[1] = 2;
				num[2] = col;

				tempColor0 = (**c).aCubie[w][2][col]->colors[0]; 
				tempColor1 = (**c).aCubie[w][2][col]->colors[1]; 
				tempColor2 = (**c).aCubie[w][2][col]->colors[2];
				
				//printf("tempColors:%c%c%c", tempColor0, tempColor1, tempColor2);
				//printf("Colors:%s", (**c).aCubie[w][2][col]->colors);
				tempColors[0] = tempColor0;
				tempColors[1] = tempColor1;
				tempColors[2] = tempColor2;
				
				
				(**c).aCubie[w][2][col]->colors[0] = tempColors[0];
				(**c).aCubie[w][2][col]->colors[1] = tempColors[1];
				(**c).aCubie[w][2][col]->colors[2] = tempColors[2];
				//printf("\n\n1 tempOrientation (outsideFunct): %s\n", tempOrientation);
				//strcpy((**c).aCubie[w][2][col]->colors, tempColors);
				reorient(tempColors, num, tempOrientation, aNum);
				//printf("\n\n3 tempOrientation (outsideFunct): %s", tempOrientation);
				strcpy((**c).aCubie[w][2][col]->currentOrientation, tempOrientation);
				//printf("currentOrientation: %s\n\n", (**c).aCubie[w][2][col]->currentOrientation);
			//}
		}
	}	
	
	return;
}

void reorient(char a[3], int b[3], char *tempOrientation, int aNum) {

	//LEFT: col = 0
	//RIGHT: col = 2
	//UP: row = 2
	//DOWN: row = 0
	//FRONT: width = 0
	//BACK: width = 2
		//UFDBLR
	//a=tempcolors
	//b=number(cubie name)
	if(b[2] == 0){ //col == 0 left
		tempOrientation[4]= a[2]; //left spot 
	}
	else if(b[2] == 2)
	{
		tempOrientation[5]= a[2]; //right
		

	}
	else if(b[2] == 1)
	{
		//b[2] = 'B';
	}
	if(b[1] == 0)
	{ 
		tempOrientation[2] = a[1]; //down 
	}
	else if(b[1] == 2)
	{ 
		tempOrientation[0] = a[1]; //up
	}
	else if(b[1] == 1)
	{
		//b[1] = 'B';
	}
	if(b[0] == 0)
	{
		tempOrientation[1] = a[0]; //front
	}
	else if(b[0] == 2)
	{
		tempOrientation[3] = a[0]; //back
	}
	else if(b[0] == 1)
	{
		//b[0] = 'B';
	}
	
//	printf("TempOrientation:%s\n", tempOrientation);
 	return;

	
}

	

