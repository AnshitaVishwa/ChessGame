// Including the header file for the class
#include"class.h"


void Chess :: checkValidSquareForKing (int i, int j, int r, int c, char C, MPS & moves) {
    if (C == 'K') {
        if (whitePiecesPosition.count({r, c})) return;
        if (allBlackMoves.count({r, c})) return;
        moves[{i, j}].insert({r, c});
    }
    if (C == 'k') {
        if (blackPiecesPosition.count({r, c})) return;
        if (allWhiteMoves.count({r, c})) return;
        moves[{i, j}].insert({r, c});
    }
    return;
}


MPS Chess :: kingValidMoves (char C) {
    MPS moves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == C) {
                vpi combos = {{i - 1, j - 1}, {i - 1, j}, {i - 1, j + 1}, {i, j + 1}, {i + 1, j + 1}, {i + 1, j}, {i + 1, j - 1}, {i, j - 1}};
                for (auto& [x, y] : combos) {
                    checkValidSquareForKing (i, j, x, y, C, moves);
                }
            }
        }
    }
    return moves;
}