#include "board.h"
#include <iostream>
#include <array>
#include <stack>
using std::cout;
using std::cin;
using std::endl;

void bruteForce(Board state);

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
    bruteForce(board1);

    return 0;
}

void bruteForce(Board state) {
    std::stack<Board> stack;
    stack.push(state);

    Board copy;
    int z = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                if (!state.isOccupied(i, j)) {
                    copy = state;
                    std::array<int, 3> move = {i, j, k + 1};
                    copy.update(move);
                    stack.push(copy);
                }
            }
        }
    }

    while (!stack.empty()) {
        state = stack.top();
        stack.pop();

        if(state.failTest()){
            state = stack.top();
            stack.pop();
        }

        state.printPretty();

        if(state.goalTest()){
            break;
        }
    }
}