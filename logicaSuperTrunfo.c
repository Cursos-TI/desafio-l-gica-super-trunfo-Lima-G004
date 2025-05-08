#include <stdio.h>
#include <string.h>

// Definição da estrutura de uma carta (país)
typedef struct {
    char nome[30];
    int populacao;              // milhões
    int area;                   // mil km²
    int densidade;              // hab/km²
    int pib;                    // bilhões de dólares
} Carta;

// Função para exibir os atributos disponíveis
void mostrarAtributosDisponiveis(int escolhido1) {
    printf("Escolha um atributo:\n");
    if (escolhido1 != 1) printf("1. Populacao\n");
    if (escolhido1 != 2) printf("2. Area\n");
    if (escolhido1 != 3) printf("3. Densidade Demografica\n");
    if (escolhido1 != 4) printf("4. PIB\n");
}

// Função para obter o valor de um atributo de uma carta
int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        default: return -1;
    }
}

// Nome do atributo como string
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "Densidade Demografica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta cartas[] = {
        {"Brasil", 213, 8516, 25, 1440},
        {"Japao", 125, 378, 330, 5060},
        {"Estados Unidos", 331, 9834, 36, 21400},
        {"India", 1380, 3287, 420, 2875},
        {"Canada", 38, 9985, 4, 1800},
        {"Russia", 146, 17098, 9, 1700},
        {"Alemanha", 83, 357, 233, 4200},
        {"Franca", 67, 643, 104, 3000},
        {"Reino Unido", 68, 243, 280, 3200},
        {"China", 1440, 9597, 153, 14700}
    };
    int totalCartas = sizeof(cartas) / sizeof(Carta);

    // Listar as cartas disponíveis
    printf("Cartas disponíveis:\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("%d. %s\n", i + 1, cartas[i].nome);
    }

    int escolha1, escolha2;
    do {
        printf("\nEscolha o número da primeira carta: ");
        scanf("%d", &escolha1);
        printf("Escolha o número da segunda carta: ");
        scanf("%d", &escolha2);

        if (escolha1 < 1 || escolha1 > totalCartas || escolha2 < 1 || escolha2 > totalCartas || escolha1 == escolha2) {
            printf("Escolhas inválidas. Tente novamente.\n");
        }
    } while (escolha1 < 1 || escolha1 > totalCartas || escolha2 < 1 || escolha2 > totalCartas || escolha1 == escolha2);

    Carta carta1 = cartas[escolha1 - 1];
    Carta carta2 = cartas[escolha2 - 1];

    int atributo1, atributo2;

    printf("\nComparacao de Cartas entre %s e %s!\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    do {
        mostrarAtributosDisponiveis(0);
        printf("Digite o numero do primeiro atributo: ");
        scanf("%d", &atributo1);

        if (atributo1 < 1 || atributo1 > 4) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 4);

    // Escolha do segundo atributo
    do {
        mostrarAtributosDisponiveis(atributo1);
        printf("Digite o numero do segundo atributo: ");
        scanf("%d", &atributo2);

        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);

    // Obter valores dos atributos
    int valor1_c1 = obterValorAtributo(carta1, atributo1);
    int valor2_c1 = obterValorAtributo(carta1, atributo2);
    int valor1_c2 = obterValorAtributo(carta2, atributo1);
    int valor2_c2 = obterValorAtributo(carta2, atributo2);

    // Comparar individualmente
    int pontos_c1 = 0, pontos_c2 = 0;

    for (int i = 0; i < 2; i++) {
        int atr = (i == 0) ? atributo1 : atributo2;
        int v1 = (i == 0) ? valor1_c1 : valor2_c1;
        int v2 = (i == 0) ? valor1_c2 : valor2_c2;

        // Regra da densidade: menor vence, demais: maior vence
        if (atr == 3) {
            if (v1 < v2) pontos_c1++;
            else if (v2 < v1) pontos_c2++;
        } else {
            if (v1 > v2) pontos_c1++;
            else if (v2 > v1) pontos_c2++;
        }
    }

    // Soma total dos atributos
    int soma_c1 = valor1_c1 + valor2_c1;
    int soma_c2 = valor1_c2 + valor2_c2;

    // Exibição dos resultados
    printf("\n--- Resultado da Comparacao ---\n");
    printf("Pais 1: %s\n", carta1.nome);
    printf(" - %s: %d\n", nomeAtributo(atributo1), valor1_c1);
    printf(" - %s: %d\n", nomeAtributo(atributo2), valor2_c1);
    printf(" - Soma: %d\n", soma_c1);

    printf("Pais 2: %s\n", carta2.nome);
    printf(" - %s: %d\n", nomeAtributo(atributo1), valor1_c2);
    printf(" - %s: %d\n", nomeAtributo(atributo2), valor2_c2);
    printf(" - Soma: %d\n", soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\nVencedor: %s!\n", carta1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedor: %s!\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
