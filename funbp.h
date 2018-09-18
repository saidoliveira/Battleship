#ifndef FUNPB_H
#define	FUNPB_H
void printboard(int board[18][18], int n, int m);
void zeraBoard(int board[18][18], int n, int m);
void aondeehproibido(int mat[18][18],int n, int m);
void battleship(int mat[18][18],int n, int m, int &counter);//1
void cruiser(int board[18][18],int n, int m, int &counter);//2
void destroyer(int board[18][18], int n, int m, int &counter);//3
void submarine(int board[18][18], int n, int m, int &counter);//4
void submarinerandom(int board[18][18], int n, int m, int &counter);
void versaoFinal(int board[18][18], int n, int m);

#endif