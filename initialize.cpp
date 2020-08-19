// Including the header file for the class
#include"class.h"

void Chess :: allMoves () {
    whitePawnsMoves     = pawnValidMoves  ('P');
    blackPawnsMoves     = pawnValidMoves  ('p');
    whiteKnightMoves   = knightValidMoves('N');
    blackKnightMoves   = knightValidMoves('n');
    blackRookMoves     = rookValidMoves  ('r');
    whiteRookMoves     = rookValidMoves  ('R');
    whiteBishopMoves   = bishopValidMoves('B');
    blackBishopMoves   = bishopValidMoves('b');
    blackQueenMoves    = queenValidMoves ('q');
    whiteQueenMoves    = queenValidMoves ('Q');
    for (auto itr = whitePawnsMoves.begin(); itr != whitePawnsMoves.end(); ++itr) {
        whitePiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allWhiteMoves.insert(x);
        }
    }
    for (auto itr = whiteKnightMoves.begin(); itr != whiteKnightMoves.end(); ++itr) {
        whitePiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allWhiteMoves.insert(x);
        }
    }
    for (auto itr = whiteBishopMoves.begin(); itr != whiteBishopMoves.end(); ++itr) {
        whitePiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allWhiteMoves.insert(x);
        }
    }
    for (auto itr = whiteRookMoves.begin(); itr != whiteRookMoves.end(); ++itr) {
        whitePiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allWhiteMoves.insert(x);
        }
    }
    for (auto itr = whiteQueenMoves.begin(); itr != whiteQueenMoves.end(); ++itr) {
        whitePiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allWhiteMoves.insert(x);
        }
    }
    for (auto itr = blackPawnsMoves.begin(); itr != blackPawnsMoves.end(); ++itr) {
        blackPiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allBlackMoves.insert(x);
        }
    }
    for (auto itr =blackKnightMoves.begin(); itr != blackKnightMoves.end(); ++itr) {
        blackPiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allBlackMoves.insert(x);
        }
    }
    for (auto itr = blackBishopMoves.begin(); itr != blackBishopMoves.end(); ++itr) {
        blackPiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allBlackMoves.insert(x);
        }
    }
    for (auto itr = blackRookMoves.begin(); itr != blackRookMoves.end(); ++itr) {
        blackPiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allBlackMoves.insert(x);
        }
    }
    for (auto itr = blackQueenMoves.begin(); itr != blackQueenMoves.end(); ++itr) {
        blackPiecesPosition.insert(itr -> first);
        for (auto x : itr -> second) {
            allBlackMoves.insert(x);
        }
    }
    whiteKingMoves = kingValidMoves('K');
    blackKingMoves = kingValidMoves('k');
}

void Chess :: initializer () {
    allMoves();
    vpi input = getInput();
    boardMark(input);
    displayBoard();
    isPlayerWhite = !isPlayerWhite;
}