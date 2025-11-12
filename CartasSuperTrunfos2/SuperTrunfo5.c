#include <stdio.h>

// 1. Definição da estrutura para agrupar os dados de uma carta
typedef struct {
    char estado[3];           // Estado (ex: "SP", "RJ")
    char codigo[10];          // Código da carta (ex: "A01")
    char cidade[50];          // Nome da cidade
    unsigned long int populacao;  // População da cidade
    float area;               // Área em km²
    float pib;                // PIB em bilhões
    int pontos;               // Número de pontos turísticos
    float densidade;          // Densidade populacional (calculada)
    float pib_per_capita;     // PIB per capita (calculado)
    float super_poder;        // Super poder (calculado)
} Carta;

// 2. Função para ler os dados de uma carta
// O asterisco (*) indica que a função receberá um ponteiro para uma 'struct Carta'
void ler_dados_carta(Carta *c, int numero) {
    printf("\n========================================\n");
    printf("   CADASTRO DA CARTA %d\n", numero);
    printf("========================================\n");
    
    printf("Digite o estado (ex: SP, RJ): ");
    scanf("%s", c->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", c->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->cidade);  // Lê string com espaços

    printf("Digite a população: ");
    scanf("%lu", &c->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontos);
}

// 3. Função para calcular os atributos derivados
void calcular_atributos(Carta *c) {
    // Cálculo da densidade populacional
    if (c->area > 0) {
        c->densidade = (float)c->populacao / c->area;
    } else {
        c->densidade = 0;
    }
    
    // Cálculo do PIB per capita
    if (c->populacao > 0) {
        // Convertendo bilhões para reais e dividindo pela população
        c->pib_per_capita = (c->pib * 1000000000) / c->populacao;
    } else {
        c->pib_per_capita = 0;
    }
    
    // Cálculo do super poder
    if (c->densidade > 0) {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos + 
                         c->pib_per_capita + (1.0f / c->densidade);
    } else {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos + 
                         c->pib_per_capita;
    }
}

// 4. Função para exibir os dados de uma carta
void exibir_dados_carta(Carta c, int numero) {
    printf("\n========================================\n");
    printf("   CARTA %d - %s (%s)\n", numero, c.cidade, c.estado);
    printf("========================================\n");
    printf("Código: %s\n", c.codigo);
    printf("População: %lu habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos);
    printf("----------------------------------------\n");
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: R$ %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
    printf("========================================\n");
}

// 5. Função para comparar cartas por um atributo específico
void comparar_cartas(Carta c1, Carta c2, char* atributo) {
    printf("\n========================================\n");
    printf("   COMPARAÇÃO DE CARTAS\n");
    printf("========================================\n");
    printf("Atributo escolhido: %s\n\n", atributo);
    
    int carta1_venceu = 0;  // Flag para indicar se a carta 1 venceu
    
    // Escolha o atributo para comparar (modificar esta seção para comparar outro atributo)
    // Atributo atual: POPULAÇÃO (descomente outro para mudar)
    
    // POPULAÇÃO - Maior valor vence
    printf("Carta 1 - %s (%s): %lu habitantes\n", c1.cidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %lu habitantes\n", c2.cidade, c2.estado, c2.populacao);
    if (c1.populacao > c2.populacao) {
        carta1_venceu = 1;
    }
    
    /* ÁREA - Maior valor vence (descomente para usar)
    printf("Carta 1 - %s (%s): %.2f km²\n", c1.cidade, c1.estado, c1.area);
    printf("Carta 2 - %s (%s): %.2f km²\n", c2.cidade, c2.estado, c2.area);
    if (c1.area > c2.area) {
        carta1_venceu = 1;
    }
    */
    
    /* PIB - Maior valor vence (descomente para usar)
    printf("Carta 1 - %s (%s): R$ %.2f bilhões\n", c1.cidade, c1.estado, c1.pib);
    printf("Carta 2 - %s (%s): R$ %.2f bilhões\n", c2.cidade, c2.estado, c2.pib);
    if (c1.pib > c2.pib) {
        carta1_venceu = 1;
    }
    */
    
    /* PONTOS TURÍSTICOS - Maior valor vence (descomente para usar)
    printf("Carta 1 - %s (%s): %d pontos turísticos\n", c1.cidade, c1.estado, c1.pontos);
    printf("Carta 2 - %s (%s): %d pontos turísticos\n", c2.cidade, c2.estado, c2.pontos);
    if (c1.pontos > c2.pontos) {
        carta1_venceu = 1;
    }
    */
    
    /* DENSIDADE POPULACIONAL - Menor valor vence (descomente para usar)
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", c1.cidade, c1.estado, c1.densidade);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", c2.cidade, c2.estado, c2.densidade);
    if (c1.densidade < c2.densidade) {
        carta1_venceu = 1;
    }
    */
    
    /* PIB PER CAPITA - Maior valor vence (descomente para usar)
    printf("Carta 1 - %s (%s): R$ %.2f\n", c1.cidade, c1.estado, c1.pib_per_capita);
    printf("Carta 2 - %s (%s): R$ %.2f\n", c2.cidade, c2.estado, c2.pib_per_capita);
    if (c1.pib_per_capita > c2.pib_per_capita) {
        carta1_venceu = 1;
    }
    */
    
    /* SUPER PODER - Maior valor vence (descomente para usar)
    printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, c1.super_poder);
    printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, c2.super_poder);
    if (c1.super_poder > c2.super_poder) {
        carta1_venceu = 1;
    }
    */
    
    // Exibir resultado
    printf("\n----------------------------------------\n");
    if (carta1_venceu) {
        printf("🏆 RESULTADO: Carta 1 (%s) venceu!\n", c1.cidade);
    } else {
        printf("🏆 RESULTADO: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    printf("========================================\n");
}

int main() {
    Carta carta1, carta2;
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   SUPER TRUNFO - CIDADES DO BRASIL    ║\n");
    printf("╚════════════════════════════════════════╝\n");

    // Leitura dos dados da Carta 1
    ler_dados_carta(&carta1, 1);
    calcular_atributos(&carta1);

    // Leitura dos dados da Carta 2
    ler_dados_carta(&carta2, 2);
    calcular_atributos(&carta2);
    
    // Exibição dos dados das cartas
    exibir_dados_carta(carta1, 1);
    exibir_dados_carta(carta2, 2);

    // Comparação das cartas
    // Modifique o atributo na função comparar_cartas() descomentando a seção desejada
    comparar_cartas(carta1, carta2, "População");

    return 0;
}