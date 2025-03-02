#include "printer.h"

#include <stdarg.h>

void println(char *format, ...) {
    va_list args;
    va_start(args, format);

    vprintf(format, args);
    printf("\n");

    va_end(args);
}