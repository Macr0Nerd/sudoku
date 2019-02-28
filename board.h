//
// Created by erev on 2/26/19.
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <vector>

class board {
public:
    std::vector<std::vector<std::vector<int> > > b;
    board() : b (9, std::vector< std::vector<int> >(9, std::vector<int>(9, 1))){
        for (int i = 0; i< 9; ++i){
            for (int j = 0; j < 9; ++j){
                for (int k = 0; k < 9; ++k) {
                    b[i][j][k] += k;
                }
            }
        }
    }

    int failTest();
    int goalTest();
    void printPretty();
    int update(int *move);

private:
    int numsPlaced = 0;
    std::vector<int> findMostConstrained();
    int isValid(int x, int y, int val);
    void removeIfExists(int x, int y, int val);
};


#endif //SUDOKU_BOARD_H
