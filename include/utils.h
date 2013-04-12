#ifndef _UTILS_H
#define _UTILS_H

void _utils_error(char []);
int max(int [], int);
void print_array(int [], int);
void random_array(int [], int, int);
void random_array_with_range(int [], int, int, int);
float leakage (int array[], int size);
void create_file();
void write_file(int size, double tempo, float leakage);

#endif
