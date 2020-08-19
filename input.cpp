// Including the header file for the class
#include"class.h"

vector<pair<int, int>> Chess ::getInput () {
    if (isPlayerWhite) {
        cout << "Player 1: \n";
    } else {
        cout << "Player 2: \n";
    }
    int ux, uy, vx, vy;
    cout << "Select the position that you want to move: ";
    cin >> ux >> uy;
    cout << "Select the position where to move: ";
    cin >> vx >> vy;
    return {{ux, uy}, {vx, vy}};
}