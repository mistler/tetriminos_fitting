#include "field.h"
#include "tetriminos.h"

#include <stdio.h>
#include <stdlib.h>

#if 0
int fillField(struct Field* f) {
}
#endif

int main(void) {
    struct Field* f = field_init(7, 12);
    f->show(f);
    struct Tetriminos* ot = newOTetriminos();
    ot->put(ot, f, 1, 1);
    f->show(f);
    ot->destroy(ot);
    free(ot);
    field_destroy(f);
    return 0;
}
