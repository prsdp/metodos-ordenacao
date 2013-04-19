#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	
	float soma_array=0, media=0, soma=0, variancia, desvio;
	int i;
	
	for (i = 0; i < size; i++) {
		soma_array+=array[i];
		media = soma_array/size;
	}
	
	for (i = 0; i < size; i++) {
		soma+=(array[i] - media)*(array[i] - media);
	}
	
	variancia = soma/size;
	desvio = pow(variancia,0.5);
	return desvio;
}

void create_file(char filename[], int size, double tempo, float leakage, double media_tempo){
	
	FILE *fp;
    int length;
    char str[50];

    if (!(int)strlen(filename)){
        fprintf(stderr, "É necessário o nome do arquivo!\n");        
    }
    
    strncpy(str, filename, sizeof(str));
    strncat(str, ".dat", strlen(filename));

    fp = fopen(str, "a");

    if (fp == NULL) {
        fprintf(stderr,"Não foi possível abrir o arquivo.\n");
    }

    fprintf(fp, "%d %.2f %.2f %.2f\n", size,tempo,leakage, media_tempo);
    fclose(fp);
    
}
