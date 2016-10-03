/*
Algoritmos e Programação II
Nome: Guilherme Quintal Gonçalves
RA: 620386
Exercício: Atividade 4 - Número: 2
Junho/2016
*/

#include <stdio.h>
#include <stdlib.h>

void imprimeConteudo (int *elementos, int tam);
void imprimeMenor (int *elementos, int tam, int *menor);
void imprimeMaior(int *elementos, int tam, int *maior);
int imprimeSoma (int *elementos, int tam, int *soma);
int imprimeProduto (int *elementos, int tam, int *produto);

int main(){

    int opcao;
    int quantidade_elementos, i, *elementos;
    int menor, maior, soma = 0, produto=1;

      scanf("%d", &quantidade_elementos);

      elementos = (int*)malloc(quantidade_elementos*sizeof(int));
      

        for (i = 0; i < quantidade_elementos; i++){

        scanf("%d", &elementos[i]);

        }

    
        printf("0. Sair\n");
        printf("1. Imprimir Conteúdo\n");
        printf("2. Imprimir menor elemento\n");
        printf("3. Imprimir maior elemento\n");
        printf("4. Imprimir soma dos elementos\n");
        printf("5. Imprimir produto dos elementos\n");

        scanf("%d", &opcao);

        while (opcao <= 5){

            switch(opcao)
            {

                case 0:
                    return 0;
                break;

                case 1:
                    imprimeConteudo (elementos, quantidade_elementos);
                    printf("\n");
                break;

                case 2:
                    menor = elementos[0];
                    imprimeMenor (elementos, quantidade_elementos, &menor);
                    printf("%d\n", menor);
                break;

                case 3:
                    maior = elementos[0];
                    imprimeMaior(elementos, quantidade_elementos, &maior);
                    printf("%d\n", maior);
                break;

                case 4:
                    imprimeSoma (elementos, quantidade_elementos, &soma);
                    printf("%d\n", soma);
                    
                break;

                case 5:
                    imprimeProduto (elementos, quantidade_elementos, &produto);
                    printf("%d\n", produto);
                break;

                default:

                    printf("Entre com uma opção válida");
            }

        printf("0. Sair\n");
        printf("1. Imprimir Conteúdo\n");
        printf("2. Imprimir menor elemento\n");
        printf("3. Imprimir maior elemento\n");
        printf("4. Imprimir soma dos elementos\n");
        printf("5. Imprimir produto dos elementos\n");

        scanf("%d", &opcao);

        }

}

void imprimeConteudo (int *elementos, int tam) //FUNÇÃO PARA IMPRIMIR OS ELEMENTOS
{
    if (tam > 0)
    {
        printf("%d ", *elementos);
        imprimeConteudo(elementos + 1, tam-1);
    }
    
}

void imprimeMenor (int *elementos, int tam, int *menor) //FUNÇÃO PARA IMPRIMIR OS ELEMENTOS
{
    if (tam > 0)
    {

        if(*elementos < *menor){

            *menor = *elementos;
        }

        imprimeMenor(elementos +1, tam -1 , menor);
    }

    
}

void imprimeMaior(int *elementos, int tam, int *maior){

    if (tam > 0)
    {

        if(*elementos > *maior){

            *maior = *elementos;
        }

        imprimeMaior(elementos +1, tam -1 , maior);
    }

}

int imprimeSoma (int *elementos, int tam, int *soma){


    if(tam > 0){

        *soma = *soma + elementos[tam -1];

        imprimeSoma(elementos, tam -1, soma);
    }
}

int imprimeProduto (int *elementos, int tam, int *produto){

    if (tam > 0){

        *produto = *produto * elementos[tam -1];

        imprimeProduto(elementos, tam -1, produto);
    }

}