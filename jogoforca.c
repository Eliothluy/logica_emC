#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"
//Declaração de variáveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados=0;

int letraexiste(char letra){
    for(int j=0; j<strlen(palavrasecreta); j++){
        if(letra == palavrasecreta[j]){
            return 1;
        }
    }
    return 0;
}

int chuteserrados(){
    int erros = 0;

    for(int i = 0; i < chutesdados; i++){
        if(!letraexiste(chutes[i])){
                erros++;
            }
        }
    return erros;
}

int enforcou(){
    return chuteserrados() >= 5;
}

int ganhou(){
    for(int i = 0; i<strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;
}

//Função que imprime a abertura do jogo
void abertura(){
    printf("/****************/\n");
    printf("/ Jogo de Forca*\n");
    printf("/****************/\n");
}
//Funçao que lê e guarda a tentativa de chutes.
void chuta(){
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    if(letraexiste(chute)){
        printf("Você acertou a palavra tem a letra %c\n\n", chute);
    }else{
        printf("\nVOcê errou: a palavra NÃO tem a letra %c\n\n", chute);
    }
    chutes[chutesdados]=chute;
    chutesdados++;
}
//Função que mostra se acertou a letra da palavra
int jachutou(char letra){
    int achou =0;
    for(int j=0; j < chutesdados; j++){
        if(chutes[j] == letra){
            achou=1;
            break;
        }
    }
    return achou;
}

void desenhaforca(){
   int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
    printf("Você já deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(jachutou(palavrasecreta[i])) {
        printf("%c ", palavrasecreta[i]);
        }else{
        printf("_ ");
        }
        }
    printf("\n");
}
//Função que escolhe a palavra do jogo.
void escolhepalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f==0){
        printf("Banco de dados de palavras não disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() %qtddepalavras;

    for(int i = 0; i<=randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }
    fclose(f);
}

void adicionapalavra(){
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer == 'S'){
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        //abre o arquivo
        f=fopen("palavras.txt", "r+");
        if(f==0){
            printf("Banco de dados de palavras não disponivel\n\n");
            exit(1);
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        //fecha
        fclose(f);
    }
}

//Função principal.
int main(){

    abertura();
    escolhepalavra();

    do{
        desenhaforca();
        chuta();
    }while(!ganhou() && !enforcou());
    if(ganhou()){
        printf("\nParabéns, você ganhou! Vamos tomar um vinho?\n\n");
      printf("  ########                                    \n");
      printf("  ########                                    \n");
      printf("  ########                                    \n");
      printf("  ########                                    \n");
      printf("  ########                                    \n");
      printf("  ########                                    \n");
      printf("  ########\n");
      printf("  ########\n");
    printf("  ############\n");
  printf("  ################\n");
printf("  ####################\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ##########  ##########\n");
printf("  ####################      ########      ######\n");
printf("  ####################        ####          ##\n");
printf("  ####################        ####          ##\n");
printf("  ####################        ####          ##\n");
printf("  ####################        ####          ##\n");
printf("  ####################        ####          ##\n");
printf("  ####################      ##########  ##########\n");
    }else{
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);



                 printf(" ################                \n");
              printf(" ########################            \n");
            printf(" ############################          \n");
          printf(" ################################        \n");
          printf(" ################################        \n");
        printf(" ####################################      \n");
        printf(" ####################################      \n");
        printf(" ######################################    \n");
      printf(" ########################################    \n");
      printf(" ########################################    \n");
      printf(" ########      ++##########      ########    \n");
      printf(" MM####          ########          ######    \n");
      printf(" @@####            @@##..          @@####    \n");
      printf(" --@@##            ######          MM####    \n");
        printf(" ####          ########          ####      \n");
        printf(" ####################################      \n");
        printf(" ################    ################      \n");
      printf(" --##############        ################    \n");
      printf(" @@##############        ################    \n");
        printf(" ##############  ::MM  ##############      \n");
                printf(" ####################              \n");
                printf(" @@##################              \n");
                  printf(" ##  ####++##  ####              \n");
                printf(" ::##  ####++##  ####              \n");
                        printf("--..                      \n");

    }
    adicionapalavra();


    return 0;
}

