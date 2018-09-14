#include <iterator>
#include <iostream>
#include <ctime> 
#include <cstdlib> 
#include "funbp.h"
using std::cout;
using std::cin;
#define TAM 25 
//OBS: tá imprimindo a borda do tabuleiro para ter noção doq ta contesendo, dps tira
//OBS o barco grande tá sendo colocado lindamente em qualquer lugar , aparentemente sem erros,
//acredito q pros outros barcos seje só trocar trocar os numeros...etc etc;
//se digitado 15x15 dá um erro mas foda-se
//colocar limite de n e m
int main()
{	

	srand(time(NULL));
	int i, j, board[TAM][TAM]; // LINHA, COLUNA E A MATRIZ DO BOARD.
	int p,q;
	int n, m;
	cin >> n >> m; // VALORES QUE O USUÁRIO VAI PASSAR (LINHA E COLUNA) DO BOARD.

	// PREENCHIMENTO DO TABULEIRO COM ZEROS / CRIAÇÃO DO TABULEIRO e 2 nas bordas. FAZER FUNÇAÕ DISSO
	for(i = 0; i < TAM; ++i)
	{
		for(j = 0; j < TAM; ++j)
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
	


			battleship(board, n , m );
			cruiser(board, n, m);
			cruiser(board, n, m);
			destroyer(board, n, m);
			destroyer(board, n, m);
			destroyer(board, n, m);
			submarine(board, n, m);
			submarine(board, n, m);
			submarine(board, n, m);
			submarine(board, n, m);
		
			printboard(board, n, m);
			
			
	

	return 0;
}