#include "field.h"

#include <stdio.h>

#if 0
int fillField(struct Field* f) {
}
#endif

int main(void) {
    struct Field* f = field_init(7, 12);
    f->show(f);
    f->put(f, 0, 0);
    f->show(f);
    f->put(f, 2, 3);
    f->show(f);
    field_destroy(f);
    return 0;
}
