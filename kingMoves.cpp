// Including the header file for the class
#include"class.h"


void Chess :: checkValidSquareForKing (int i, int j, int r, int c, char C, MPS & moves) {
    if (C == 'K') {
        whiteKing = {i, j};
        if (whitePiecesPosition.count({r, c})) return;
        if (allBlackMoves.count({r, c})) return;
        moves[{i, j}].insert({r, c});
        // checking for the queen and king side castling
        // adding later if the king under check
        // Queen side castling
        if (r == 0 and c == 4 and i == 0 and j == 3 and whiteKingUnderCheck == false) {
            if (board[0][4] == ' ' and board[0][5] == ' ' and board[0][6] == ' ') {
                if (allBlackMoves.count({0, 4}) == 0 and allBlackMoves.count({0, 5}) == 0) {
                    if (castlePositions[{0, 3}] == false and castlePositions[{0, 7}] == false) {
                        moves[{i, j}].insert({0, 5});
                    }
                }
            }
        }
        // King Side castling
        if (r == 0 and c == 2 and i == 0 and j == 3 and whiteKingUnderCheck == false) {
            if (board[0][2] == ' ' and board[0][1] == ' ') {
                if (allBlackMoves.count({0, 2}) == 0 and allBlackMoves.count({0, 1}) == 0) {
                    if (castlePositions[{0, 3}] == false and castlePositions[{0, 0}] == false) {
                        moves[{i, j}].insert({0, 1});
                    }
                }
            }
        }
    }
    if (C == 'k') {
        blackKing = {i, j};
        if (blackPiecesPosition.count({r, c})) return;
        if (allWhiteMoves.count({r, c})) return;
        moves[{i, j}].insert({r, c});
        // checking for the queen and king side castling
        // adding later if the king under check
        // Queen side castling
        if (r == 7 and c == 4 and i == 7 and j == 3 and blackKingUnderCheck == false) {
            if (board[7][4] == ' ' and board[7][5] == ' ' and board[7][6] == ' ') {
                if (allWhiteMoves.count({7, 4}) == 0 and allWhiteMoves.count({7, 5}) == 0) {
                    if (castlePositions[{7, 3}] == false and castlePositions[{7, 7}] == false) {
                        moves[{i, j}].insert({7, 5});
                    }
                }
            }
        }
        // King Side castling
        if (r == 7 and c == 2 and i == 7 and j == 3 and blackKingUnderCheck == false) {
            if (board[7][2] == ' ' and board[7][1] == ' ') {
                if (allWhiteMoves.count({7, 2}) == 0 and allWhiteMoves.count({7, 1}) == 0) {
                    if (castlePositions[{7, 3}] == false and castlePositions[{7, 0}] == false) {
                        moves[{i, j}].insert({7, 1});
                    }
                }
            }
        }
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