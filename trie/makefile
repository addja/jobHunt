CC      = gcc
CFLAGS  = -Wall -std=c++17
LDFLAGS = -lstdc++
BIN			= bin
CODE		= main

all: $(BIN)

$(BIN): $(CODE).o
	$(CC) -o $@ $^ $(LDFLAGS)

$(CODE).o: $(CODE).cpp
	$(CC) -c $(CFLAGS) $<

.PHONY: clean

clean:
	rm *.o $(BIN)

run: all
	./$(BIN) < input.in
