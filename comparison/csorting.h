//jfr
#ifndef CSORTING_H
#define CSORTING_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MALLOC_INIT 10

typedef struct {
    unsigned int ascii_value;
    char string[50];
} line;

void parse_file(FILE *file, int line_count, line *lines);
unsigned int get_line_value(char *line);
int count_lines (FILE *file);


#endif