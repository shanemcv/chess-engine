#include "moves.h"
#include <stdint.h>
#include <stdio.h>

// DECLARE MOVES ARRAYS
uint64_t white_pawn_moves[64];
uint64_t black_pawn_moves[64];
uint64_t knight_moves[64];

void init_pawn_moves() {
    for (int sq = 0; sq < 64; sq++) {
        uint64_t b = 1ULL << sq;
        white_pawn_moves[sq] = 0;
        black_pawn_moves[sq] = 0;

        // One step forward
        if (sq < 56) white_pawn_moves[sq] |= (b << 8);
        if (sq >= 8) black_pawn_moves[sq] |= (b >> 8);

        // Two squares forward from rank 2 (white) and rank 7 (black)
        if (sq >= 8 && sq <= 15) white_pawn_moves[sq] |= (b << 16);
        if (sq >= 48 && sq <= 55) black_pawn_moves[sq] |= (b >> 16);

        // Captures
        if ((b & ~FILE_A) && sq < 56) white_pawn_moves[sq] |= (b << 7);  // Capture left
        if ((b & ~FILE_H) && sq < 56) white_pawn_moves[sq] |= (b << 9);  // Capture right
        if ((b & ~FILE_A) && sq >= 8) black_pawn_moves[sq] |= (b >> 9);  // Capture left
        if ((b & ~FILE_H) && sq >= 8) black_pawn_moves[sq] |= (b >> 7);  // Capture right
    }
}

void init_knight_moves() {
    for (int sq = 0; sq < 64; sq++) {
        uint64_t b = 1ULL << sq;
        knight_moves[sq] = 0;  // Reset before assigning moves

        // Left 2
        if ((b & ~0x0101010101010101ULL) >> 17) knight_moves[sq] |= (b >> 17);
        if ((b & ~0x0101010101010101ULL) << 15) knight_moves[sq] |= (b << 15);

        // Right 2
        if ((b & ~0x8080808080808080ULL) >> 15) knight_moves[sq] |= (b >> 15);
        if ((b & ~0x8080808080808080ULL) << 17) knight_moves[sq] |= (b << 17);

        // Up 2
        if ((b & ~0x0303030303030303ULL) << 6) knight_moves[sq] |= (b << 6);
        if ((b & ~0xC0C0C0C0C0C0C0C0ULL) << 10) knight_moves[sq] |= (b << 10);

        // Down 2
        if ((b & ~0x0303030303030303ULL) >> 10) knight_moves[sq] |= (b >> 10);
        if ((b & ~0xC0C0C0C0C0C0C0C0ULL) >> 6) knight_moves[sq] |= (b >> 6);
    }
}

void print_moves_bitboard(uint64_t moves_board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            printf("%d ", (moves_board >> square) & 1);
        }
        printf("\n");
    }
    printf("\n");
}