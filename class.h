#include<bits/stdc++.h>
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;

class Chess {
private:
    char board[8][8];
    vector<set<int>> pieces = {{'p', 'q', 'k', 'n', 'b', 'r'}, {'P', 'Q', 'K', 'N', 'B', 'R'}};
    set<char> low = {'q', 'b', 'r'}, high = {'Q', 'B', 'R'};
public:
    Chess();
    vector<pair<int, int>> getInput();
    void   boardMark(vector<pair<int, int>> input);
    void   displayBoard();
    bool   check                        (set<int> pieces, int r, int c);
    void   blackPawnMoves               (int r, int c, MPS& moves);
    void   whitePawnMoves               (int r, int c, MPS& moves);
    MPS    pawnValidMoves               (char C);
    bool   checkValidSquareForKnight    (int r, int c, char C);
    MPS    knightValidMoves             (char C);
    void   checkValidSquareForRook      (int i, int j, char C, MPS& moves);
    bool   checkValidSquareForRookAdd   (int i, int j, int v, MPS& moves, bool horizontal, char C);
    MPS    rookValidMoves               (char C);
    bool   checkValidSquareForBishopAdd (int i, int j, int r, int c, char C, MPS & moves);
    void   checkValidSquareForBishop    (int i, int j, char C, MPS & moves);
    MPS    bishopValidMoves             (char C);
    MPS    queenValidMoves              (char C);
};