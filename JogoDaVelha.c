//Karen Selenic da Costa 2º semestre ADS Vespertino
//Esse é um sistema para jogo da velha de dois jogadores (X e O)
//Este sistema gerencia um tabuleiro de matriz 3x3
//Alterna turnos, valida jogadas e verifica  vitória ou empate

#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdbool.h> //Inclui a biblioteca de booleanos

// Representa espaço vazio
const char vazio = ' ';

// Matriz 3x3 que representa o tabuleiro
char tabuleiro[3][3];

// Jogador atual (começa com X)
char jogador_atual = 'X';

// Variável para controlar se houve vencedor
bool vencedor = false;

// Função que inicializa o tabuleiro com espaços vazios
void inicializarTabuleiro() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tabuleiro[i][j] = vazio;
        }
    }
}

// Imprime o tabuleiro na tela
void mostrarTabuleiro() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if(i < 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n\n");
}

// Função que verifica vitória
bool verificarVitoria() {

    // Verifica linhas
    for(int i = 0; i < 3; i++) {
        if(tabuleiro[i][0] != vazio &&
           tabuleiro[i][0] == tabuleiro[i][1] &&
           tabuleiro[i][1] == tabuleiro[i][2]) {
            return true;
        }
    }

    // Verifica colunas
    for(int j = 0; j < 3; j++) {
        if(tabuleiro[0][j] != vazio &&
           tabuleiro[0][j] == tabuleiro[1][j] &&
           tabuleiro[1][j] == tabuleiro[2][j]) {
            return true;
        }
    }

    // Diagonal principal
    if(tabuleiro[0][0] != vazio &&
       tabuleiro[0][0] == tabuleiro[1][1] &&
       tabuleiro[1][1] == tabuleiro[2][2]) {
        return true;
    }

    // Diagonal secundária
    if(tabuleiro[0][2] != vazio &&
       tabuleiro[0][2] == tabuleiro[1][1] &&
       tabuleiro[1][1] == tabuleiro[2][0]) {
        return true;
    }

    return false;
}

// Função que verifica se há espaços vazios
bool tabuleiroCheio() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tabuleiro[i][j] == vazio) {
                return false;
            }
        }
    }
    return true;
}

// Função principal
int main() {
    int linha, coluna;
    inicializarTabuleiro();

    while(!vencedor && !tabuleiroCheio()) {
        mostrarTabuleiro();
        printf("Jogador %c, digite linha e coluna (0-2): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);

        // Validação da jogada
        if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Coordenadas invalidas! Tente novamente.\n");
            continue;
        }

        if(tabuleiro[linha][coluna] != vazio) {
            printf("Posicao ocupada! Escolha outra.\n");
            continue;
        }

        // Atualiza o tabuleiro
        tabuleiro[linha][coluna] = jogador_atual;

        // Verifica vitória
        if(verificarVitoria()) {
            vencedor = true;
            break;
        }

        // Alterna jogador
        if(jogador_atual == 'X') {
            jogador_atual = 'O';
        } else {
            jogador_atual = 'X';
        }
    }

    // Mostra tabuleiro final
    mostrarTabuleiro();

    // Resultado final
    if(vencedor) {
        printf("O jogador %c venceu!\n", jogador_atual);
    } else {
        printf("O jogo terminou em empate.\n");
    }
    return 0;
}