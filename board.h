//
// Created by erev on 2/26/19.
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <vector>
#include <array>

class Board {
public:
    std::vector<std::vector<int> > c;
    int numsPlaced = 0;

    Board() {
        c.assign(9, std::vector<int> (9, 0));
        attempts = 0;
        numsPlaced = 0;
    }

    Board& operator= (const Board& d);

    int failTest();
    int goalTest();
    int isOccupied(int x, int y);
    void printPretty();
    int update(std::array<int, 3> move);

private:
    int attempts = 0;
};


#endif //SUDOKU_BOARD_H
