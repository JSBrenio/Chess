#include "bitboard.h"
#include <stddef.h> // For NULL
#include <stdio.h>
#include <stdlib.h> // For malloc

struct bitboard {
    u64 board;
};

bitboardPtr create(u64 board) {
    bitboardPtr ptr = malloc(sizeof(struct bitboard));
    if (ptr != NULL) {
        ptr->board = board;
    }
    return ptr;
}

void destroy(bitboardPtr bitboard) {
    free(bitboard);
}

u64 getBoard(bitboardPtr bitboard) { // inout
    return bitboard->board;
}

void setBoard(bitboardPtr bitboard, u64 board) {
    bitboard->board = board;
}

// Returns true 1 or false 0 if empty
int isEmpty(bitboardPtr bitboard) {
    return (bitboard->board == 0);
}

int popCount(bitboardPtr bitboard) {
    if (isEmpty(bitboard)) return 0;

    int count = 0;
    for (int i = 63; i >= 0; i--) {
        // Right shift the hexValue by i and mask out all but the least significant bit
        int bit = (bitboard->board >> i) & 1;
        if (bit == 1) count++;
    }
    return count;
}

u64 isolateLSB(u64 board) {
    return (board & -board);
}

u64 north(bitboardPtr bitboard) {
    return bitboard->board << 8;
}

u64 east(bitboardPtr bitboard) {
    if (bitboard->board != 0x0101010101010101) return bitboard->board << 1;
}

u64 south(bitboardPtr bitboard) {
    return bitboard->board >> 8;
}

u64 west(bitboardPtr bitboard) {
    if (bitboard->board != 0x8080808080808080) return bitboard->board >> 1;
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
void printBoard(bitboardPtr bitboard) {
    if (bitboard == NULL) return;

    printf("Num: (%llu), \nHex: (%#018llX)\n", 
    bitboard->board, bitboard->board);

    char rank[9] = "87654321";

    for (int row = 7; row >= 0; --row) {
        printf("%c | ", rank[row]);
        for (int col = 0; col < 8; ++col) {
            // Extract the bit at position (row*8 + col)
            int bit = (bitboard->board >> (row * 8 + col)) & 1;
            printf("%d ", bit);
        }
        printf("\n");
    }

    printf("--------------------\n");
    printf("  | A B C D E F G H\n");

}

void printBoardFromHex(u64 board) {
    if (board == NULL) return;

    printf("Num: (%llu), \nHex: (%#018llX)\n",
    board, board);

    char rank[9] = "12345678";

    for (int row = 7; row >= 0; --row) {
        printf("%c | ", rank[row]);
        for (int col = 0; col < 8; ++col) {
            // Extract the bit at position (row*8 + col)
            int bit = (board >> (row * 8 + col)) & 1;
            printf("%d ", bit);
        }
        printf("\n");
    }

    printf("--------------------\n");
    printf("  | A B C D E F G H\n");

}


