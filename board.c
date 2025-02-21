#include "board.h"
#include <stdio.h>

void init_board(ChessBoard *board){
    // Initialize piece bitboards
    board->pieces[PAWN] = 0x00FF00000000FF00ULL;
    board->pieces[KNIGHT] = 0x4200000000000042ULL;
    board->pieces[BISHOP] = 0x2400000000000024ULL;
    board->pieces[ROOK] = 0x8100000000000081ULL;
    board->pieces[QUEEN] = (1ULL << 3) | (1ULL << 59);  
    board->pieces[KING] =  (1ULL << 4) | (1ULL << 60);

    // initialize EMPTY bitboard to 0 (no piecess
    board->pieces[EMPTY] = 0;

    // Initialize color bitboards
    board->colors[WHITE] = 0xFFFF000000000000ULL;
    board->colors[BLACK] = 0x000000000000FFFFULL;

    // Set side to move (0 white, 1 black)
    board->side_to_move = 0;

    printf("Board initialized successfully.\n");
}

void display_board(const ChessBoard *board){
    char symbols[] = {'.', 'P', 'N', 'B', 'R', 'Q', 'K'};

    printf("Current board:\n\n");

    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            char piece_char = '.'; // default to empty

            // check each piece type for the given square and assign symbol
            for (int piece = 0; piece < 7; piece++) {
                if (board->pieces[piece] & (1ULL << square)) {
                    // Check if the piece belongs to white or black
                    if (board->colors[WHITE] & (1ULL << square)){
                        piece_char = symbols[piece];
                    } else {
                        piece_char = symbols[piece] + 32;
                    }
                    break;  // We found the piece, no need to check others
                }
            }
            printf("%c ", piece_char);  // Print the piece symbol (upper or lower case)
        }
        printf("\n");
    }
    printf("\n");
}

void display_bitboard(Bitboard bitboard) {
    // Print the bitboard in a board-like format (8x8 grid)

    // Loop through each rank (row) from 7 to 0 (top to bottom)
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            char piece_char = (bitboard & (1ULL << square)) ? '1' : '0';  // '1' if bit is set, '0' if not
            printf("%c ", piece_char);  // Print the bit (either '1' or '0')
        }
        printf("\n");
    }
    printf("\n");
}

void display_all_bitboards(ChessBoard *board) {
    const char *piece_names[] = {"EMPTY", "PAWN", "KNIGHT", "BISHOP", "ROOK", "QUEEN", "KING"};
    
    for (int piece = 1; piece <= 6; piece++) {
        // Display the bitboard for the current piece
        printf("%s Bitboard:\n\n", piece_names[piece]);
        display_bitboard(board->pieces[piece]);
    }
}