// Including the header file for the class
#include"class.h"

bool Chess :: checkValidSquareForRookAdd (int i, int j, int v, MPS& moves, bool horizontal, char C) {
    int row, col;
    if (horizontal) {
        row = i, col = v;
    } else {
        row = v, col = j;
    }
    if (pieces[1].count(board[row][col])) {
        if (low.count(C)) moves[{i, j}].insert({row, col});
        return true;
    }
    if (pieces[0].count(board[row][col])) {
        if (high.count(C)) moves[{i, j}].insert({row, col});
        return true;
    }
    if (low.count(C) || high.count(C)) moves[{i, j}].insert({row, col});
    return false;
}


void Chess :: checkValidSquareForRook (int i, int j, char C, MPS& moves) {
    for (int c = j + 1; c < 8; ++c) {
        if (checkValidSquareForRookAdd (i, j, c, moves, true, C)) break;
    }
    for (int c = j - 1; c >= 0; --c) {
        if (checkValidSquareForRookAdd (i, j, c, moves, true, C)) break;
    }
    for (int r =  i + 1; r < 8; ++r) {
        if (checkValidSquareForRookAdd (i, j, r, moves, false, C)) break;
    }
    for (int r = i - 1; r >= 0; --r) {
        if (checkValidSquareForRookAdd (i, j, r, moves, false, C)) break;
    }
}


MPS Chess :: rookValidMoves (char C) {
    MPS moves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == C) {
                checkValidSquareForRook(i, j, C, moves);
            }
        }
    }
    return moves;
}