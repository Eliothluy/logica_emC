#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
int repet = 1;
int again;
while(repet==1){
    printf("\n\n");
	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|_|_/_\\                            \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|__/                              \n");
	printf("\n\n");

#define NIVEL1 20
#define NIVEL2 15
#define NIVEL3 6
    int segundos = time(0);
    srand(segundos);
    int numerogrande= rand();
    int chute;  //declarando o chute como número inteiro
    int acertou;
    int nivel;
    int totaldetentativas;
    int tentativas =1; //declarando o número de tentativas
    double pontos=1000; // O jogador começa com 1000 pontos
    int inicio;
    int final;
    int intervalo;
    printf("Qual será o intervalo do numero randomico?\n");
    printf("Escolha o inicio do intervalo: ");
    scanf("%d", &inicio);
    printf("Escolha o final do intervalo: ");
    scanf("%d", &final);
    if(inicio>=final){
        while(inicio>=final){
        printf("O inicio tem que ser menor que o numero final\n");
        printf("Escolha o inicio do intervalo: ");
        scanf("%d", &inicio);
        printf("Escolha o final do intervalo: ");
        scanf("%d", &final);
        }
    }else{
        intervalo = inicio-final;

    }
    int numerosecreto= numerogrande%(intervalo +1); //declarando o número secreto
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            totaldetentativas = NIVEL1;
            break;
        case 2:
            totaldetentativas = NIVEL2;
            break;
        default:
            totaldetentativas = NIVEL3;
            break;
    }

    for(int i=1; i<= totaldetentativas; i++){
        printf("Qual é o seu %do. chute? ", tentativas);
        scanf("%d", &chute);
        if(chute<0){
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }
        printf("Seu %do. chute foi %d\n", tentativas, chute);
        acertou=chute == numerosecreto;
        int maior = chute>numerosecreto;
        if(acertou){
        break;
        }else if(maior){
            printf("Seu chute foi maior do que o número secreto!\n");
        }else{
            printf("Seu chute foi menor do que o número secreto!\n");
        }
        tentativas++;
        double pontosperdidos = abs((chute-numerosecreto)/2.0);
        pontos = pontos - pontosperdidos;
    }
    if(acertou){
        printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns! Você acertou!\n");
		printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    }else{
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");

        printf("\nVocê perdeu! Tente novamente!\n\n");
    }
    printf("\n");
    printf("Obrigado por jogar!\n");
    printf("Você gostaria de jogar de novo? Se sim, aperte 1\n");
    scanf("%d", &again);
    switch(again){
        case 1:
            repet=repet+0;
            break;
        default:
            repet=repet+2;
            break;
    }
}
}
