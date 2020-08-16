// Including the header file for the class
#include"class.h"

void Chess :: displayBoard () {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << "   " << board[i][j] << "   ";
            if (j != 7) cout << "|";
        }
        cout << "\n";
        if (i != 7) cout << "------------------------------------------------------------------\n";
    }
}