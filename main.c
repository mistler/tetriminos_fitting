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
    {
        struct Tetriminos* ot = newOTetriminos();
        ot->put(ot, f, 1, 1);
        printf("rot: %d\n", ot->rotate(ot));
        printf("rot: %d\n", ot->rotate(ot));
        ot->put(ot, f, 4, 4);
        f->show(f);
        ot->destroy(ot);
        free(ot);
    }

    {
        struct Tetriminos* tt = newTTetriminos();
        tt->put(tt, f, 1, 1);
        tt->put(tt, f, 3, 6);
        f->show(f);
        tt->destroy(tt);
        free(tt);
    }

    field_destroy(f);
    return 0;
}
