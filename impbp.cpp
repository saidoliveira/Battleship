#include <iterator>
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <random>
#include "funbp.h"
using std::cout;
using std::endl;

void

int rand_number(){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 15);

	return std::round(dis(gen));
}

void printboard(int board[18][18], int n, int m) 
{
	int i, j;
	for(i = 1; i < n+1; ++i)
	{
		for(j = 1; j < m+1; ++j)
		{
			cout<<board[i][j]<<' ';
			
		}
		cout<<'\n';
	}

}
void zeraBoard(int board[18][18], int n, int m)
{	int i,j;
	for(i = 0; i < 18; ++i)
	{
		for(j = 0; j < 18; ++j)
		{
			board[i][j] = 0; 
			if (i==0)
			{
				board[i][j]=2;
			}
			if (j==0)
			{
				board[i][j]=2;
			}
		}
	}
	for(i = 0; i < n+1; ++i)
	{
		for(j = 0; j < m+1; ++j)
		{
			
			if (i==n)
			{
				board[i+1][j]=2;
			}
			if (j==m)
			{
				board[i][j+1]=2;
			}
		}
	}
}
void aondeehproibido(int mat[18][18],int n, int m) 
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
void battleship(int board[18][18],int n, int m, int &counter)
{	
	int p, q;
	p = rand_number() % n;
	q =rand_number() % m;
	
	int hv;
	int c=0;
	hv = rand_number() % 2; // HV DE 0 E 1. SE HV = 0::HORIZONTAL | SE HV = 1::VERTICAL.

	int count=0; //Contador para garantir que o while não entre no looping infinito;
	while(1)
	{	c++;
		if(board[p][q] == 0)
		{
			if(hv == 0)
			{
				if(board[p][q+1] == 1 && board[p][q+2] == 0 && board[p][q+3] == 0)
				{
					board[p][q] = 1;
					board[p][q+1] = 1; 
					board[p][q+2] = 1;
					board[p][q+3] = 1;
					counter += 4;
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
					counter += 4;
					break;
				}	
				else 
				{
					hv=0;			//Se não deu certo com hv=1, troca para hv=0
					count++;
				}
			}
		}
		
		{
			
			p = rand_number() % n+1 ;		//Se não deu certo com hv=0,nem com hv=1, gera outra cordenada
			q = rand_number() % m+1 ;
			
		}
	}
	aondeehproibido(board, n, m);
}

void cruiser(int board[18][18], int n, int m, int &counter)
{
	
	int p,q;
	p = rand_number() % n+1 ;  //Gerando coordenadas aleatórias
	q = rand_number() % m+1 ;	
	
	int hv;
	int c=0;
	hv = rand_number() % 2; // HV DE 0 E 1. SE HV = 0::HORIZONTAL | SE HV = 1::VERTICAL.

	int count=0; //Contador para garantir que o while não entre no looping infinito; hv;	
	while(1)
	{	c++;
		if(board[p][q] == 0)
		{
			if(hv == 0)
			{
				if(board[p][q+1] == 0 && board[p][q+2] == 0 && board[p][q+3] != 1)
				{
					board[p][q] = 1;
					board[p][q+1] = 1; 
					board[p][q+2] = 1;
					counter += 3;
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
				if(board[p+1][q] == 0 && board[p+2][q] == 0 && board[p+3][q] != 1)
				{
					board[p][q] = 1;
					board[p+1][q] = 1; 
					board[p+2][q] = 1;
					counter += 3;
					break;
				}	
				else 
				{
					hv=0;			//Se não deu certo com hv=1, troca para hv=0
					count++;
				}
			}
		}
		
		{
			p = rand_number() % n+1 ;		//Se não deu certo com hv=0,nem com hv=1, gera outra cordenada
			q = rand_number() % m+1 ;
			
		}
	}
	aondeehproibido(board, n, m);
}



void destroyer(int board[18][18], int n, int m, int &counter)
{
	
	int p,q;
	p = rand_number() % n+1 ;  //Gerando coordenadas aleatórias
	q = rand_number() % m+1 ;	
	
	int hv;
	int c=0;
	hv = rand_number() % 2; // HV DE 0 E 1. SE HV = 0::HORIZONTAL | SE HV = 1::VERTICAL.

	int count=0; //Contador para garantir que o while não entre no looping infinito; hv;
	
	while(1)
	{	c++;
		if(board[p][q] == 0)
		{
			if(hv == 0)
			{
				if(board[p][q+1] == 0 && board[p][q+2] != 1)
				{
					board[p][q] = 1;
					board[p][q+1] = 1;
					counter += 2;
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
				if(board[p+1][q] == 0 && board[p+2][q] != 1)
				{
					board[p][q] = 1;
					board[p+1][q] = 1;
					counter += 2; 
					break;
				}	
				else 
				{
					hv=0;			//Se não deu certo com hv=1, troca para hv=0
					count++;
				}
			}
		}
		
		{
			p = rand_number() % n+1 ;		//Se não deu certo com hv=0,nem com hv=1, gera outra cordenada
			q = rand_number() % m+1 ;
			
		}
	}
	aondeehproibido(board, n, m);
}

void submarinerandom(int board[18][18], int n, int m, int &counter){
	
	int p,q;
	p = rand_number() % n+1 ;  //Gerando coordenadas aleatórias
	q = rand_number() % m+1 ;	
	
	int hv;
	int c=0;
	hv = rand_number() % 2; // HV DE 0 E 1. SE HV = 0::HORIZONTAL | SE HV = 1::VERTICAL.

	int count=0; //Contador para garantir que o while não entre no looping infinito; hv;
	
	while(1)
	{	c++;
		if(board[p][q] == 0)
		{
			if(hv == 0)
			{
				if(board[p][q+1] == 0)
				{
					board[p][q] = 1;
					counter++;
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
				if(board[p+1][q] == 0)
				{
					board[p][q] = 1;
					counter++;
					break;
				}	
				else 
				{
					hv=0;			//Se não deu certo com hv=1, troca para hv=0
					count++;
				}
			}
		}
		
		{
			p = rand_number() % n+1 ;		//Se não deu certo com hv=0,nem com hv=1, gera outra cordenada
			q = rand_number() % m+1 ;
			
		}
	}
	aondeehproibido(board, n, m);
}

void submarine(int board[18][18], int n, int m, int &counter){
	int x, y;
	int c(0);//BURRO
	int hv;
	hv = rand_number() % 2;
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
							counter++;
							aondeehproibido(board, n, m);						
						}
					}
					if(hv == 1)
					{
						if(board[x+1][y] != 1)
						{
							board[x][y] = 1;
							c++;
							counter++;
							aondeehproibido(board, n, m);

						}
					}
				}
		}
	}
}