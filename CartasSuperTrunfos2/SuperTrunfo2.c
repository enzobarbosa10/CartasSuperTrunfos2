#include <stdio.h>

int main() {

// Dados do primeiro CARTA1
    char estado1;
    char codigo1 [10];
    char cidade1 [50];
    int populacao1;
    float area1;
    float pib1; 
    int pontos1;
    float densidade1;
    float pib_per_capita1;

// Dados do segundo CARTA2
    char estado2;
    char codigo2 [10];
    char cidade2 [50];
    int populacao2;
    float area2;
    float pib2; 
    int pontos2;
    float densidade2;
    float pib_per_capita2;


// Entrada de dados da CARTA1
    printf("Digite o estado da Carta 1 (A-H): ");
    scanf(" %c", &estado1); // espaço antes do %c para ignorar ENTRs

    printf("Digite o código da Carta 1 (ex: A01): ");
    scanf("%s", codigo1); // sem & poeque arrays já são ponteiros

    printf("Digite a cidade da Carta 1: ");
    scanf(" %[^\n]", cidade1); // lê encontrar ENTER // mesma coisa do que CODGO

    printf("Digite a população da Carta 1: ");
    scanf("%d", &populacao1);

    printf("Digite a área da Carta 1 (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite os pontos turisticos da Carta 1: ");
    scanf("%d", &pontos1);


// Entrada de dados da CARTA2
    printf("Digite o estado da Carta 2 (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o código da Carta 2 (ex: A01): ");
    scanf("%s", codigo2);

    printf("Digite a cidade da Carta 2: ");
    scanf(" %[^\n]", cidade2); // lê encontrar ENTER

    printf("Digite a população da Carta 2: ");
    scanf("%d", &populacao2);

    printf("Digite a área da Carta 2 (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite os pontos turisticos da Carta 2: ");
    scanf("%d", &pontos2);
    

//Cálcilos
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (float)pib1 * 1000000000 / populacao1; // PIB em bilhões

    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (float)pib2 * 1000000000 / populacao2; // PIB em bilhões


// Exibir os dados das cartas
    printf("\n--- Dados da Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);

    printf("\n--- Dados da Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);

    return 0;
}