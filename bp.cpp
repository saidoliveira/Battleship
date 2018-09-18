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
	std::ofstream outFile;
	outFile.open("teste.txt");
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
				
				int i, j;
				for(i = 1; i < n+1; ++i)
				{
					for(j = 1; j < m+1; ++j)
					{
						outFile << board[i][j] << ' ';
			
					}
					outFile << "\n";
				}
				printboard(board, n, m);
				
				
				break;
			}
		}
		outFile << "\n";
	}

	outFile.close();
	return 0;
}