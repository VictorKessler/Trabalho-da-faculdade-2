#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define tam 100

struct Turma{
	char nome[tam];
	int matricula;
	float nota1;
	float nota2;
};

float MediaNotas(float N1, float N2){
	float media;

	media = (N1+N2)/2;
	
	return media;
}

int main(void){
setlocale(LC_ALL, "Portuguese");

	int tamturma, i;
	struct Turma *vet;
	
	printf("Qual será o tamanho da turma: ");
	scanf("%d", &tamturma);
	
	vet=(struct Turma *)malloc(tamturma * sizeof(struct Turma));
	if(vet==NULL){
		printf("Não foi possível alocar espaço de memória!");
		exit(1);
	}
	
	printf("\n * Digitação dos dados das Pessoas *\n");
	
	for(i=0;i<tamturma;i++){
		printf("Digite o nome: ");
		scanf ("%s", &vet[i].nome);
		fflush (stdin);
		printf ("\nDigite a matrícula: ");
		scanf ("%d", &vet[i].matricula);
		fflush (stdin);
		printf("\nDigite a nota 1: ");
		scanf("%f", &vet[i].nota1);
		fflush (stdin);
		printf("\nDigite a nota 2: ");
		scanf("%f", &vet[i].nota2);
		fflush (stdin);
		printf ("\n\n");
	}

	for (i=0;i<tamturma;i++){
		printf ("\n\nA matrícula do aluno %d é %d", i+1, vet[i].matricula);
		printf ("\nO nome do aluno %d é %s", i+1, vet[i].nome);
		printf("\nA média do aluno %d é: %.2f\n\n", i+1, MediaNotas(vet[i].nota1, vet[i].nota2));
	}
	
	free(vet);
}
