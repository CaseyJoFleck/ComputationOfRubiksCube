#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "cubieStruct.h"


//mixedCube
struct cube *cube1; //can't declare this in main DO I NEED THIS?!?!
//struct cube *ptr;

/**
*mixedCube - function that randomizes currentOrientation for each 
*	      cubie in solved positions and returns a mixed cube. 
*/ 
   
void mixedCube(struct cube **cube1){

	//variables for going through for loop
	int randT;
	//**cube1 = cube1;
	//how would he fight threw the fire

	for(int i = 0; i < 19; i++){
		randT = rand() % 18+1;
		switch(randT){
			case 1:
				up(cube1);
				break;
			case 2:
				down(cube1);
				break;
			case 3:
				left(cube1);
				break;
			case 4:
				right(cube1);
				break;
			case 5:
				back(cube1);
				break;
			case 6:
				front(cube1);
				break;
			case 7:
				upI(cube1);
				break;
			case 8:
				downI(cube1);
				break;
			case 9:
				leftI(cube1);
				break;
			case 10:
				rightI(cube1);
				break;
			case 11:
				backI(cube1);
				break;
			case 12:
				frontI(cube1);
				break;
			case 13:
				up2(cube1);
				break;
			case 14:
				down2(cube1);
				break;
			case 15:
				left2(cube1);
				break;
			case 16:
				right2(cube1);
				break;
			case 17:
				back2(cube1);
				break;
			case 18:
				front2(cube1);
				break;
		}
	}

}
