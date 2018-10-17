#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "cubieStruct.h"
#include "initializeFunctionForSolvedStateSolver.h"
#include <getopt.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

//1)try to do function with a permutation of 3 and 5
//2)add in other method that checks to see if conditions apply to get rid of turns we dont need to check

//may need to fix sequence pointer and counter may need to make it a pointer
//struct cube *cube1 ->put back in param
//decterlare function backup here + all other functions undeclared***********************
//struct cube *cube1;

//next time
//run 1000 times in main to get average time
//make chart in latex
//add time to main
struct cube *cube1;
struct cube *cube2;
void cubePermutation(int length, int *sequence, int index){
	int endLoop = -1;
	int a = 0;
	int endLoopLength = 4;
	if(length < endLoopLength){
		endLoopLength=length;
	}
	while(endLoop == -1){

		endLoop = 1;
		
		for(int i = 0; i < endLoopLength; i++){
			if(sequence[i]!=12){
				endLoop = -1;	
			}
		}
		
		if(endLoop == 1){
			printf("\nSequence:");
			for(int i = 0; i < length;i++){printf(" %d ",sequence[i]); }
			
		}
		else{
			if(sequence[length-1]!=0){


				a = checkEquality(sequence, length);							// needed to call checkEquality + trivialMoveRemover before calling backup 
				if(a==1){
					writeTurn(sequence, length);
					//for(int i = 0; i < length;i++){printf(" %d ",sequence[i]); }
					//printf("\n");
				}
				//for(int i = 0; i < length;i++){printf(" %d ",sequence[i]); }			//because it changes all 0's to 1's here!
				//printf("\n");
				backup(length,&sequence,&index);
																				

				
			}
			else{
							//printf("\nSequence:");
			//for(int i = 0; i < length;i++){printf(" %d ",sequence[i]); }
				index++;
				backup(length,&sequence,&index);
			}

			
		}
	}
	return 0;
} 


void backup(int length, int **sequence, int *index){ 
	int a = 24;
	int i=*index; 
	int s = (*sequence)[length-1];
	int tempSequence[length];
	int incrementNextIndex = 1;

	
	while(incrementNextIndex == 1){
		if(length > 3){
			//dont set to 0 if its the first value! WHWHWYYYYY does the first value go back to one!?
			//try to check if first 4 values are 12 here
			if((*sequence)[0] == 12 && (*sequence)[1] == 12 && (*sequence)[2] == 12 &&(*sequence)[3] == 12){
				incrementNextIndex = 2;
			}   
			else{

				i=*index;
				s=(*sequence)[i];
				
						
				while(s==12){
					if(i!=0){
						(*sequence)[i]=0;
						i--;
						*index=i;
						s=(*sequence)[i];
					}
					else{
						if((*sequence)[0] == 12){
							printf("HEY!!!");
							i++;
							*index=i;
							s=(*sequence)[i];
						} 
					}
				}
					(*sequence)[i]=s+1;
					
					for(int i = 0; i < length;i++){printf(" %d ",(*sequence)[i]); }
					printf("\n");
					
					incrementNextIndex = trivialMoveRemover(&sequence,&index);
			}	
		}
	}
		return;
}

int trivialMoveRemover(int ***sequence, int **index){
	int a = 0;
	int currentValue = (**sequence)[**index]; //comment all out at some point
	int currentValueInFront = (**sequence)[**index + 1]; //+1; next incremented value Of Position One In Front Of CurrentPosition
	int nextValueBehind = (**sequence)[**index-a]; //next value of each position behind currentValueInFront
	int commuterOfCurrentValue = currentValue+1; //a commuter move is one where the move does not effect the current move e.g. commuter of 1 is 2
	int inverseOfCommuterValue = (currentValue+7)%12; //the inverse of the current commuter e.g. inverse of 2 is 8, so commuter inverse of 1 is 8
	int outOfLoop = 1;
	int incrementNextIndex = 0;
	int changed = 1; //the current moves are unique and necessary moves if changed = 0 

	while(changed == 1 && incrementNextIndex == 0){ //while not equal
		changed = 0;
	//	printf("1nextindex: %d", incrementNextIndex);
	
		//if value of position one ahead is odd
		if(currentValue%2==1){		

			a=0;
			outOfLoop = 1;
			currentValue = (**sequence)[**index]; 
			nextValueBehind = (**sequence)[**index-a];
			commuterOfCurrentValue = currentValue+1; 
			inverseOfCommuterValue = (currentValue+7)%12;
			if(inverseOfCommuterValue == 0){
				inverseOfCommuterValue = 12;
			}
			
			
			while(outOfLoop == 1){
				
				a++;
				outOfLoop = 0; 	
				nextValueBehind = (**sequence)[**index-a];
				
				if(a < **index){//while these are true //thing 2
					if(nextValueBehind == inverseOfCommuterValue || nextValueBehind == commuterOfCurrentValue){
						outOfLoop = 1;
					}
					
				}
			
			}

				
			if(((currentValue - nextValueBehind)%6==0)&&(currentValue != nextValueBehind)){ //if current value is the inverse value (bc it will go back to the same positioning ) want to increment
				(**sequence)[**index]= (**sequence)[**index]+1;
				currentValue++;
				changed = 1;
			}
			
			
			
			int i = **index;
			if(i > 2){ //below code can only happen if there are at least 4 moves (positions in the array) 0-3
				
				//if four positions in a row are the same value
				if(currentValue ==(**sequence)[i-1] && currentValue == (**sequence)[i-2] && currentValue == (**sequence)[i-3]){
					if(currentValue >= 12){
						incrementNextIndex = 1;
						printf("HEY!!!");
						for(int j = 0; j < 5; j++){
							printf(" %d ",(**sequence)[j]);
						}
						
					}else{
						(**sequence)[i] = (**sequence)[i]+1; 
						currentValue++;
						changed = 1;
					}
						
				}
				
				int tempSeq2[6];
				for(int j = 0; j < 6; j++){
					tempSeq2[j] = (**sequence)[j];
				}
				incrementNextIndex = fourFinder(&sequence, index);
				for(int j = 0; j < 6; j++){
					if(tempSeq2[j] != (**sequence)[j]){
						changed = 1;
						currentValue = (**sequence)[i];//incrementNextIndex
					}
				}
					
			//printf("%d",changed);
			}
		}
		
		//if even
		else{
			if(changed != 1){
										
			a=0;
			outOfLoop = 1;
			currentValue = (**sequence)[**index]; 
			nextValueBehind = (**sequence)[**index-a];
			commuterOfCurrentValue = currentValue-1; 
			inverseOfCommuterValue = (currentValue+5)%12;
						
			while(outOfLoop == 1){
				
				a++;
				outOfLoop = 0; 	
				nextValueBehind = (**sequence)[**index-a];
				
				if(a < **index){//while these are true
					if(nextValueBehind == inverseOfCommuterValue || nextValueBehind == commuterOfCurrentValue){
						outOfLoop = 1;
					}
					
				}
			
			}

		
				int i = **index;
				if(i > 2){ //below code can only happen if there are at least 4 moves (positions in the array)
				
				//if four positions in a row are the same value
				if(currentValue ==(**sequence)[i-1] && currentValue == (**sequence)[i-2] && currentValue == (**sequence)[i-3]){
					if(currentValue >= 12){
						incrementNextIndex = 1;
					}
					else{
						
					(**sequence)[i] = (**sequence)[i]+1; 
					currentValue++;
					changed = 1;
					}
				}
				
				int tempSeq[6];
				for(int j = 0; j < 6; j++){
					tempSeq[j] = (**sequence)[j];
				}
				incrementNextIndex = fourFinder(&sequence, index);
				for(int j = 0; j < 6; j++){
					if(tempSeq[j] != (**sequence)[j]){
						changed = 1;
						currentValue = (**sequence)[i];
					}
					
				}
				
						
			}	
			

				
				if((currentValue - nextValueBehind)%6==0&&currentValue != nextValueBehind){ 	//if current value is the inverse value (bc it will go back to the same positioning ) want to increment
				
					if(currentValue >= 12){													//if current value is greater than 12, exit the loop
						incrementNextIndex = 1;
					}
					else{
																													// but not equal numbers (bc two of the same turns do not go back to original)
						(**sequence)[**index]= (**sequence)[**index]+1;				
						currentValue++;
						changed = 1;	
					}
				}
			}
		}
	}
	return incrementNextIndex;
} 

//1: even or odd? 2: can put this code in method above or call inside method above
//cant I put this method in trivial move remover method?
int fourFinder(int ****sequence, int **index){//thing 1
	//check length before function called
	int a = 1;
	int outOfLoop = 1;
	int counter = 1;
	int changed = 1;


	
	
		while(outOfLoop == 1 && a <= **index){		
			
			int currentValue = (***sequence)[**index]; 
			int commuterOfCurrentValue = currentValue+1; 
			int inverseOfCommuterValue = (currentValue+7)%12;
			int nextValueBehind = (***sequence)[**index-a];	
							
			if(nextValueBehind != inverseOfCommuterValue || nextValueBehind != commuterOfCurrentValue || nextValueBehind != currentValue){
				//printf("%d%d",outOfLoop,a);
				outOfLoop = 0;				
			}
			if(nextValueBehind == currentValue){
				counter++;
			}
			if(counter > 3){
				(***sequence)[**index] = (***sequence)[**index]+1; 
				a = 0;
				counter = 1;
			}
			if((***sequence)[**index] >= 12){
				outOfLoop = 0;
				changed = 0;
				
			}
			a++;		
		}								
	//printf("out of loop!\n");
	return changed;
}
	
int checkEquality(int *sequence,int length){
	initialize(&cube1);
	initialize(&cube2);
	int w, r, col;
	int isEqual=1; 
	int i, turnNum;
	for(i = 0; i < length; i++){
			turnNum = sequence[i];
			switch(turnNum){
				case 1:
					up(&cube1);
					break;
				case 2:
					down(&cube1);
					break;
				case 3:
					left(&cube1);
					break;
				case 4:
					right(&cube1);
					break;
				case 5:
					back(&cube1);
					break;
				case 6:
					front(&cube1);
					break;
				case 7:
					upI(&cube1);
					break;
				case 8:
					downI(&cube1);
					break;
				case 9:
					leftI(&cube1);
					break;
				case 10:
					rightI(&cube1);
					break;
				case 11:
					backI(&cube1);
					break;
				case 12:
					frontI(&cube1);
					break;
				}
		}
		for(w = 0; w < 3; w++){	
			for(r = 0; r < 3; r++){
				for(col = 0; col < 3; col++){
					for(i = 0; i < 6; i++){
						if((*cube1).aCubie[w][r][col]->currentOrientation[i] != (*cube2).aCubie[w][r][col]->currentOrientation[i]){							
							isEqual= 0;//if not solved, then isEqual == 0. If solved, isEqual ==1
						}
				}
			}
		}
	}
	//printCube(&cube1);
	for(int w = 0; w < 3; w++){
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				free(cube1->aCubie[w][r][c]);
				free(cube2->aCubie[w][r][c]);
			}
		}
	}
	free(cube1);
	free(cube2);
	
	return isEqual;
}

void writeTurn(int *sequence,int length){
	int turnNum;
	int i;
	char lengthAsString[2];
	char fileName[25]="permutation_length_";
	char folderName[50]="original_state_text_files/";
	
	sprintf(lengthAsString, "%d", length);
	strcat(fileName,lengthAsString);
	strcat(fileName,".txt");
	strcat(folderName,fileName);
	
	FILE *pf;
	pf = fopen(folderName, "a+");

	for(i = 0; i < length; i++){
		turnNum = sequence[i];
		switch(turnNum){
			case 1:
				fprintf(pf," u ");
				break;
			case 2:
				fprintf(pf," d ");
				break;
			case 3:
				fprintf(pf," l ");
				break;
			case 4:
				fprintf(pf," r ");
				break;
			case 5:
				fprintf(pf," b ");
				break;
			case 6:
				fprintf(pf," f ");
				break;
			case 7:
				fprintf(pf," uI ");
				break;
			case 8:
				fprintf(pf," dI ");
				break;
			case 9:
				fprintf(pf," lI ");
				break;
			case 10:
				fprintf(pf," rI ");
				break;
			case 11:
				fprintf(pf," bI ");
				break;
			case 12:
				fprintf(pf," fI ");
				break;
			}
		}
	
		//fprintf(pf, "\n");
		//fprintf(pf, "%d", a); 
		fprintf(pf, "\n\n");
		fclose(pf);
}
	
void clearFile(int length){
	
	char lengthAsString[2];
	char fileName[25]="permutation_length_";
	char folderName[50]="original_state_text_files/";
	
	sprintf(lengthAsString, "%d", length);
	strcat(fileName,lengthAsString);
	strcat(fileName,".txt");
	strcat(folderName,fileName);
	
	FILE *pf;
	//pf = fopen(folderName, "a+");
	//fclose(pf);
	
	pf = fopen(folderName, "w");
	fclose(pf);
}
	

void writeTime(double sec, int length){
	int turnNum;
	int i;
	double h, m, s, ms, es;
	char lengthAsString[2];
	char fileName[25]="permutation_length_";
	char folderName[50]="original_state_text_files/";
	
	sprintf(lengthAsString, "%d", length);
	strcat(fileName,lengthAsString);
	strcat(fileName,".txt");
	strcat(folderName,fileName);
	
	FILE *pf;
	pf = fopen(folderName, "a+");
	 
	 h = floor(sec/3600); 
	 m = floor((sec -(3600*h))/60);
	 s = floor((sec -(3600*h)-(m*60)));
	 ms = floor((sec -(3600*h)-(m*60)-s)*1000);							// 1000 converts s to ms
	
	printf("Total time: %.0f hrs %f  min %f  sec %f ms \n",h,m,s,ms);	
	fprintf(pf, "Total time: %.0f hrs %f  min %f  sec %f ms \n",h,m,s,ms);
	fprintf(pf, "\n\n");
	fclose(pf);
}		
		

