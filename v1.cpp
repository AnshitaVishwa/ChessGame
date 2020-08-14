#include<bits/stdc++.h>
using namespace std;
#include"prettyprint.hpp"

class Chess {
private:
    char board[8][8];
    int  ux, uy, vx, vy;
    map<pair<int, int>, set<pair<int, int>>> pawnMoves;
public:
    Chess () {
        // Initially the board is empty
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = ' ';
            }
        }
        // The white pawns are made on the top denoted by 'W'
        for (int i = 0; i < 8; ++i) {
            board[1][i] = 'W';
        }
        // The Black pawns are made on the top denoted by 'B'
        for (int i = 0; i < 8; ++i) {
            board[6][i] = 'B';
        }
    }
    void displayBoard () {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << "   " << board[i][j] << "   ";
                if (j != 7) cout << "|";
            }
            cout << "\n";
            if (i != 7) cout << "------------------------------------------------------------------\n";
        }
    }
    void getInput () {
        cout << "Select the position that you want to move: ";
        cin >> ux >> uy;
        cout << "Select the position where to move: ";
        cin >> vx >> vy;
        if (!(pawnMoves.count({ux, uy}) and pawnMoves[{ux, uy}].count({vx, vy}))) {
            getInput();
        }
    }
    void boardMark () {
        board[vx][vy] = board[ux][uy];
        board[ux][uy] = ' ';
    }
    void pawnValidMoves () {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'B') {
                    if (i == 6) {
                        if (board[i - 1][j] == ' ' and board[i - 2][j] == ' ') pawnMoves[{i, j}].insert({i - 2, j});
                    }
                    if (i - 1 >= 0) {
                        if (board[i - 1][j] == ' ') pawnMoves[{i, j}].insert({i - 1, j});
                        if (j + 1 <= 7 and board[i - 1][j + 1] != ' ') pawnMoves[{i, j}].insert({i - 1, j + 1});
                        if (j - 1 >= 0 and board[i - 1][j - 1] != ' ') pawnMoves[{i, j}].insert({i - 1, j - 1});
                    }
                } else if (board[i][j] == 'W') {
                    if (i == 1) {
                        if (board[i + 1][j] == ' ' and board[i + 2][j] == ' ') pawnMoves[{i, j}].insert({i + 2, j});
                    }
                    if (i + 1 <= 7) {
                        if (board[i + 1][j] == ' ') pawnMoves[{i, j}].insert({i + 1, j});
                        if (j + 1 <= 7 and board[i + 1][j + 1] != ' ') pawnMoves[{i, j}].insert({i + 1, j + 1});
                        if (j - 1 >= 0 and board[i + 1][j - 1] != ' ') pawnMoves[{i, j}].insert({i + 1, j - 1});
                    }
                }
            }
        }
        debug(pawnMoves);
    }
};

int main () {
    Chess C;
    C.displayBoard();
    while(1) {
        C.pawnValidMoves();
        C.getInput();
        C.boardMark();
        C.displayBoard();
    }
    return 0;
}