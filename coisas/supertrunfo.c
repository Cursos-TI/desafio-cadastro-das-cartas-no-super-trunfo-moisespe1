#include <stdio.h>
#define cidades 69

// estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;             // letra do estado ('a' ate 'h')
    char codigo[5];          // codigo da carta (ex: A01, B03)
    char nomecidade[cidades]; // nome da cidade
    int populacao;           // população da cidade
    float area;              // area da cidade (em km²)
    float pib;               // pib da cidade
    int pontos_turisticos;   // numero de pontos turisticos
} Carta;

void exibircarta(Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomecidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    Carta carta1, carta2;

    // cadastro da primeira carta
    printf("Digite as informações da primeira carta:\n");
    printf("Estado (de 'A' ate 'H'): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta1.codigo); 
    printf("Nome da Cidade: ");
    scanf(" %s[^\n]", carta1.nomecidade); // le o nome da cidade com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em R$): ");
    scanf("%f", &carta1.pib);
    printf("Numero d Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // calculando a densidade populacional e o pib per capita da primeira carta
    float densidade_populacional1 = carta1.populacao / carta1.area;
    float pib_per_capita1 = carta1.pib / carta1.populacao;
    float superpoder1 = carta1.populacao + carta1.area + carta1.pib + carta1.pontos_turisticos + pib_per_capita1 + (1 / densidade_populacional1);

    // calculando a densidade populacional e o pib per capita da segunda carta
    float densidade_populacional2 = carta2.populacao / carta2.area;
    float pib_per_capita2 = carta2.pib / carta2.populacao;
    float superpoder2 = carta2.populacao + carta2.area + carta2.pib + carta2.pontos_turisticos + pib_per_capita2 + (1 / densidade_populacional2);
    
    // cadastro da segunda cartaa
    printf("\nDigite as informações da segunda carta:\n");
    printf("Estado (de 'A' ate 'H'): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %s[^\n]", carta2.nomecidade); // le o nome da cidade com espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em R$): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // exibindo as informaçoes das cartas
    exibircarta(carta1);
    exibircarta(carta2);

        // comparar população
    printf("\nPopulação: Carta 1 vence (%d)\n", carta1.populacao > carta2.populacao);
    printf("População: Carta 2 vence (%d)\n", carta2.populacao > carta1.populacao);
    printf("População: Empate (%d)\n", carta1.populacao == carta2.populacao);

    // comparar área
    printf("\nÁrea: Carta 1 vence (%d)\n", carta1.area > carta2.area);
    printf("Área: Carta 2 vence (%d)\n", carta2.area > carta1.area);
    printf("Área: Empate (%d)\n", carta1.area == carta2.area);

    // comparar PIB
    printf("\nPIB: Carta 1 vence (%d)\n", carta1.pib > carta2.pib);
    printf("PIB: Carta 2 vence (%d)\n", carta2.pib > carta1.pib);
    printf("PIB: Empate (%d)\n", carta1.pib == carta2.pib);

    // cmparar pontos turísticos
    printf("\nPontos Turísticos: Carta 1 vence (%d)\n", carta1.pontos_turisticos > carta2.pontos_turisticos);
    printf("Pontos Turísticos: Carta 2 vence (%d)\n", carta2.pontos_turisticos > carta1.pontos_turisticos);
    printf("Pontos Turísticos: Empate (%d)\n", carta1.pontos_turisticos == carta2.pontos_turisticos);

    // comparar PIB per capita
    printf("\nPIB per Capita: Carta 1 vence (%d)\n", pib_per_capita1 > pib_per_capita2);
    printf("PIB per Capita: Carta 2 vence (%d)\n", pib_per_capita2 > pib_per_capita1);
    printf("PIB per Capita: Empate (%d)\n", pib_per_capita1 == pib_per_capita2);

    // Comparar densidade populacional
    printf("\nDensidade Populacional (menor vence): Carta 1 vence (%d)\n", (1 / densidade_populacional1) > (1 / densidade_populacional2));
    printf("Densidade Populacional (menor vence): Carta 2 vence (%d)\n", (1 / densidade_populacional2) > (1 / densidade_populacional1));
    printf("Densidade Populacional (menor vence): Empate (%d)\n", (1 / densidade_populacional1) == (1 / densidade_populacional2));

    // Ccmparar super poder
    printf("\nSuper Poder: Carta 1 vence (%d)\n", superpoder1 > superpoder2);
    printf("Super Poder: Carta 2 vence (%d)\n", superpoder2 > superpoder1);
    printf("Super Poder: Empate (%d)\n", superpoder1 == superpoder2);    

    return 0;
}

// obrigado prof sergio.
