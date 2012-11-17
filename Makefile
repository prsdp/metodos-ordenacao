CFLAGS=-I
HEADERS=include
SOURCES=src
TESTS=tests
CC=gcc

all: bubble-sort insertion-sort

testdir:
	mkdir -p tests

bubble-sort: testdir
	$(CC) -o $(TESTS)/bubble-sort $(CFLAGS) $(HEADERS) $(SOURCES)/bubble-sort.c
	
insertion-sort: testdir
	$(CC) -o $(TESTS)/insertion-sort $(CFLAGS) $(HEADERS) $(SOURCES)/insertion-sort.c
	clear
	./$(TESTS)/insertion-sort

clean:
	rm -r $(TESTS)
