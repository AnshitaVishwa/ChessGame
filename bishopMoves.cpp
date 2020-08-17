// Including the header file for the class
#include"class.h"


bool Chess :: checkValidSquareForBishopAdd (int i, int j, int r, int c, char C, MPS & moves) {
    if (pieces[1].count(board[r][c])) {
        if (low.count(C)) moves[{i, j}].insert({r, c});
        return true;
    }
    if (pieces[0].count(board[r][c])) {
        if (high.count(C)) moves[{i, j}].insert({r, c});
        return true;
    }
    if (low.count(C) || high.count(C)) moves[{i, j}].insert({r, c});
    return false;
}


void Chess :: checkValidSquareForBishop (int i, int j, char C, MPS & moves) {
        int r, c;
        r = i - 1, c = j + 1;
        while (r >= 0 and c < 8) {
            if (checkValidSquareForBishopAdd(i, j, r, c, C, moves)) break;
            --r, ++c;
        }
        r = i - 1, c = j - 1;
        while (r >= 0 and c >= 0) {
            if (checkValidSquareForBishopAdd(i, j, r, c, C, moves)) break;
            --r, --c;
        } 
        r = i + 1, c = j - 1;
        while (r < 8 and c >= 0) {
            if (checkValidSquareForBishopAdd(i, j, r, c, C, moves)) break;
            ++r, --c;
        }
        r = i + 1, c = j + 1;
        while (r < 8 and c < 8) {
            if (checkValidSquareForBishopAdd(i, j, r, c, C, moves)) break;
            ++r, ++c;
        }
    }


MPS Chess :: bishopValidMoves (char C) {
    MPS moves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == C) {
                checkValidSquareForBishop(i, j, C, moves);
            }
        }
    }
    return moves;
}