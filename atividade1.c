/*
Algoritmos e Programação II
Nome: Guilherme Quintal Gonçalves
RA: 620386
Exercício: Atividade 4 - Número: 1
Junho/2016
*/

#include <stdio.h>
#include <math.h>

void Circulo(float raio, float *area, float *circunferencia);
void Esfera(float raio, float *volume, float *areaSuperficie);
void Retangulo(float largura, float comprimento, float *area, float *perimetro);
void Cubo(float aresta, float *volume, float *areaSuperficie, float *diagonal);
void Cone(float raio, float altura, float *volume, float *areaSuperficie);

int main()
{

int opcao;
int i;
float raio, circunferencia, area, volume, areaSuperficie, largura, comprimento, perimetro, aresta, diagonal, altura;

	printf("0. Sair\n");
	printf("1. Círculo\n");
	printf("2. Esfera\n");
	printf("3. Retângulo\n");
	printf("4. Cubo\n");
	printf("5. Cone\n");

	scanf("%d", &opcao);

	while (opcao <= 5){

		switch(opcao)
		{

			case 0:
				return 0;
			break;

			case 1:
				Circulo(raio, &area, &circunferencia);
			break;

			case 2:
				Esfera(raio, &volume, &areaSuperficie);
			break;

			case 3:
				Retangulo(largura, comprimento, &area, &perimetro);
			break;

			case 4:
				Cubo(aresta, &volume, &areaSuperficie, &diagonal);
			break;

			case 5:
				Cone(raio, altura, &volume, &areaSuperficie);
			break;

			default:

				printf("Entre com uma opção válida");
		}

    printf("0. Sair\n");
	printf("1. Círculo\n");
	printf("2. Esfera\n");
	printf("3. Retângulo\n");
	printf("4. Cubo\n");
	printf("5. Cone\n");

	scanf("%d", &opcao);

	}

	return 0;
}

void Circulo(float raio, float *area, float *circunferencia){

	scanf("%f", &raio);

	*area = 3.1415 * raio * raio;
	*circunferencia = 2 * 3.1415 * raio;

	printf("%.2f %.2f\n", *area, *circunferencia);
	printf("\n");


}

void Esfera(float raio, float *volume, float *areaSuperficie){

	scanf("%f", &raio);

	*volume = (4 * 3.1415 * raio * raio * raio) / 3;
	*areaSuperficie = 4 * 3.1415 * raio * raio;

	printf("%.2f %.2f\n", *volume, *areaSuperficie);
	printf("\n");

}

void Retangulo(float largura, float comprimento, float *area, float *perimetro){

	scanf("%f %f", &comprimento, &largura);

	*area = comprimento * largura;
	*perimetro = (2 * largura) + (2 * comprimento);

	printf("%.2f %.2f\n", *area, *perimetro);
	printf("\n");
}

void Cubo(float aresta, float *volume, float *areaSuperficie, float *diagonal){

	scanf("%f", &aresta);

	*volume = aresta * aresta * aresta;
	*areaSuperficie = 6 * aresta * aresta;
	*diagonal = aresta * sqrt (3);

	printf("%.2f %.2f %.2f\n", *volume, *areaSuperficie, *diagonal);
	printf("\n");

}

void Cone(float raio, float altura, float *volume, float *areaSuperficie){

	scanf("%f %f", &raio, &altura);

	*volume = (3.1415 * raio * raio * altura) / 3;
	*areaSuperficie = (3.1415 * raio * (raio + sqrt(altura * altura + raio * raio)));

	printf("%.2f %.2f\n", *volume, *areaSuperficie);
	printf("\n");
}