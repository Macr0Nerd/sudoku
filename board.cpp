//
// Created by erev on 2/26/19.
//

#include "board.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <vector>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;

int board::isValid(int x, int y, int val){
    for (int i = 0; i < 9; ++i) {
        if(b[x][i].size() == 1 && b[x][i][0] == val){
            return 0;
        }

        if(b[i][y].size() == 1 && b[i][y][0] == val) {
            return 0;
        }
    }

    int subX = x - (x % 3);
    int subY = y - (y % 3);

    for (int j = subX; j < subX + 3; ++j) {
        for (int i = subY; i < subY + 3; ++i) {
            if(b[j][i].size() == 1 && b[j][i][0] == val) {
                return 0;
            }
        }
    }

    return 1;
}

void board::printPretty() {
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            if (b[i][j].size() > 1){
                cout << "# ";
            } else {
                cout << b[i][j][0] << " ";
            }

            if (j == 2 || j == 5){
                cout << "| ";
            }
        }
        cout << endl;

        if (i == 2 || i == 5){
            cout << "----------------------" << endl;
        }
    }
}

void board::removeIfExists(int x, int y, int val) {
    for (int i = 0; i < 9; ++i) {
        auto xInd = std::find(std::begin(b[x][i]), std::end(b[x][i]), val);
        if(typeid(b[x][i]) != typeid(int)) {
            if (xInd != end(b[x][i]) && b[x][i].size() > 1) {
                b[x][i].erase(xInd);
            }
        }

        auto yInd = std::find(std::begin(b[i][y]), std::end(b[i][y]), val);
        if(typeid(b[i][y]) != typeid(int)) {
            if(yInd != end(b[i][y]) && b[i][y].size() > 1) {
                b[i][y].erase(yInd);
            }
        }
    }

    int subX = x - (x % 3);
    int subY = y - (y % 3);

    for (int j = subX; j < subX + 3; ++j) {
        for (int i = subY; i < subY + 3; ++i) {
            auto subInd = std::find(std::begin(b[j][i]), std::end(b[j][i]), val);
            if(typeid(b[j][i]) != typeid(int)) {
                if (subInd != end(b[j][i]) && b[j][i].size() > 1) {
                    b[j][i].erase(subInd);
                }
            }
        }
    }
}

int board::update(int *move) {
    if(isValid(move[0], move[1], move[2])) {
        removeIfExists(move[0], move[1], move[2]);
        b[move[0]][move[1]].assign(1, move[2]);
        ++numsPlaced;
        cout << "Move completed" << endl;
        return 0;
    } else {
        cout << "Move could not be done" << endl;
        return 1;
    }
}
