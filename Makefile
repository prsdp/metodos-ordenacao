CFLAGS=-I
HEADERS=include
SOURCES=src
TESTS=tests
CC=gcc

all:
	make bubble-sort
	make insertion-sort
	make quick-sort
	make heap-sort
	make count-sort
	make selection-sort
	make merge-sort
	make bubble-sort-random-array
	make heap-sort-random-array
	make quick-sort-random-array
	make merge-sort-random-array
	make random-arrays-with-ranges
	make sortable

testdir:
	mkdir -p tests

utils.o:
	cp $(HEADERS)/utils* $(TESTS)
	$(CC) -c $(TESTS)/utils.c -o $(TESTS)/utils.o

sorting.o: testdir utils.o bubble.o insertion.o quick.o heap.o count.o selection.o merge.o
	cp $(HEADERS)/sorting.c $(HEADERS)/sorting.h $(TESTS)
	$(CC) -c $(TESTS)/sorting.c -o $(TESTS)/sorting.o

bubble.o:
	cp $(HEADERS)/bubble* $(SOURCES)/bubble-sort.c $(TESTS)
	$(CC) -c $(TESTS)/bubblesort.c -o $(TESTS)/bubblesort.o

insertion.o:
	cp $(HEADERS)/insertion* $(SOURCES)/insertion-sort.c $(TESTS)
	$(CC) -c $(TESTS)/insertionsort.c -o $(TESTS)/insertionsort.o

quick.o:
	cp $(HEADERS)/quick* $(SOURCES)/quick-sort.c $(TESTS)
	$(CC) -c $(TESTS)/quicksort.c -o $(TESTS)/quicksort.o

heap.o:
	cp $(HEADERS)/heap* $(SOURCES)/heap-sort.c $(TESTS)
	$(CC) -c $(TESTS)/heapsort.c -o $(TESTS)/heapsort.o

count.o:
	cp $(HEADERS)/count* $(SOURCES)/count-sort.c $(TESTS)
	$(CC) -c $(TESTS)/countsort.c -o $(TESTS)/countsort.o

selection.o:
	cp $(HEADERS)/selection* $(SOURCES)/selection-sort.c $(TESTS)
	$(CC) -c $(TESTS)/selectionsort.c -o $(TESTS)/selectionsort.o

merge.o:
	cp $(HEADERS)/merge* $(SOURCES)/merge-sort.c $(TESTS)
	$(CC) -c $(TESTS)/mergesort.c -o $(TESTS)/mergesort.o

bubble-sort: testdir utils.o bubble.o
	$(CC) -c $(TESTS)/bubble-sort.c -o $(TESTS)/bubble-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/bubble-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

insertion-sort: testdir utils.o insertion.o
	$(CC) -c $(TESTS)/insertion-sort.c -o $(TESTS)/insertion-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/insertion-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

quick-sort: testdir utils.o quick.o
	$(CC) -c $(TESTS)/quick-sort.c -o $(TESTS)/quick-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/quick-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

heap-sort: testdir utils.o heap.o
	$(CC) -c $(TESTS)/heap-sort.c -o $(TESTS)/heap-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/heap-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

count-sort: testdir utils.o count.o
	$(CC) -c $(TESTS)/count-sort.c -o $(TESTS)/count-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/count-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

selection-sort: testdir utils.o selection.o
	$(CC) -c $(TESTS)/selection-sort.c -o $(TESTS)/selection-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/selection-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

merge-sort: testdir utils.o merge.o
	$(CC) -c $(TESTS)/merge-sort.c -o $(TESTS)/merge-sort.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/merge-sort
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

bubble-sort-random-array: testdir utils.o
	cp $(SOURCES)/bubble-sort-random-array.c $(HEADERS)/bubble* $(TESTS)
	$(CC) -c $(TESTS)/bubblesort.c -o $(TESTS)/bubblesort.o
	$(CC) -c $(TESTS)/bubble-sort-random-array.c -o $(TESTS)/bubble-sort-random-array.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/bubble-sort-random-array
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

heap-sort-random-array: testdir utils.o
	cp $(SOURCES)/heap-sort-random-array.c $(HEADERS)/heap* $(TESTS)
	$(CC) -c $(TESTS)/heapsort.c -o $(TESTS)/heapsort.o
	$(CC) -c $(TESTS)/heap-sort-random-array.c -o $(TESTS)/heap-sort-random-array.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/heap-sort-random-array
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

quick-sort-random-array: testdir utils.o
	cp $(SOURCES)/quick-sort-random-array.c $(HEADERS)/quick* $(TESTS)
	$(CC) -c $(TESTS)/quicksort.c -o $(TESTS)/quicksort.o
	$(CC) -c $(TESTS)/quick-sort-random-array.c -o $(TESTS)/quick-sort-random-array.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/quick-sort-random-array
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

merge-sort-random-array: testdir utils.o
	cp $(SOURCES)/merge-sort-random-array.c $(HEADERS)/merge* $(TESTS)
	$(CC) -c $(TESTS)/mergesort.c -o $(TESTS)/mergesort.o
	$(CC) -c $(TESTS)/merge-sort-random-array.c -o $(TESTS)/merge-sort-random-array.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/merge-sort-random-array
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

random-arrays-with-ranges: testdir utils.o sorting.o
	cp $(SOURCES)/random-arrays-with-ranges.c $(TESTS)
	$(CC) -c $(TESTS)/random-arrays-with-ranges.c -o $(TESTS)/random-arrays-with-ranges.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/random-arrays-with-ranges
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

sortable: testdir utils.o sorting.o
	cp $(SOURCES)/sortable.c $(TESTS)
	$(CC) -c $(TESTS)/sortable.c -o $(TESTS)/sortable.o
	$(CC) $(TESTS)/*.o -o $(TESTS)/sortable -lm
	rm $(TESTS)/*.o $(TESTS)/*.c $(TESTS)/*.h

clean:
	rm -rf $(TESTS)
