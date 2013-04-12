#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "utils.h"

void _utils_error(char msg[]) {
    printf("ERROR: %s\n", msg);
    exit(1);
}

int max(int array[], int size) {

	int i=0;
	int max = array[i];

	for(i=0;i<size;i++){
		if(array[i]>max){
			max = array[i];
		}
	}

    return max;
}

void print_array(int array[], int size) {
    int i;

    if (size <= 0)
        _utils_error("Tamanho de vetor inválido!");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void random_array(int array[], int size, int range) {
    int i;

    if (range < 0)
        _utils_error("A faixa de valores randomicos não pode ser negativa!");

    if (size <= 0)
        _utils_error("Tamanho de vetor inválido");

    srand(time(0));
    for (i = 0; i < size; i++) {
        array[i] = rand() % range;
    }
}

void random_array_with_range(int array[], int size, int range_min, int range_max) {
     int i;

    if (range_min < 0)
        _utils_error("A faixa inicial de valores randomicos não pode ser negativa!");
    if (range_max < 0)
        _utils_error("A faixa final de valores randomicos não pode ser negativa!");
    if (range_min > range_max)
        _utils_error("A faixa inicial precisa ser maior que a faixa final!");
    if (range_min == range_max)
        _utils_error("As faixas precisam ser diferentes!");
    if (size <= 0)
        _utils_error("Tamanho de vetor inválido!");

    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % (range_max - range_min + 1) + range_min;
    }
}

float leakage (int array[], int size){
	
	float soma_array=0, media=0, desvio, soma=0, variancia;
	int i;
	
	for (i = 0; i < size; i++) {
		soma_array+=array[i];
		media = soma_array/size;
	}
	
	for (i = 0; i < size; i++) {
		soma+=(array[i] - media)*(array[i] - media);
	}
	
	variancia = soma/size;
	desvio = pow(variancia,1/2);
	
	return desvio;
}

void create_file(){
	
	FILE *fp;

    fp = fopen("methods.csv", "a");

    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        exit(0);
    }

    fprintf(fp, "Size,Time,Leakage\n");
    fclose(fp);
    
}

void write_file(int size, double tempo, float leakage){
	
	FILE *fp;
	
	fp = fopen("methods.csv", "a");

    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        exit(0);
    }

    fprintf(fp, "%d,%.2f,%.2f\n", size,tempo,leakage);
    fclose(fp);
    
}
