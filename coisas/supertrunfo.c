#include <stdio.h>
#define cidades 69

// estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;             // letra do estado ('a' ate 'h')
    char codigo[5];          // código da carta (ex: A01, B03)
    char nomecidade[cidades]; // nome da cidade
    int populacao;           // população da cidade
    float area;              // area da cidade (em km²)
    float pib;               // PIB da cidade
    int pontos_turisticos;   // número de pontos turísticos
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
    int escolha;

    // Definir as variáveis para PIB per Capita e densidade populacional aqui
    float pib_per_capita1 = carta1.pib / carta1.populacao;
    float pib_per_capita2 = carta2.pib / carta2.populacao;
    float densidade_populacional1 = carta1.populacao / carta1.area;
    float densidade_populacional2 = carta2.populacao / carta2.area;

    // exibir o menu interativo
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - PIB per Capita\n");
    printf("6 - Densidade Populacional\n");
    printf("7 - Super Poder\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:

            // comparação de População
            if (carta1.populacao > carta2.populacao) {
                printf("\nPopulação: Carta 1 vence\n");
            } else if (carta1.populacao < carta2.populacao) {
                printf("\nPopulação: Carta 2 vence\n");
            } else {
                printf("\nPopulação: Empate\n");
            }
            break;

        case 2:

            // comparação de área
            if (carta1.area > carta2.area) {
                printf("\nÁrea: Carta 1 vence\n");
            } else if (carta1.area < carta2.area) {
                printf("\nÁrea: Carta 2 vence\n");
            } else {
                printf("\nÁrea: Empate\n");
            }
            break;

        case 3:

            // comparação de PIB
            if (carta1.pib > carta2.pib) {
                printf("\nPIB: Carta 1 vence\n");
            } else if (carta1.pib < carta2.pib) {
                printf("\nPIB: Carta 2 vence\n");
            } else {
                printf("\nPIB: Empate\n");
            }
            break;

        case 4:

            // comparação de pontos turísticos
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("\nPontos Turísticos: Carta 1 vence\n");
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("\nPontos Turísticos: Carta 2 vence\n");
            } else {
                printf("\nPontos Turísticos: Empate\n");
            }
            break;

        case 5:

            // comparação de PIB per Capita
            if (pib_per_capita1 > pib_per_capita2) {
                printf("\nPIB per Capita: Carta 1 vence\n");
            } else if (pib_per_capita1 < pib_per_capita2) {
                printf("\nPIB per Capita: Carta 2 vence\n");
            } else {
                printf("\nPIB per Capita: Empate\n");
            }
            break;

        case 6:

            // comparação de densidade populacional
            if (densidade_populacional1 < densidade_populacional2) {
                printf("\nDensidade Populacional: Carta 1 vence (menor é melhor)\n");
            } else if (densidade_populacional1 > densidade_populacional2) {
                printf("\nDensidade Populacional: Carta 2 vence (menor é melhor)\n");
            } else {
                printf("\nDensidade Populacional: Empate\n");
            }
            break;

        case 7:

            // comparação de Super Poder
            float densidade_populacional1_inv = 1 / densidade_populacional1;
            float densidade_populacional2_inv = 1 / densidade_populacional2;

            float superpoder1 = carta1.populacao + carta1.area + carta1.pib + carta1.pontos_turisticos + pib_per_capita1 + densidade_populacional1_inv;
            float superpoder2 = carta2.populacao + carta2.area + carta2.pib + carta2.pontos_turisticos + pib_per_capita2 + densidade_populacional2_inv;

            if (superpoder1 > superpoder2) {
                printf("\nSuper Poder: Carta 1 vence\n");
            } else if (superpoder1 < superpoder2) {
                printf("\nSuper Poder: Carta 2 vence\n");
            } else {
                printf("\nSuper Poder: Empate\n");
            }
            break;

        default:
            printf("\nOpção inválida.\n");
            break;
    }
}


int main() {
    Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Digite as informações da primeira carta:\n");
    printf("Estado (de 'A' até 'H'): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta1.codigo); 
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomecidade);  // lê o nome com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em R$): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // cadastro da segunda carta
    printf("\nDigite as informações da segunda carta:\n");
    printf("Estado (de 'A' até 'H'): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomecidade);  // lê o nome com espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em R$): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Exibir as cartas
    exibircarta(carta1);
    exibircarta(carta2);

    // comparar as cartas com base na escolha do jogador
    comparar_cartas(carta1, carta2);

    return 0;
}
// obrigado prof sergio.
