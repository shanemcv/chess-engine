#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "moves.h"

int main(){
    // initialize board state
    ChessBoard board;
    init_board(&board);

    // initialize legal moves
    init_pawn_moves();
    init_knight_moves();

    // print board to console
    display_board(&board);

    // print all bitboards
    //display_all_bitboards(&board);

    //print knight moves from d4 (27)
    printf("Knight moves from d4:\n");
    print_moves_bitboard(knight_moves[27]);

    //print white pawn moves from c2 (10)
    printf("white pawn moves from d4:\n");
    print_moves_bitboard(white_pawn_moves[10]);

    //print black pawn moves from c2 (10)
    printf("black pawn moves from d4:\n");
    print_moves_bitboard(black_pawn_moves[10]);

    return 0;
}