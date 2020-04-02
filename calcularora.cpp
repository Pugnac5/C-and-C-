#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main()
{   setlocale(LC_ALL, "Portuguese");
	int n1,n2,n3,soma,sub,mut,div;
	printf("\n Digite o primeiro número:");
	scanf("%d", &n1);
	printf("\n Digite o segundo número:");
	scanf("%d", &n2);
	printf("\n Digite\n 1 para somar os numeros,\n 2 para subtrair,\n 3 para dividir e\n 4 para multiplicar:");
	scanf("%d", &n3);
	soma=n1+n2;
	sub=n1-n2;
	div=n1/n2;
	mut=n1*n2;
	switch (n3)
    {
	case 1: 
	    printf("A soma de:%d + %d =%d",n1,n2,soma);
		break;   
   case 2: 
        printf("A subtração de:%d - %d =%d",n1,n2,sub);
		break;   
   	case 3: 
	    printf("A divisão de:%d : %d =%d",n1,n2,div);
		break;   
    case 4: 
    	printf("A multiplicação de:%d . %d =%d",n1,n2,mut);
		break;   
    }
}
