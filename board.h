#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;

class Board {
public:
    std::vector<std::vector<std::string> > c;
    int numsPlaced = 0;

    Board() {
        c.assign(9, std::vector<std::string> (9, "123456789"));
        numsPlaced = 0;
    }

    Board& operator= (const Board& d) {
        Board board;

        this->c = d.c;
        this->numsPlaced = d.numsPlaced;

        return *this;
    }


    int failTest() {
        std::vector<std::string> row;
        std::vector<std::string> col;
        std::vector<std::string> sub;

        for (int i = 0; i < 9; ++i) {
            row.clear();
            col.clear();
            row.assign(9, "");
            col.assign(9, "");

            for (int j = 0; j < 9; ++j) {
                if (std::find(row.begin(), row.end(), c[j][i]) != row.end()) {
                    return 1;
                } else if (c[j][i].size() == 1) {
                    row[j] += c[j][i];
                }

                if (std::find(col.begin(), col.end(), c[i][j]) != col.end()) {
                    return 1;
                } else if (c[i][j].size() == 1) {
                    col[j] = c[i][j];
                }
            }
        }

        for (int k = 0; k < 3; ++k) {
            for (int i = 0; i < 3; ++i) {
                sub.clear();
                sub.assign(9, "");
                int z = 0;

                for (int j = 0; j < 3; ++j) {
                    for (int l = 0; l < 3; ++l) {
                        if(std::find(sub.begin(), sub.end(), c[k * 3 + j][i * 3 + l]) != sub.end()){
                            return 1;
                        } else if (c[k * 3 + j][i * 3 + l].size() == 1) {
                            sub[z] += c[k * 3 + j][i * 3 + l];
                        }

                        ++z;
                    }
                }
            }
        }

        return 0;
    }

    int goalTest() {
        if (numsPlaced == 81 && !failTest()) {
            return 1;
        } else {
            return 0;
        }
    }

    int isOccupied(int x, int y) {
        if(c[x][y].size() == 1){
            return 1;
        } else {
            return 0;
        }
    }

    int isValid(int x, int y, std::string move) {
        std::vector<std::string> row (9, "");
        std::vector<std::string> col (9, "");
        std::vector<std::string> sub (9, "");

        for (int i = 0; i < 9; ++i) {
            row[i] = c[x][i];
            col[i] = c[i][y];

            if (c[x][i].size() > 1)
                row[i] = "#";
            if (c[i][y].size() > 1)
                col[i] = "#";
        }

        int subX = x - (x % 3);
        int subY = y - (y % 3);
        int z = 0;

        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                sub[z] = c[subX + j][subY + k];

                if (c[subX + j][subY + k].size() > 1)
                    sub[z] = "#";

                ++z;
            }
        }

        if (std::find(row.begin(), row.end(), move) != row.end() || std::find(col.begin(), col.end(), move) != col.end() || std::find(sub.begin(), sub.end(), move) != sub.end()){
            return 0;
        }

        if (isOccupied(x, y)){
            return 0;
        }

        return 1;
    }

    void printPretty() {
        cout << "    1 2 3   4 5 6   7 8 9" << endl;
        cout << "  -----------------------" << endl;

        for (int i = 0; i < 9; ++i){
            cout << i + 1 << " | ";

            for (int j = 0; j < 9; ++j){
                if (c[i][j].size() > 1){
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
                cout << "   ----------------------" << endl;
            }
        }
        cout << endl;
    }

    int update(std::array<int, 3> move) {
        if (move[0] > 8 || move[0] < 0 || move[1] > 8 || move[1] < 0 || move[2] > 9 || move[2] < 1){
            cout << "Enter answers between 1-9" << endl;
            cout << endl;
            return 0;
        } else if (isValid(move[0], move[1], std::to_string(move[2]))) {
            c[move[0]][move[1]] = std::to_string(move[2]);
            ++attempts;
            ++numsPlaced;
            return 1;
        } else {
            return 0;
        }
    }

private:
    int attempts = 0;
};