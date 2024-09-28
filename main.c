#include <stdio.h>
#include <stdlib.h> /* for freeing */
#include "bitboard.h"

int main(void) {

    /* 0XFFFF00000000FFFF */
    u64 starting = white_pawns | black_pawns | white_rooks | black_rooks |
                      white_knights | black_knights | white_bishops | black_bishops |
                      white_queen | black_queen | white_king | black_king;

    bitboard test = { starting }; /* test.board = starting */

    printBoard(&test);
    printf("Empty?: True = 1, False = 0, Result: %d\n", isEmpty(&test));
    printf("Pop count: %d\n", popCount(&test));
    printf("Least Significant Bit Board: \n");
    printBoardFromHex(isolateLSB(test.board));

    test.board = 1ULL << A1;
    printf("TESTING MOVEMENT \n");
    printf("North: \n");
    printBoardFromHex(north(test.board));
    printf("TESTING ENUMS \n");

    printBoardFromHex(1ULL << A8);
    printBoardFromHex(1ULL << A1);

    printf("TESTING BIT EXISTENCE \n");
    printBoard(&test);
    printf("Is bit A1 set? True = 1, False = 0, Result: %d\n", isBitSet(&test, A1));
    printf("Is bit A2 set? True = 1, False = 0, Result: %d\n", isBitSet(&test, A2));


    return 0;
}
