#include <stdio.h>

int main() {

// Dados do primeiro CARTA1
    char estado1;
    char codigo1 [10];
    char cidade1 [50];
    unsigned long int populacao1;
    float area1;
    float pib1; 
    int pontos1;
    float densidade1;
    float pib_per_capita1;
    float super_poder1;

// Dados do segundo CARTA2
    char estado2;
    char codigo2 [10];
    char cidade2 [50];
    unsigned long int populacao2;
    float area2;
    float pib2; 
    int pontos2;
    float densidade2;
    float pib_per_capita2;
    float super_poder2;


// Entrada de dados da CARTA1
    printf("Digite o estado da Carta 1 (A-H): ");
    scanf(" %c", &estado1); 

    printf("Digite o código da Carta 1 (ex: A01): ");
    scanf("%s", codigo1); 

    printf("Digite a cidade da Carta 1: ");
    scanf(" %[^\n]", cidade1); 

    printf("Digite a população da Carta 1: ");
    scanf("%lu", &populacao1);

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
    scanf("%lu", &populacao2);

    printf("Digite a área da Carta 2 (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite os pontos turisticos da Carta 2: ");
    scanf("%d", &pontos2);
    

//Cálculos
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (float)pib1 * 1000000000 / populacao1; // PIB em bilhões
    super_poder1 = (float)populacao1 + area1 + pib1 + pontos1 + pib_per_capita1 + (1.0f / densidade1);

    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (float)pib2 * 1000000000 / populacao2; // PIB em bilhões
    super_poder2 = (float)populacao2 + area2 + pib2 + pontos2 + pib_per_capita2 + (1.0f / densidade2);  


// Exibir os dados das cartas
    printf("\n---Dados da Carta 1 ---\n");
    printf("Estado: %c\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", 
            estado1, codigo1, cidade1, populacao1, area1, pib1);
    printf("Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n", 
            pontos1, densidade1, pib_per_capita1, super_poder1);

    printf("\n---Dados da Carta 2 ---\n");
    printf("Estado: %c\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", 
            estado2, codigo2, cidade2, populacao2, area2, pib2);
    printf("Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n", 
            pontos2, densidade2, pib_per_capita2, super_poder2);


// Comparação dos atributos
    printf("\n--- Comparação de Cartas ---\n");
    printf("População: Carta 1 venceu (%d)\n", (populacao1 > populacao2));
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontos1 > pontos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2); 
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder1 > super_poder2);
/*
        printf("\n--- Comparação de Cartas ---\n");

    if (populacao1 > populacao2) printf("População: Carta 1 venceu\n");
    else if (populacao2 > populacao1) printf("População: Carta 2 venceu\n");
    else printf("População: Empate\n");

    if (area1 > area2) printf("Área: Carta 1 venceu\n");
    else if (area2 > area1) printf("Área: Carta 2 venceu\n");
    else printf("Área: Empate\n");

    if (pib1 > pib2) printf("PIB: Carta 1 venceu\n");
    else if (pib2 > pib1) printf("PIB: Carta 2 venceu\n");
    else printf("PIB: Empate\n");

    if (pontos1 > pontos2) printf("Pontos Turísticos: Carta 1 venceu\n");
    else if (pontos2 > pontos1) printf("Pontos Turísticos: Carta 2 venceu\n");
    else printf("Pontos Turísticos: Empate\n");

    if (densidade1 < densidade2) printf("Densidade Populacional: Carta 1 venceu\n");
    else if (densidade2 < densidade1) printf("Densidade Populacional: Carta 2 venceu\n");
    else printf("Densidade Populacional: Empate\n");

    if (pib_per_capita1 > pib_per_capita2) printf("PIB per Capita: Carta 1 venceu\n");
    else if (pib_per_capita2 > pib_per_capita1) printf("PIB per Capita: Carta 2 venceu\n");
    else printf("PIB per Capita: Empate\n");

    if (super_poder1 > super_poder2) printf("Super Poder: Carta 1 venceu\n");
    else if (super_poder2 > super_poder1) printf("Super Poder: Carta 2 venceu\n");
    else printf("Super Poder: Empate\n");


*/

    return 0;
}