#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios

    // Declaração de variáveis

    // Tamanho fixo 10x10
    int tabuleiro[10][10];
    // Define os navios como vetores unidimensionais
    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical
    // Define coordenadas iniciais
    int linhaNavio1 = 2, colunaNavio1 = 4; // navio horizontal começa na linha 2, coluna 4
    int linhaNavio2 = 5, colunaNavio2 = 1; // navio vertical começa na linha 5, coluna 1

    int valido = 1; // flag para validar se há espaço e não há sobreposição

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    // Valida e posiciona o navio horizontal
    if (colunaNavio1 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaNavio1][colunaNavio1 + i] != 0) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i];
            }
        }
    }

    // Valida e posiciona o navio vertical
    valido = 1; // reseta flag
    if (linhaNavio2 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] != 0) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i];
            }
        }
    }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    // Exibe o tabuleiro para verificar
    printf("Tabuleiro inicializado:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
