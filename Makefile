CFLAGS=-I
HEADERS=include
SOURCES=src
TESTS=tests
CC=gcc

all: bubble-sort insertion-sort quick-sort heap-sort count-sort selection-sort \
	bubble-sort-random-array heap-sort-random-array quick-sort-random-array \
	random-arrays-with-ranges testdir

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

count-sort: testdir
	$(CC) -o $(TESTS)/count-sort $(CFLAGS) $(HEADERS) $(SOURCES)/count-sort.c

selection-sort: testdir
	$(CC) -o $(TESTS)/selection-sort $(CFLAGS) $(HEADERS) $(SOURCES)/selection-sort.c

bubble-sort-random-array: testdir
	$(CC) -o $(TESTS)/bubble-sort-random-array $(CFLAGS) $(HEADERS) $(SOURCES)/bubble-sort-random-array.c

heap-sort-random-array: testdir
	$(CC) -o $(TESTS)/heap-sort-random-array $(CFLAGS) $(HEADERS) $(SOURCES)/heap-sort-random-array.c

quick-sort-random-array: testdir
	$(CC) -o $(TESTS)/quick-sort-random-array $(CFLAGS) $(HEADERS) $(SOURCES)/quick-sort-random-array.c

random-arrays-with-ranges: testdir
	$(CC) -o $(TESTS)/random-arrays-with-ranges $(CFLAGS) $(HEADERS) $(SOURCES)/random-arrays-with-ranges.c

clean:
	rm -rf $(TESTS)
