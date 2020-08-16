// Including the header file for the class
#include"class.h"

Chess::Chess () {
    // Initially the board is empty
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = ' ';
        }
    }
    // The white pawns are made on the top denoted by 'W'
    for (int i = 0; i < 8; ++i) {
        board[1][i] = 'P';
    }
    // The Black pawns are made on the top denoted by 'B'
    for (int i = 0; i < 8; ++i) {
        board[6][i] = 'p';
    }
    // The white rook denoted by 'R'
    board[0][0] = 'R', board[0][7] = 'R';
    // the black rook denoted by 'r'
    board[7][0] = 'r', board[7][7] = 'r';
    // the white knight denoted by 'N'
    board[0][1] = 'N', board[0][6] = 'N';
    // the black knight denoted by 'n'
    board[7][1] = 'n', board[7][6] = 'n';
    // the white king denoted by 'K'
    board[0][3] = 'K';
    // the black king denoted by 'k'
    board[7][3] = 'k';
    // the white bishop denoted by 'B'
    board[0][2] = 'B', board[0][5] = 'B';
    // the black bishop denoted by 'b'
    board[7][2] = 'b', board[7][5] = 'b';
    // the white Queen denoted by 'Q'
    board[0][4] = 'Q';
    // the black Queen denoted by 'q'
    board[7][4] = 'q';
}
