#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // === 1. Inicialização do Tabuleiro ===
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche todas as posições com 0 (representa água)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // === 2. Navios (vetores unidimensionais) ===
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3}; // 3 representa navio
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // === 3. Coordenadas iniciais (pré-definidas no código) ===
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // === 4. Validação de limites e sobreposição ===

    // Validação do navio horizontal
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }
        } else {
            printf("Erro: Sobreposição no navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Validação do navio vertical
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: Sobreposição no navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // === 5. Impressão do tabuleiro ===
    printf("\n=== Tabuleiro de Batalha Naval ===\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
