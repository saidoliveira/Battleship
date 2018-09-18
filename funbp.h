#ifndef FUNPB_H
#define	FUNPB_H
void printboard(int board[18][18], int n, int m);
void zeraBoard(int board[18][18], int n, int m);
void aondeehproibido(int mat[18][18],int n, int m);
void battleship(int mat[18][18],int n, int m, int &counter);
void cruiser(int board[18][18],int n, int m, int &counter);
void destroyer(int board[18][18], int n, int m, int &counter);
void submarine(int board[18][18], int n, int m, int &counter);
void submarinerandom(int board[18][18], int n, int m, int &counter);
//void versaoFinal(int mat[18][18],int n, int m) ;
#endif