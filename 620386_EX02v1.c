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

//#define SWAP(a, b) { a^=b; b^=a; a^=b; }


int main (){
	int i, j;
	FILE *fp;
	char op;
	Roteiro roteiro, *arquivo, aux;
	int verifica = 0, cont = 0, num_roteiros;
	char flag;
	
	Roteiro roteiroaux;

	do{
		verifica = 0;
		cont = 0;
		num_roteiros = 0;
		i = 0;
		j = 0;

		printf("Escolha um opção:\n");
		printf ("1. Cadastrar um roteiro.\n");
		printf ("2. Alterar um roteiro.\n");
		printf ("3. Remover um roteiro.\n");
		printf ("4. Buscar um roteiro pelo código.\n");
		printf ("5. Buscar roteiros pela cidade de origem.\n");
		printf ("6. Buscar roteiros pela cidade de destino.\n");
		printf ("7. Listar roteiros.\n");
		printf ("0. Sair.\n");

		fp = fopen("roteiro.dat", "a+");
		
		if (fp == NULL)
			perror("Erro ao abrir o arquivo.\n");
		else{
			while (fscanf (fp,"%c", &flag) != EOF){
				if (flag == '#'){
					num_roteiros++;
				}
			}
			
			arquivo = (Roteiro *) calloc (num_roteiros, sizeof(Roteiro));
			
			rewind (fp);
			
			while ((fscanf(fp," %d#%[^#]#%[^#]#%f",  &arquivo[cont].codigo, arquivo[cont].cidadeorigem, arquivo[cont].cidadedestino, &arquivo[cont].valor)) != EOF){
				cont++;
			}
			
			scanf(" %c", &op);
						
			switch (op){
				case '1':
					printf("Escreva o código do roteiro: ");
					scanf("%d", &roteiro.codigo);
					printf("Escreva a cidade de origem: ");
					scanf(" %[^\n]", roteiro.cidadeorigem); 
					printf("Escreva a cidade de destino: ");
					scanf(" %[^\n]", roteiro.cidadedestino); 
					printf("Escreva o valor da viagem: ");
					scanf("%f", &roteiro.valor); 
					
					for (i = 0; i < cont; i++){
						if (arquivo[i].codigo == roteiro.codigo){
							printf("\nDisciplina já cadastrada.\n\n");
							verifica = 1;
							break;
						}
					}
					if (verifica != 1){
						fseek (fp, 0, SEEK_END);
						fprintf(fp, "%d#%s#%s#%.2f\n", roteiro.codigo, roteiro.cidadeorigem, roteiro.cidadedestino, roteiro.valor);
						printf("\nRoteiro cadastrado.\n\n");
						cont = 0;
						verifica = 0;
					}
					fclose (fp);
					break;
				case '2':
					printf("Escreva o código do roteiro que deseja alterar: ");
					scanf("%d", &roteiro.codigo);
				
					for (i = 0; i < cont; i++){
						if (arquivo[i].codigo == roteiro.codigo){
							printf("Escreva a nova cidade de origem: ");
							scanf(" %[^\n]", arquivo[i].cidadeorigem); 
							printf("Escreva a nova cidade de destino: ");
							scanf(" %[^\n]", arquivo[i].cidadedestino); 
							printf("Escreva o novo valor da viagem: ");
							scanf("%f", &arquivo[i].valor); 
							verifica = 1;
							j = i;
							break;
						}
					}
					if (verifica == 1){
						fclose (fp);
						fp = fopen ("roteiro.dat", "w+");
						for (i = 0; i < cont; i++){
							fprintf(fp, "%d#%s#%s#%.2f\n", arquivo[i].codigo, arquivo[i].cidadeorigem, arquivo[i].cidadedestino, arquivo[i].valor);
						}
						printf("\nRoteiro alterado.\n\n");
						fclose (fp);
					}
					else{
						printf("\nRoteiro não cadastrado.\n\n");
					}
					break;
				case '3':
					printf("Escreva o código do roteiro que deseja remover: ");
					scanf("%d", &roteiro.codigo);
					
					for (i = 0; i < cont; i++){
						if (arquivo[i].codigo == roteiro.codigo){
							verifica = 1;
							j = i;
							break;
						}
					}
					
					if (verifica == 1){
						for (i = j; i < cont - 1; i++){
							arquivo[i].codigo = arquivo[i + 1].codigo;
							strcpy (arquivo[i].cidadeorigem,  arquivo[i + 1].cidadeorigem);
							strcpy (arquivo[i].cidadedestino, arquivo[i + 1].cidadedestino);
							arquivo[i].valor = arquivo[i + 1].valor;
						}
						fclose (fp);
						fp = fopen ("roteiro.dat", "w+");
						for (i = 0; i < cont - 1; i++){
							fprintf(fp, "%d#%s#%s#%f\n", arquivo[i].codigo, arquivo[i].cidadeorigem, arquivo[i].cidadedestino, arquivo[i].valor);
						}
						printf("\nRoteiro removido.\n\n");
						fclose (fp);
					}
					else{
						printf("\nRoteiro não cadastrado.\n\n");
					}
					break;
				case '4':
					printf("Escreva o código do roteiro que deseja buscar: ");
					scanf("%d", &roteiro.codigo);
					for (i = 0; i < cont; i++){
						if (roteiro.codigo == arquivo[i].codigo){
							printf("\nCódigo da disciplina: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", arquivo[i].codigo, arquivo[i].cidadeorigem, arquivo[i].cidadedestino, arquivo[i].valor);
							verifica = 1;
						}
					}
					if (verifica != 1)
						printf("\nRoteiro não cadastrado.\n\n");
					fclose (fp);
					break;
				case '5':
					printf("Escreva a cidade de origem que deseja buscar: ");
					scanf("%s", roteiro.cidadeorigem);
					for (i = 0; i < cont; i++){
							if(strcmp (arquivo[i].cidadeorigem, roteiro.cidadeorigem) == 0){

							printf("\nCódigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", arquivo[i].codigo, arquivo[i].cidadeorigem, arquivo[i].cidadedestino, arquivo[i].valor);
							verifica = 1;

							}
					}

						if (verifica != 1)
						printf("\nRoteiro não cadastrado.\n\n");
					fclose (fp);
					break;

				case'6':
					printf("Escreva a cidade de destino que deseja buscar: ");
					scanf("%s", roteiro.cidadedestino);
					for (i = 0; i < cont; i++){
							if(strcmp (arquivo[i].cidadedestino, roteiro.cidadedestino) == 0){

							printf("\nCódigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", arquivo[i].codigo, arquivo[i].cidadeorigem, arquivo[i].cidadedestino, arquivo[i].valor);
							verifica = 1;

							}
					}

						if (verifica != 1)
						printf("\nRoteiro não cadastrado.\n\n");
					fclose (fp);
					break;
				case'7':

					printf("Listar roteiros:");

						for (i = 0; i < cont; i++)
						{
							for (j = i+1; j < cont; j++)
							{
								if (arquivo[i].codigo > arquivo[j].codigo)
								{

									roteiroaux = arquivo[i];
									arquivo[i] = arquivo[j];
									arquivo[j] = roteiroaux;

								}
							}
						}

					for (i = 0; i < cont; i++){
						aux = arquivo[i];
						for (j = i; (j > 0) && (strcmp(aux.cidadeorigem, arquivo[j-1].cidadeorigem) < 0); j--){
							arquivo[j] = arquivo[j - 1];
						}
						arquivo[j] = aux;
					}
					for (i = 0, j = 0; i < cont; i++){
						printf("\nCodigo do roteiro: %d\nCidade de origem: %s\nCidade de destino: %s\nValor da viagem: %.2f\n\n", arquivo[i].codigo, arquivo[i].cidadeorigem, arquivo[i].cidadedestino, arquivo[i].valor);
					}

					fclose (fp);
					break;
				case '0':
					return 0;
					break;
				default:
					printf("Opção inválida, escolha outra.\n\n");
			}
		}
		free (arquivo);
	
	} while (1);
return 0;
}
