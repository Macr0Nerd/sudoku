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

Board& Board::operator= (const Board& d){
    Board board;

    this->c = d.c;
    this->numsPlaced = d.numsPlaced;

    return *this;
}

int Board::failTest() {
    std::vector<int> row;
    std::vector<int> col;
    std::vector<int> sub;

    for (int i = 0; i < 9; ++i) {
        row.clear(); col.clear();
        row.assign(9, -1); col.assign(9, -1);

        for (int j = 0; j < 9; ++j) {
            if(std::find(row.begin(), row.end(), c[j][i]) != row.end()) {
                return 1;
            } else if (c[j][i] != 0) {
                row[j] = c[j][i];
            }

            if(std::find(col.begin(), col.end(), c[i][j]) != col.end()){
                return 1;
            } else if (c[i][j] != 0) {
                col[j] = c[i][j];
            }
        }
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            sub.clear();
            sub.assign(9, -1);
            int z = 0;

            for (int j = 0; j < 3; ++j) {
                for (int l = 0; l < 3; ++l) {
                    if(std::find(sub.begin(), sub.end(), c[k * 3 + j][i * 3 + l]) != sub.end()){
                        return 1;
                    } else if (c[k * 3 + j][i * 3 + l]) {
                        sub[z] = c[k * 3 + j][i * 3 + l];
                    }

                    ++z;
                }
            }
        }
    }

    return 0;
}

std::array<int, 2> Board::findMostConstrained() {
    std::array<int, 2> cell = {0, 0};
    long size = 9;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (b[i][j].size() < size && !isOccupied(i, j)){
                size = b[i][j].size();

                cell[0] = i; cell[1] = j;
            }
        }
    }

    return cell;
}

int Board::goalTest() {
    if (numsPlaced == 81 && !failTest()) {
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

int Board::update(std::array<int, 3> move) {
    c[move[0]][move[1]] = move[2];
    b[move[0]][move[1]][0] = move[2];
    ++attempts;
    ++numsPlaced;
    return 1;
}
