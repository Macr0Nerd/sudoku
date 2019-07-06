#pragma once

#include "board.h"
#include <iostream>
#include <string>
#include <array>
#include <stack>
#include <exception>

using std::cout;
using std::cin;
using std::endl;

Board& dfs(const Board& d);

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

    for (auto i : hardest) {
        board1.update(i);
    }

    board1.printPretty();

    /* Uncomment to play
    std::array<int, 3> move = {0, 0, -1};

    while (!board1.goalTest()){
        std::string row;std::string col; std::string num;
        cout << "Enter row index: ";
        getline(cin, row);
        cout << "Enter column index: ";
        getline(cin, col);
        cout << "Enter your answer: ";
        getline(cin, num);
        cout << endl;

        try {
            move[0] = std::stoi(row) - 1;
            move[1] = std::stoi(col) - 1;
            move[2] = std::stoi(num);
        } catch (std::exception& n) {
            board1.printPretty();
            continue;
        }

        board1.update(move);

        board1.printPretty();

        if(board1.failTest()){
            cout << "You failed..." << endl;
            return 1;
        }
    }

    cout << "You win!" << endl;
     */

    dfs(board1);


    return 0;
}


Board& dfs(const Board& d) {
    Board state;
    Board newState;
    state = d;

    std::stack<Board> stack;
    stack.push(state);
    int counter = 0;
    int x;

    while (!stack.empty()) {
        x = 0;
        ++counter;

        std::array<int, 2> cons = state.findMostConstrained();

        cout << counter << endl;
        cout << state.numsPlaced << endl;
        cout << "(" << cons[0] + 1 << "," << cons[1] + 1 << ")" << endl;
        cout << state.c[cons[0]][cons[1]] << endl;

        if (state.c[cons[0]][cons[1]].size() == 2){
            std::array<int, 3> move = {cons[0], cons[1], state.c[cons[0]][cons[1]][0] - '0'};
            state.update(move);
        } else if (state.c[cons[0]][cons[1]].size() > 1) {
            for (int i = 0; i < state.c[cons[0]][cons[1]].size() - 1; ++i) {
                ++x;
                char mo =  state.c[cons[0]][cons[1]][i];

                newState = state;
                std::array<int, 3> move = {cons[0], cons[1], mo - '0'};
                if (newState.update(move))
                    stack.push(newState);
            }
        } else {
            state = stack.top();
            stack.pop();
        }

        if (x) {
            state = stack.top();
            stack.pop();
        }

        cout << state.c[cons[0]][cons[1]] << endl;
        state.printPretty();

        if (state.goalTest()){
            break;
        }
    }

    return state;
}