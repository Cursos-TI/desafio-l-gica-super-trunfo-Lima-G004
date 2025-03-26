#include <stdio.h>

int main() {
   
    /*CADASTRO DA CARTA 1*/
    char estado[50];
    char codigo_da_carta[15];
    char nome_da_cidade[40];
    signed long int populacao;  // Alterado para signed long int
    float area;
    float pib;
    int pontos_turisticos; 
    float densidade;  // Declarando a variável sem valor inicial
    float pib_per_capita;  // Declarando a variável sem valor inicial
    float super_poder_1;  // Variável para armazenar o super poder da Carta 1

    // DADOS CARTA 1
    printf("Digite o Estado:\n");
    scanf("%s", estado);

    printf("Digite o código da carta:\n");
    scanf("%s", codigo_da_carta);

    printf("Digite o nome da Cidade:\n");
    scanf("%s", nome_da_cidade);

    printf("População: \n");
    scanf("%ld", &populacao);  // Alterado para %ld para ler signed long int

    printf("Área: \n");
    scanf("%f", &area);

    printf("PIB: \n");
    scanf("%f", &pib);

    printf("Pontos turísticos: \n");
    scanf("%d", &pontos_turisticos);

    // Calculando a densidade populacional e o PIB per capita
    densidade = (float)populacao / area;  // Cast para garantir que a divisão seja feita corretamente
    pib_per_capita = pib / populacao;

    // Calculando o Super Poder da Carta 1 (soma de todos os atributos numéricos)
    super_poder_1 = (float)populacao + area + pib + pontos_turisticos + densidade + pib_per_capita;

    /*CADASTRO DA CARTA 2*/
    char estado2[30];
    char codigo_da_carta2[15];
    char nome_da_cidade2[30];
    signed long int populacao2;  // Alterado para signed long int
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;  // Declarando a variável sem valor inicial
    float pib_per_capita2;  // Declarando a variável sem valor inicial
    float super_poder_2;  // Variável para armazenar o super poder da Carta 2

    // DADOS CARTA 2
    printf("Digite o Estado: \n");
    scanf("%s", estado2);

    printf("Digite o código da carta: \n");
    scanf("%s", codigo_da_carta2);

    printf("Digite o nome da Cidade: \n");
    scanf("%s", nome_da_cidade2);

    printf("População: \n");
    scanf("%ld", &populacao2);  // Alterado para %ld para ler signed long int

    printf("Área: \n");
    scanf("%f", &area2);

    printf("PIB: \n");
    scanf("%f", &pib2);

    printf("Pontos turísticos: \n");
    scanf("%d", &pontos_turisticos2);

    // Calculando a densidade populacional e o PIB per capita
    densidade2 = (float)populacao2 / area2;  // Cast para garantir que a divisão seja feita corretamente
    pib_per_capita2 = pib2 / populacao2;

    // Calculando o Super Poder da Carta 2 (soma de todos os atributos numéricos)
    super_poder_2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + densidade2 + pib_per_capita2;

    // Variáveis para contar as vitórias
    int vitorias_carta1 = 0, vitorias_carta2 = 0;

    // Comparações entre os atributos das duas cartas
    printf("\nComparações entre os Atributos das Cartas:\n");

    // Comparando População
    if (populacao > populacao2) {
        printf("Carta 1 vence por ter maior População: %ld\n", populacao);
        vitorias_carta1++;
    } else if (populacao < populacao2) {
        printf("Carta 2 vence por ter maior População: %ld\n", populacao2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm a mesma População: %ld\n", populacao);
    }

    // Comparando Área
    if (area > area2) {
        printf("Carta 1 vence por ter maior Área: %.2f\n", area);
        vitorias_carta1++;
    } else if (area < area2) {
        printf("Carta 2 vence por ter maior Área: %.2f\n", area2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm a mesma Área: %.2f\n", area);
    }

    // Comparando PIB
    if (pib > pib2) {
        printf("Carta 1 vence por ter maior PIB: %.2f\n", pib);
        vitorias_carta1++;
    } else if (pib < pib2) {
        printf("Carta 2 vence por ter maior PIB: %.2f\n", pib2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm o mesmo PIB: %.2f\n", pib);
    }

    // Comparando Pontos Turísticos
    if (pontos_turisticos > pontos_turisticos2) {
        printf("Carta 1 vence por ter mais Pontos Turísticos: %d\n", pontos_turisticos);
        vitorias_carta1++;
    } else if (pontos_turisticos < pontos_turisticos2) {
        printf("Carta 2 vence por ter mais Pontos Turísticos: %d\n", pontos_turisticos2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm o mesmo número de Pontos Turísticos: %d\n", pontos_turisticos);
    }

    // Comparando Densidade Populacional (menor vence)
    if (densidade < densidade2) {
        printf("Carta 1 vence por ter menor Densidade Populacional: %.2f\n", densidade);
        vitorias_carta1++;
    } else if (densidade > densidade2) {
        printf("Carta 2 vence por ter menor Densidade Populacional: %.2f\n", densidade2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm a mesma Densidade Populacional: %.2f\n", densidade);
    }

    // Comparando PIB per Capita
    if (pib_per_capita > pib_per_capita2) {
        printf("Carta 1 vence por ter maior PIB per Capita: %.2f\n", pib_per_capita);
        vitorias_carta1++;
    } else if (pib_per_capita < pib_per_capita2) {
        printf("Carta 2 vence por ter maior PIB per Capita: %.2f\n", pib_per_capita2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm o mesmo PIB per Capita: %.2f\n", pib_per_capita);
    }

    // Comparando Super Poder
    if (super_poder_1 > super_poder_2) {
        printf("Carta 1 vence por ter maior Super Poder: %.2f\n", super_poder_1);
        vitorias_carta1++;
    } else if (super_poder_1 < super_poder_2) {
        printf("Carta 2 vence por ter maior Super Poder: %.2f\n", super_poder_2);
        vitorias_carta2++;
    } else {
        printf("Ambas as cartas têm o mesmo Super Poder: %.2f\n", super_poder_1);
    }

    // Exibindo a carta vencedora
    if (vitorias_carta1 > vitorias_carta2) {
        printf("\nA Carta 1 venceu com %d vitórias!\n", vitorias_carta1);
    } else if (vitorias_carta1 < vitorias_carta2) {
        printf("\nA Carta 2 venceu com %d vitórias!\n", vitorias_carta2);
    } else {
        printf("\nAs duas cartas empataram com %d vitórias cada!\n", vitorias_carta1);
    }

    return 0;
}

