# Build target
chess: main.o bitboard.o
	gcc -std=c89 -o chess main.o bitboard.o

# Object file compilation
main.o: main.c bitboard.h
	gcc -std=c89 -c main.c

bitboard.o: bitboard.c bitboard.h
	gcc -std=c89 -c bitboard.c

# Run target
run: chess
	./chess