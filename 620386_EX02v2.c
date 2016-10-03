//////////////////////////////////////
//Algoritimos e Programação         //
//Nome: Guilherme Quintal Gonçalves //
//RA: 620386                        //
//Exercicio: 2                      //
//Setembro/2016                 //
//////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct roteiro {
	int codigo;
	char cidadeorigem[100], cidadedestino[100];
	float valor;
}	Roteiro;

typedef struct no{
  Roteiro info;
  struct no *prox;
} No_lista;

typedef No_lista *Lista;

void inicLista(Lista *l);
int listaVazia(Lista *l);
void insereOrdenado(Lista *l, Roteiro e);
void altera(Lista *l, Roteiro e);
void removeCodigo(Lista *l, int e);
void removeInicio(Lista *l, FILE *fpWrite);
int exibeCodigo(Lista *l, int e);
int exibeCidade(Lista *l, char *cidade);
int exibeDestino(Lista *l, char *cidade);
void exibe(Lista *l); 
void libera(Lista *l);

int main (){
	FILE *fpRead;
	FILE *fpWrite;
	char op;
	int codigo;
	Lista l;	
	Roteiro aux;

	inicLista(&l);

	fpRead = fopen("roteiro.dat", "a+");

	if (fpRead == NULL)
	{
		printf("Erro ao abrir o arquivo.\n");
	}


	while ((fscanf(fpRead," %d#%[^#]#%[^#]#%f",  &aux.codigo, aux.cidadeorigem, aux.cidadedestino, &aux.valor)) != EOF)
	{
		insereOrdenado(&l, aux);
	}	
	fclose(fpRead);
	

	do{
		printf("Escolha um opção:\n");
		printf ("1. Cadastrar um roteiro.\n");
		printf ("2. Alterar um roteiro.\n");
		printf ("3. Remover um roteiro.\n");
		printf ("4. Buscar um roteiro pelo código.\n");
		printf ("5. Buscar roteiros pela cidade de origem.\n");
		printf ("6. Buscar roteiros pela cidade de destino.\n");
		printf ("7. Listar roteiros.\n");
		printf ("0. Sair.\n");
		
		scanf(" %c", &op);
					
		switch (op){
			case '1':
				printf("Escreva o código do roteiro: ");
				scanf("%d", &aux.codigo);
				printf("Escreva a cidade de origem: ");
				scanf(" %[^\n]", aux.cidadeorigem); 
				printf("Escreva a cidade de destino: ");
				scanf(" %[^\n]", aux.cidadedestino); 
				printf("Escreva o valor da viagem: ");
				scanf("%f", &aux.valor);

				//printf("Codigo: %d\nOrigem: %s\nDestino: %s\nValor: %.2f\n\n", aux.codigo, aux.cidadeorigem, aux.cidadedestino, aux.valor);

				insereOrdenado(&l, aux);
				printf("Roteiro cadastrado\n");
			break;

			case '2':
				printf("Escreva o código do roteiro que deseja alterar: ");
				scanf("%d", &aux.codigo);
				altera(&l, aux);

			break;

			case '3':
				printf("Escreva o código do roteiro que deseja remover: ");
				scanf("%d", &codigo);
				
				removeCodigo(&l, codigo);
				printf("Roteiro removido\n");
			break;

			case '4':
				printf("Escreva o código do roteiro que deseja buscar: ");
				scanf("%d", &codigo);
				
				if(!exibeCodigo(&l, codigo))
				{
					printf("Roteiro não cadastrado\n");
				}
			break;

			case '5':
				printf("Escreva a cidade de origem que deseja buscar: ");
				scanf("%s", aux.cidadeorigem);
				

				if (!exibeCidade(&l, aux.cidadeorigem))
				{
					printf("Roteiro não cadastrado\n");
				}
			break;

			case'6':
				printf("Escreva a cidade de destino que deseja buscar: ");
				scanf("%s", aux.cidadedestino);
				
				if(!exibeDestino(&l, aux.cidadedestino))
				{
					printf("Roteiro não cadastrado.\n");
				}
			break;

			case'7':
				printf("Listar roteiros:");
				exibe(&l);
			break;

			case '0':
				fpWrite = fopen("roteiro.dat", "w");
				while (!listaVazia(&l))
				{

					removeInicio(&l, fpWrite);
				}
					
				fclose(fpWrite);
				return 0;
			break;

			default:
				printf("Opção inválida, escolha outra.\n\n");
		}
		} while (1);
}

/* Inicializa uma lista */
void inicLista(Lista *l)
{
	*l = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *l)
{
	if ((*l) == NULL)
	{
		return 1;
	}

	return 0;
}

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *l, Roteiro e){
    No_lista *atual, *proximo, *novo;
    atual = *l;
    novo = (No_lista*)malloc(sizeof(No_lista));
    novo->info.codigo = e.codigo;
    strcpy(novo->info.cidadeorigem, e.cidadeorigem);
    strcpy(novo->info.cidadedestino, e.cidadedestino);
    novo->info.valor = e.valor;
    //printf("Entrou na função, insere ordenado!!!\n");
 	//printf("Codigo: %d\nOrigem: %s\nDestino: %s\nValor: %.2f\n\n", novo->info.codigo, novo->info.cidadeorigem, novo->info.cidadedestino, novo->info.valor);

    if (atual == NULL)
    {
        *l = novo;
        novo->prox = NULL;
        return;
    }
    else if (atual->prox == NULL)
    {
        if (atual->info.codigo > e.codigo)
        {
            novo->prox = atual;
            *l = novo;
            return;
        }
        else
        {
            atual->prox = novo;
            novo->prox = NULL;
            return;
        }
    }
    else if (atual->prox != NULL && e.codigo < atual->info.codigo)
    {
        *l = novo;
        novo->prox = atual;
        return;
    }
 
    proximo = atual->prox;
 
    while (atual->prox != NULL)
    {
        if (proximo->info.codigo > e.codigo && atual->info.codigo < e.codigo)
        {
            novo->prox = proximo;
            atual->prox = novo;
            return;
        }
 
        atual = atual->prox;
        proximo = proximo->prox;
    }

    if (proximo->info.codigo == e.codigo)
    {
    	printf("Roteiro ja cadastrado\n");
    	return;
    }
 
    novo->prox = NULL;
    atual->prox = novo;
}

void altera(Lista *l, Roteiro e)
{
	No_lista *atual, *proximo;
    atual = *l;
    Roteiro aux;
 
    if (atual == NULL)
    {
    	printf("Roteiro não cadastrado\n");
        return;
    }
    else if (atual->prox == NULL && atual->info.codigo == e.codigo)
    {
    	printf("Escreva a cidade de origem: ");
		scanf(" %[^\n]", aux.cidadeorigem); 
		printf("Escreva a cidade de destino: ");
		scanf(" %[^\n]", aux.cidadedestino); 
		printf("Escreva o valor da viagem: ");
		scanf("%f", &aux.valor); 

	    strcpy(atual->info.cidadeorigem, aux.cidadeorigem);
	    strcpy(atual->info.cidadedestino, aux.cidadedestino);
	    atual->info.valor = aux.valor;

        return;
    }
    else if (atual->prox != NULL && atual->info.codigo == e.codigo)
    {
    	printf("Escreva a cidade de origem: ");
		scanf(" %[^\n]", aux.cidadeorigem); 
		printf("Escreva a cidade de destino: ");
		scanf(" %[^\n]", aux.cidadedestino); 
		printf("Escreva o valor da viagem: ");
		scanf("%f", &aux.valor); 
        
	    strcpy(atual->info.cidadeorigem, aux.cidadeorigem);
	    strcpy(atual->info.cidadedestino, aux.cidadedestino);
	    atual->info.valor = aux.valor;

        return;
    }
     
    proximo = atual->prox;
 
    while (proximo != NULL)
    {
        if (proximo->info.codigo == e.codigo)
        {
        	printf("Escreva a cidade de origem: ");
			scanf(" %[^\n]", aux.cidadeorigem); 
			printf("Escreva a cidade de destino: ");
			scanf(" %[^\n]", aux.cidadedestino); 
			printf("Escreva o valor da viagem: ");
			scanf("%f", &aux.valor); 
            
		    strcpy(proximo->info.cidadeorigem, aux.cidadeorigem);
		    strcpy(proximo->info.cidadedestino, aux.cidadedestino);
		    proximo->info.valor = aux.valor;

            return;
        }

        proximo = proximo->prox;
    }
 
 	printf("Roteiro não cadastrado\n");
    return;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
void removeCodigo(Lista *l, int e){
    No_lista *atual, *proximo;
    atual = *l;
 
    if (atual == NULL)
    {
        return;
    }
    else if (atual->prox == NULL && atual->info.codigo == e)
    {
        free(atual);
        *l = NULL;
        return;
    }
    else if (atual->prox != NULL && atual->info.codigo == e)
    {
        proximo = atual->prox;
        free(atual);
        *l = proximo;
        return;
    }
     
    proximo = atual->prox;
 
    while (proximo != NULL)
    {
        if (proximo->info.codigo == e)
        {
            atual->prox = proximo->prox;
            free(proximo);
            proximo = atual->prox;
            return;
        }
 
        proximo = proximo->prox;
        atual = atual->prox;
    }
 
    return;
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
void removeInicio(Lista *l, FILE *fpWrite){
    No_lista *aux;
    aux = *l;
 
    if (aux == NULL)
    {
        return;
    }
     
    *l = aux->prox;
    fprintf(fpWrite, "%d#%s#%s#%.2f\n", aux->info.codigo, aux->info.cidadeorigem, aux->info.cidadedestino, aux->info.valor);
    free(aux);

    return;
}

int exibeCodigo(Lista *l, int e){
    Lista aux;
    aux = *l;
    while(aux != NULL){

    	if (aux->info.codigo == e){
        	printf("\nCodigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", aux->info.codigo, aux->info.cidadeorigem, aux->info.cidadedestino, aux->info.valor);
        	return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

int exibeCidade(Lista *l, char *cidade){
	Lista aux;
    aux = *l;

    while(aux != NULL){

    	if (strcmp(aux->info.cidadeorigem, cidade) == 0){
        	printf("\nCodigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", aux->info.codigo, aux->info.cidadeorigem, aux->info.cidadedestino, aux->info.valor);
        	return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

int exibeDestino(Lista *l, char *cidade){
	Lista aux;
    aux = *l;

    while(aux != NULL){

    	if (strcmp(aux->info.cidadedestino, cidade) == 0){
        	printf("\nCodigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", aux->info.codigo, aux->info.cidadeorigem, aux->info.cidadedestino, aux->info.valor);
        	return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

/* Exibe o conteudo da lista */
void exibe(Lista *l){
    Lista aux;
    aux = *l;

    while(aux != NULL){

        printf("\nCodigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", aux->info.codigo, aux->info.cidadeorigem, aux->info.cidadedestino, aux->info.valor);
        aux = aux->prox;
    }
} 

/* Remove todos os numeros da lista */
void libera(Lista *l){
    No_lista *aux;
    aux = *l;
 	
    while ((*l) != NULL)
    {
        (*l) = (*l)->prox;
        free(aux);
        aux = *l;
    }
 
    *l = NULL;
}