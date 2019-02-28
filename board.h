//
// Created by erev on 2/26/19.
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <vector>

class board {
public:
    board() : b (9, std::vector< std::vector<int> >(9, std::vector<int>(9, 1))){
        for (int i = 0; i< 9; ++i){
            for (int j = 0; j < 9; ++j){
                for (int k = 0; k < 9; ++k) {
                    b[i][j][k] += k;
                }
            }
        }
    }

private:
    std::vector<std::vector<std::vector<int> > > b;
};


#endif //SUDOKU_BOARD_H
