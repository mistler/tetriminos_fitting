#include "tetriminos.h"

#include "field.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void destroyZT(struct Tetriminos* t) {
    printf("destroyZT\n");
    struct ZTetriminos* curr = (struct ZTetriminos*)t;
    struct Tetriminos* base = curr->base;
    base->destroy(base);
    free(base);
}

struct Tetriminos* newZTetriminos(void) {
    printf("newZTetriminos\n");
    struct ZTetriminos* t = malloc(sizeof(*t));
    assert(t);

    t->base = newTetriminos();
    ((struct Tetriminos*)t->base)->derived = t;

    t->rotate = ((struct Tetriminos*)t->base)->rotate;
    t->put = ((struct Tetriminos*)t->base)->put;

    t->destroy = &destroyZT;

    t->isUsed = ((struct Tetriminos*)t->base)->isUsed;
    t->setUsed = ((struct Tetriminos*)t->base)->setUsed;

    t->coords[0][0][0] = 0;
    t->coords[0][0][1] = 1;

    t->coords[0][1][0] = 1;
    t->coords[0][1][1] = 1;

    t->coords[0][2][0] = 1;
    t->coords[0][2][1] = 0;

    t->coords[0][3][0] = 2;
    t->coords[0][3][1] = 0;




    t->coords[1][0][0] = 0;
    t->coords[1][0][1] = 0;

    t->coords[1][1][0] = 0;
    t->coords[1][1][1] = 1;

    t->coords[1][2][0] = 1;
    t->coords[1][2][1] = 1;

    t->coords[1][3][0] = 1;
    t->coords[1][3][1] = 2;

    t->maxRotation = 2;

    return (struct Tetriminos*)t;
};
