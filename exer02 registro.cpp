#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<locale.h>
#include<windows.h>
#include<string.h>

struct tcarro{
	char marca[15];
	int ano;
	char cor[10];
	float preco;
};

void preenche (struct tcarro vet[]);
void menu (struct tcarro vet[]);
void leitura (struct tcarro vet[]);
void comparapreco (struct tcarro vet[]);
void comparamarca (struct tcarro vet[]);
void comparamult (struct tcarro vet[]);
void leituraunica (struct tcarro c);

main()
{	
	setlocale(LC_ALL,"portuguese");
	struct tcarro vet[5];
	preenche(vet);
	menu (vet);
}

void preenche (struct tcarro vet[])
{
	int i;
	for (i=0;i<5;i++)
	{
		printf("marca: ");
		scanf("%s", vet[i].marca);
		printf("ano: ");
		scanf("%d", &vet[i].ano);
		printf("cor: ");
		scanf("%s", vet[i].cor);
		printf("preço: ");
		scanf("%f", &vet[i].preco);
	}
}


void menu (struct tcarro vet[])
{
	int i;
	do
	{
		printf("Digite uma opção de acordo com o menu: \n");
		printf("1 - Lista todos os carros\n");
		printf("2 - Compara um preço digitado e retorna os carros com preço menor\n");
		printf("3 - Compara uma marca digitada e retorna os carros desta marca\n");
		printf("4 - Compara marca, cor e ano digitados e retorna o preço do carro que atenda aos critérios\n");
		printf("5 - Sair\n");
		scanf("%d", &i);
  		switch (i)
  		{
    		case 1:
    			leitura(vet);
     		break;
 			
			case 2:
    			comparapreco(vet);
     		break;
 
     		case 3:
    			comparamarca(vet);
     		break;
 
     		case 4:
    			comparamult(vet);
     		break;
     		
     		case 5:
     			printf("\n\nO programa se encerrará!");
     		break;
 
     		default:
       			printf ("Valor invalido!\n");
  		}
  	}while (i!=5);
}

void leitura (struct tcarro vet[])
{
	int i;
	for (i=0;i<5;i++)
	{
		printf("Carro n° %d:  \n", i+1);
		printf("Marca: %s\n", vet[i].marca);
		printf("Ano: %d\n", vet[i].ano);
		printf("Cor: %s\n", vet[i].cor);
		printf("Preço: %f\n\n", vet[i].preco);
		
	}
}

void leituraunica (struct tcarro c)
{
	printf("Marca: %s\n", c.marca);
	printf("Ano: %d\n", c.ano);
	printf("Cor: %s\n", c.cor);
	printf("Preço: %f\n\n", c.preco);
}

void comparapreco (struct tcarro vet[])
{
	float preco;
	int i;
	printf("Digite um preço: ");
	scanf("%f", &preco);
	printf("\nOs carros que tem um preço menor ou igual a %f.2 são: \n\n", preco);
	for (i=0; i<5; i++)
	{
		if (vet[i].preco<=preco)
		{
			leituraunica(vet [i]);
		}
	}
		system("pause");
	system("cls");
}

void comparamarca (struct tcarro vet[])
{
	int i;
	char marca[15];
	printf("Digite uma marca: ");
	scanf("%s", marca);
	printf("\nOs carros da mesma marca digitada são: \n\n");
	for (i=0; i<5; i++)
	{
		if (strcmp(vet[i].marca, marca)==0)     /// strcmp compara strings, resulta 0 se forem iguais
		{
			leituraunica(vet [i]);
		}
	}
		system("pause");
	system("cls");
}


void comparamult (struct tcarro vet[])
{
	char marca[15], cor[10];
	int i, ano;
	printf("Digite uma marca: ");
	scanf("%s", marca);
	printf("Digite uma cor: ");
	scanf("%s", cor);
	printf("Digite um ano: ");
	scanf("%d", &ano);
	printf("\nOs carros que atendem aos três requesitos tem os preços: \n\n");
	for (i=0; i<5; i++)
	{
		if (strcmp(vet[i].marca, marca)==0)
		{
			if(vet[i].ano==ano)
			{
				if(strcmp(vet[i].cor, cor)==0)
				{
					printf("%f", vet[i].preco);	
				}
			}
		}
	}
		system("pause");
	system("cls");
}

