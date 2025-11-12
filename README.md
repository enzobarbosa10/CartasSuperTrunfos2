# 🏆 Super Trunfo - Cidades do Brasil

Um projeto de jogo de cartas Super Trunfo desenvolvido em linguagem C, focado em cidades brasileiras. O projeto faz parte da disciplina de **Introdução à Programação de Computadores** do curso de Estácio.

## 📋 Sobre o Projeto

Este projeto implementa um sistema de comparação de cartas temáticas sobre cidades brasileiras, onde cada carta contém informações como população, área, PIB, pontos turísticos e outros atributos derivados. O objetivo é criar um jogo interativo que permite comparar duas cartas e determinar a vencedora baseada em critérios específicos.

## 🎮 Funcionalidades

### Versão Básica (SuperTrunfo.c)
- ✅ Cadastro de duas cartas com dados de cidades
- ✅ Entrada e exibição de informações básicas
- ✅ Interface simples de console

### Versão Completa (SuperTrunfo7.c)
- ✅ Sistema completo de cadastro de cartas
- ✅ Cálculo automático de atributos derivados
- ✅ Comparação avançada com dois atributos simultâneos
- ✅ Interface interativa com menu dinâmico
- ✅ Sistema de pontuação e determinação de vencedor
- ✅ Múltiplas rodadas de comparação

## 📊 Atributos das Cartas

### Atributos Básicos
- **Estado**: Sigla do estado (ex: SP, RJ)
- **Código**: Identificador da carta (ex: A01, B02)
- **Cidade**: Nome da cidade
- **População**: Número de habitantes
- **Área**: Área em km²
- **PIB**: Produto Interno Bruto em bilhões de reais
- **Pontos Turísticos**: Quantidade de pontos turísticos

### Atributos Calculados
- **Densidade Populacional**: População ÷ Área (hab/km²)
- **PIB per Capita**: PIB ÷ População (R$ por habitante)
- **Super Poder**: Fórmula complexa que combina todos os atributos

## 🎯 Regras do Jogo

### Critérios de Vitória
- **Maior vence**: População, Área, PIB, Pontos Turísticos, PIB per Capita, Super Poder
- **Menor vence**: Densidade Populacional (cidades menos densas são mais "habitáveis")

### Sistema de Comparação Avançada
1. O jogador escolhe dois atributos diferentes
2. As cartas são comparadas em cada atributo
3. O resultado final é determinado pela soma dos valores dos dois atributos
4. A carta com maior soma é declarada vencedora

## 🚀 Como Executar

### Pré-requisitos
- Compilador C (GCC, MinGW, Visual Studio, etc.)
- Sistema operacional Windows/Linux/Mac

### Compilação e Execução

#### Versão Básica
```bash
gcc SuperTrunfo.c -o SuperTrunfo
./SuperTrunfo
```

#### Versão Completa
```bash
gcc SuperTrunfo7.c -o SuperTrunfo7
./SuperTrunfo7
```

### Para Windows (PowerShell)
```powershell
gcc SuperTrunfo7.c -o SuperTrunfo7.exe
./SuperTrunfo7.exe
```

## 🔄 Evolução do Projeto

O projeto foi desenvolvido de forma incremental através de várias versões:

- **SuperTrunfo.c**: Versão inicial básica
- **SuperTrunfo2.c - SuperTrunfo6.c**: Versões intermediárias com funcionalidades incrementais
- **SuperTrunfo7.c**: Versão final completa com todas as funcionalidades

## 📁 Estrutura do Projeto

```
CartasSuperTrunfos2/
├── README.md                 # Este arquivo
├── SuperTrunfo.c            # Versão básica
├── SuperTrunfo2.c           # Versão incremental 2
├── SuperTrunfo3.c           # Versão incremental 3
├── SuperTrunfo4.c           # Versão incremental 4
├── SuperTrunfo5.c           # Versão incremental 5
├── SuperTrunfo6.c           # Versão incremental 6
├── SuperTrunfo7.c           # Versão final completa
├── Fluxograma              # Documentação do fluxo do programa
└── Pseudocódigo            # Pseudocódigo do algoritmo
```

## 🎯 Exemplo de Uso

```
========================================
   SUPER TRUNFO - CIDADES DO BRASIL
   COMPARAÇÃO AVANÇADA DE CARTAS
========================================

>>> Vamos cadastrar as cartas!

Digite o estado (ex: SP, RJ): SP
Digite o código da carta (ex: A01): A01
Digite o nome da cidade: São Paulo
Digite a população: 12325232
Digite a área (em km²): 1521.11
Digite o PIB (em bilhões de reais): 875.50
Digite o número de pontos turísticos: 150

>>> Escolha o PRIMEIRO atributo:
1 - População
2 - Área
3 - PIB
...

🏆 VENCEDOR FINAL: Carta 1 - São Paulo
   (Soma: 12325232.00 > 8500000.00)
```

## 🎓 Conceitos Aprendidos

- **Estruturas de dados**: Uso de `struct` para organizar dados
- **Funções**: Modularização do código
- **Ponteiros**: Passagem de parâmetros por referência
- **Arrays de caracteres**: Manipulação de strings
- **Entrada/Saída formatada**: `scanf` e `printf`
- **Lógica de programação**: Estruturas condicionais e loops
- **Cálculos matemáticos**: Operações com diferentes tipos de dados

## 👨‍💻 Autor

**Enzo Barbosa**  
Estudante de Estácio - 1º Semestre de 2025  
Disciplina: Introdução à Programação de Computadores

## 📝 Licença

Este projeto é desenvolvido para fins educacionais como parte do curso de graduação.

---

*Projeto desenvolvido como parte do aprendizado em programação C - Estácio 2025*