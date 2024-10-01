#include <stdio.h>
#include <stdlib.h> /* for freeing */
#include "bitboard.h"

int main(void) {

    // 0XFFFF00000000FFFF
    u64 starting = WHITE_PAWNS | BLACK_PAWNS | WHITE_ROOKS | BLACK_ROOKS |
                      WHITE_KNIGHTS | BLACK_KNIGHTS | WHITE_BISHOPS | BLACK_BISHOPS |
                      WHITE_QUEEN | BLACK_QUEEN | WHITE_KING | BLACK_KING;

    bitboard test = { starting }; // test.board = starting

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
