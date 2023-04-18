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

int put(struct Tetriminos* t, struct Field* f, int x, int y, int value) {
    // printf("Tetriminos::put %d %d %d\n", x, y, value);
    if (value) {
        int is_empty = 0;
        for (int i = 0; i < 4; ++i) {
            const int xi = t->coords[t->currentRotation][i][0];
            const int yi = t->coords[t->currentRotation][i][1];
            is_empty += f->is_empty(f, x + xi, y + yi);
        }
        if (is_empty != 4) {
            return 0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        const int xi = t->coords[t->currentRotation][i][0];
        const int yi = t->coords[t->currentRotation][i][1];
        f->put(f, x + xi, y + yi, value);
    }
    return 1;
}

int rotate(struct Tetriminos* t) {
    // printf("rotate\n");
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
