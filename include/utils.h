#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void utils_error(char msg[]) {
    printf("ERROR: %s\n", msg);
    exit(1);
}

void print_array(int array[], int size) {
    int i;

    if (size <= 0)
        utils_error("Tamanho de vetor inválido!");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void random_array(int array[], int size, int range) {
    int i;

    if (range < 0)
        utils_error("A faixa de valores randomicos não pode ser negativa!");

    if (size <= 0)
        utils_error("Tamanho de vetor inválido");

    srand(time(0));
    for (i = 0; i < size; i++) {
        array[i] = rand() % range;
    }
}

void random_array_with_range(int array[], int size, int range_min, int range_max) {
     int i;

    if (range_min < 0)
        utils_error("A faixa inicial de valores randomicos não pode ser negativa!");
    if (range_max < 0)
        utils_error("A faixa final de valores randomicos não pode ser negativa!");
    if (range_min > range_max)
        utils_error("A faixa inicial precisa ser maior que a faixa final!");
    if (range_min == range_max)
        utils_error("As faixas precisam ser diferentes!");
    if (size <= 0)
        utils_error("Tamanho de vetor inválido!");

    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % (range_max - range_min + 1) + range_min;
    }
}

#endif
