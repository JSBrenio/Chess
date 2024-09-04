# Build target
chessex: main.o bitboard.o
	gcc -o chessex main.o bitboard.o

# Object file compilation
main.o: main.c bitboard.h
	gcc -c main.c

bitboard.o: bitboard.c bitboard.h
	gcc -c bitboard.c

# Run target
run: chessex
	./chessex