// Including the header file for the class
#include"class.h"


MPS Chess :: queenValidMoves (char C) {
    MPS moves;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == C) {
                checkValidSquareForBishop (i, j, C, moves);
                checkValidSquareForRook   (i, j, C, moves);
            } 
        }
    }
    return moves;
}