/*
Algoritmos e Programacao II
Nome: Guilherme Quintal Gonçalves
RA: 620386
Exercicio: Atividade 1 - Número 1
Julho/2016
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    long int cpf;
    char status[30], partido[100], nome[100];
} info;


void listartodos(int a, info *vereador);

int adicionarvereador(int a, info *vereador);

int excluirvereador(int a, info *vereador);

int alterarpartido(int a, info *vereador);

int alterarstatus(int a, info *vereador);

int listarporpartido(int a, info *vereador);


int main(){

    
    int opcao, a, i, contador;

    contador = 0;
    a = 0;

	info *vereador = (info *) malloc (MAX * (sizeof(info)));


    printf("0 - Fechar programa.\n");
    printf("1 - Adicionar vereador.\n");
    printf("2 - Excluir vereador.\n");
    printf("3 - Alterar partido de um vereador.\n");
    printf("4 - Alterar status de um vereador.\n");
    printf("5 - Listar todos os vereadores.\n");
    printf("6 - Listar os nomes dos vereadores de um determinado partido.\n");


    scanf("%d", &opcao);


    while(opcao <=6)
    {


        if(opcao == 1){

            if(a>MAX-1) vereador = (info *) realloc(vereador, MAX * (sizeof(info)));

            if(adicionarvereador(a, vereador)==1)

             a+=1;

        }

        if(opcao==2){

            if(excluirvereador(a, vereador)==1)

             a-=1;
        }

        if(opcao==3){

            if(alterarpartido(a, vereador)==1)

            	printf("Partido alterado\n");

        }

        if(opcao==4){

            if(alterarstatus(a, vereador)==1) 

            	printf("Status alterado\n");
        }

        if(opcao==5){

        	listartodos(a, vereador);
        }


        if(opcao==6){

            if(listarporpartido(a, vereador)==0) 

            	printf("Partido não cadastrado.\n");

        }

        if (opcao == 0){

        	return 0;
        }


        if(opcao !=0 ){
       

		    printf("0 - Fechar programa.\n");
		    printf("1 - Adicionar vereador.\n");
		    printf("2 - Excluir vereador.\n");
		    printf("3 - Alterar partido de um vereador.\n");
		    printf("4 - Alterar status de um vereador.\n");
		    printf("5 - Listar todos os vereadores.\n");
		    printf("6 - Listar os nomes dos vereadores de um determinado partido.\n");

            scanf("%d", &opcao);
        }

        contador += 1;

    }

    return 0;
}


void listartodos(int a, info *vereador)
{
    int x=0, i=0, j=0;

    info aux;

    for (i = 0; i < a; i++)
    {
        aux=vereador[i];

        for( j = i; (j > 0) && strcmp(aux.nome, vereador[j-1].nome) < 0; j--)
        {
            vereador[j] = vereador[j-1];
        }

        vereador[j] = aux;

    }

    for (x = 0; x < a; x++)
            {
                printf("CPF: %ld\n", vereador[x].cpf);
                printf("Nome: %s\n", vereador[x].nome);
                printf("Partido: %s\n", vereador[x].partido);
                printf("Status: %s\n", vereador[x].status);
            }
}

int adicionarvereador(int a, info *vereador)
{
            int i=0;

            printf("Informee o CPF, nome, partido e status\n");

            scanf("%ld", &vereador[a].cpf);
            scanf(" %[^\n]s", vereador[a].nome);
            scanf(" %[^\n]s", vereador[a].partido);
            scanf(" %[^\n]s", vereador[a].status);


            for (i = 0; i < a; i++)
            {
                if(vereador[i].cpf==vereador[a].cpf)
                {
                    printf("CPF não cadastrado\n");

                    return 0;
                }
            }

            return 1;
}

int excluirvereador(int a, info *vereador)
{
    int i=0, j=0, CPF;

    printf("Informe o CPF do vereador que deseja excluir\n");

        scanf("%d", &CPF);

        for (i = 0; i < a; i++)
            {
                if(vereador[i].cpf==CPF)
                {
                    for (j = i;  j< a; j++)
                    {
                        vereador[j].cpf=vereador[j+1].cpf;
                        strcpy(vereador[j].nome, vereador[j+1].nome);
                        strcpy(vereador[j].partido, vereador[j+1].partido);
                        strcpy(vereador[j].status, vereador[j+1].status);
                    }
                    printf("Vereador exlcuido\n");

                    return 1;
                }
            }

            printf("Vereador não cadastrado\n");

            return 0;
}



int alterarpartido(int a, info *vereador)
{

    int i=0, CPF;
    char PARTIDO[100];

    printf("Informe o CPF do vereador\n");

    scanf("%d", &CPF);

    printf("Digite o novo partido\n");

    scanf(" %[^\n]s", PARTIDO);

            for (i = 0; i < a; i++)
            {
                if(vereador[i].cpf==CPF)
                {
                    strcpy(vereador[i].partido, PARTIDO);
                    return 1;
                }
            }

            printf("CPF não cadastrado\n");

            return 0;
}




int alterarstatus(int a, info *vereador)
{

    int i=0, CPF;
    char STATUS[100];

    printf("Digite o CPF do vereador\n");

    scanf("%d", &CPF);

    printf("Digite o novo status\n");

    scanf(" %[^\n]s", STATUS);

            for (i = 0; i < a; i++)
            {
                if(vereador[i].cpf==CPF)
                {
                    strcpy(vereador[i].status, STATUS);
                    return 1;
                }
            }
            printf("CPF não cadastrado\n");

            return 0;
}




int listarporpartido(int a, info *vereador)
{

    int i=0, aux=0;
    char PARTIDO[100];


    printf("Digite o nome do partido\n");

    scanf(" %[^\n]s", PARTIDO);


            for (i = 0; i < a; i++)
            {
                if(strcmp(vereador[i].partido, PARTIDO)==0)
                {
                    printf("Nome: %s\n", vereador[i].nome);

                    aux=1;
                }
            }

            return aux;
}