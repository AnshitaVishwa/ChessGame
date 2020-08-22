#include<bits/stdc++.h>
using namespace std;
// #include"prettyprint.hpp"
typedef map<pair<int, int>, set<pair<int, int>>> MPS;
typedef vector<pair<int, int>> vpi;
typedef vector<set<char>> vsc;
typedef set<pair<int, int>> spi;
typedef map<pair<int, int>, bool> mpb;
typedef pair<int, int> pi;

class Chess {
private:
    char   board[8][8];
    mpb    castlePositions = {{{0, 0}, false}, {{0, 7}, false}, {{7, 0}, false}, {{7, 7}, false}, {{0, 3}, false}, {{7, 3}, false}};
    bool   isPlayerWhite = true, blackEnpassant = false, whiteEnpassant = false, blackKingUnderCheck = false, whiteKingUnderCheck = false;
    int    prevUx = -1, prevUy = -1, prevVx = -1, prevVy = -1, mouseUx, mouseUy, mouseVx, mouseVy;
    pi     whiteKing = {0, 3}, blackKing = {7, 3};
    vsc    pieces = {{'p', 'q', 'k', 'n', 'b', 'r'}, {'P', 'Q', 'K', 'N', 'B', 'R'}};
    set<char> low = {'q', 'b', 'r'}, high = {'Q', 'B', 'R'};
    spi    allBlackMoves,   allWhiteMoves,   blackPiecesPosition, whitePiecesPosition;
    MPS    whitePawnsMoves, blackPawnsMoves, whiteKnightMoves,    blackKnightMoves, 
           blackRookMoves,  whiteRookMoves,  whiteBishopMoves,    blackBishopMoves, 
           blackQueenMoves, whiteQueenMoves, whiteKingMoves,      blackKingMoves, 
           movesByWhiteUnderCheck, movesByBlackUnderCheck;
    vpi    getInput                     (int mouseUx, int mouseUy, int mouseVx, int mouseVy);
    void   boardMark                    (vpi input);
    bool   check                        (set<char> pieces, int r, int c);
    void   blackPawnMoves               (int r, int c, MPS& moves);
    void   whitePawnMoves               (int r, int c, MPS& moves);
    MPS    pawnValidMoves               (char C);
    bool   checkValidSquareForKnight    (int r, int c, char C);
    MPS    knightValidMoves             (char C);
    void   checkValidSquareForRook      (int i, int j, char C, MPS& moves);
    bool   checkValidSquareForRookAdd   (int i, int j, int v, MPS& moves, bool horizontal, char C);
    MPS    rookValidMoves               (char C);
    bool   checkValidSquareForBishopAdd (int i, int j, int r, int c, char C, MPS& moves);
    void   checkValidSquareForBishop    (int i, int j, char C, MPS & moves);
    MPS    bishopValidMoves             (char C);
    MPS    queenValidMoves              (char C);
    void   allMoves                     ();
    bool   checkValidityOfMoves         (bool isPlayerWhite, int ux, int uy, int vx, int vy);
    void   checkValidSquareForKing      (int i, int j, int r, int c, char C, MPS& moves);
    MPS    kingValidMoves               (char C);
public:
    Chess();
    char*  getBoard                     ();
    void   getMouseCoordinates          (int ux, int uy, int vx, int vy);
    void   displayBoard                 ();
    void   initializer                  ();
};