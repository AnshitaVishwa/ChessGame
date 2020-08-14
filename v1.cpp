#include<bits/stdc++.h>
using namespace std;

class Chess {
private:
    char board[8][8];
    int  ux, uy, vx, vy;
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
    }
    void boardMark () {
        board[vx][vy] = board[ux][uy];
        board[ux][uy] = ' ';
    }
};

int main () {
    Chess C;
    C.displayBoard();
    C.getInput();
    C.boardMark();
    C.displayBoard();
    return 0;
}