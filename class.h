#include<bits/stdc++.h>
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;

class Chess {
private:
    char board[8][8];
    vector<set<int>> pieces = {{'p', 'q', 'k', 'n', 'b', 'r'}, {'P', 'Q', 'K', 'N', 'B', 'R'}};
public:
    Chess();
    vector<pair<int, int>> getInput();
    void boardMark(vector<pair<int, int>> input);
    void displayBoard();
    MPS pawnValidMoves(char C);
    void blackPawnMoves(int r, int c, MPS& moves);
    void whitePawnMoves(int r, int c, MPS& moves);
    bool check(set<int> pieces, int r, int c);
};