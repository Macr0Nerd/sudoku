#include "board.h"
#include <iostream>
#include <array>
#include <stack>
using std::cout;
using std::cin;
using std::endl;

void DFS(board state);

int main() {
    board board1;

     std::array<std::array<int, 3>, 34> easy = {{{0, 1, 3}, {0, 3, 2}, {1, 1, 6}, {1, 2, 4}, {1, 5, 8}, {1, 8, 7},
                                                 {2, 0, 2}, {2, 1, 8}, {2, 2, 1}, {2, 5, 4}, {2, 7, 9}, {3, 2, 5},
                                                 {3, 3, 9}, {3, 8, 1}, {4, 0, 3}, {4, 1, 1}, {4, 2, 9}, {4, 6, 4},
                                                 {4, 7, 5}, {4, 8, 2}, {5, 0, 8}, {5, 5, 1}, {5, 6, 3}, {6, 1, 2},
                                                 {6, 3, 8}, {6, 6, 9}, {6, 7, 7}, {6, 8, 3}, {7, 0, 1}, {7, 3, 3},
                                                 {7, 6, 5}, {7, 7, 4}, {8, 5, 6}, {8, 7, 2}}};

    for (auto i : easy) {
        board1.update(i);
    }

    board1.printPretty();

    DFS(board1);

    return 0;
}

void DFS(board state){
    std::stack <std::vector<std::vector<std::vector<int> > > > stck;
    stck.push(state.b);

    board copy;

    while (!stck.empty()) {
        int x = 0;

        std::vector<int> cons = state.findMostConstrained();

        if (state.b[cons[0]][cons[1]].size() > 1) {
            for (int i = 0; i < state.b[cons[0]][cons[1]].size(); ++i) {
                ++x;

                copy.b = state.b;
                std::array<int, 3> move = {cons[0], cons[1], copy.b[cons[0]][cons[1]][i]};
                copy.update(move);
                stck.push(copy.b);
            }
        } else {
            state.b = stck.top();
            stck.pop();
        }

        if (x > 0){
            state.b = stck.top();
            stck.pop();
        }

        if (state.goalTest()){
            break;
        }
    }
}