#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(){
    // initialize board state
    ChessBoard board;
    init_board(&board);

    // print board to console
    display_board(&board);

    // print all bitboards
    display_all_bitboards(&board);

    return 0;
}