# Build target
chess: main.o bitboard.o
	gcc -o chess main.o bitboard.o

# Object file compilation
main.o: main.c bitboard.h
	gcc -c main.c

bitboard.o: bitboard.c bitboard.h
	gcc -c bitboard.c

# Run target
run: chess
	./chess