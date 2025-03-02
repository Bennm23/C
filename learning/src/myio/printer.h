#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>

inline void print_line() {
    printf("------------------\n");
}

void println(char *text, ...);
#endif