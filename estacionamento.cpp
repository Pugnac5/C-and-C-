#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct esta
{
	char placa[7];
	int hor;
	int dat;
	int  min;
}; 

void menu (struct esta cobra[]);
void prenche(struct esta cobra[]);
void precosai (struct esta cobra[]);
void leitura(struct esta cobra[]);

main()
{
	setlocale(LC_ALL,"portuguese");
	int i;
	struct esta cobra[5];
	menu(cobra);	
	scanf("%d", &i);

}




void menu (struct esta cobra[])
{
	int i;
	do
	{
		printf("Digite uma opção de acordo com o menu: \n");
		printf("1 - Cadastra o veiculo\n");
		printf("2 - Informa a saida do veiculo\n");
		printf("3 - Digite o Numero da vaga que queira consultar\n");
		printf("4 - Sair\n");
		scanf("%d", &i);
  		switch (i)
  		{
    		case 1:
    			prenche(cobra);
     		break;
 				
			case 2:
    			precosai(cobra);
     		break;
 			case 3:
    			leitura(cobra);
     		break;
 			
			 case 4:
    			printf("\n\nO programa se encerrará!");
     		break;
 				
     		default:
       			printf ("Valor invalido!\n");
  		}
  		
  	}while (i!=4);
}

void prenche(struct esta cobra[])
{	
	char caracter;
	int i;
	FILE *arq;
	printf("Digite a vaga no qual irá cadastra o veiculo!");
		scanf("%d", &i);
		arq=fopen("estacionamento.txt","w+");
	
		printf("Digite a Placa:");
		scanf("%s", cobra[i].placa);
		printf("\n Digite a hora:");
		scanf("%d:%d", &cobra[i].hor, &cobra[i].min);
		printf("\n Digite a Data:");
		scanf("%d", &cobra[i].dat);
		fwrite(&cobra, sizeof(struct esta),1, arq);
	
	
	fclose(arq);		
}




void precosai (struct esta cobra[])
{	
	int preco, saida, minut;
	int i,t;
	printf("Digite a vaga no qual irá dar baixa do veiculo!");
	scanf("%d", &i);
	printf("Digite a hora de saida: ");
	scanf("%d:%d", &saida,&minut);
	
		t=(saida*60)-(cobra[i].hor*60);	 
		
		if(cobra[i].min>30||t>30)
		{	
			
			preco=6;
			printf("\nO preço a ser pago é:%d \n\n", preco);
		}else
		{
			printf("você ainda estar no harario gratuito!");
		}
		if(t>240)
			{
				
				preco=preco+((t-240)/60);
				printf("\nO preço a ser pago é:%d \n\n", preco);
			}
		
}

void leitura(struct esta cobra[])
{
	int i;
		printf("Digite a vaga no qual gotará de ler!");
		scanf("%d", &i);
		FILE *arq;
		arq=fopen("estacionamento.txt","r");
		fread(&cobra, sizeof(struct esta),1, arq);
		printf("A vaga n° %d:  \n", i);
		printf("Placa: %s\n", cobra[i].placa);
		printf("Hora: %d%d\n\n", cobra[i].hor,&cobra[i].min);
		printf("Data: %f\n\n", cobra[i].dat);
		_sleep(1000);

	fclose(arq);	
}

