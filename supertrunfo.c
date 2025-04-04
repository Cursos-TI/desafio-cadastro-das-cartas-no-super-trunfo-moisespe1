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

    return 0;
}

// obrigado prof sergio.