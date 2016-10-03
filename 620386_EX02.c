/*
Algoritmos e Programação II
Nome: Guilherme Quintal Gonçalves
RA: 620386
Exercício: Atividade 3 - Número: 2
Junho/2016
*/

#include<stdio.h>

int sudoku[9][9];
void resolver(int,int);


//Verificação das colunas
int verificacoluna(int i,int num)
{
    int j;

        for(j=0; j < 9; j++)

            if(sudoku[i][j]==num)

                return 0 ;
    return 1;
}

//Verificação das linhas
int verificalinha(int j,int num)
{

    int i;
        for(i=0; i < 9; i++)
            if(sudoku[i][j]==num)
                return 0;
    return 1;

}

int verificagrade(int i,int j,int num)
{

i=(i/3)*3 ;
j=(j/3)*3;

    int r,c;

        for(r=0; r < 3; r++)

            for(c=0; c < 3; c++)

                 if(sudoku[i+r][j+c] == num)

                    return 0;
    return 1;
}

void verificacao(int i,int j)
{

    if(j < 8)

            resolver(i,j+1);

        else

           resolver(i+1,0);
}

void mostrar()
{

    int i,j;

    printf("Solução\n");

        for(i=0; i < 9; i++)
        {

        for(j=0; j < 9; j++)

        printf("%d ",sudoku[i][j]);
        printf("\n");
        }

        getch();
}

void resolver(int i,int j)
{
    if(i > 8)

        mostrar();

    if(sudoku[i][j]!= 0)

        verificacao(i,j);

    else
    {
        int ctr;

            for(ctr=1; ctr <=9 ; ctr++)
            {
                if((verificacoluna(i,ctr) == 1)&&(verificalinha(j,ctr) == 1)&&(verificagrade(i,j,ctr) == 1))
                {
                    sudoku[i][j]=ctr;
                     verificacao(i,j);
                }
        }
        sudoku[i][j]=0;
    }

}

int main()
{

    int i,j;

    printf("Entre com o Sudoku\n");

        for(i=0; i<9; i++)

            for(j=0; j < 9; j++)

                scanf("%d",&sudoku[i][j]);

        resolver(0,0);
}
