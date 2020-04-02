#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<locale.h>
int val=1; 
int u=9 /*ultima posição do vetor*/,a,level=3,n,idlevel=1;
int vet[10];//vetor de tamanho 10
int escolha;
void jogo();
void gotoxy(int x,int y){ //Comando para substituir a biblioteca conio2.h
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void aleatorio(){
    if(idlevel==1)
	{
		printf("Você Está No Nível %d\n",idlevel++);
		
	}
	else
	printf("Grave esta sequência:\n");
    val = 1;a=0;
    while (val == 1){
        vet[a] = rand() % level + 1; 
        if(a==0)printf("  %d ", vet[a]);
        else printf("- %d ", vet[a]);
        //posição do vetor é = ao tamanho do vetor    
        if (a == u){
            val = 0;
        }else{
            a++;
       
	    }
    }
    printf("\n");
    system("pause");
    system("cls");
    jogo();
}
void jogo(){
    val = 1;
    a = 0;
    while(val == 1){
        printf("Digite O %dº Número ",a+1);
        scanf("%d",&n);
        if (vet[a] != n){
            printf("\n");
            printf("Você perdeu no nível %d a sequência correta e:\n",idlevel);
            //printa a sequencia correta
            for(int i=0; i<=u; i++){
                if(i==0)printf("  %d ", vet[i]);
                else printf("- %d ", vet[i]);
            }
            val = 0;
            printf("\n\n         ");
            for(val=10;val>-1;val--){
                gotoxy(15,5);
                printf(" %d ",val);
                Sleep(200);
            }
            gotoxy(15,5);
            printf("   \n\n");
        }
        else
            if(a == u){
                printf("Parabéns! Você passou para o nível %d\n\n",idlevel);
                level= level + 3;
                a = 0;
                n = 0;
                aleatorio();
                idlevel++;
                level;
                Sleep(2000);
                val=0;
            }
            else{
                a++;
            }
    }
}
int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));/* para gerar números randomicos diferentes */
    do{
        system("cls");
        printf("\n\n      =================   BEM-VINDO AO GENIUS   ================     \n\n");
        printf("\n0 - para sair Do Jogo\n1 - Para um jogador\n2 - Para dois jogadores "   );
        printf("\n         ");
        fflush(stdin);
        escolha=getch()-48;/* não precisar pessionar enter*/
        switch (escolha){
            case 1:
                printf("\n ---- UM JOGADOR ----\n");
                aleatorio();
                break;
            case 2:
                printf("\n ---- DOIS JOGADORES ----\n\n");
                printf("voce é o jogador 1\n\n");
                aleatorio();
                printf("Agora é A Vez Do Jogador 2\n\n");
                aleatorio();
                break;
            case 0:
                printf("\n       TCHAU");
                for(val=0;val<10;val++){
                    printf(" .");
                    Sleep(200);
                }
                printf("!\n\n");
                break;
        }
    }while(escolha != 0);
}
