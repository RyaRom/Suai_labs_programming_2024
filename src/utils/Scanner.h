//
// Created by locadm on 9/11/2024.
//

#ifndef SCANNER_H
#define SCANNER_H
#include <stdio.h>

#include "collections/AbstractList.h"

typedef struct Scanner Scanner;

void read_int_sequence_stdin(const AbstractList *list, void *collection);

char *read_line(FILE *stream, int bufferSize);

char *read_line_stdin(int bufferSize);

void fill_int_array(int *array, int size);
void fill_int_matrix(int **matrix, int cols, int rows);

#endif //SCANNER_H
