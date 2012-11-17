CFLAGS=-I
HEADERS=include
SOURCES=src
TESTS=tests
CC=gcc

all: bubble-sort insertion-sort quick-sort heap-sort testdir

testdir:
	mkdir -p tests

bubble-sort: testdir
	$(CC) -o $(TESTS)/bubble-sort $(CFLAGS) $(HEADERS) $(SOURCES)/bubble-sort.c

insertion-sort: testdir
	$(CC) -o $(TESTS)/insertion-sort $(CFLAGS) $(HEADERS) $(SOURCES)/insertion-sort.c

quick-sort: testdir
	$(CC) -o $(TESTS)/quick-sort $(CFLAGS) $(HEADERS) $(SOURCES)/quick-sort.c

heap-sort: testdir
	$(CC) -o $(TESTS)/heap-sort $(CFLAGS) $(HEADERS) $(SOURCES)/heap-sort.c

clean:
	rm -rf $(TESTS)
