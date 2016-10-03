//////////////////////////////////////
//Algoritimos e Programação         //
//Nome: Guilherme Quintal Gonçalves //
//RA: 620386                        //
//Exercicio: 3                      //
//Maio/2016                         //
//////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coord{
	int x;
	int y;
} Coord;

Coord procura(char **m, char *palavra, int nLin, int nCol);

int main ()
{
	int linha, coluna, qtd_palavra;
	int i, j, ok, t, k;
	Coord coordenada;
	char **m;
	char *pesquisa;

	do
	{
		scanf("%d", &linha);
	}while( linha < 1 && linha > 50);

	do
	{
		scanf("%d", &coluna);
	}while( coluna < 1 && coluna > 50);

	m = (char **) malloc(linha * sizeof(char *)); //Aloca um Vetor de Ponteiros

	if( m != NULL)
	{
		for (i = 0; i < linha; i++)	//Percorre as linhas do Vetor de Ponteiros
		{ 	
			m[i] = (char *) malloc(coluna * sizeof(char)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
		
		    scanf("%s", m[i]); 
		}
	}

	do
	{
		scanf("%d", &qtd_palavra);
	}while( qtd_palavra < 1 && qtd_palavra > 50);

	pesquisa = (char *) calloc(linha + 1,sizeof(char)); //Aloca um Vetor de Ponteiros

	for (i = 0 ; i < qtd_palavra ; i++)
	{
		coordenada = procura(m, pesquisa, linha, coluna);

		if (coordenada.x == -1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d %d\n", coordenada.x, coordenada.y);	
		}
	}

	free(pesquisa);

	for (i = 0 ; i < linha ; i++)
	{
		free(m[i]);
	}

	free(m);
}

Coord procura(char **m, char *palavra, int nLin, int nCol)
{
	int i, j, k = 0, primeiro;
	Coord coordenada;

	scanf("%s", palavra);

	for (i = 0 ; i < nLin ; i++)
	{
		for (j = 0 ; j < nCol ; j++)
		{
			if (m[i][j] == palavra[k])
			{
				k++;

				if (k == 1)
				{
					coordenada.x = i;
					coordenada.y = j;
				}

				if (palavra[k] == '\0')
				{
					return coordenada;
				}
			}
			else
			{
				k = 0;
			}
		}
	}

	coordenada.x = -1;
	coordenada.y = -1;
	return coordenada;
}
