//
// Created by erev on 2/26/19.
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <vector>
#include <array>

class Board {
public:
    std::vector<std::vector<std::vector<int> > > b;
    std::vector<std::vector<int> > c;
    int numsPlaced = 0;

    Board() : b(9, std::vector<std::vector<int> > (9, std::vector<int>(9, 1))) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < 9; ++k) {
                    b[i][j][k] += k;
                }
            }
        }

        c.assign(9, std::vector<int> (9, 0));
        attempts = 0;
        numsPlaced = 0;
    }

    Board& operator= (const Board& d);

    int failTest();
    std::array<int, 2> findMostConstrained();
    int goalTest();
    int isOccupied(int x, int y);
    void printPretty();
    int update(std::array<int, 3> move);

private:
    int attempts = 0;
};


#endif //SUDOKU_BOARD_H
