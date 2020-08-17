#include<bits/stdc++.h>
// Including the header file for the class
#include"class.h"
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;
#include"prettyprint.hpp"

int main () {
    Chess C;
    C.displayBoard();
    vector<pair<int, int>> input = C.getInput();
    C.boardMark(input);
    C.displayBoard();
    MPS whitePawnMoves = C.pawnValidMoves('P');
    MPS blackPawnMoves = C.pawnValidMoves('p');
    MPS whiteKnightMoves = C.knightValidMoves('N');
    MPS blackKnightMoves = C.knightValidMoves('n');
    MPS blackRookMoves = C.rookValidMoves('r');
    MPS whiteRookMoves = C.rookValidMoves('R');
    debug(blackPawnMoves);
    debug(whitePawnMoves);
    debug(whiteRookMoves);
    debug(blackRookMoves);
    debug(blackKnightMoves);
    debug(whiteKnightMoves);
    return 0;
}