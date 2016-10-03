/*
Algoritmos e Programação II
Nome: Guilherme Quintal Gonçalves
RA: 620386
Exercício: Atividade 3 - Número: 1
Junho/2016
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct materias{

	int codigo;
	char nome[100];
	char status[10];
	int creditos;
	int notas;
	int frequencia;

} Materias;

void Cadastrar (Materias *quantidade_total, char *arquivo_ler);
int BuscaMateria(Materias *quantidade_total);
void Alterar (Materias *quantidade_total, char *arquivo_ler);
void Remover (Materias *quantidade_total, char *arquivo_ler);
int Buscar (Materias *quantidade_total, char *arquivo_ler);
void Exibir_historico_sujo (Materias *quantidade_total, char *arquivo_ler);
void Exibir_historico_limpo (Materias *quantidade_total, char *arquivo_ler);

int main()
{

int opcao;
int i;

	Materias *quantidade_total;

	quantidade_total = (Materias *) malloc (5 * sizeof(Materias));

	printf("1. Cadastrar\n");
	printf("2. Alterar\n");
	printf("3. Remover\n");
	printf("4. Buscar\n");
	printf("5. Exibir histórico sujo\n");
	printf("6. Exibir historico limpo\n");
	printf("7. Sair\n");

	scanf("%d", &opcao);

	while (opcao <= 7){

		switch(opcao)
		{

			case 1:
				Cadastrar(quantidade_total, "historico.dat");
			break;

			case 2:
				Alterar(quantidade_total, "historico.dat");
			break;

			case 3:
				Remover(quantidade_total, "historico.dat");
			break;

			case 4:
				Buscar(quantidade_total, "historico.dat");
			break;

			case 5:
				Exibir_historico_sujo(quantidade_total, "historico.dat");
			break;

			case 6:
				Exibir_historico_limpo(quantidade_total, "historico.dat");
			break;

			case 7:
				return 0;
			break;

			default:

				printf("Entre com uma opção válida");
		}

    printf("1. Cadastrar\n");
	printf("2. Alterar\n");
	printf("3. Remover\n");
	printf("4. Buscar\n");
	printf("5. Exibir histórico sujo\n");
	printf("6. Exibir historico limpo\n");
	printf("7. Sair\n");

	scanf("%d", &opcao);

	}

	free(quantidade_total);
	return 0;
}

void Cadastrar(Materias *quantidade_total, char *arquivo_ler){

	int i;

	FILE *arquivo;
	arquivo = fopen(arquivo_ler, "a");

		scanf("%s", quantidade_total[i].nome);
		fprintf(arquivo, "%s@",quantidade_total[i].nome);

		scanf("%d", &quantidade_total[i].codigo);
		fprintf(arquivo, "%d@",quantidade_total[i].codigo);

		scanf("%d", &quantidade_total[i].creditos);
		fprintf(arquivo, "%d@",quantidade_total[i].creditos);

		scanf("%s", quantidade_total[i].status);
		fprintf(arquivo, "%s@",quantidade_total[i].status);

		scanf("%d", &quantidade_total[i].notas);
		fprintf(arquivo, "%d@",quantidade_total[i].notas);

		scanf("%d", &quantidade_total[i].frequencia);
		fprintf(arquivo, "%d\n",quantidade_total[i].frequencia);

		fclose(arquivo);
}

int BuscaMateria(Materias *quantidade_total){ //teste

	int i, retorno, codigo;

	scanf("%d", &codigo);

	for(i = 1; i < 5; i++){

		if(quantidade_total[i].codigo == codigo){

			retorno = i;

			return retorno;

			break;

		} 

		else {
			retorno = 0;
		}
	}
	return retorno;

}


void Alterar (Materias *quantidade_total, char *arquivo_ler){


	FILE *arquivo;
	arquivo = fopen(arquivo_ler, "a+");

	int i;
	int codigo;

	i = BuscaMateria(quantidade_total);

	if(i != 0){	

		printf("Entre com os dados que deseja alterar\n");

		__fpurge(stdin);
		scanf("%[^\n]s", quantidade_total[i].nome);
		scanf("%d", &quantidade_total[i].creditos);
		__fpurge(stdin);
		scanf("%[^\n]s", quantidade_total[i].status);
		scanf("%d %d", &quantidade_total[i].notas, &quantidade_total[i].frequencia);
	}

	else {

		printf("Codigo Inválido\n");
	}
}


void Remover (Materias *quantidade_total, char *arquivo_ler){


	FILE *arquivo;
	arquivo = fopen(arquivo_ler, "a+");

	int j, i, codigo;

	scanf("%d", &codigo);

	i = BuscaMateria(quantidade_total);

	for(j = i; j < 5; j++){
		quantidade_total[j] = quantidade_total[j + 1];
	}

}

int Buscar (Materias *quantidade_total, char *arquivo_ler){ //Nao funciona de jeito nenhum D:

	FILE *arquivo;
	arquivo = fopen(arquivo_ler, "r");


	int buscacodigo; 
	int i;
	int naoencontrada;
	char linha[100], *pos;

	naoencontrada = 0;

	scanf("%d", &buscacodigo);


	while (!feof(arquivo)){

       	fgets(linha, 100-1, arquivo);

		pos = strchr(linha, '@');
		printf("pos = %x\n", pos);
		printf("linha = %x\n", linha);
		printf("pos-linha = %d\n", pos-linha);
		printf("String = %s\n", quantidade_total[i].nome);

		strncpy(quantidade_total[i].nome, linha, pos-linha);
		printf("copiou a 1 string\n");

		sscanf(pos+1, "%d", &quantidade_total[i].codigo);

		pos = strchr(++pos, '@');

		sscanf(pos+1, "%d", &quantidade_total[i].creditos);

		pos = strchr(++pos, '@');

		sscanf(pos+1, "%s", quantidade_total[i].status);

		pos = strchr(++pos, '@');

		sscanf(pos+1, "%d", &quantidade_total[i].notas);

		pos = strchr(++pos, '@');

		sscanf(pos+1, "%d", &quantidade_total[i].frequencia);


		if (quantidade_total[i].codigo == buscacodigo){

			printf("%s\n", quantidade_total[i].nome);
			printf("%d\n", quantidade_total[i].codigo);
			printf("%d\n", quantidade_total[i].creditos);
			printf("%s\n", quantidade_total[i].status);
			printf("%d\n", quantidade_total[i].notas);
			printf("%d\n", quantidade_total[i].frequencia);

			naoencontrada++;

		}


			naoencontrada++;

	}

	if(naoencontrada == 0){

		printf("Código inválido.");
		return;
	}

		fclose(arquivo);
}



void Exibir_historico_sujo (Materias *quantidade_total, char *arquivo_ler){

	FILE *arquivo;
	arquivo = fopen(arquivo_ler, "r");

	int i = 0, j;
	int totaldecreditos;
	char linha[100], *pos;

	totaldecreditos = 0;

	while (!feof(arquivo)){

       fgets(linha, 100-1, arquivo);

	   pos = strchr(linha, '@');

	   strncpy(quantidade_total[i].nome, linha, pos-linha);

	   sscanf(pos+1, "%d", &quantidade_total[i].codigo);

	   pos = strchr(++pos, '@');

	   sscanf(pos+1, "%d", &quantidade_total[i].creditos);

	   pos = strchr(++pos, '@');

	   sscanf(pos+1, "%[^@]", quantidade_total[i].status);

	   pos = strchr(++pos, '@');

	   sscanf(pos+1, "%d", &quantidade_total[i].notas);

	   pos = strchr(++pos, '@');

	   sscanf(pos+1, "%d", &quantidade_total[i].frequencia);


		printf("%s\n ", quantidade_total[i].nome);
		printf("%d\n ", quantidade_total[i].codigo);
		printf("%d\n ", quantidade_total[i].creditos);
		printf("%s\n ", quantidade_total[i].status);
		printf("%d\n ", quantidade_total[i].notas);
		printf("%d\n ", quantidade_total[i].frequencia);
		printf("\n");


		totaldecreditos = totaldecreditos + quantidade_total[i].creditos;

		i++;
	}
	printf("%d\n", totaldecreditos);
	printf("\n");
	fclose(arquivo);


}

void Exibir_historico_limpo (Materias *quantidade_total, char *arquivo_ler){

	FILE *arquivo;
	arquivo = fopen(arquivo_ler, "r");

	int buscacodigo;
	int i;
	char status[20] = "APROVADO";
	int totaldecreditos;


	totaldecreditos = 0;



	for(i = 0; i <= 5; i++){

		fscanf(arquivo, "%s@%d@%d@%[^@]%d@%d", quantidade_total[i].nome, &quantidade_total[i].codigo, &quantidade_total[i].creditos, quantidade_total[i].status, &quantidade_total[i].notas, &quantidade_total[i].frequencia);

		if (strcmp(quantidade_total[i].status, status) == 0){

			printf("%s", quantidade_total[i].nome);
			printf("%d", quantidade_total[i].codigo);
			printf("%d", quantidade_total[i].creditos);
			printf("%s", quantidade_total[i].status);
			printf("%d", quantidade_total[i].notas);
			printf("%d", quantidade_total[i].frequencia);

			totaldecreditos = totaldecreditos + quantidade_total[i].creditos;

		}

	}

	printf("%d\n", totaldecreditos);
	fclose(arquivo);

}

