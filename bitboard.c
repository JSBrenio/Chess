#include "bitboard.h"
#include <stddef.h> // For NULL
#include <stdio.h>
#include <stdlib.h> // For malloc

// bitboard* create(u64 board) {
//     bitboard* bb = malloc(sizeof(bitboard));
//     if (bb != NULL) {
//         bb->board = board;
//     }
//     return bb;
// }

// void destroy(bitboard* bb) {
//     free(bb);
// }

// u64 getBoard(const bitboard *bb) {
//     return bb->board;
// }

// void setBoard(bitboard *bb, u64 board) {
//     bb->board = board;
// }


/* Returns true 1 or false 0 if empty */ 
int isEmpty(const bitboard *bb) {
    return (bb->board == 0);
}


/*
Hamming weight, Brian Kernighan's algorithm
Subtracting 1 from board flips all the bits after the least significant set bit (including the least significant set bit itself).
Performing a bitwise AND with the original board clears the least significant set bit.
*/
int popCount(const bitboard *bb) {
    u64 board = bb->board;
    int count = 0;
    while (board) { // While board is not 0
        board &= (board - 1); // Equivalent to board = board & (board - 1)
        count++;
    }
    return count;
}

u64 isolateLSB(u64 bitboard) {
    return bitboard & -bitboard;
}

int isBitSet(const bitboard *bb, Square position) {
    return (bb->board & (1ULL << position)) != 0;
}

u64 north(u64 board) {
    return board << 8;
}

u64 east(u64 board) {
    if (board != 0x0101010101010101) return board << 1;
}

u64 south(u64 board) {
    return board >> 8;
}

u64 west(u64 board) {
    if (board != 0x8080808080808080) return board >> 1;
}

/*
To convert from little-endian file mapping to big-endian file mapping and vice versa:

squareIndexBigEndianFile    = squareIndexLittleEndianFile ^ 7;
squareIndexLittleEndianFile = squareIndexBigEndianFile    ^ 7;

To convert from little-endian rank mapping to big endian-rank mapping and vice versa:

squareIndexBigEndianRank    = squareIndexLittleEndianRank ^ 56;
squareIndexLittleEndianRank = squareIndexBigEndianRank    ^ 56;


Some bitboard constants with LERF-mapping:
a-file             0x0101010101010101
h-file             0x8080808080808080
1st rank           0x00000000000000FF
8th rank           0xFF00000000000000
a1-h8 diagonal     0x8040201008040201
h1-a8 antidiagonal 0x0102040810204080
light squares      0x55AA55AA55AA55AA
dark squares       0xAA55AA55AA55AA55
*/
void printBoardHelper(u64 board) {
    printf("Num: (%llu), \nHex: (%#018llX)\n", board, board);

    const char* rank = "12345678";
    const char* file = "A B C D E F G H";
    int row, col;
    for (row = 7; row >= 0; --row) {
        printf("%c | ", rank[row]);
        for (col = 0; col < 8; ++col) {
            int bit = (board >> (row * 8 + col)) & 1;
            printf("%d ", bit);
        }
        printf("\n");
    }
    printf("--------------------\n");
    printf("  | %s\n", file);
}

void printBoard(const bitboard *bb) {
    printBoardHelper(bb->board);
}

void printBoardFromHex(u64 board) {
    printBoardHelper(board);
}

const u64 WHITE_PAWNS   = 0x000000000000FF00;
const u64 BLACK_PAWNS   = 0x00FF000000000000;
const u64 WHITE_ROOKS   = 0x0000000000000081;
const u64 BLACK_ROOKS   = 0x8100000000000000;
const u64 WHITE_KNIGHTS = 0x0000000000000042;
const u64 BLACK_KNIGHTS = 0x4200000000000000;
const u64 WHITE_BISHOPS = 0x0000000000000024;
const u64 BLACK_BISHOPS = 0x2400000000000000;
const u64 WHITE_QUEEN   = 0x0000000000000010;
const u64 BLACK_QUEEN   = 0x1000000000000000;
const u64 WHITE_KING    = 0x0000000000000008;
const u64 BLACK_KING    = 0x0800000000000000;

// Rank masks
const u64 RANK_1 = 0x00000000000000FF;
const u64 RANK_2 = 0x000000000000FF00;
const u64 RANK_3 = 0x0000000000FF0000;
const u64 RANK_4 = 0x00000000FF000000;
const u64 RANK_5 = 0x000000FF00000000;
const u64 RANK_6 = 0x0000FF0000000000;
const u64 RANK_7 = 0x00FF000000000000;
const u64 RANK_8 = 0xFF00000000000000;

// File masks
const u64 FILE_A = 0x0101010101010101;
const u64 FILE_B = 0x0202020202020202;
const u64 FILE_C = 0x0404040404040404;
const u64 FILE_D = 0x0808080808080808;
const u64 FILE_E = 0x1010101010101010;
const u64 FILE_F = 0x2020202020202020;
const u64 FILE_G = 0x4040404040404040;
const u64 FILE_H = 0x8080808080808080;