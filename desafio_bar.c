/*Em um bar, o ingresso custa 10 reais para homens e 8 reais para mulheres. Cada cerveja custa 5
reais, cada refrigerante 3 reais e cada espetinho custa 7. Além disso, o bar cobra uma taxa de
couvert artístico no valor de 4 reais, porém, se o valor gasto com consumo for superior a 30 reais,
o couvert artístico não é cobrado. Fazer um programa para ler os seguintes dados de um cliente do
bar: sexo (F ou M), quantidade de cervejas, refrigerantes e espetinhos consumidos. O programa
deve então mostrar um relatório com a conta a ser paga pelo cliente.*/
#include <stdio.h>
#define precocerveja 5
#define precorefri 3
#define precoespeto 7
int main(){
    char sexo;
    int cerveja, espetinho, refrigerante, couvert=4;
    float ingresso;
    printf("Sexo: ");
    scanf("%c", &sexo);
    printf("Quantidade de cervejas: ");
    scanf("%d", &cerveja);
    printf("Quantidade de refrigerantes: ");
    scanf("%d", &refrigerante);
    printf("Quantidade de espetinhos: ");
    scanf("%d", &espetinho);
    if(sexo=='f' || sexo == 'F'){
         ingresso = 8;
    }else if(sexo == 'm' || sexo=='M'){
         ingresso = 10;
    }
    float consumo=(precocerveja*cerveja)+(precoespeto*espetinho)+(precorefri*refrigerante);
    float total;
    if(consumo>30){
        couvert=0;
         total=consumo+ingresso+couvert;
    printf("RELATÓRIO:\n");
    printf("Consumo = R$ %.2f\n", consumo);
    printf("Isento de Couvert\n");
    printf("Ingresso = R$ %.2f\n", ingresso);
    printf("\n");
    printf("Valor a pagar = R$ %.2f\n", total);
    }else{
         total=consumo+ingresso+couvert;
    printf("RELATÓRIO:\n");
    printf("Consumo = R$ %.2f\n", consumo);
    printf("Couvert = R$ %d\n", couvert);
    printf("Ingresso = R$ %.2f\n", ingresso);
    printf("\n");
    printf("Valor a pagar = R$ %.2f\n", total);

    }


 return 0;
}
