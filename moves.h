#ifndef MOVES_H
#define MOVES_H

#include <stdint.h> // for using uint64_t in bitboards

// PAWN DEFINITIONS
extern uint64_t white_pawn_moves[64];
extern uint64_t black_pawn_moves[64];
#define FILE_A 0x0101010101010101ULL  // A-file mask
#define FILE_H 0x8080808080808080ULL  // H-file mask

/*
* init_pawn_moves - initializes pawn moves
*/
void init_pawn_moves();

// KNIGHT DEFINITIONS
extern uint64_t knight_moves[64];  // Knight moves, precomputed for each square

/*
* init_knight_moves - initializes knight moves
*/
void init_knight_moves();

/*
* print_moves_bitboard - prints the moves bitboard from a given square for a certain piece
*/
void print_moves_bitboard(uint64_t moves_board) ;

#endif // MOVES_H