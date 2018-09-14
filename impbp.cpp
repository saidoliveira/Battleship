#include <iterator>
#include <iostream>
#include <ctime> 
#include <cstdlib> 
#include "funbp.h"
using std::cout;
//////////PROBLEMA>>>>As vezes não funciona porque o rand gera O MESMO NUMERO, achar um jeito de gerar numeros diferentes
void printboard(int board[25][25], int n, int m)
{
	int i, j;
	for(i = 0; i < n+2; ++i)
	{
		for(j = 0; j < m+2; ++j)////AJEITAR PRA IR ATÉ m x n
		{
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}

}

void aondeehproibido(int mat[25][25],int n, int m) 
{
	int i,j;
	for(i = 0; i < n+1; ++i)
	{
		for(j = 0; j < m+1; ++j)
		{
			if(mat[i][j]==1 )
			{
				mat[i][j+1] = mat[i][j+1]==1 ? 1 : 2;
				mat[i][j-1] = mat[i][j-1]==1 ? 1 : 2;
				mat[i+1][j] = mat[i+1][j]==1 ? 1 : 2;
				mat[i-1][j] = mat[i-1][j]==1 ? 1 : 2;
				mat[i+1][j+1] = mat[i+1][j+1]==1 ? 1 : 2;
				mat[i-1][j-1] = mat[i-1][j-1]==1 ? 1 : 2;
				mat[i-1][j+1] = mat[i-1][j+1]==1 ? 1 : 2;
				mat[i+1][j-1] = mat[i+1][j-1]==1 ? 1 : 2;
			}
		}
	}
}
void battleship(int board[25][25],int n, int m)
{	
	srand(time(NULL)); 
	int p,q;
	p = rand() % n+1 ;  //Gerando coordenadas aleatórias
	q = rand() % m+1 ;	
	
	int hv;
	int c=0;
	hv = rand() % 2; // HV DE 0 E 1. SE HV = 0::HORIZONTAL | SE HV = 1::VERTICAL.

	int count=0; //Contador para garantir que o while não entre no looping infinito;
	while(1)
	{	c++;
		if(board[p][q] == 0)
		{
			if(hv == 0)
			{
				if(board[p][q+1] == 0 && board[p][q+2] == 0 && board[p][q+3] == 0)
				{
					board[p][q] = 1;
					board[p][q+1] = 1; 
					board[p][q+2] = 1;
					board[p][q+3] = 1;
					break;
				}
				else 
				{	
					hv=1;			//Se não deu certo com hv=0, troca para hv=1
					count++;
				}
			}
			if(hv == 1)
			{
				if(board[p+1][q] == 0 && board[p+2][q] == 0 && board[p+3][q] == 0)
				{
					board[p][q] = 1;
					board[p+1][q] = 1; 
					board[p+2][q] = 1;
					board[p+3][q] = 1;
					break;
				}	
				else 
				{
					hv=0;			//Se não deu certo com hv=1, troca para hv=0
					count++;
				}
			}
		}
		//cout<<count<<'\n';
		if(count>2)
		{
			p = rand() % n+1 ;		//Se não deu certo com hv=0,nem com hv=1, gera outra cordenada
			q = rand() % m+1 ;
			//cout<<p<<q<<'\n';
		}
	}
	aondeehproibido(board, n, m);
}

void cruiser(int board[25][25], int n, int m)
{
	int x, y;
	int c(0);//BURRO
	int hv;
	for(x = 8; x < n+1; ++x)
	{
		for(y = 8; y < m+1; ++y)
		{
			hv = rand() % 2;
			if(c>0)
			{
				break;
			}
				if(board[x][y] == 0)
				{
					if(hv == 0)
					{
						if(board[x][y+1] == 0 && board[x][y+2] == 0 && board[x][y+3] != 1)
						{
							board[x][y] = 1;
							board[x][y+1] = 1;
							board[x][y+2] = 1;
							c++;
							aondeehproibido(board, n, m);						
						}
					}
					if(hv == 1)
					{
						if(board[x+1][y] == 0 && board[x+1][y] == 0 && board[x+3][y] != 1)
						{
							board[x][y] = 1;
							board[x+1][y] = 1;
							board[x+2][y] =1;
							c++;
							aondeehproibido(board, n, m);

						}
					}
				}
		}
	}
}

void destroyer(int board[25][25], int n, int m)
{
	int x, y;
	int c(0);//BURRO
	int hv;
	hv = rand() % 2;
	for(x = 1; x < n+1; ++x)
	{
		for(y = 1; y < m+1; ++y)
		{
			if(c>0)
			{
				break;
			}
				if(board[x][y] == 0)
				{
					if(hv == 0)
					{
						if(board[x][y+1] == 0 && board[x][y+2] != 1)
						{
							board[x][y] = 1;
							board[x][y+1] = 1;
							c++;
							aondeehproibido(board, n, m);						
						}
					}
					if(hv == 1)
					{
						if(board[x+1][y] == 0 && board[x+2][y] != 1)
						{
							board[x][y] = 1;
							board[x+1][y] = 1;
							c++;
							aondeehproibido(board, n, m);

						}
					}
				}
		}
	}
}

void submarine(int board[25][25], int n, int m){
	int x, y;
	int c(0);//BURRO
	int hv;
	hv = rand() % 2;
	for(x = 1; x < n+1; ++x)
	{
		for(y = 1; y < m+1; ++y)
		{
			if(c>0)
			{
				break;
			}
				if(board[x][y] == 0)
				{
					if(hv == 0)
					{
						if(board[x][y+1] != 1)
						{
							board[x][y] = 1;
							c++;
							aondeehproibido(board, n, m);						
						}
					}
					if(hv == 1)
					{
						if(board[x+1][y] != 1)
						{
							board[x][y] = 1;
							c++;
							aondeehproibido(board, n, m);

						}
					}
				}
		}
	}
}
