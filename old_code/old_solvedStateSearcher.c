
//#include "functions.h"

//may need to fix sequence pointer and counter may need to make it a pointer
//struct cube *cube1 ->put back in param
//declare function backup here***********************
struct cube *cube1;
void cubePermutation(int length, int *sequence, int index){
	int endLoop = -1;
	
	while(endLoop == -1){
		if(sequence[0]==12&&sequence[1]==12&&sequence[2]==12&&sequence[3]==12){
			printf("\nSequence:");
			for(int i = 0; i < 4;i++){printf(" %d ",sequence[i]); }
			endLoop = 1;
		}
		else{
			if(sequence[length-1]!=0){//if cube solved, print seq, just printing sequence now
				
				backup(length,cube1,&sequence,&index);
				}
			else{
							//TurnCube(cube, si)
							//turnCube(cube,s+1);
				index++;
				sequence[index]=1;
				}
		}
	}
	return 0;
} 


//struct cube *cube1 ->put back in param
void backup(int length, int **sequence, int *index){ //make backup an int function -> make backup return 1 if checkEquality is 1 (equal), and 0 otherwise****
	int a = 24;
	int i=*index; 
	int s = (*sequence)[length-1];
	int tempSequence[length];
	
	while(s==12){
		(*sequence)[i]=0;	//turn s+1;
		*index=i-1;
		i--;
		s=(*sequence)[i];
							//TurnCube(cube,12); e.g. rI
							//TurnCube(cube,6); e.g. r
		}
							//Turn(cube, sI);
							//Turn(cube, s);
		(*sequence)[i]=s+1;
		//a = checkEquality(cube1, &sequence, length);
		//if(a==1){
			//print turn
		//}
							//printf("\nSequence:");
							//for(int i = 0; i < 4;i++){
								//printf(" %d ",(*sequence)[i]); 
							//} ******NEXT TASK: CALL CHECKEQUALITY, AFTER-> MAKE BACKUP INTO AN INT FUNCTION!!!
		for(int i = 0; i < 4;i++){
			tempSequence[i]=(*sequence)[i];
		}
		a = checkEquality(tempSequence, length);////WHY IS FUNCTION NOT WORKING?!?!? CHECK PASSING THE CUBE!
		if(a==1){
			printf("EQUAL!!!!HEY!!WOOOO!");
		}
		return;
}

int checkEquality(int *sequence,int length){
	initialize(&cube1);
	int w, r, col;
	int flag = 1;
	int isEqual=99; 
	int i, turnNum;
	for(i = 0; i < length-1; i++){
			turnNum = sequence[i];
			if(turnNum==1){
				turnNum++;
			}
			switch(turnNum){
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
				}
		}
		for(w = 0; w < 3; w++){	
			for(r = 0; r < 3; r++){
				for(col = 0; col < 3; col++){
					for(i = 0; i < 6; i++){
						if((**cube1).aCubie[w][r][col]->currentOrientation[i] != (**cube1).aCubie[w][r][col]->homeOrientation[i]){							
							flag = 0;
							return 0;
						}
				}
			}
		}
	}
	
	if(flag == 1){ 
		return 1;
	}
	
	return 0
	
	//free cube
	for(int w = 0; w < 3; w++){
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				free(cube1->aCubie[w][r][c]);
			}
		}
	}
	free(cube1);
}
	
////3 TURNS!!!
int checkEquality3(struct cube **cube1, struct cube **cube2, int turn1, int turn2, int turn3){
	int w, r, col;
	int flag = 1; 
	int i, turnNum;
	for(i = 0; i < 3; i++){
			switch(i){
				case 0:
					turnNum = turn1;
					break;
				case 1:
					turnNum = turn2;
					break;
				case 2:
					turnNum = turn3;
					break;
				}
			switch(turnNum){
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
				}
		}
		for(w = 0; w < 3; w++){	
			for(r = 0; r < 3; r++){
				for(col = 0; col < 3; col++){
					for(i = 0; i < 6; i++){
						if((**cube1).aCubie[w][r][col]->currentOrientation[i] != (**cube2).aCubie[w][r][col]->currentOrientation[i]){
							flag = 0;
							return 0;
						}
					}
			}
		}
	}
	//printf("flag %d",flag);
	if(flag == 1){ //equal
		writeTurn3(turn1, turn2, turn3);
		return 1;
	}
	
	return 0;
}



int checkEquality4(struct cube **cube1, struct cube **cube2, int turn1, int turn2, int turn3, int turn4){
	int w, r, col;
	int flag = 1; 
	int i, turnNum;
	for(i = 0; i < 4; i++){
			switch(i){
				case 0:
					turnNum = turn1;
					break;
				case 1:
					turnNum = turn2;
					break;
				case 2:
					turnNum = turn3;
					break;
				case 3:
					turnNum = turn4;
					break;
				}
			switch(turnNum){
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
				}
		}
		for(w = 0; w < 3; w++){	
			for(r = 0; r < 3; r++){
				for(col = 0; col < 3; col++){
					for(i = 0; i < 6; i++){
						if((**cube1).aCubie[w][r][col]->currentOrientation[i] != (**cube2).aCubie[w][r][col]->currentOrientation[i]){							
							flag = 0;
							return 0;
						}
				}
			}
		}
	}
	//printf("flag %d",flag);
	if(flag == 1){ //equal
		writeTurn4(turn1, turn2, turn3, turn4);
		return 1;
	}
	
	return 0;


}


int checkEquality5(struct cube **cube1, struct cube **cube2, int turn1, int turn2, int turn3, int turn4, int turn5){
	int w, r, col;
	int flag = 1; 
	int i, turnNum;
	for(i = 0; i < 5; i++){
			switch(i){
				case 0:
					turnNum = turn1;
					break;
				case 1:
					turnNum = turn2;
					break;
				case 2:
					turnNum = turn3;
					break;
				case 3:
					turnNum = turn4;
					break;
				case 4:
					turnNum = turn5;
					break;
				}
			switch(turnNum){
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
				}
		}
		for(w = 0; w < 3; w++){	
			for(r = 0; r < 3; r++){
				for(col = 0; col < 3; col++){
					for(i = 0; i < 6; i++){
						if((**cube1).aCubie[w][r][col]->currentOrientation[i] != (**cube2).aCubie[w][r][col]->currentOrientation[i]){
							flag = 0;
							return 0;
						}
				}
			}
		}
	}
	//printf("flag %d",flag);
	if(flag == 1){ //equal
		writeTurn5(turn1, turn2, turn3, turn4, turn5);
		return 1;
	}
	
	return 0;

}

int checkEquality6(struct cube **cube1, struct cube **cube2, int turn1, int turn2, int turn3, int turn4, int turn5, int turn6){
	int w, r, col;
	int flag = 1; 
	int i, turnNum;
	for(i = 0; i < 5; i++){
			switch(i){
				case 0:
					turnNum = turn1;
					break;
				case 1:
					turnNum = turn2;
					break;
				case 2:
					turnNum = turn3;
					break;
				case 3:
					turnNum = turn4;
					break;
				case 4:
					turnNum = turn5;
					break;
				case 5:
					turnNum = turn6;
					break;	
				}
			switch(turnNum){
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
				}
		}
		for(w = 0; w < 3; w++){	
			for(r = 0; r < 3; r++){
				for(col = 0; col < 3; col++){
					for(i = 0; i < 6; i++){
						if((**cube1).aCubie[w][r][col]->currentOrientation[i] != (**cube2).aCubie[w][r][col]->currentOrientation[i]){
							flag = 0;
						}
				}
			}
		}
	}
	
	if(flag == 0){
		return 0;
	}
	return 1;

}




void printTurn(int a, int b, int c, int d){
	int turnNum;
	int i;
	printf("\n");
	for(i = 0; i < 4; i++){
			switch(i){
				case 0:
					turnNum = a;
					break;
				case 1:
					turnNum = b;
					break;
				case 2:
					turnNum = c;
					break;
				case 23:
					turnNum = d;
					break;
				}
			switch(turnNum){
				case 1:
					printf("u");
					break;
				case 2:
					printf("d");
					break;
				case 3:
					printf("l");
					break;
				case 4:
					printf("r");
					break;
				case 5:
					printf("b");
					break;
				case 6:
					printf("f");
					break;
				case 7:
					printf(" uI ");
					break;
				case 8:
					printf(" dI ");
					break;
				case 9:
					printf(" lI ");
					break;
				case 10:
					printf(" rI ");
					break;
				case 11:
					printf(" bI ");
					break;
				case 12:
					printf(" fI ");
					break;
				}
			}
			printf("\n");
		}
	
	
			//////WRITE TURNS FOR 3
		void writeTurn3(int a, int b, int c){
		int turnNum;
		int i;
		FILE *pf;
		pf = fopen("three_permutations.txt", "a+"); //also make sure function clear file has same file name!

		for(i = 0; i < 3; i++){
				switch(i){
					case 0:
						turnNum = a;
						break;
					case 1:
						turnNum = b;
						break;
					case 2:
						turnNum = c;					
						break;
					}
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
			fprintf(pf, "\n");
			fprintf(pf, "%d %d %d", a, b, c); 
			fprintf(pf, "\n\n");
			fclose(pf);
		}
			
	
	//WRITE 4 TURNS!!
	void writeTurn4(int a, int b, int c, int d){
		int turnNum;
		int i;
		
		FILE *pf;
		pf = fopen("four_permutations.txt", "a+"); //also make sure function clear file has same file name!

		for(i = 0; i < 4; i++){
				switch(i){
					case 0:
						turnNum = a;
						break;
					case 1:
						turnNum = b;
						break;
					case 2:
						turnNum = c;					
						break;
					case 3:
						turnNum = d;
						break;
					}
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
			fprintf(pf, "\n");
			fprintf(pf, "%d %d %d %d", a, b, c, d); 
			fprintf(pf, "\n\n");
			fclose(pf);
		}
		
					
		////write turn 5
		void writeTurn(int length, int sequence[4]){
		int turnNum;
		int i;
		
		FILE *pf;
		pf = fopen("five_permutations.txt", "a+"); //also make sure function clear file has same file name!

		for(i = 0; i < 5; i++){
				switch(i){
					case 0:
						turnNum = a;
						break;
					case 1:
						turnNum = b;
						break;
					case 2:
						turnNum = c;					
						break;
					case 3:
						turnNum = d;
						break;
					case 4:
						turnNum = e;
						break;
					}
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
			fprintf(pf, "\n");
			fprintf(pf, "%d %d %d %d %d", a, b, c, d, e); 
			fprintf(pf, "\n\n");
			fclose(pf);
		}
		
		void clearFile(){
			FILE *pf;
			pf = fopen("three_permutations.txt", "w");
			pf = fopen("four_permutations.txt", "w");
			pf = fopen("five_permutations.txt", "w");
			fclose(pf);
		}
		
		
		

