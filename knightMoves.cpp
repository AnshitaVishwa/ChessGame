// Including the header file for the class
#include"class.h"


bool Chess :: checkValidSquareForKnight (int r, int c, char C) {
    if (r < 0 || r > 7 || c < 0 || c > 7) return false;
    if (C == 'N') {
        if (pieces[1].count(board[r][c])) {
            return false;
        }
    }
    if (C == 'n') {
        if (pieces[0].count(board[r][c])) {
            return false;
        }
    }
    return true;
}


MPS Chess :: knightValidMoves (char C) {
    MPS moves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == C) {
                vector<pair<int, int>> combos = {{i - 2, j + 1}, {i - 2, j - 1}, {i + 2, j + 1}, {i + 2, j - 1},
                                                 {i - 1, j + 2}, {i + 1, j + 2}, {i - 1, j - 2}, {i + 1, j - 2}};
                for (auto& [x, y] : combos) {
                    if (checkValidSquareForKnight(x, y, C)) moves[{i, j}].insert({x, y});
                }
            }
        }
    }
    return moves;
}