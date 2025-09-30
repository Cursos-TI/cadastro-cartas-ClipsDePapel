#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica; // populacao / area
} Carta;

// Função auxiliar para imprimir o menu
void exibirMenu(int excluir) {
    printf("\nEscolha um atributo para comparacao:\n");
    if (excluir != 1) printf("1 - Populacao\n");
    if (excluir != 2) printf("2 - Area\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turisticos\n");
    if (excluir != 5) printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
}

// Função para pegar valor de um atributo específico
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Função para imprimir nome do atributo
void nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turisticos"); break;
        case 5: printf("Densidade Demografica"); break;
    }
}

int main() {
    // --- Cadastro das cartas ---
    Carta carta1, carta2;

    strcpy(carta1.nome, "Brasil");
    carta1.populacao = 213000000;
    carta1.area = 8515767.0;
    carta1.pib = 2200000000000.0;
    carta1.pontosTuristicos = 45;
    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;

    strcpy(carta2.nome, "Argentina");
    carta2.populacao = 45000000;
    carta2.area = 2780400.0;
    carta2.pib = 500000000000.0;
    carta2.pontosTuristicos = 30;
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    int atributo1, atributo2;

    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n");

    // --- Escolha do primeiro atributo ---
    exibirMenu(0);
    scanf("%d", &atributo1);

    // --- Escolha do segundo atributo (dinâmico, exclui o primeiro) ---
    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    // --- Comparação de atributos ---
    float valor1_c1 = obterValor(carta1, atributo1);
    float valor1_c2 = obterValor(carta2, atributo1);
    float valor2_c1 = obterValor(carta1, atributo2);
    float valor2_c2 = obterValor(carta2, atributo2);

    printf("\nComparacao entre %s e %s\n", carta1.nome, carta2.nome);

    // Exibe primeiro atributo
    printf("\nAtributo 1: ");
    nomeAtributo(atributo1);
    printf("\n%s: %.2f\n", carta1.nome, valor1_c1);
    printf("%s: %.2f\n", carta2.nome, valor1_c2);

    // Operador ternário para regra da densidade
    int vitoria1 = (atributo1 == 5) 
                    ? (valor1_c1 < valor1_c2) 
                    : (valor1_c1 > valor1_c2);

    printf("Vencedor do atributo 1: %s\n",
           (valor1_c1 == valor1_c2) ? "Empate" : (vitoria1 ? carta1.nome : carta2.nome));

    // Exibe segundo atributo
    printf("\nAtributo 2: ");
    nomeAtributo(atributo2);
    printf("\n%s: %.2f\n", carta1.nome, valor2_c1);
    printf("%s: %.2f\n", carta2.nome, valor2_c2);

    int vitoria2 = (atributo2 == 5) 
                    ? (valor2_c1 < valor2_c2) 
                    : (valor2_c1 > valor2_c2);

    printf("Vencedor do atributo 2: %s\n",
           (valor2_c1 == valor2_c2) ? "Empate" : (vitoria2 ? carta1.nome : carta2.nome));

    // --- Soma dos atributos ---
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma_c1);
    printf("%s: %.2f\n", carta2.nome, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("Resultado final: %s venceu!\n", carta1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("Resultado final: %s venceu!\n", carta2.nome);
    } else {
        printf("Resultado final: Empate!\n");
    }

    return 0;
}
