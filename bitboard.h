#ifndef BITBOARD_H
#define BITBOARD_H

// Try to be more procedural: focus on functions that operate on data (bitboards) than encapsulating data and functions together

typedef unsigned long long u64;

/*
extern global Bitboards for each piece

White Pawns: 0x000000000000FF00
Black Pawns: 0x00FF000000000000
White Rooks: 0x0000000000000081
Black Rooks: 0x8100000000000000
White Knights: 0x0000000000000042
Black Knights: 0x4200000000000000
White Bishops: 0x0000000000000024
Black Bishops: 0x2400000000000000
White Queen: 0x0000000000000010
Black Queen: 0x1000000000000000
White King: 0x0000000000000008
Black King: 0x0800000000000000
*/

extern const u64 white_pawns;   // 0x000000000000FF00
extern const u64 black_pawns;   // 0x00FF000000000000
extern const u64 white_rooks;   // 0x0000000000000081
extern const u64 black_rooks;   // 0x8100000000000000
extern const u64 white_knights; // 0x0000000000000042
extern const u64 black_knights; // 0x4200000000000000
extern const u64 white_bishops; // 0x0000000000000024
extern const u64 black_bishops; // 0x2400000000000000
extern const u64 white_queen;   // 0x0000000000000010
extern const u64 black_queen;   // 0x1000000000000000
extern const u64 white_king;    // 0x0000000000000008
extern const u64 black_king;    // 0x0800000000000000


typedef struct {
    u64 board;
} bitboard;

// Squares on the board
typedef enum {
A1 = 0, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
} Square;

void printBoard(const bitboard *bb);
void printBoardFromHex(u64 board);
int isEmpty(const bitboard *bb);
int popCount(const bitboard *bb);
u64 isolateLSB(u64 bitboard);
int isBitSet(const bitboard *bb, Square position);
u64 north(u64 board);
u64 east(u64 board);
u64 south(u64 board);
u64 west(u64 board);

#endif