// Including the header file for the class
#include"class.h"

bool Chess :: check (set<int> pieces, int r, int c) {
    if (r < 0 || r > 7 || c > 7 || c < 0) return false;
    if (pieces.count(board[r][c]) == false) {
        return false;
    }
    return true;
}


void Chess :: blackPawnMoves(int r, int c, MPS& moves) {
    vector<int> cols = {c + 1, c - 1};
    if (r == 6) {
        if (board[r - 1][c] == ' ' and board[r - 2][c] == ' ') moves[{r, c}].insert({r - 2, c});
    }
    if (r - 1 >= 0 and board[r - 1][c] == ' ') moves[{r, c}].insert({r - 1, c});
    for (auto& x : cols) {
        if (check(pieces[1], r - 1, x)) moves[{r, c}].insert({r - 1, x});
    }
}


void Chess :: whitePawnMoves(int r, int c, MPS& moves) {
    vector<int> cols = {c + 1, c - 1};
    if (r == 1) {
        if (board[r + 1][c] == ' ' and board[r + 2][c] == ' ') moves[{r, c}].insert({r + 2, c});
    }
    if (r + 1 < 8 and board[r + 1][c] == ' ') moves[{r, c}].insert({r + 1, c});
    for (auto& x : cols) {
        if (check(pieces[0], r + 1, x)) moves[{r, c}].insert({r + 1, x});
    }
}


MPS Chess :: pawnValidMoves(char C) {
    MPS moves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == C) {
                if (C == 'p') blackPawnMoves(i, j, moves);
                if (C == 'P') whitePawnMoves(i, j, moves);
            }
        }
    }
    return moves;
}
