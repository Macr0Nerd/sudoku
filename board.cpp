//
// Created by erev on 2/26/19.
//

#include "board.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;

int Board::failTest() {
    std::vector<int> row;
    std::vector<int> col;
    std::vector<int> sub;

    for (int i = 0; i < 9; ++i) {
        row.clear(); col.clear();
        row.assign(9, 0); col.assign(9, 0);

        for (int j = 0; j < 9; ++j) {
            if(std::find(row.begin(), row.end(), c[j][i]) != row.end()) {
                return 1;
            } else {
                row[j] = c[j][i];
            }

            if(std::find(col.begin(), col.end(), c[i][j]) != col.end()){
                return 1;
            } else {
                col[j] = c[i][j];
            }
        }
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            sub.clear();
            sub.assign(9, 0);
            int z = 0;

            for (int j = 0; j < 3; ++j) {
                for (int l = 0; l < 3; ++l) {
                    if(std::find(sub.begin(), sub.end(), c[k * 3 + j][i * 3 + l]) != sub.end()){
                        return 1;
                    } else {
                        sub[z] = c[k * 3 + j][i * 3 + l];
                    }

                    ++z;
                }
            }
        }
    }

    return 0;
}

std::vector<int> Board::findMostConstrained() {
    std::vector<int> cell = {0, 0};
    long val = 9;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (b[i][j].size() < val && b[i][j].size() > 1) {
                val = b[i][j].size();
                cell[0] = i;
                cell[1] = j;
            }
        }
    }

    return cell;
}

int Board::goalTest() {
    if (numsPlaced == 81) {
        return 1;
    } else {
        return 0;
    }
}

int Board::isOccupied(int x, int y) {
    if(c[x][y] != 0){
        return 1;
    } else {
        return 0;
    }
}

int Board::isValid(int x, int y, int val){
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

void Board::printPretty() {
    cout << numsPlaced << endl;

    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            if (c[i][j] == 0){
                cout << "# ";
            } else {
                cout << c[i][j] << " ";
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
    cout << endl;
}

void Board::removeIfExists(int x, int y, int val) {
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

int Board::update(std::array<int, 3> move) {
    c[move[0]][move[1]] = move[2];
    ++attempts;
    ++numsPlaced;
    return 1;
}
