#include <stdio.h>

#include "structures/vector.h"
#include "myio/printer.h"

int main(int argc, char** argv) {
    println("Hello!");

    Vec *vec = init_vec(2, TYPE_DOUBLE);

    append_vecd(vec, 12.4);
    append_vecd(vec, 10000.5);
    append_vecd(vec, 3.3);

    double d = 5.5;
    insert_vec(vec, 2, (void*) &d);
    print_vec(vec);

    // double *front = (double*)pop_front(vec);
    void* raw = pop_front(vec);
    while (raw != NULL) {

        println("Front = %.2f", *(double*) raw);
        raw = pop_front(vec);
    }

    free_vec(vec);

    return 0;
}