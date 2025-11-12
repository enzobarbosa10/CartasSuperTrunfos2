#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Implementação completa do sistema de comparação de cartas de cidades

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
    scanf(" %[^\n]", c->cidade);

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

// 5. Função para exibir menu dinâmico
int exibir_menu_dinamico(int atributo_excluido)
{
    int opcao;

    printf("\n========================================\n");
    printf("        MENU DE COMPARAÇÃO\n");
    printf("========================================\n");
    printf("Escolha o atributo para comparar:\n\n");

    // Exibe apenas os atributos que não foram escolhidos
    (atributo_excluido != 1) ? printf("1 - População\n") : printf("");
    (atributo_excluido != 2) ? printf("2 - Área\n") : printf("");
    (atributo_excluido != 3) ? printf("3 - PIB\n") : printf("");
    (atributo_excluido != 4) ? printf("4 - Pontos Turísticos\n") : printf("");
    (atributo_excluido != 5) ? printf("5 - Densidade Populacional\n") : printf("");
    (atributo_excluido != 6) ? printf("6 - PIB per Capita\n") : printf("");
    (atributo_excluido != 7) ? printf("7 - Super Poder\n") : printf("");

    printf("0 - Sair\n");
    printf("========================================\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

// 6. Função para obter valor do atributo
float obter_valor_atributo(Carta c, int opcao)
{
    switch (opcao)
    {
    case 1:
        return (float)c.populacao;
    case 2:
        return c.area;
    case 3:
        return c.pib;
    case 4:
        return (float)c.pontos;
    case 5:
        return c.densidade;
    case 6:
        return c.pib_per_capita;
    case 7:
        return c.super_poder;
    default:
        return 0;
    }
}

// 7. Função para obter nome do atributo
void obter_nome_atributo(int opcao, char *nome)
{
    switch (opcao)
    {
    case 1:
        strcpy(nome, "População");
        break;
    case 2:
        strcpy(nome, "Área");
        break;
    case 3:
        strcpy(nome, "PIB");
        break;
    case 4:
        strcpy(nome, "Pontos Turísticos");
        break;
    case 5:
        strcpy(nome, "Densidade Populacional");
        break;
    case 6:
        strcpy(nome, "PIB per Capita");
        break;
    case 7:
        strcpy(nome, "Super Poder");
        break;
    default:
        strcpy(nome, "Desconhecido");
        break;
    }
}

// 8. Função para exibir valor formatado do atributo
void exibir_valor_atributo(Carta c, int opcao)
{
    switch (opcao)
    {
    case 1:
        printf("%lu habitantes", c.populacao);
        break;
    case 2:
        printf("%.2f km²", c.area);
        break;
    case 3:
        printf("R$ %.2f bilhões", c.pib);
        break;
    case 4:
        printf("%d pontos turísticos", c.pontos);
        break;
    case 5:
        printf("%.2f hab/km²", c.densidade);
        break;
    case 6:
        printf("R$ %.2f", c.pib_per_capita);
        break;
    case 7:
        printf("%.2f", c.super_poder);
        break;
    default:
        printf("N/A");
        break;
    }
}

// 9. Função para verificar se tem regra invertida
int tem_regra_invertida(int opcao)
{
    return (opcao == 5) ? 1 : 0;
}

// 10. Função para comparar um atributo
int comparar_atributo(Carta c1, Carta c2, int opcao)
{
    float valor1 = obter_valor_atributo(c1, opcao);
    float valor2 = obter_valor_atributo(c2, opcao);
    int regra_invertida = tem_regra_invertida(opcao);

    if (regra_invertida)
    {
        return (valor1 < valor2) ? 1 : (valor1 > valor2) ? 2
                                                         : 0;
    }
    else
    {
        return (valor1 > valor2) ? 1 : (valor1 < valor2) ? 2
                                                         : 0;
    }
}

// 11. Função de comparação avançada com dois atributos
void comparar_cartas_avancado(Carta c1, Carta c2, int atributo1, int atributo2)
{
    char nome_atributo1[30], nome_atributo2[30];
    float valor1_carta1, valor2_carta1, valor1_carta2, valor2_carta2;
    float soma_carta1, soma_carta2;
    int vencedor_atributo1, vencedor_atributo2, vencedor_final;

    // Obtém informações dos atributos
    obter_nome_atributo(atributo1, nome_atributo1);
    obter_nome_atributo(atributo2, nome_atributo2);
    valor1_carta1 = obter_valor_atributo(c1, atributo1);
    valor2_carta1 = obter_valor_atributo(c1, atributo2);
    valor1_carta2 = obter_valor_atributo(c2, atributo1);
    valor2_carta2 = obter_valor_atributo(c2, atributo2);

    // Calcula as somas
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    // Compara cada atributo
    vencedor_atributo1 = comparar_atributo(c1, c2, atributo1);
    vencedor_atributo2 = comparar_atributo(c1, c2, atributo2);
    vencedor_final = (soma_carta1 > soma_carta2) ? 1 : (soma_carta1 < soma_carta2) ? 2
                                                                                   : 0;

    // Exibe resultados
    printf("\n========================================\n");
    printf("   COMPARAÇÃO AVANÇADA DE CARTAS\n");
    printf("========================================\n");
    printf("Atributos: %s e %s\n", nome_atributo1, nome_atributo2);
    printf("========================================\n\n");

    // Primeiro atributo
    printf(">>> %s %s:\n", nome_atributo1, tem_regra_invertida(atributo1) ? "(menor vence)" : "(maior vence)");
    printf("Carta 1 - %s (%s): ", c1.cidade, c1.estado);
    exibir_valor_atributo(c1, atributo1);
    printf("\nCarta 2 - %s (%s): ", c2.cidade, c2.estado);
    exibir_valor_atributo(c2, atributo1);
    printf("\nResultado: %s\n",
           (vencedor_atributo1 == 1) ? "Carta 1 venceu!" : (vencedor_atributo1 == 2) ? "Carta 2 venceu!"
                                                                                     : "Empate!");

    printf("\n----------------------------------------\n\n");

    // Segundo atributo
    printf(">>> %s %s:\n", nome_atributo2, tem_regra_invertida(atributo2) ? "(menor vence)" : "(maior vence)");
    printf("Carta 1 - %s (%s): ", c1.cidade, c1.estado);
    exibir_valor_atributo(c1, atributo2);
    printf("\nCarta 2 - %s (%s): ", c2.cidade, c2.estado);
    exibir_valor_atributo(c2, atributo2);
    printf("\nResultado: %s\n",
           (vencedor_atributo2 == 1) ? "Carta 1 venceu!" : (vencedor_atributo2 == 2) ? "Carta 2 venceu!"
                                                                                     : "Empate!");

    // Resultado final
    printf("\n========================================\n");
    printf("   RESULTADO FINAL (SOMA)\n");
    printf("========================================\n");
    printf("Carta 1 - %s: %.2f + %.2f = %.2f\n", c1.cidade, valor1_carta1, valor2_carta1, soma_carta1);
    printf("Carta 2 - %s: %.2f + %.2f = %.2f\n", c2.cidade, valor1_carta2, valor2_carta2, soma_carta2);
    printf("\n----------------------------------------\n");

    if (vencedor_final == 1)
    {
        printf("🏆 VENCEDOR FINAL: Carta 1 - %s\n", c1.cidade);
        printf("   (Soma: %.2f > %.2f)\n", soma_carta1, soma_carta2);
    }
    else if (vencedor_final == 2)
    {
        printf("🏆 VENCEDOR FINAL: Carta 2 - %s\n", c2.cidade);
        printf("   (Soma: %.2f > %.2f)\n", soma_carta2, soma_carta1);
    }
    else
    {
        printf("🤝 EMPATE! Ambas as cartas têm a mesma soma.\n");
        printf("   (Soma: %.2f = %.2f)\n", soma_carta1, soma_carta2);
    }

    printf("========================================\n");
}

// FUNÇÃO PRINCIPAL
int main()
{
    // Definição das variáveis para armazenar as propriedades das cidades
    Carta carta1, carta2;
    int continuar = 1;
    int atributo1, atributo2;
    int opcao_valida;

    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   SUPER TRUNFO - CIDADES DO BRASIL    ║\n");
    printf("║    COMPARAÇÃO AVANÇADA DE CARTAS      ║\n");
    printf("╚════════════════════════════════════════╝\n");

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    printf("\n>>> Vamos cadastrar as cartas!\n");

    // Carta 1
    ler_dados_carta(&carta1, 1);
    calcular_atributos(&carta1);

    // Carta 2
    ler_dados_carta(&carta2, 2);
    calcular_atributos(&carta2);

    // Exibição das cartas cadastradas
    printf("\n========================================\n");
    printf("   CARTAS CADASTRADAS COM SUCESSO!\n");
    printf("========================================\n");

    exibir_dados_carta(carta1, 1);
    exibir_dados_carta(carta2, 2);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas
    while (continuar)
    {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║      NOVA RODADA DE COMPARAÇÃO        ║\n");
        printf("╚════════════════════════════════════════╝\n");

        // Escolha do primeiro atributo
        opcao_valida = 0;
        while (!opcao_valida)
        {
            printf("\n>>> Escolha o PRIMEIRO atributo:\n");
            atributo1 = exibir_menu_dinamico(-1);

            switch (atributo1)
            {
            case 0:
                printf("\n========================================\n");
                printf("  Obrigado por jogar Super Trunfo!\n");
                printf("         Até a próxima!\n");
                printf("========================================\n\n");
                return 0;

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                opcao_valida = 1;
                break;

            default:
                printf("\n========================================\n");
                printf("Opção inválida! Tente novamente.\n");
                printf("========================================\n");
                break;
            }
        }

        // Escolha do segundo atributo (diferente do primeiro)
        opcao_valida = 0;
        while (!opcao_valida)
        {
            printf("\n>>> Escolha o SEGUNDO atributo (diferente do primeiro):\n");
            atributo2 = exibir_menu_dinamico(atributo1);

            switch (atributo2)
            {
            case 0:
                printf("\n========================================\n");
                printf("  Obrigado por jogar Super Trunfo!\n");
                printf("         Até a próxima!\n");
                printf("========================================\n\n");
                return 0;

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                if (atributo2 == atributo1)
                {
                    printf("\n========================================\n");
                    printf("Erro: Escolha um atributo diferente!\n");
                    printf("========================================\n");
                }
                else
                {
                    opcao_valida = 1;
                }
                break;

            default:
                printf("\n========================================\n");
                printf("Opção inválida! Tente novamente.\n");
                printf("========================================\n");
                break;
            }
        }

        // Exibição dos Resultados:
        // Após realizar as comparações, exiba os resultados para o usuário
        comparar_cartas_avancado(carta1, carta2, atributo1, atributo2);

        // Pergunta se deseja continuar
        printf("\nDeseja fazer outra comparação? (1-Sim / 0-Não): ");
        scanf("%d", &continuar);
        continuar = (continuar == 1) ? 1 : 0;

        if (!continuar)
        {
            printf("\n========================================\n");
            printf("  Obrigado por jogar Super Trunfo!\n");
            printf("         Até a próxima!\n");
            printf("========================================\n\n");
        }
    }

    return 0;
}