#include<bits/stdc++.h>
// Including the header file for the class
#include"class.h"
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;
#include"prettyprint.hpp"

int main () {
    Chess C;
    C.displayBoard();
    MPS pawnMoves = C.pawnValidMoves('P');
    debug(pawnMoves);
    vector<pair<int, int>> input = C.getInput();
    C.boardMark(input);
    C.displayBoard();
    pawnMoves = C.pawnValidMoves('P');
    debug(pawnMoves);
    return 0;
}