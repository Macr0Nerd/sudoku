#include "board.h"
#include <iostream>
#include <string>
#include <array>
#include <stack>
using std::cout;
using std::cin;
using std::endl;

int main() {
    Board board1;

    std::array<std::array<int, 3>, 34> easy = {{{0, 1, 3}, {0, 3, 2}, {1, 1, 6}, {1, 2, 4}, {1, 5, 8}, {1, 8, 7},
                                                {2, 0, 2}, {2, 1, 8}, {2, 2, 1}, {2, 5, 4}, {2, 7, 9}, {3, 2, 5},
                                                {3, 3, 9}, {3, 8, 1}, {4, 0, 3}, {4, 1, 1}, {4, 2, 9}, {4, 6, 4},
                                                {4, 7, 5}, {4, 8, 2}, {5, 0, 8}, {5, 5, 1}, {5, 6, 3}, {6, 1, 2},
                                                {6, 3, 8}, {6, 6, 9}, {6, 7, 7}, {6, 8, 3}, {7, 0, 1}, {7, 3, 3},
                                                {7, 6, 5}, {7, 7, 4}, {8, 5, 6}, {8, 7, 2}}};

    std::array<std::array<int, 3>, 21> hardest = {{{0, 0, 8}, {1, 2, 3}, {1, 3, 6}, {2, 1, 7}, {2, 4, 9}, {2, 6, 2},
                                                   {3, 1, 5}, {3, 5, 7}, {4, 4, 4}, {4, 5, 5}, {4, 6, 7}, {5, 3, 1},
                                                   {5, 7, 3}, {6, 2, 1}, {6, 7, 6}, {6, 8, 8}, {7, 2, 8}, {7, 3, 5},
                                                   {7, 7, 1}, {8, 1, 9}, {8, 6, 4}}};

    for (auto i : easy) {
        board1.update(i);
    }

    board1.printPretty();

    std::array<int, 3> move = {0, 0, -1};

    while (!board1.goalTest()){
        std::string row;std::string col; std::string num;
        cout << "Enter row index: ";
        getline(cin, row);
        cout << "Enter column index: ";
        getline(cin, col);
        cout << "Enter your answer: ";
        getline(cin, num);

        move[0] = std::stoi(row) - 1;
        move[1] = std::stoi(col) - 1;
        move[2] = std::stoi(num);

        board1.update(move);

        board1.printPretty();

        if(board1.failTest()){
            cout << "You failed..." << endl;
            return 1;
        }
    }

    cout << "You win!" << endl;

    return 0;
}
