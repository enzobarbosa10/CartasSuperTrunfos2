#include <stdio.h>
#include <string.h>

// 1. Definição da estrutura para agrupar os dados de uma carta
typedef struct
{
    char estado[3];              // Estado (ex: "SP", "RJ")
    char codigo[10];             // Código da carta (ex: "A01")
    char cidade[50];             // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões
    int pontos;                  // Número de pontos turísticos
    float densidade;             // Densidade populacional (calculada)
    float pib_per_capita;        // PIB per capita (calculado)
    float super_poder;           // Super poder (calculado)
} Carta;

// 2. Função para ler os dados de uma carta
void ler_dados_carta(Carta *c, int numero)
{
    printf("\n========================================\n");
    printf("   CADASTRO DA CARTA %d\n", numero);
    printf("========================================\n");

    printf("Digite o estado (ex: SP, RJ): ");
    scanf("%s", c->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", c->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->cidade); // Lê string com espaços

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
void calcular_atributos(Carta *c)
{
    // Cálculo da densidade populacional
    if (c->area > 0)
    {
        c->densidade = (float)c->populacao / c->area;
    }
    else
    {
        c->densidade = 0;
    }

    // Cálculo do PIB per capita
    if (c->populacao > 0)
    {
        // Convertendo bilhões para reais e dividindo pela população
        c->pib_per_capita = (c->pib * 1000000000) / c->populacao;
    }
    else
    {
        c->pib_per_capita = 0;
    }

    // Cálculo do super poder
    if (c->densidade > 0)
    {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos +
                         c->pib_per_capita + (1.0f / c->densidade);
    }
    else
    {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos +
                         c->pib_per_capita;
    }
}

// 4. Função para exibir os dados de uma carta
void exibir_dados_carta(Carta c, int numero)
{
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

// 5. Função para exibir o menu interativo
int exibir_menu()
{
    int opcao;

    printf("\n========================================\n");
    printf("        MENU DE COMPARAÇÃO\n");
    printf("========================================\n");
    printf("Escolha o atributo para comparar:\n\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("0 - Sair\n");
    printf("========================================\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

// 6. Função para comparar cartas com base no atributo escolhido
void comparar_cartas(Carta c1, Carta c2, int opcao)
{
    // Variáveis para armazenar o resultado da comparação
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2
    char atributo[30];

    printf("\n========================================\n");
    printf("   COMPARAÇÃO DE CARTAS\n");
    printf("========================================\n");

    // Switch para determinar qual atributo será comparado
    switch (opcao)
    {
    case 1: // População
        strcpy(atributo, "População");
        printf("Atributo escolhido: %s\n\n", atributo);
        printf("Carta 1 - %s (%s): %lu habitantes\n", c1.cidade, c1.estado, c1.populacao);
        printf("Carta 2 - %s (%s): %lu habitantes\n", c2.cidade, c2.estado, c2.populacao);

        // Estrutura de decisão aninhada para comparação
        if (c1.populacao > c2.populacao)
        {
            vencedor = 1;
        }
        else if (c1.populacao < c2.populacao)
        {
            vencedor = 2;
        }
        else
        {
            vencedor = 0; // Empate
        }
        break;

    case 2: // Área
        strcpy(atributo, "Área");
        printf("Atributo escolhido: %s\n\n", atributo);
        printf("Carta 1 - %s (%s): %.2f km²\n", c1.cidade, c1.estado, c1.area);
        printf("Carta 2 - %s (%s): %.2f km²\n", c2.cidade, c2.estado, c2.area);

        // Estrutura de decisão aninhada para comparação
        if (c1.area > c2.area)
        {
            vencedor = 1;
        }
        else if (c1.area < c2.area)
        {
            vencedor = 2;
        }
        else
        {
            vencedor = 0; // Empate
        }
        break;

    case 3: // PIB
        strcpy(atributo, "PIB");
        printf("Atributo escolhido: %s\n\n", atributo);
        printf("Carta 1 - %s (%s): R$ %.2f bilhões\n", c1.cidade, c1.estado, c1.pib);
        printf("Carta 2 - %s (%s): R$ %.2f bilhões\n", c2.cidade, c2.estado, c2.pib);

        // Estrutura de decisão aninhada com validação adicional
        if (c1.pib > 0 && c2.pib > 0)
        {
            if (c1.pib > c2.pib)
            {
                vencedor = 1;
            }
            else if (c1.pib < c2.pib)
            {
                vencedor = 2;
            }
            else
            {
                vencedor = 0; // Empate
            }
        }
        else
        {
            printf("\nAtenção: Valores de PIB inválidos!\n");
            return;
        }
        break;

    case 4: // Pontos Turísticos
        strcpy(atributo, "Pontos Turísticos");
        printf("Atributo escolhido: %s\n\n", atributo);
        printf("Carta 1 - %s (%s): %d pontos turísticos\n", c1.cidade, c1.estado, c1.pontos);
        printf("Carta 2 - %s (%s): %d pontos turísticos\n", c2.cidade, c2.estado, c2.pontos);

        // Estrutura de decisão aninhada para comparação
        if (c1.pontos > c2.pontos)
        {
            vencedor = 1;
        }
        else if (c1.pontos < c2.pontos)
        {
            vencedor = 2;
        }
        else
        {
            vencedor = 0; // Empate
        }
        break;

    case 5: // Densidade Populacional (REGRA INVERTIDA - menor vence)
        strcpy(atributo, "Densidade Populacional");
        printf("Atributo escolhido: %s\n", atributo);
        printf("(Regra especial: Menor densidade vence!)\n\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", c1.cidade, c1.estado, c1.densidade);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", c2.cidade, c2.estado, c2.densidade);

        // Estrutura de decisão aninhada com regra invertida
        if (c1.densidade > 0 && c2.densidade > 0)
        {
            // Para densidade, MENOR valor vence
            if (c1.densidade < c2.densidade)
            {
                vencedor = 1;
            }
            else if (c1.densidade > c2.densidade)
            {
                vencedor = 2;
            }
            else
            {
                vencedor = 0; // Empate
            }
        }
        else
        {
            printf("\nAtenção: Valores de densidade inválidos!\n");
            return;
        }
        break;

    case 6: // PIB per Capita
        strcpy(atributo, "PIB per Capita");
        printf("Atributo escolhido: %s\n\n", atributo);
        printf("Carta 1 - %s (%s): R$ %.2f\n", c1.cidade, c1.estado, c1.pib_per_capita);
        printf("Carta 2 - %s (%s): R$ %.2f\n", c2.cidade, c2.estado, c2.pib_per_capita);

        // Estrutura de decisão aninhada para comparação
        if (c1.pib_per_capita > c2.pib_per_capita)
        {
            vencedor = 1;
        }
        else if (c1.pib_per_capita < c2.pib_per_capita)
        {
            vencedor = 2;
        }
        else
        {
            vencedor = 0; // Empate
        }
        break;

    case 7: // Super Poder
        strcpy(atributo, "Super Poder");
        printf("Atributo escolhido: %s\n\n", atributo);
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, c1.super_poder);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, c2.super_poder);

        // Estrutura de decisão aninhada para comparação
        if (c1.super_poder > c2.super_poder)
        {
            vencedor = 1;
        }
        else if (c1.super_poder < c2.super_poder)
        {
            vencedor = 2;
        }
        else
        {
            vencedor = 0; // Empate
        }
        break;

    default: // Opção inválida (tratamento de segurança)
        printf("\nOpção inválida! Por favor, escolha um número de 0 a 7.\n");
        return;
    }

    // Exibição do resultado da comparação
    printf("\n----------------------------------------\n");

    // Estrutura de decisão aninhada para exibir o resultado
    if (vencedor == 1)
    {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
    }
    else if (vencedor == 2)
    {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    else
    {
        printf("Resultado: Empate!\n");
    }

    printf("========================================\n");
}

// 7. Função principal
int main()
{
    Carta carta1, carta2;
    int opcao;
    int continuar = 1;

    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   SUPER TRUNFO - CIDADES DO BRASIL    ║\n");
    printf("╚════════════════════════════════════════╝\n");

    // Leitura dos dados da Carta 1
    ler_dados_carta(&carta1, 1);
    calcular_atributos(&carta1);

    // Leitura dos dados da Carta 2
    ler_dados_carta(&carta2, 2);
    calcular_atributos(&carta2);

    // Exibição dos dados das cartas cadastradas
    printf("\n========================================\n");
    printf("   CARTAS CADASTRADAS COM SUCESSO!\n");
    printf("========================================\n");

    exibir_dados_carta(carta1, 1);
    exibir_dados_carta(carta2, 2);

    // Loop do menu interativo
    while (continuar)
    {
        opcao = exibir_menu();

        // Switch para processar a opção escolhida no menu
        switch (opcao)
        {
        case 0: // Sair do jogo
            printf("\n========================================\n");
            printf("  Obrigado por jogar Super Trunfo!\n");
            printf("         Até a próxima!\n");
            printf("========================================\n\n");
            continuar = 0;
            break;

        case 1: // População
        case 2: // Área
        case 3: // PIB
        case 4: // Pontos Turísticos
        case 5: // Densidade Populacional
        case 6: // PIB per Capita
        case 7: // Super Poder
            // Chama a função de comparação
            comparar_cartas(carta1, carta2, opcao);

            // Pergunta se deseja continuar jogando
            printf("\nDeseja fazer outra comparação? (1-Sim / 0-Não): ");
            scanf("%d", &continuar);

            // Validação da entrada
            if (continuar != 0 && continuar != 1)
            {
                printf("Opção inválida! Encerrando o jogo.\n");
                continuar = 0;
            }
            break;

        default: // Opção inválida no menu
            printf("\n========================================\n");
            printf("Opção inválida! Tente novamente.\n");
            printf("========================================\n");
            break;
        }
    }

    return 0;
}