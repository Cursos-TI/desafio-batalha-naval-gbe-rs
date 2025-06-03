#include <stdio.h>
#include <stdlib.h>

// Constantes
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define TAMANHO_NAVIO 3
#define HABILIDADE 5
#define TAM_HABILIDADE 5
#define TAM_OCTA_LIN 3
#define TAM_OCTA_COL 5

// Funções para preencher as matrizes de habilidade
void preencherCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i <= 2) {
                matriz[i][j] = (j >= 2 - i && j <= 2 + i) ? 1 : 0;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void preencherCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void preencherOctaedro(int matriz[TAM_OCTA_LIN][TAM_OCTA_COL]) {
    // Octaedro (losango): visual centralizado
    int shape[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < TAM_OCTA_LIN; i++) {
        for (int j = 0; j < TAM_OCTA_COL; j++) {
            matriz[i][j] = shape[i][j];
        }
    }
}

/* APLICAR HABILIDADE: Esta função aplica uma matriz de habilidade ao tabuleiro,
 centralizando-a no ponto de origem (centroLinha, centroColuna).
 Apenas as posições com valor 1 na matriz são aplicadas,
 e só substitui posições com valor AGUA. */
void aplicarHabilidade(int linhas, int colunas, int matriz[linhas][colunas], int centroLinha, int centroColuna, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int meioLinha = linhas / 2;
    int meioColuna = colunas / 2;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int linhaTab = centroLinha - meioLinha + i;
            int colunaTab = centroColuna - meioColuna + j;

            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO && colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {
                if (matriz[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA) {
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    //Declaração de Variáveis
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_OCTA_LIN][TAM_OCTA_COL];

    // Cria o tabuleiro e inicializa com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int valido;

    // Navio 1 - Horizontal
    int linhaNavio1 = 0, colunaNavio1 = 4;
    valido = 1; // Reseta a flag
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
    int linhaNavio2 = 3, colunaNavio2 = 9;
    valido = 1; // Reseta a flag
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
    valido = 1; // Reseta a flag
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

    // Navio 4 - Diagonal
    int linhaNavio4 = 0, colunaNavio4 = 9;
    valido = 1; // Reseta a flag
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

    // Preenche habilidades
    preencherCone(cone);
    preencherCruz(cruz);
    preencherOctaedro(octaedro);

    // Aplica habilidades
    aplicarHabilidade(TAM_HABILIDADE, TAM_HABILIDADE, cone, 8, 7, tabuleiro);
    aplicarHabilidade(TAM_HABILIDADE, TAM_HABILIDADE, cruz, 4, 4, tabuleiro);
    aplicarHabilidade(TAM_OCTA_LIN, TAM_OCTA_COL, octaedro, 8, 2, tabuleiro);

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval:\n");
    printf("Legenda: %d = água, %d = navio, %d = habilidade especial\n\n", AGUA, NAVIO, HABILIDADE);
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}