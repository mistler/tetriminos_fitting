#include "tetriminos.h"

#include "field.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void destroyOT(struct Tetriminos* t) {
    printf("destroyOT\n");
    struct OTetriminos* curr = (struct OTetriminos*)t;
    struct Tetriminos* base = curr->base;
    base->destroy(base);
    free(base);
}

struct Tetriminos* newOTetriminos(void) {
    printf("newOTetriminos\n");
    struct OTetriminos* t = malloc(sizeof(*t));
    assert(t);

    t->base = newTetriminos();
    ((struct Tetriminos*)t->base)->derived = t;

    t->rotate = ((struct Tetriminos*)t->base)->rotate;
    t->put = ((struct Tetriminos*)t->base)->put;

    t->destroy = &destroyOT;

    t->isUsed = ((struct Tetriminos*)t->base)->isUsed;
    t->setUsed = ((struct Tetriminos*)t->base)->setUsed;

    t->coords[0][0][0] = 0;
    t->coords[0][0][1] = 0;

    t->coords[0][1][0] = 0;
    t->coords[0][1][1] = 1;

    t->coords[0][2][0] = 1;
    t->coords[0][2][1] = 0;

    t->coords[0][3][0] = 1;
    t->coords[0][3][1] = 1;

    t->maxRotation = 1;

    return (struct Tetriminos*)t;
};
