#include <stdio.h>
#include <stdlib.h> // for freeing
#include "bitboard.h"

int main(void) {

    u64 white_pawns   = 0x000000000000FF00;
    u64 black_pawns   = 0x00FF000000000000;
    u64 white_rooks   = 0x0000000000000081;
    u64 black_rooks   = 0x8100000000000000;
    u64 white_knights = 0x0000000000000042;
    u64 black_knights = 0x4200000000000000;
    u64 white_bishops = 0x0000000000000024;
    u64 black_bishops = 0x2400000000000000;
    u64 white_queen   = 0x0000000000000010;
    u64 black_queen   = 0x1000000000000000;
    u64 white_king    = 0x0000000000000008;
    u64 black_king    = 0x0800000000000000;

    // 0XFFFF00000000FFFF
    u64 starting = white_pawns | black_pawns | white_rooks | black_rooks |
                      white_knights | black_knights | white_bishops | black_bishops |
                      white_queen | black_queen | white_king | black_king;

    bitboardPtr test = create(starting);

    printBoard(test);
    printf("Empty?: True = 1, False = 0, Result: %d\n", isEmpty(test));
    printf("Pop count: %d\n", popCount(test));
    printf("Least Significant Bit Board: \n");
    printBoardFromHex(isolateLSB(getBoard(test)));
    
    setBoard(test, (1ULL << A1));

    printf("TESTING MOVEMENT \n");

    printf("North: \n");
    printBoardFromHex(north(test));

    printf("TESTING ENUMS \n");
    
    printBoardFromHex(1ULL << A8);
    printBoardFromHex(1ULL << A1);

    free(test);

    return 0;
}
