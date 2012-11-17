CFLAGS=-I
HEADERS=include
SOURCES=src
TESTS=tests
CC=gcc

all: bubble-sort testdir

testdir:
	mkdir -p tests

bubble-sort: testdir
	$(CC) -o $(TESTS)/bubble-sort $(CFLAGS) $(HEADERS) $(SOURCES)/bubble-sort.c

clean:
	rm -r $(TESTS)
