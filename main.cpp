#include<bits/stdc++.h>
// Including the header file for the class
#include"class.h"
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;
#include"prettyprint.hpp"

int main () {
    Chess C;
    C.displayBoard();
    MPS whitePawnMoves = C.pawnValidMoves('P');
    MPS blackPawnMoves = C.pawnValidMoves('p');
    MPS whiteKnightMoves = C.knightValidMoves('N');
    MPS blackKnightMoves = C.knightValidMoves('n');
    vector<pair<int, int>> input = C.getInput();
    C.boardMark(input);
    C.displayBoard();
    whitePawnMoves = C.pawnValidMoves('P');
    blackPawnMoves = C.pawnValidMoves('p');
    whiteKnightMoves = C.knightValidMoves('N');
    blackKnightMoves = C.knightValidMoves('n');
    debug(blackPawnMoves);
    debug(whitePawnMoves);
    debug(blackKnightMoves);
    debug(whiteKnightMoves);
    return 0;
}