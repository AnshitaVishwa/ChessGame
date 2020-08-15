#include<bits/stdc++.h>
using namespace std;
#include"prettyprint.hpp"

class Chess {
private:
    char board[8][8];
    int  ux, uy, vx, vy;
    map<pair<int, int>, set<pair<int, int>>> pawnMoves, rookMoves, knightMoves, kingMoves;
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
            board[1][i] = 'P';
        }
        // The Black pawns are made on the top denoted by 'B'
        for (int i = 0; i < 8; ++i) {
            board[6][i] = 'p';
        }
        // The white rook denoted by 'R'
        board[0][0] = 'R', board[0][7] = 'R';
        // the black rook denoted by 'r'
        board[7][0] = 'r', board[7][7] = 'r';
        // the white knight denoted by 'N'
        board[0][1] = 'N', board[0][6] = 'N';
        // the black knight denoted by 'n'
        board[7][1] = 'n', board[7][6] = 'n';
        // the white king denoted by 'K'
        board[0][3] = 'K';
        // the black king denoted by 'k'
        board[7][3] = 'k';

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
    bool checkValidityOfMoves () {
        if (pawnMoves.count({ux, uy}) and pawnMoves[{ux, uy}].count({vx, vy})) return true;
        if (rookMoves.count({ux, uy}) and rookMoves[{ux, uy}].count({vx, vy})) return true;
        if (knightMoves.count({ux, uy}) and knightMoves[{ux, uy}].count({vx, vy})) return true;
        return false;
    }
    void getInput () {
        cout << "Select the position that you want to move: ";
        cin >> ux >> uy;
        cout << "Select the position where to move: ";
        cin >> vx >> vy;
        if (checkValidityOfMoves() == false) {
            getInput();
        }
    }
    void boardMark () {
        board[vx][vy] = board[ux][uy];
        board[ux][uy] = ' ';
    }
    void pawnValidMoves () {
        pawnMoves.clear();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'p') {
                    if (i == 6) {
                        if (board[i - 1][j] == ' ' and board[i - 2][j] == ' ') pawnMoves[{i, j}].insert({i - 2, j});
                    }
                    if (i - 1 >= 0) {
                        if (board[i - 1][j] == ' ') pawnMoves[{i, j}].insert({i - 1, j});
                        if (j + 1 <= 7 and (board[i - 1][j + 1] == 'P' || board[i - 1][j + 1] == 'K' || board[i - 1][j + 1] == 'N' || board[i - 1][j + 1] == 'Q' || board[i - 1][j + 1] == 'R' || board[i - 1][j + 1] == 'B')) pawnMoves[{i, j}].insert({i - 1, j + 1});
                        if (j - 1 >= 0 and (board[i - 1][j - 1] == 'P' || board[i - 1][j - 1] == 'K' || board[i - 1][j - 1] == 'N' || board[i - 1][j - 1] == 'Q' || board[i - 1][j - 1] == 'R' || board[i - 1][j - 1] == 'B')) pawnMoves[{i, j}].insert({i - 1, j - 1});
                    }
                } else if (board[i][j] == 'P') {
                    if (i == 1) {
                        if (board[i + 1][j] == ' ' and board[i + 2][j] == ' ') pawnMoves[{i, j}].insert({i + 2, j});
                    }
                    if (i + 1 <= 7) {
                        if (board[i + 1][j] == ' ') pawnMoves[{i, j}].insert({i + 1, j});
                        if (j + 1 <= 7 and (board[i + 1][j + 1] == 'p' || board[i + 1][j + 1] == 'k' || board[i + 1][j + 1] == 'n' || board[i + 1][j + 1] == 'q' || board[i + 1][j + 1] == 'r' || board[i + 1][j + 1] == 'b')) pawnMoves[{i, j}].insert({i + 1, j + 1});
                        if (j - 1 >= 0 and (board[i + 1][j - 1] == 'p' || board[i + 1][j - 1] == 'k' || board[i + 1][j - 1] == 'n' || board[i + 1][j - 1] == 'q' || board[i + 1][j - 1] == 'r' || board[i + 1][j - 1] == 'b')) pawnMoves[{i, j}].insert({i + 1, j - 1});
                    }
                }
            }
        }
        debug(pawnMoves);
    }
    void checkValidSquareForRook (int i, int j, char C) {
        for (int c = j + 1; c < 8; ++c) {
            if (board[i][c] == 'P' || board[i][c] == 'R' || board[i][c] == 'N' || board[i][c] == 'K' || board[i][c] == 'B' || board[i][c] == 'Q') {
                if (C == 'r') rookMoves[{i, j}].insert({i, c});
                break;
            }
            if (board[i][c] == 'p' || board[i][c] == 'r' || board[i][c] == 'n' || board[i][c] == 'k' || board[i][c] == 'b' || board[i][c] == 'q') {
                if (C == 'R') rookMoves[{i, j}].insert({i, c});
                break;
            }
            rookMoves[{i, j}].insert({i, c});
        }
        for (int c = j - 1; c >= 0; --c) {
            if (board[i][c] == 'P' || board[i][c] == 'R' || board[i][c] == 'N' || board[i][c] == 'K' || board[i][c] == 'B' || board[i][c] == 'Q') {
                if (C == 'r') rookMoves[{i, j}].insert({i, c});
                break;
            }
            if (board[i][c] == 'p' || board[i][c] == 'r' || board[i][c] == 'n' || board[i][c] == 'k' || board[i][c] == 'b' || board[i][c] == 'q') {
                if (C == 'R') rookMoves[{i, j}].insert({i, c});
                break;
            }
            rookMoves[{i, j}].insert({i, c});
        }
        for (int r = i + 1; r < 8; ++r) {
            if (board[r][j] == 'P' || board[r][j] == 'R' || board[r][j] == 'N' || board[r][j] == 'K' || board[r][j] == 'B' || board[r][j] == 'Q') {
                if (C == 'r') rookMoves[{i, j}].insert({r, j});
                break;
            }
            if (board[r][j] == 'p' || board[r][j] == 'r' || board[r][j] == 'n' || board[r][j] == 'k' || board[r][j] == 'b' || board[r][j] == 'q') {
                if (C == 'R') rookMoves[{i, j}].insert({r, j});
                break;
            }
            rookMoves[{i, j}].insert({r, j});
        }
        for (int r = i - 1; r >= 0; --r) {
            if (board[r][j] == 'P' || board[r][j] == 'R' || board[r][j] == 'N' || board[r][j] == 'K' || board[r][j] == 'B' || board[r][j] == 'Q') {
                if (C == 'r') rookMoves[{i, j}].insert({r, j});
                break;
            }
            if (board[r][j] == 'p' || board[r][j] == 'r' || board[r][j] == 'n' || board[r][j] == 'k' || board[r][j] == 'b' || board[r][j] == 'q') {
                if (C == 'R') rookMoves[{i, j}].insert({r, j});
                break;
            }
            rookMoves[{i, j}].insert({r, j});
        }
    }
    void rookValidMoves () {
        rookMoves.clear();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    checkValidSquareForRook(i, j, 'R');
                } else if (board[i][j] == 'r') {
                    checkValidSquareForRook(i, j, 'r');
                }
            }
        }
        debug(rookMoves);
    }
    bool checkValidSquareForKnight (int r, int c, char C) {
        if (r < 0 || r > 7 || c < 0 || c > 7) return false;
        if (C == 'N') {
            if (board[r][c] == 'P' || board[r][c] == 'K' || board[r][c] == 'Q' || board[r][c] == 'B' || board[r][c] == 'N' || board[r][c] == 'R') {
                return false;
            }
        }
        if (C == 'n') {
            if (board[r][c] == 'p' || board[r][c] == 'k' || board[r][c] == 'q' || board[r][c] == 'b' || board[r][c] == 'n' || board[r][c] == 'r') {
                return false;
            }
        }
        return true;
    }
    void knightValidMoves () {
        knightMoves.clear();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'N') {
                    if (checkValidSquareForKnight(i - 2, j + 1, 'N')) knightMoves[{i, j}].insert({i - 2, j + 1});
                    if (checkValidSquareForKnight(i - 2, j - 1, 'N')) knightMoves[{i, j}].insert({i - 2, j - 1});
                    if (checkValidSquareForKnight(i + 2, j + 1, 'N')) knightMoves[{i, j}].insert({i + 2, j + 1});
                    if (checkValidSquareForKnight(i + 2, j - 1, 'N')) knightMoves[{i, j}].insert({i + 2, j - 1});
                    if (checkValidSquareForKnight(i - 1, j + 2, 'N')) knightMoves[{i, j}].insert({i - 1, j + 2});
                    if (checkValidSquareForKnight(i + 1, j + 2, 'N')) knightMoves[{i, j}].insert({i + 1, j + 2});
                    if (checkValidSquareForKnight(i - 1, j - 2, 'N')) knightMoves[{i, j}].insert({i - 1, j - 2});
                    if (checkValidSquareForKnight(i + 1, j - 2, 'N')) knightMoves[{i, j}].insert({i + 1, j - 2});
                } else if (board[i][j] == 'n') {
                    if (checkValidSquareForKnight(i - 2, j + 1, 'n')) knightMoves[{i, j}].insert({i - 2, j + 1});
                    if (checkValidSquareForKnight(i - 2, j - 1, 'n')) knightMoves[{i, j}].insert({i - 2, j - 1});
                    if (checkValidSquareForKnight(i + 2, j + 1, 'n')) knightMoves[{i, j}].insert({i + 2, j + 1});
                    if (checkValidSquareForKnight(i + 2, j - 1, 'n')) knightMoves[{i, j}].insert({i + 2, j - 1});
                    if (checkValidSquareForKnight(i - 1, j + 2, 'n')) knightMoves[{i, j}].insert({i - 1, j + 2});
                    if (checkValidSquareForKnight(i + 1, j + 2, 'n')) knightMoves[{i, j}].insert({i + 1, j + 2});
                    if (checkValidSquareForKnight(i - 1, j - 2, 'n')) knightMoves[{i, j}].insert({i - 1, j - 2});
                    if (checkValidSquareForKnight(i + 1, j - 2, 'n')) knightMoves[{i, j}].insert({i + 1, j - 2});
                }
            }
        }
        debug(knightMoves);
    }
    void kingValidMoves () {

    }
};

int main () {
    Chess C;
    C.displayBoard();
    while(1) {
        C.pawnValidMoves();
        C.rookValidMoves();
        C.knightValidMoves();
        C.getInput();
        C.boardMark();
        C.displayBoard();
    }
    return 0;
}