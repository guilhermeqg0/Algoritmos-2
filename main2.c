
/*
Algoritmos e Programação II
Nome: Guilherme Quintal Gonçalves
RA: 620386
Exercício: Atividade 2 - Número: 1
Junho/2016
*/

#include <stdio.h>

#define MAX 3

char matriz[MAX][MAX];

char verificacao(void);

void iniciarjogo(void);

void jogadapessoa(void);

void jogadaPC(void);

void mostramatriz(void);

void aleatorio(void);


int main(){

int i, j, linha, coluna, fim, opcao, cond;
char matriz[MAX][MAX];
char O, X, vazio;
char VAZIO;

fim = 0;
cond = 0;

	printf("Selecione a opção desejada:");

	printf("\n");

	printf("1. Player 1  X  Player 2\n2. Jogar contra o computador\n");

	scanf("%d", &opcao);

	switch (opcao){

		case 1:

        printf("Opção 1. escolhida.");

	for(i = 0; i < MAX; i++){

		for(j = 0; j < MAX; j++)

			matriz[i][j] = vazio;
			
	}

	while(fim < 9){

			for(i = 0; i < MAX; i++){

				for(j = 0; j < MAX; j++)

					if(matriz[i][j] == vazio)

						printf("|-|");
						
				

					else

						printf("|%c|", matriz[i][j]);

						printf("\n");
					

			}

		printf ("\n");

		printf("Vez de Player 1! Digite as coordenadas que deseja inserir O: \n");

		scanf("%d %d", &linha, &coluna);

			while(matriz[linha][coluna] != vazio || linha > 2 || coluna >2){

				printf("Vez de Player 1! Digite as coordenadas que deseja inserir O: \n");

				scanf("%d %d", &linha, &coluna);

				}

		matriz[linha][coluna] = 'O';

		fim++;


		if(matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O' || matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O' || matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O' || matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O' || matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O' || matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O' || matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O' || matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O') {

		printf("Player 1 ganhou!\n");

		break;

		}

		for(i = 0; i < MAX; i++){

			for(j = 0; j < MAX; j++)

				if(matriz[i][j] == vazio)

					printf("|-|");
				

				else

					printf("|%c|", matriz[i][j]);

					printf("\n");	

		}

		printf ("\n");

		printf("Player 2 - X: \n");

		scanf("%d %d", &linha, &coluna);


		while(matriz[linha][coluna] != vazio || linha > 2 || coluna >2){

			printf("Player 2 - X: \n");

			scanf("%d %d", &linha, &coluna);

		}

		matriz[linha][coluna] = 'X';

		fim++;


		if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X' || matriz[2][0] == 'X' && matriz[1][1] == 'X' && matriz[0][2] == 'X' || matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X' || matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X' || matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[1][2] == 'X' || matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X' || matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X' || matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'){

			printf("Player 2 ganhou!\n");

			break;
		}

	}

	break;

	case 2:

    printf("Opcao 2. escolhida.\n");

    VAZIO = ' ';

    iniciarjogo();

    do {

        mostramatriz();

        jogadapessoa();

        VAZIO = verificacao();

        if (VAZIO != ' ') 

            break;

        jogadaPC();

        VAZIO = verificacao();

        }

         while (VAZIO == ' ');

        if (VAZIO == 'X') 

            printf("Você Ganhou!\n");

        else 
            printf("Você Perdeu!\n");

        mostramatriz();

        return 0;


		default:

		printf("Opção inválida");

		break;

}

return 0;

}

void iniciarjogo(void)
{
    int i, j;

    for(i=0; i<MAX; ++i)

        for(j=0; j<MAX; ++j) 

            matriz[i][j] = ' ';
}

void jogadapessoa(void)
{
    int i, j;

    printf("Vez de Plajer 1! Digite as coordenadas:\n");

    scanf("%d%d", &i, &j);

    if (matriz[i][j] != ' ') {

        printf("Posição inválida, tente novamente. \n");

        jogadapessoa();
    }

    else 

        matriz[i][j] = 'X';
}

void jogadaPC(void)
{

register int i;

int ver = 0;


    for (i=0; i<MAX; ++i)

        if (ver !=1 && matriz[i][0] != ' ' && matriz[i][0] == matriz[i][1]) {

            if (matriz[i][2] == ' ') {

                matriz[i][2] = 'O';

                ver = 1;

                break;
            }
        }

    for (i=0; i<MAX;++i)

        if (ver !=1 && matriz[i][1] != ' ' && matriz[i][1] == matriz[i][2]) {

            if (matriz[i][0] == ' ') {

            matriz[i][0] = 'O';

            ver = 1;

            break;

            }
        }

    for (i=0; i<MAX;++i)

        if (ver !=1 && matriz[i][0] != ' ' && matriz[i][0] == matriz[i][2]) {

            if (matriz[i][1] == ' ') {

                matriz[i][1] = 'O';

                ver = 1;

                break;
            }
        }


    for (i=0; i<MAX; ++i)

        if (ver !=1 && matriz[0][i] != ' ' && matriz[0][i] == matriz[1][i]) {

            if (matriz[2][i] == ' ') {

                matriz[2][i] = 'O';

                ver = 1;

                break;
            }
        }

    for (i=0; i<MAX;++i)

        if (ver !=1 && matriz[1][i] != ' ' && matriz[1][i] == matriz[2][i]) {

            if (matriz[0][i] == ' ') {

                matriz[0][i] = 'O';

                ver = 1;

                break;
            }
        }

    for (i=0; i<MAX;++i)

        if (ver !=1 && matriz[0][i] != ' ' && matriz[0][i] == matriz[2][i]) {

            if (matriz[1][i] == ' ') {

                matriz[1][i] = 'O';

                ver = 1;

                break;
            }
        }


    if (ver !=1 && matriz[0][0] != ' ' && matriz[0][0] == matriz[1][1])

        if (matriz[2][2] == ' ') {

            matriz[2][2] = 'O';

            ver = 1;
        }

    if (ver !=1 && matriz[0][0] != ' ' && matriz[0][0] == matriz[2][2])

        if (matriz[1][1] == ' ') {

            matriz[1][1] = 'O';

            ver = 1;
        }

    if (ver !=1 && matriz[1][1] != ' ' && matriz[1][1] == matriz[2][2])

        if (matriz[0][0] == ' ') {

            matriz[0][0] = 'O';

            ver = 1;
        }

    if (ver !=1 && matriz[0][0] != ' ' && matriz[0][0] == matriz[1][1])

        if (matriz[2][2] == ' ') {

            matriz[2][2] = 'O';
            ver = 1;
        }


    if (ver !=1 && matriz[0][2] != ' ' && matriz[0][2] == matriz[1][1])

        if (matriz[2][0] == ' ') {

            matriz[2][0] = 'O';

            ver = 1;
        }

    if (ver !=1 && matriz[0][2] != ' ' && matriz[0][2] == matriz[2][0])

        if (matriz[1][1] == ' ') {

            matriz[1][1] = 'O';

            ver = 1;
        }

    if (ver !=1 && matriz[1][1] != ' ' && matriz[1][1] == matriz[2][0])

        if (matriz[0][2] == ' ') {

            matriz[0][2] = 'O';

            ver = 1;
        }

    if (ver == 1)

        ver = 0;

    else

        aleatorio();

    	ver = 0;

}

void aleatorio(void)
{
    int i, j;

    for(i=0; i<MAX; ++i) {

        for(j=0; j<MAX; ++j)

        if (matriz[i][j] == ' ')
         break;

    if (matriz[i][j] == ' ') 

        break;
    }

    if (i*j == 9) {

        printf("Empate!");

        }

    else

     matriz[i][j] = 'O';
}

void mostramatriz(void)
{
    int i, j;

    for(i = 0; i < MAX; i++){

        for(j = 0; j < MAX; j++)

            if(matriz[i][j] == ' ')

                printf("|-|");             

            else

                printf("|%c|", matriz[i][j]);

                printf("\n");
                    

            }
}

char verificacao(void)
{

int i;

    for (i=0; i<MAX;++i)

        if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2])

         return matriz[i][0];

    for (i=0; i<MAX;++i)

        if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) 

            return matriz[0][i];

    if (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]) 

        return matriz[0][0];

    if (matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]) 

        return matriz[0][2];

    return ' ';

}