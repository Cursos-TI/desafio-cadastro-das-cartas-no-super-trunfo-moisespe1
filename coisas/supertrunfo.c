#include <stdio.h>
#define cidades 69

// estrutura para armazenar os dados da carta
typedef struct {
    char estado;              // letra do estado ('a' ate 'h')
    char codigo[5];           // código da carta (ex: A01, B03)
    char nomecidade[cidades]; // nome da cidade
    int populacao;            // população da cidade
    float area;               // area da cidade (em km²)
    float pib;                // PIB da cidade
    int pontos_turisticos;    // número de pontos turísticos
} Carta;

// função para exibir os dados da carta
void exibircarta(Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomecidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// função para comparar os atributos com base na escolha do jogador
void comparar_cartas(Carta carta1, Carta carta2) {
    int escolha1, escolha2;

    // menu para o primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha1);

    // menu para o segundo atributo garantindo que o jogador nao escolha o mesmo atributo
    do {
        printf("\nEscolha o segundo atributo para comparar as cartas (diferente do primeiro):\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("Digite a opção: ");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1);

    // comparação dos atributos
    float valor1, valor2, soma1 = 0, soma2 = 0;

    // comparar o primeiro atributo
    switch (escolha1) {
        case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; break;
        case 2: valor1 = carta1.area; valor2 = carta2.area; break;
        case 3: valor1 = carta1.pib; valor2 = carta2.pib; break;
        case 4: valor1 = carta1.pontos_turisticos; valor2 = carta2.pontos_turisticos; break;
    }

    if (valor1 > valor2) {
        printf("Carta 1 vence no primeiro atributo.\n");
        soma1 += valor1;
    } else if (valor1 < valor2) {
        printf("Carta 2 vence no primeiro atributo.\n");
        soma2 += valor2;
    } else {
        printf("Empate no primeiro atributo.\n");
    }

    // comparar o segundo atributo
    switch (escolha2) {
        case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; break;
        case 2: valor1 = carta1.area; valor2 = carta2.area; break;
        case 3: valor1 = carta1.pib; valor2 = carta2.pib; break;
        case 4: valor1 = carta1.pontos_turisticos; valor2 = carta2.pontos_turisticos; break;
    }
    if (valor1 > valor2) {
        printf("Carta 1 vence no segundo atributo.\n");
        soma1 += valor1;
    } else if (valor1 < valor2) {
        printf("Carta 2 vence no segundo atributo.\n");
        soma2 += valor2;
    } else {
        printf("Empate no segundo atributo.\n");
    }

    // comparar as somas dos atributos
    printf("\nSoma dos atributos para cada carta:\n");
    printf("Carta 1: %.2f\n", soma1);
    printf("Carta 2: %.2f\n", soma2);
    if (soma1 > soma2) {
        printf("\nCarta 1 vence a rodada!\n");
    } else if (soma1 < soma2) {
        printf("\nCarta 2 vence a rodada!\n");
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    Carta carta1, carta2;

    // cadastro da primeira carta
    printf("Digite as informações da primeira carta:\n");
    printf("Estado (de 'A' até 'H'): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomecidade);  // le o nome com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em R$): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da segunda carta
    printf("\nDigite as informações da segunda carta:\n");
    printf("Estado (de 'A' até 'H'): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomecidade);  // le o nome com espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em R$): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // exibir as cartas
    exibircarta(carta1);
    exibircarta(carta2);

    // comparar as cartas com base na escolha do jogador
    comparar_cartas(carta1, carta2);

    return 0;
}
// obrigado prof sergio.
