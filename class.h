#include<bits/stdc++.h>
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;
typedef vector<pair<int, int>> vpi;
typedef vector<set<int>> vsi;
typedef set<pair<int, int>> spi;

class Chess {
private:
    char board[8][8];
    bool isPlayerWhite = true;
    vsi pieces = {{'p', 'q', 'k', 'n', 'b', 'r'}, {'P', 'Q', 'K', 'N', 'B', 'R'}};
    set<char> low = {'q', 'b', 'r'}, high = {'Q', 'B', 'R'};
    spi    allBlackMoves,   allWhiteMoves, blackPiecesPosition, whitePiecesPosition;
    MPS    whitePawnsMoves,  blackPawnsMoves,  whiteKnightMoves, blackKnightMoves, 
           blackRookMoves,  whiteRookMoves,  whiteBishopMoves, blackBishopMoves, 
           blackQueenMoves, whiteQueenMoves, whiteKingMoves,   blackKingMoves;
    vpi    getInput                     ();
    void   boardMark                    (vpi input);
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
    void   allMoves                     ();
    bool   checkValidityOfMoves         (bool isPlayerWhite, int ux, int uy, int vx, int vy);
    void   checkValidSquareForKing      (int i, int j, int r, int c, char C, MPS & moves);
    MPS    kingValidMoves               (char C);
public:
    Chess();
    void   displayBoard                 ();
    void   initializer                  ();
};