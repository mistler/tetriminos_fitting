#include "tetriminos.h"

#include "field.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void destroyTetriminos(struct Tetriminos* t) {
    printf("destroyTetriminos\n");
}

int isUsedTetriminos(struct Tetriminos* t) {
    printf("isUsedTetriminos\n");
    return t->isUsedVal;
}

int put(struct Tetriminos* t, struct Field* f, int x, int y) {
    printf("put\n");
    int is_empty = 0;
    for (int i = 0; i < 4; ++i) {
        const int xi = t->coords[t->currentRotation][i][0];
        const int yi = t->coords[t->currentRotation][i][1];
        is_empty += f->is_empty(f, x + xi, y + yi);
    }
    if (is_empty != 4) {
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        const int xi = t->coords[t->currentRotation][i][0];
        const int yi = t->coords[t->currentRotation][i][1];
        f->put(f, x + xi, y + yi);
    }
    return 1;
}

int rotate(struct Tetriminos* t) {
    printf("rotate\n");
    t->currentRotation += 1;
    if (t->currentRotation == t->maxRotation) {
        t->currentRotation = 0;
        return 0;
    }
    return 1;
}

void setUsedTetriminos(struct Tetriminos* t, int val) {
    printf("setUsedTetriminos\n");
    t->isUsedVal = val;
}

struct Tetriminos* newTetriminos(void) {
    printf("newTetriminos\n");
    struct Tetriminos* t = malloc(sizeof(*t));
    assert(t);

    t->derived = NULL;

    t->rotate = &rotate;
    t->put = &put;

    t->destroy = &destroyTetriminos;

    t->isUsed = &isUsedTetriminos;
    t->setUsed = &setUsedTetriminos;

    t->currentRotation = 0;
    t->isUsedVal = 0;

    return t;
};


// ========= DERIVED =====
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
