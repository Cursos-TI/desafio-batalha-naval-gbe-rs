#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define TAMANHO_NAVIO 3

int main() {
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    
     // Cria o tabuleiro e inicializa com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int valido;

    // Navio 1 - Horizontal 
    int linhaNavio1 = 4, colunaNavio1 = 4;
    valido = 1; // Limpa a flag
    // Verifica os limites do tabuleiro
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se as posições estão livres
            if (tabuleiro[linhaNavio1][colunaNavio1 + i] != AGUA) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                // Posiciona o Navio
                tabuleiro[linhaNavio1][colunaNavio1 + i] = NAVIO;
            }
        }
    }

    // Navio 2 - Vertical 
    int linhaNavio2 = 5, colunaNavio2 = 1;
    valido = 1;
    // Verifica os limites do tabuleiro
    if (linhaNavio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se as posições estão livres
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] != AGUA) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                // Posiciona o Navio
                tabuleiro[linhaNavio2 + i][colunaNavio2] = NAVIO;
            }
        }
    }

    // Navio 3 - Diagonal
    int linhaNavio3 = 0, colunaNavio3 = 0;
    valido = 1;
    // Verifica os limites do tabuleiro
    if (linhaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se as posições estão livres
            if (tabuleiro[linhaNavio3 + i][colunaNavio3 + i] != AGUA) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                // Posiciona o Navio
                tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = NAVIO;
            }
        }
    }

    //Navio 4 - Diagonal
    int linhaNavio4 = 0, colunaNavio4 = 9;
    valido = 1;
    // Verifica os limites do tabuleiro
    if (linhaNavio4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio4 - (TAMANHO_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se as posições estão livres
            if (tabuleiro[linhaNavio4 + i][colunaNavio4 - i] != AGUA) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                // Posiciona o Navio
                tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = NAVIO;
            }
        }
    }
    
    // Exibe o tabuleiro 
    printf("Tabuleiro Batalha Naval (%d = água, %d = navio):\n\n", AGUA, NAVIO);
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

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
