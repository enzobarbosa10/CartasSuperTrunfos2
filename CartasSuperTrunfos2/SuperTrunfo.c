#include <stdio.h>

int main() {
    // Dados do primeiro CARTA1
    char estado1;
    char codigo1[10];
    char cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;

    // Dados do segundo CARTA2
    char estado2;
    char codigo2[10];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Entrada de dados da CARTA1
    printf("Digite o estado da Carta 1 (UF): ");
    scanf(" %c", &estado1);

    printf("Digite o código da Carta 1 (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite a cidade da Carta 1: ");
    scanf(" %[^\n]", cidade1); // permite espaços

    printf("Digite a população da Carta 1: ");
    scanf("%d", &populacao1);

    printf("Digite a área da Carta 1 (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite os pontos turísticos da Carta 1: ");
    scanf("%d", &pontos1);

    // Entrada de dados da CARTA2
    printf("\nDigite o estado da Carta 2 (UF): ");
    scanf(" %c", &estado2);

    printf("Digite o código da Carta 2 (ex: A01): ");
    scanf("%s", codigo2);

    printf("Digite a cidade da Carta 2: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população da Carta 2: ");
    scanf("%d", &populacao2);

    printf("Digite a área da Carta 2 (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite os pontos turísticos da Carta 2: ");
    scanf("%d", &pontos2);

    // Exibir os dados das cartas
    printf("\n--- Dados da Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos1);

    printf("\n--- Dados da Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos2);

    return 0;
}
