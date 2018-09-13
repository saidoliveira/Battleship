#include <iterator>
#include <iostream>
#include <ctime> 
#include <cstdlib> 
using std::cout;
using std::cin;
//OBS: tá imprimindo a borda do tabuleiro para ter noção doq ta contesendo, dps tira
//OBS o barco grande tá sendo colocado lindamente em qualquer lugar , aparentemente sem erros,
//acredito q pros outros barcos seje só trocar trocar os numeros...etc etc;
//se digitado 15x15 dá um erro mas foda-se
//colocar limite de n e m

/*void aondeehproibido(COLOCAR MATRIZ AQUI) //terminar a função
{
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
			if(M[i][j]==1)
			{
				Mi[i][j+1] = Mi[i][j+1]==1 ? 1 : 2;
				Mi[i][j-1] = Mi[i][j-1]==1 ? 1 : 2;
				Mi[i+1][j] = Mi[i+1][j]==1 ? 1 : 2;
				Mi[i-1][j] = Mi[i-1][j]==1 ? 1 : 2;
				Mi[i+1][j+1] = Mi[i+1][j+1]==1 ? 1 : 2;
				Mi[i-1][j-1] = Mi[i-1][j-1]==1 ? 1 : 2;
				Mi[i-1][j+1] = Mi[i-1][j+1]==1 ? 1 : 2;
				Mi[i+1][j-1] = Mi[i+1][j-1]==1 ? 1 : 2;
			}
		}
	}
}*/
int main()
{	

	srand(time(NULL));
	int i, j, board[16][16]; // LINHA, COLUNA E A MATRIZ DO BOARD.
	int p,q;
	int n=10, m=10;
	//cin >> n >> m; // VALORES QUE O USUÁRIO VAI PASSAR (LINHA E COLUNA) DO BOARD.

	// PREENCHIMENTO DO TABULEIRO COM ZEROS / CRIAÇÃO DO TABULEIRO e 2 nas bordas.
	for(i = 0; i < 16; ++i)
	{
		for(j = 0; j < 16; ++j)
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
	board[q+1][p+1]=2;
	
	
	p = rand() % n+1 ;  //Gerando coordenadas aleatórias
	q = rand() % m+1 ;	
	cout<<"p= "<<p<<" q= "<<q<<'\n';
	int hv;
	int c=0;
	hv = rand() % 2; // HV DE 0 E 1. SE HV = 0::HORIZONTAL | SE HV = 1::VERTICAL.
	cout<<"hv Original: "<<hv<<'\n';
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
					cout<<"hv trocado pra um q dê certo: "<<hv<<'\n';
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
					cout<<"hv trocado pra um q dê certo:  "<<hv<<'\n';
					count++;
				}
			}
		}
		cout<<count<<'\n';
		if(count>=2)
		{
			p = rand() % n+1 ;		//Se não deu certo com hv=0,nem com hv=1, gera outra cordenada
			q = rand() % m+1 ;
			cout<<p<<q<<'\n';
		}
	}
		//FUNÇÃO PARA COLOCAR 2 NOS LUGARES QUE NÃO PODE
	for(i = 0; i < n+2; ++i)
	{
		for(j = 0; j < m+2; ++j)
		{
			if(board[i][j]==1)
			{
				board[i][j+1] = board[i][j+1]==1 ? 1 : 2;
				board[i][j-1] = board[i][j-1]==1 ? 1 : 2;
				board[i+1][j] = board[i+1][j]==1 ? 1 : 2;
				board[i-1][j] = board[i-1][j]==1 ? 1 : 2;
				board[i+1][j+1] = board[i+1][j+1]==1 ? 1 : 2;
				board[i-1][j-1] = board[i-1][j-1]==1 ? 1 : 2;
				board[i-1][j+1] = board[i-1][j+1]==1 ? 1 : 2;
				board[i+1][j-1] = board[i+1][j-1]==1 ? 1 : 2;
			}
		}
	}

	//print test
	for(i = 0; i < n+2; ++i)
	{
		for(j = 0; j < m+2; ++j)////AJEITAR PRA IR ATÉ m x n
		{
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}
		
	

	return 0;
}