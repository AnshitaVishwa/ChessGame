#include<bits/stdc++.h>
// Including the header file for the class
#include"class.h"
using namespace std;
typedef map<pair<int, int>, set<pair<int, int>>> MPS;
#include"prettyprint.hpp"

int main () {
    Chess C;
    C.displayBoard();
    while (1) {
        C.initializer();
    }
    return 0;
}