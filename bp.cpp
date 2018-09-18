#include <iterator>
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include "funbp.h"
#include <fstream>
#define TAM 18 
using std::cout;
using std::cin;

int main()
{	
	int i, j, board[TAM][TAM]; // Incrementadores I linhas, J colunas e a declaração da matriz do board com tamanho máximo TAM = 25.
	int n, m; // Valores que indicam o tamanho de N linhas e M colunas.
	std::ofstream ofs ("teste.txt", std::ofstream::out);
	cin >> n >> m; // Leitura das linhas e colunas do board.
	for ( i = 0; i < 5; ++i)
	{
		while(1)
		{	
			int counter = 0;
			if(n >= 9 && m >= 9)
			{
				zeraBoard(board, n, m);
				battleship(board, n , m, counter);
				cruiser(board, n, m, counter);
				cruiser(board, n, m, counter);							
				destroyer(board, n, m, counter);							
				destroyer(board, n, m, counter);
				destroyer(board, n, m, counter);						
				submarinerandom(board, n, m, counter);
				submarinerandom(board, n, m, counter);
				submarinerandom(board, n, m, counter);
				submarinerandom(board, n, m, counter);
			}
			else
			{
				zeraBoard(board, n, m);
				battleship(board, n , m, counter);
				cruiser(board, n, m, counter);
				cruiser(board, n, m, counter);
				destroyer(board, n, m, counter);
				destroyer(board, n, m, counter);
				destroyer(board, n, m, counter);						
				submarine(board, n, m, counter);
				submarine(board, n, m, counter);
				submarine(board, n, m, counter);
				submarine(board, n, m, counter);
			}

			std::cout << "Tem " << counter << " 1's \n";

			if(counter == 20)
			{	//versaoFinal( board, n,  m) 
				ofs << board[n][m];
				printboard(board, n, m);
				break;
			}
		}
	}

	return 0;
}