CC = clang++
CFLAGS = -std=c++17 -c -Wall
LFLAGS = -lSDL2

main: main.o LCD.o Cell.o
	${CC} main.o LCD.o Cell.o -o main ${LFLAGS}

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

LCD.o: LCD.cpp LCD.hpp
	${CC} ${CFLAGS} LCD.cpp

Cell.o: Cell.hpp Cell.cpp
	${CC} ${CFLAGS} Cell.cpp

.PHONY: clean
clean:
	rm -f *.o main

.PHONY: run
run:
	./main
