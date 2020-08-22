// Including the header file for the class
#include"class.h"


bool Chess :: checkValidityOfMoves (bool isPlayerWhite, int ux, int uy, int vx, int vy) {
    if (isPlayerWhite) {
        if (whitePawnsMoves.count({ux, uy}) and whitePawnsMoves[{ux, uy}].count({vx, vy})) return true;
        if (whiteKingMoves.count({ux, uy}) and whiteKingMoves[{ux, uy}].count({vx, vy})) return true;
        if (whiteRookMoves.count({ux, uy}) and whiteRookMoves[{ux, uy}].count({vx, vy})) return true;
        if (whiteKnightMoves.count({ux, uy}) and whiteKnightMoves[{ux, uy}].count({vx, vy})) return true;
        if (whiteBishopMoves.count({ux, uy}) and whiteBishopMoves[{ux, uy}].count({vx, vy})) return true;
        if (whiteQueenMoves.count({ux, uy}) and whiteQueenMoves[{ux, uy}].count({vx, vy})) return true;
    } else {
        if (blackPawnsMoves.count({ux, uy}) and blackPawnsMoves[{ux, uy}].count({vx, vy})) return true;
        if (blackKingMoves.count({ux, uy}) and blackKingMoves[{ux, uy}].count({vx, vy})) return true;
        if (blackRookMoves.count({ux, uy}) and blackRookMoves[{ux, uy}].count({vx, vy})) return true;
        if (blackKnightMoves.count({ux, uy}) and blackKnightMoves[{ux, uy}].count({vx, vy})) return true;
        if (blackBishopMoves.count({ux, uy}) and blackBishopMoves[{ux, uy}].count({vx, vy})) return true;
        if (blackQueenMoves.count({ux, uy}) and blackQueenMoves[{ux, uy}].count({vx, vy})) return true;
    }
    return false;
}


void Chess :: boardMark(vpi input) {
    pair<int, int> u = input[0], v = input[1];
    int ux = u.first, uy = u.second, vx = v.first, vy = v.second;
    if (isPlayerWhite) {
        if (checkValidityOfMoves(isPlayerWhite, ux, uy, vx, vy)) {
            // castling rule 
            // checking if king and rook ever moved
            if (ux == 0 and uy == 0 and board[ux][uy] == 'R' and castlePositions[{ux, uy}] == false) {
                castlePositions[{ux, uy}] = true;
            } else if (ux == 0 and uy == 7 and board[ux][uy] == 'R' and castlePositions[{ux, uy}] == false) {
                castlePositions[{ux, uy}] = true; 
            } else if (ux == 0 and uy == 3 and board[ux][uy] == 'K' and castlePositions[{ux, uy}] == false) {
                castlePositions[{ux, uy}] = true;
            } else if (vx == 7 and vy == 0 and board[vx][vy] == 'r' and castlePositions[{vx, vy}] == false) {
                castlePositions[{vx, vy}] = true;
            } else if (vx == 7 and vy == 7 and board[vx][vy] == 'r' and castlePositions[{vx, vy}] == false) {
                castlePositions[{vx, vy}] = true;
            }
            // if queen side castling validated
            if (ux == 0 and uy == 3 and vx == 0 and vy == 5) {
                board[0][4] = 'R';
                board[0][7] = ' ';
                castlePositions[{0, 7}] = true;
            }
            // if king side castling validated
            if (ux == 0 and uy == 3 and vx == 0 and vy == 1) {
                board[0][2] = 'R';
                board[0][0] = ' ';
                castlePositions[{0, 0}] = true;
            }
            // white Enpassant 
            if (whiteEnpassant) {
                board[ux][vy] = ' ';
                whiteEnpassant = false;
            }
            //board mark
            board[vx][vy] = board[ux][uy];
            board[ux][uy] = ' ';
            // white pawn promotion
            if (vx == 7 and board[vx][vy] == 'P') {
                board[vx][vy] = 'Q';
            }
        } 
        // else {
        //     vpi input = getInput();
        //     boardMark(input);
        // }
    } else {
        if (checkValidityOfMoves(isPlayerWhite, ux, uy, vx, vy)) {
            // castling rule 
            // checking if king and rook ever moved
            if (ux == 7 and uy == 0 and board[ux][uy] == 'r' and castlePositions[{ux, uy}] == false) {
                castlePositions[{ux, uy}] = true;
            } else if (ux == 7 and uy == 7 and board[ux][uy] == 'r' and castlePositions[{ux, uy}] == false) {
                castlePositions[{ux, uy}] = true; 
            } else if (ux == 7 and uy == 3 and board[ux][uy] == 'k' and castlePositions[{ux, uy}] == false) {
                castlePositions[{ux, uy}] = true;
            } else if (vx == 0 and vy == 0 and board[vx][vy] == 'R' and castlePositions[{vx, vy}] == false) {
                castlePositions[{vx, vy}] = true;
            } else if (vx == 0 and vy == 7 and board[vx][vy] == 'R' and castlePositions[{vx, vy}] == false) {
                castlePositions[{vx, vy}] = true;
            }
            // if queen side castling validated
            if (ux == 7 and uy == 3 and vx == 7 and vy == 5) {
                board[7][4] = 'R';
                board[7][7] = ' ';
                castlePositions[{7, 7}] = true;
            }
            // if king side castling validated
            if (ux == 7 and uy == 3 and vx == 7 and vy == 1) {
                board[7][2] = 'R';
                board[7][0] = ' ';
                castlePositions[{7, 0}] = true;
            }
            // black Enpassant
            if (blackEnpassant) {
                board[ux][vy] = ' ';
                blackEnpassant = false;
            }
            // board mark
            board[vx][vy] = board[ux][uy];
            board[ux][uy] = ' ';
            // black pawn promotion
            if (vx == 0 and board[vx][vy] == 'p') {
                board[vx][vy] = 'q';
            }
        } 
        // else {
        //     vpi input = getInput();
        //     boardMark(input);
        // }
    }
    prevUx = ux, prevUy = uy, prevVx = vx, prevVy = vy;
    // cout << prevUx << " " << prevUy << " " << prevVx << " " << prevVy << " " << prevPiece << "\n";
    // debug(prevPiece, prevUx, prevUy, prevVx, prevVy);
}