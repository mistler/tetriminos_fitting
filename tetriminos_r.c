#include "tetriminos.h"

#include "field.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void destroyRT(struct Tetriminos* t) {
    printf("destroyRT\n");
    struct RTetriminos* curr = (struct RTetriminos*)t;
    struct Tetriminos* base = curr->base;
    base->destroy(base);
    free(base);
}

struct Tetriminos* newRTetriminos(void) {
    printf("newRTetriminos\n");
    struct RTetriminos* t = malloc(sizeof(*t));
    assert(t);

    t->base = newTetriminos();
    ((struct Tetriminos*)t->base)->derived = t;

    t->rotate = ((struct Tetriminos*)t->base)->rotate;
    t->put = ((struct Tetriminos*)t->base)->put;

    t->destroy = &destroyRT;

    t->isUsed = ((struct Tetriminos*)t->base)->isUsed;
    t->setUsed = ((struct Tetriminos*)t->base)->setUsed;


    t->coords[0][0][0] = 0;
    t->coords[0][0][1] = 0;

    t->coords[0][1][0] = 0;
    t->coords[0][1][1] = 1;

    t->coords[0][2][0] = 0;
    t->coords[0][2][1] = 2;

    t->coords[0][3][0] = 1;
    t->coords[0][3][1] = 2;




    t->coords[1][0][0] = 0;
    t->coords[1][0][1] = 1;

    t->coords[1][1][0] = 1;
    t->coords[1][1][1] = 1;

    t->coords[1][2][0] = 2;
    t->coords[1][2][1] = 1;

    t->coords[1][3][0] = 2;
    t->coords[1][3][1] = 0;



    t->coords[2][0][0] = 0;
    t->coords[2][0][1] = 0;

    t->coords[2][1][0] = 1;
    t->coords[2][1][1] = 0;

    t->coords[2][2][0] = 1;
    t->coords[2][2][1] = 1;

    t->coords[2][3][0] = 1;
    t->coords[2][3][1] = 2;



    t->coords[3][0][0] = 0;
    t->coords[3][0][1] = 0;

    t->coords[3][1][0] = 1;
    t->coords[3][1][1] = 0;

    t->coords[3][2][0] = 2;
    t->coords[3][2][1] = 0;

    t->coords[3][3][0] = 0;
    t->coords[3][3][1] = 1;

    t->maxRotation = 4;

    return (struct Tetriminos*)t;
};
