#include <stdio.h>

char brd[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void display() {
    printf(" %c | %c | %c \n", brd[0][0], brd[0][1], brd[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", brd[1][0], brd[1][1], brd[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", brd[2][0], brd[2][1], brd[2][2]);
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (brd[i][0] == brd[i][1] && brd[i][1] == brd[i][2]) return 1;
        if (brd[0][i] == brd[1][i] && brd[1][i] == brd[2][i]) return 1;
    }
    if (brd[0][0] == brd[1][1] && brd[1][1] == brd[2][2]) return 1;
    if (brd[0][2] == brd[1][1] && brd[1][1] == brd[2][0]) return 1;
    return 0;
}

int main() {
    int player = 1;
    int move;
    int row, col;
    char mark;
    int moves = 0;

    while (1) {
        display();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter your move: ", player);
        scanf("%d", &move);

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (brd[row][col] != 'X' && brd[row][col] != 'O') {
            brd[row][col] = mark;
            moves++;
        }
        else {
            printf("Invalid move, try again.\n");
            player--;
        }
        if (checkWin()) {
            display();
            printf("Player %d wins!\n", player);
            break;
        }
        if (moves == 9) {
            display();
            printf("It's a draw!\n");
            break;
        }
        player++;
    }

    return 0;
}