CC = gcc
CFLAGS = -Wall -std=c99
OBJ = lexer.o parser.o stack.o main.o
DEPS = lexer.h parser.h stack.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) calc
