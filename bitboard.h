#ifndef BITBOARD_H
#define BITBOARD_H

// Try to be more procedural: focus on functions that operate on data (bitboards) than encapsulating data and functions together

typedef unsigned long long u64;

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

extern const u64 WHITE_PAWNS;   // 0x000000000000FF00
extern const u64 BLACK_PAWNS;   // 0x00FF000000000000
extern const u64 WHITE_ROOKS;   // 0x0000000000000081
extern const u64 BLACK_ROOKS;   // 0x8100000000000000
extern const u64 WHITE_KNIGHTS; // 0x0000000000000042
extern const u64 BLACK_KNIGHTS; // 0x4200000000000000
extern const u64 WHITE_BISHOPS; // 0x0000000000000024
extern const u64 BLACK_BISHOPS; // 0x2400000000000000
extern const u64 WHITE_QUEEN;   // 0x0000000000000010
extern const u64 BLACK_QUEEN;   // 0x1000000000000000
extern const u64 WHITE_KING;    // 0x0000000000000008
extern const u64 BLACK_KING;    // 0x0800000000000000

// Rank masks
extern const u64 RANK_1; // 0x00000000000000FF
extern const u64 RANK_2; // 0x000000000000FF00
extern const u64 RANK_3; // 0x0000000000FF0000
extern const u64 RANK_4; // 0x00000000FF000000
extern const u64 RANK_5; // 0x000000FF00000000
extern const u64 RANK_6; // 0x0000FF0000000000
extern const u64 RANK_7; // 0x00FF000000000000
extern const u64 RANK_8; // 0xFF00000000000000

// File masks
extern const u64 FILE_A; // 0x0101010101010101
extern const u64 FILE_B; // 0x0202020202020202
extern const u64 FILE_C; // 0x0404040404040404
extern const u64 FILE_D; // 0x0808080808080808
extern const u64 FILE_E; // 0x1010101010101010
extern const u64 FILE_F; // 0x2020202020202020
extern const u64 FILE_G; // 0x4040404040404040
extern const u64 FILE_H; // 0x8080808080808080

#endif