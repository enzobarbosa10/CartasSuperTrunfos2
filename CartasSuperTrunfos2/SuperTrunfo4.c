
#include <stdio.h>

// 1. Definição da estrutura para agrupar os dados de uma carta
typedef struct {
    char estado;
    char codigo[10];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// 2. Função para ler os dados de uma carta
// O asterisco (*) indica que a função receberá um ponteiro para uma 'struct Carta'
void ler_dados_carta(Carta *c, int numero) {
    printf("--- Entrada de dados da CARTA %d ---\n", numero);
    printf("Digite o estado da Carta %d (A-H): ", numero);
    scanf(" %c", &c->estado); // O operador '->' acessa membros de um ponteiro

    printf("Digite o código da Carta %d (ex: A01): ", numero);
    scanf("%s", c->codigo);

    printf("Digite a cidade da Carta %d: ", numero);
    scanf(" %[^\n]", c->cidade);

    printf("Digite a população da Carta %d: ", numero);
    scanf("%lu", &c->populacao);

    printf("Digite a área da Carta %d (em km²): ", numero);
    scanf("%f", &c->area);

    printf("Digite o PIB da Carta %d (em bilhões): ", numero);
    scanf("%f", &c->pib);

    printf("Digite os pontos turisticos da Carta %d: ", numero);
    scanf("%d", &c->pontos);
}

// 3. Função para calcular os atributos derivados
void calcular_atributos(Carta *c) {
    if (c->area > 0) {
        c->densidade = (float)c->populacao / c->area;
    } else {
        c->densidade = 0;
    }
    
    if (c->populacao > 0) {
        c->pib_per_capita = (float)c->pib * 1000000000 / c->populacao;
    } else {
        c->pib_per_capita = 0;
    }
    
    // Cálculo do super poder com verificação para evitar divisão por zero
    if (c->densidade > 0) {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos + c->pib_per_capita + (1.0f / c->densidade);
    } else {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos + c->pib_per_capita;
    }
}

// 4. Função para exibir os dados de uma carta
void exibir_dados_carta(Carta c) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %c\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", 
           c.estado, c.codigo, c.cidade, c.populacao, c.area, c.pib);
    printf("Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n", 
           c.pontos, c.densidade, c.pib_per_capita, c.super_poder);
}

int main() {
    Carta carta1, carta2;

    // Leitura e cálculos para a Carta 1
    ler_dados_carta(&carta1, 1);
    calcular_atributos(&carta1);

    // Leitura e cálculos para a Carta 2
    ler_dados_carta(&carta2, 2);
    calcular_atributos(&carta2);
    
    // Exibição dos dados
    exibir_dados_carta(carta1);
    exibir_dados_carta(carta2);

    // Comparação dos atributos
    printf("\n--- Comparação de Cartas ---\n");
    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontos > carta2.pontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidade < carta2.densidade); 
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pib_per_capita > carta2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.super_poder > carta2.super_poder);

    return 0;
}
