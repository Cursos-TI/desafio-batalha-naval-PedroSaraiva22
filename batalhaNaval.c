#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define TAM 10

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal (linha 1, colunas 0 a 3)
    for (int j = 0; j < 4; j++) {
        tabuleiro[1][j] = 3;
    }

    // Navio vertical (coluna 6, linhas 2 a 5)
    for (int i = 2; i < 6; i++) {
        tabuleiro[i][6] = 3;
    }

    // Navio diagonal principal (do canto superior esquerdo)
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio diagonal secundária (do canto superior direito)
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][TAM - 1 - i] = 3;
    }
}

void habilidadeCone(int matriz[5][5]) {
    int centro = 2;
    limparTabuleiro(matriz);
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            matriz[i][j] = 1;
        }
    }
}

void habilidadeCruz(int matriz[5][5]) {
    limparTabuleiro(matriz);
    for (int i = 0; i < 5; i++) {
        matriz[2][i] = 1; // linha do meio
        matriz[i][2] = 1; // coluna do meio
    }
}

void habilidadeOctaedro(int matriz[5][5]) {
    limparTabuleiro(matriz);
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                matriz[i][j] = 1;
            }
        }
    }
}


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

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
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    printf("=== Posicionamento dos Navios ===\n");
    posicionarNavios(tabuleiro);
    exibirTabuleiro(tabuleiro);

    printf("\n=== Habilidade: Cone ===\n");
    int cone[5][5];
    habilidadeCone(cone);
    exibirTabuleiro(cone);

    printf("\n=== Habilidade: Cruz ===\n");
    int cruz[5][5];
    habilidadeCruz(cruz);
    exibirTabuleiro(cruz);

    printf("\n=== Habilidade: Octaedro ===\n");
    int octaedro[5][5];
    habilidadeOctaedro(octaedro);
    exibirTabuleiro(octaedro);

    return 0;
}
