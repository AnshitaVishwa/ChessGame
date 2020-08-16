// Including the header file for the class
#include"class.h"

void Chess :: boardMark(vector<pair<int, int>> input) {
    pair<int, int> u = input[0], v = input[1];
    int ux = u.first, uy = u.second, vx = v.first, vy = v.second;
    board[vx][vy] = board[ux][uy];
    board[ux][uy] = ' ';
}