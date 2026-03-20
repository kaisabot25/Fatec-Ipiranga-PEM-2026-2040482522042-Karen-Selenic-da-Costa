/**-------------------------------------------*
*                 XEQUE PASTOR               *
* Karen Selenic da Costa   2040482522042     *
* Segundo Semestre ADS Vespertino - PEM      *
  *------------------------------------------*/
#include <stdio.h>
#include <string.h>

// Define tabuleiro como 8x8 com valor (peças) armazenado em 4 dessas linhas
char tabuleiro[8][8][4];

// Limpa a tela imprimindo várias linhas vazias
void limparTela() {
    int i;
    for(i = 0; i < 30; i++) {
        printf("\n");
    }
}

// Espera o usuário apertar ENTER
void esperarEnter() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Inicializa o tabuleiro
void inicializarTabuleiro() {
    int i, j;
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            strcpy(tabuleiro[i][j], "...");
        }
    }

    // Representa os peões
    for(j = 0; j < 8; j++) {
        sprintf(tabuleiro[1][j], "PP%d", j+1);
        sprintf(tabuleiro[6][j], "PB%d", j+1);
    }

    // Representa as torres
    strcpy(tabuleiro[0][0], "TP1"); strcpy(tabuleiro[0][7], "TP2");
    strcpy(tabuleiro[7][0], "TB1"); strcpy(tabuleiro[7][7], "TB2");

    // Representa os cavalos
    strcpy(tabuleiro[0][1], "CP1"); strcpy(tabuleiro[0][6], "CP2");
    strcpy(tabuleiro[7][1], "CB1"); strcpy(tabuleiro[7][6], "CB2");

    // Representa os bispos
    strcpy(tabuleiro[0][2], "BP1"); strcpy(tabuleiro[0][5], "BP2");
    strcpy(tabuleiro[7][2], "BB1"); strcpy(tabuleiro[7][5], "BB2");

    // Damas
    strcpy(tabuleiro[0][3], "DP ");
    strcpy(tabuleiro[7][3], "DB ");

    // Reis
    strcpy(tabuleiro[0][4], "RP ");
    strcpy(tabuleiro[7][4], "RB ");
}

// Mostra tabuleiro
void imprimirTabuleiro() {
    int i, j;
    printf("\n    a   b   c   d   e   f   g   h\n\n");
    for(i = 0; i < 8; i++) {
        printf("%d  ", 8 - i);
        for(j = 0; j < 8; j++) {
            printf("%-4s", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Realiza jogada
void realizarJogada(int linOrigem, int colOrigem, int linDestino, int colDestino, char descricao[]) {
    limparTela();
    printf("\n%s\n", descricao);
    strcpy(tabuleiro[linDestino][colDestino], tabuleiro[linOrigem][colOrigem]);
    strcpy(tabuleiro[linOrigem][colOrigem], "...");
    imprimirTabuleiro();
    esperarEnter();
}

int main() {
    inicializarTabuleiro();
    printf("======== TABULEIRO INICIAL ========\n");
    imprimirTabuleiro();
    esperarEnter();

    // Jogada 1
    realizarJogada(6, 4, 4, 4, "Brancas jogam peão e2 para e4");
    realizarJogada(1, 4, 3, 4, "Pretas jogam peão e7 para e5");

    // Jogada 2
    realizarJogada(7, 5, 4, 2, "Brancas jogam bispo f1 para c4");
    realizarJogada(0, 1, 2, 2, "Pretas jogam cavalo b8 para c6");

    // Jogada 3
    realizarJogada(7, 3, 3, 7, "Brancas jogam dama d1 para h5");
    realizarJogada(0, 6, 2, 5, "Pretas jogam cavalo g8 para f6");

    // Jogada 4 (Xeque Mate)
    realizarJogada(3, 7, 1, 5, "======== XEQUE MATE! Dxf7 ========");

    limparTela();
    printf("\nXEQUE PASTOR CONCLUÍDO\n");
    return 0;
}