#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
void printCube(struct cube **c);
void initialize(struct cube **c);
void rUnsolved(struct cube **c);
void wUnsolved(struct cube **c, char textFile[10]);
void left(struct cube **c);
void right(struct cube **c);
void up(struct cube **c);
void down(struct cube **c);
void front(struct cube **c);
void back(struct cube **c);
void leftI(struct cube **c);
void rightI(struct cube **c);
void upI(struct cube **c);
void downI(struct cube **c);
void frontI(struct cube **c);
void backI(struct cube **c);
void left2(struct cube **c);
void right2(struct cube **c);
void up2(struct cube **c);
void down2(struct cube **c);
void front2(struct cube **c);
void back2(struct cube **c);
void reinitialize(struct cube *aCube);
void printSide(struct cube **c, char side);
fourFinder(int ****sequence, int **index);
#endif
