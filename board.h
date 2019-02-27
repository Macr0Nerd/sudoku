//
// Created by erev on 2/26/19.
//

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H


class board {
public:
    int b[9][9][9];

    board(){
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                for (int k = 1; k < 10; ++k) {
                    b[i][j][k] = k;
                }
            }
        }
    }
};


#endif //SUDOKU_BOARD_H
