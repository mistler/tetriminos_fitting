#include "field.h"

#include <stdio.h>

int main(void) {
    struct Field* f = init(7, 12);
    show(f);
    put(f, 0, 0);
    show(f);
    put(f, 2, 3);
    show(f);
    destroy(f);
    return 0;
}
