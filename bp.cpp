#include <iterator>
#include <iostream>
#include <ctime> 
#include <cstdlib>
//#include <>
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
	//zeraBoard(board, n , m);
	//std::vector< int** > Ve;	
	//zeraBoard(board, n, m);
		for ( i = 0; i < 5; ++i)
		{
			
			while(1)
			{	
	
				zeraBoard(board, n, m);
				int counter = 0;
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
							
				
				//for(int i=0; i < Ve.size(); i++){
				//	printboard(Ve[i], n, m);
				//}

				std::cout << "Tem " << counter << " 1's \n";

				if(counter == 20)
				{
					cout<<"PQP\n";
					printboard(board, n, m);
					break;//	Ve.push_back(board);
				}
			}
		}
		
		
		


			
	

	return 0;
}