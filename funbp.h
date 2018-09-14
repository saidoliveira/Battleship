#ifndef FUNPB_H
#define	FUNPB_H
void printboard(int board[25][25], int n, int m);
void zeraBoard(int board[25][25], int n, int m);
void aondeehproibido(int mat[25][25],int n, int m);
void battleship(int mat[25][25],int n, int m, int &counter);//1
void cruiser(int board[25][25],int n, int m, int &counter);//2
void destroyer(int board[25][25], int n, int m, int &counter);//3
void submarine(int board[25][25], int n, int m, int &counter);//4

#endif