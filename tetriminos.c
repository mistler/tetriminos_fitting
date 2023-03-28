#include "tetriminos.h"

#include <assert.h>
#include <stdlib.h>

struct Tetriminos* tetriminos_init(enum TetriminosType type) {
    struct Tetriminos* t = malloc(sizeof(struct Tetriminos));
    assert(t);
    t->current_rotation = 0;
    t->type = type;
    return t;
}

void tetriminos_destroy(struct Tetriminos* t) {
    free(t);
}
