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

void setUsedTetriminos(struct Tetriminos* t, int val) {
    printf("setUsedTetriminos\n");
    t->isUsedVal = val;
}

struct Tetriminos* newTetriminos(void) {
    printf("newTetriminos\n");
    struct Tetriminos* t = malloc(sizeof(*t));
    assert(t);

    t->derived = NULL;

    t->rotate = NULL;
    t->put = NULL;

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

int rotateOT(struct Tetriminos* t) {
    printf("rotateOT\n");
    return 0;
}

int putOT(struct Tetriminos* t, struct Field* f, int x, int y) {
    printf("putOT\n");
    int is_empty = 0;
    is_empty += f->is_empty(f, x, y) + f->is_empty(f, x + 1, y) +
                f->is_empty(f, x, y + 1) + f->is_empty(f, x + 1, y + 1);
    if (is_empty != 4) {
        return 0;
    }
    f->put(f, x, y);
    f->put(f, x + 1, y);
    f->put(f, x, y + 1);
    f->put(f, x + 1, y + 1);
    return 1;
}

struct Tetriminos* newOTetriminos(void) {
    printf("newOTetriminos\n");
    struct OTetriminos* t = malloc(sizeof(*t));
    assert(t);

    t->base = newTetriminos();
    ((struct Tetriminos*)t->base)->derived = t;

    t->rotate = &rotateOT;
    t->put = &putOT;

    t->destroy = &destroyOT;

    t->isUsed = ((struct Tetriminos*)t->base)->isUsed;
    t->setUsed = ((struct Tetriminos*)t->base)->setUsed;

    return (struct Tetriminos*)t;
};
