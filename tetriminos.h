#pragma once

struct Field;
struct Tetriminos;

#include "tetriminos_I.h"
#include "tetriminos_L.h"
#include "tetriminos_O.h"
#include "tetriminos_R.h"
#include "tetriminos_S.h"
#include "tetriminos_T.h"
#include "tetriminos_Z.h"

enum TetriminosType {
    T,
    L,
    I,
    o,
    r,
    Z,
    S,
};

struct Tetriminos {
    void* derived;

    int coords[4][4][2];
    int maxRotation;
    int currentRotation;

    int (*rotate)(struct Tetriminos*);
    int (*put)(struct Tetriminos*, struct Field* f, int x, int y, int value);

    void (*destroy)(struct Tetriminos*);

    int (*isUsed)(struct Tetriminos*);
    void (*setUsed)(struct Tetriminos*, int val);

    int isUsedVal;
};

struct Tetriminos* newTetriminos(void);
void destroyTetriminos(struct Tetriminos* t);
int isUsedTetriminos(struct Tetriminos* t);
void setUsedTetriminos(struct Tetriminos* t, int val);

int put(struct Tetriminos* t, struct Field* f, int x, int y, int value);
int rotate(struct Tetriminos* t);
