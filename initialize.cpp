// Including the header file for the class
#include"class.h"

void Chess :: allMoves () {
    whitePawnsMoves    = pawnValidMoves  ('P');
    blackPawnsMoves    = pawnValidMoves  ('p');
    whiteKnightMoves   = knightValidMoves('N');
    blackKnightMoves   = knightValidMoves('n');
    blackRookMoves     = rookValidMoves  ('r');
    whiteRookMoves     = rookValidMoves  ('R');
    whiteBishopMoves   = bishopValidMoves('B');
    blackBishopMoves   = bishopValidMoves('b');
    blackQueenMoves    = queenValidMoves ('q');
    whiteQueenMoves    = queenValidMoves ('Q');

    spi wps, awm, bps, abm;

    for (auto itr = whitePawnsMoves.begin(); itr != whitePawnsMoves.end(); ++itr) {
        wps.insert(itr -> first);
        for (auto x : itr -> second) {
            awm.insert(x);
        }
    }
    for (auto itr = whiteKnightMoves.begin(); itr != whiteKnightMoves.end(); ++itr) {
        wps.insert(itr -> first);
        for (auto x : itr -> second) {
            awm.insert(x);
        }
    }
    for (auto itr = whiteBishopMoves.begin(); itr != whiteBishopMoves.end(); ++itr) {
        wps.insert(itr -> first);
        for (auto x : itr -> second) {
            awm.insert(x);
        }
    }
    for (auto itr = whiteRookMoves.begin(); itr != whiteRookMoves.end(); ++itr) {
        wps.insert(itr -> first);
        for (auto x : itr -> second) {
            awm.insert(x);
        }
    }
    for (auto itr = whiteQueenMoves.begin(); itr != whiteQueenMoves.end(); ++itr) {
        wps.insert(itr -> first);
        for (auto x : itr -> second) {
            awm.insert(x);
        }
    }
    for (auto itr = blackPawnsMoves.begin(); itr != blackPawnsMoves.end(); ++itr) {
        bps.insert(itr -> first);
        for (auto x : itr -> second) {
            abm.insert(x);
        }
    }
    for (auto itr =blackKnightMoves.begin(); itr != blackKnightMoves.end(); ++itr) {
        bps.insert(itr -> first);
        for (auto x : itr -> second) {
            abm.insert(x);
        }
    }
    for (auto itr = blackBishopMoves.begin(); itr != blackBishopMoves.end(); ++itr) {
        bps.insert(itr -> first);
        for (auto x : itr -> second) {
            abm.insert(x);
        }
    }
    for (auto itr = blackRookMoves.begin(); itr != blackRookMoves.end(); ++itr) {
        bps.insert(itr -> first);
        for (auto x : itr -> second) {
            abm.insert(x);
        }
    }
    for (auto itr = blackQueenMoves.begin(); itr != blackQueenMoves.end(); ++itr) {
        bps.insert(itr -> first);
        for (auto x : itr -> second) {
            abm.insert(x);
        }
    }
    whitePiecesPosition = wps;
    blackPiecesPosition = bps;
    allWhiteMoves       = awm;
    allBlackMoves       = abm;
    whiteKingMoves      = kingValidMoves('K');
    blackKingMoves      = kingValidMoves('k');
    if (allBlackMoves.count(whiteKing) and isPlayerWhite) {
        whiteKingUnderCheck = true;
    }
    if (allWhiteMoves.count(blackKing) and !isPlayerWhite) {
        blackKingUnderCheck = true;
    }
}

void Chess :: initializer () {
    allMoves();
    vpi input = getInput();
    boardMark(input);
    displayBoard();
    isPlayerWhite = !isPlayerWhite;
}