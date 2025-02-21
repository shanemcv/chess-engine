#ifndef BOARD_H
#define BOARD_H

#include <stdint.h> // for using uint64_t in bitboards

typedef uint64_t Bitboard; // 64-bit integer allowing efficient board representation

// Piece definitions
enum Piece {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

enum Color {
    WHITE, BLACK
};

typedef struct {
    Bitboard pieces[7]; // Bitboards for each piece type
    Bitboard colors[2]; // Separate bitboards for white and black
    int side_to_move; // 0 for white, 1 for black
} ChessBoard;

// Function definitions

/*
* void init_board - initializes a chessboard
*
* *board - the chessboard to be initialized
*/
void init_board(ChessBoard *board);

/*
* void display_board - displays the chessboard state
*
* *board - the chessboard to be displayed
*/
void display_board(const ChessBoard *board);

/*
* void display_bitboard - displays the bitboard state for a piece
*
* *bitboard - the bitboard to be displayed
*/
void display_bitboard(Bitboard bitboard);

/*
* void display_all_bitboards - displays all bitboards for current game state
*
* *board - the chessboard hosting the game state
*/
void display_all_bitboards(ChessBoard *board);

#endif // BOARD_H