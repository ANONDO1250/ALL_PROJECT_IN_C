#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
bool isBoardFull(char board[3][3]);
bool isWinner(char board[3][3], char symbol);
bool isValidMove(char board[3][3], int row, int col);
void makeMove(char board[3][3], int row, int col, char symbol);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int row, col;
    bool gameFinished = false;

    initializeBoard(board);

    printf("Tic Tac Toe\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("Let's start the game!\n");

    while (!gameFinished) {
        // Print the current state of the board
        printBoard(board);

        // Get the player's move
        printf("Player %c, enter your move (row[0-2] column[0-2]): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (isValidMove(board, row, col)) {
            // Make the move
            makeMove(board, row, col, currentPlayer);

            // Check if the current player wins
            if (isWinner(board, currentPlayer)) {
                printf("Player %c wins!\n", currentPlayer);
                gameFinished = true;
            }
            // Check if the board is full (draw)
            else if (isBoardFull(board)) {
                printf("It's a draw!\n");
                gameFinished = true;
            }
            else {
                // Switch to the other player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }

    // Print the final state of the board
    printBoard(board);

    return 0;
}

// Function to initialize the board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the current player wins
bool isWinner(char board[3][3], char symbol) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

// Function to check if the move is valid
bool isValidMove(char board[3][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        return true;
    }
    return false;
}

// Function to make the move
void makeMove(char board[3][3], int row, int col, char symbol) {
    board[row][col] = symbol;
}
