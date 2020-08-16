// Including the header file for the class
#include"class.h"

bool Chess :: check (char a, char b, char g, char d, char e, char f, int r, int c) {
    if (r < 0 || r > 7) return false;
    if (c > 7 || c < 0) return false;
    if ( !(board[r][c] == a || 
           board[r][c] == b || 
           board[r][c] == g || 
           board[r][c] == d || 
           board[r][c] == e || 
           board[r][c] == f)) {
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
        if (check('P', 'Q', 'K', 'N', 'B', 'R', r - 1, x)) moves[{r, c}].insert({r - 1, x});
    }
}


void Chess :: whitePawnMoves(int r, int c, MPS& moves) {
    vector<int> cols = {c + 1, c - 1};
    if (r == 1) {
        if (board[r + 1][c] == ' ' and board[r + 2][c] == ' ') moves[{r, c}].insert({r + 2, c});
    }
    if (r + 1 < 8 and board[r + 1][c] == ' ') moves[{r, c}].insert({r + 1, c});
    for (auto& x : cols) {
        if (check('p', 'q', 'k', 'n', 'b', 'r', r + 1, x)) moves[{r, c}].insert({r + 1, x});
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
