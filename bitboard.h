#ifndef BITBOARD_H
#define BITBOARD_H

typedef unsigned long long u64;

typedef struct bitboard *bitboardPtr;

bitboardPtr create(u64 board);
void destroy(bitboardPtr bitboard);
u64 getBoard(bitboardPtr bitboard);
void printBoard(bitboardPtr bitboard);
void printBoardFromHex(u64 board);
int isEmpty(bitboardPtr bitboard);
int popCount(bitboardPtr bitboard);
u64 isolateLSB(u64 bitboard);
u64 north(bitboardPtr bitboard);
u64 east(bitboardPtr bitboard);
u64 south(bitboardPtr bitboard);
u64 west(bitboardPtr bitboard);

/*
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

#endif