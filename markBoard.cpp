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
            if (whiteEnpassant) {
                board[ux][vy] = ' ';
                whiteEnpassant = false;
            }
            board[vx][vy] = board[ux][uy];
            board[ux][uy] = ' ';
        } else {
            vpi input = getInput();
            boardMark(input);
        }
    } else {
        if (checkValidityOfMoves(isPlayerWhite, ux, uy, vx, vy)) {
            if (blackEnpassant) {
                board[ux][vy] = ' ';
                blackEnpassant = false;
            }
            board[vx][vy] = board[ux][uy];
            board[ux][uy] = ' ';
        } else {
            vpi input = getInput();
            boardMark(input);
        }
    }
    prevUx = ux, prevUy = uy, prevVx = vx, prevVy = vy;
    // cout << prevUx << " " << prevUy << " " << prevVx << " " << prevVy << " " << prevPiece << "\n";
    // debug(prevPiece, prevUx, prevUy, prevVx, prevVy);
}