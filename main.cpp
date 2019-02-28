#include "board.h"
#include <iostream>
using namespace std;

int main() {
    board board1;

    int lst[3] = {1, 2, 9};
    board1.update(lst);
    lst[0] = 1;
    board1.update(lst);

    board1.printPretty();

    return 0;
}