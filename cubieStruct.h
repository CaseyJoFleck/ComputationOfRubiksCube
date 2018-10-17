//UFDBLR

#ifndef _cubieStruct_h_
#define _cubieStruct_h_
struct cubies{
//Orientation
char homeOrientation[6];		//original orientation of colors of the cubie
int a;
char currentOrientation[6]; 		//current orientation of colors of the cubie
int b;
char colors[3];
int cc;				//if declaring two arrays next to each other, each array bleeds into each other. So if printing out the array, will print out the letters in next array too. Need to figure out how
						//to separate the arrays without declaring another variable inbtw
//homeLocation
int homeLocation[3]; 			//original location of the cubie [width,row,column[
int dd;
char orientationNames[6]; 		//these are the names of the positions in the cube UFDBLR


};

struct cube{
	 struct cubies *aCubie[3][3][3]; //might need a pointer 
					//extern?
};

extern struct cube *cube1;
					//PREVIOUS: extern struct cubies *cubie[3][3][3];
					//PREVIOUS: Hoffman said figure out how to label the cubies here like i did when i did my for loop - but didnt say delete the for loop
#endif
					//3D array!


		
