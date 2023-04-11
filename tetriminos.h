#pragma once

struct Field;

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
    int (*put)(struct Tetriminos*, struct Field* f, int x, int y);

    void (*destroy)(struct Tetriminos*);

    int (*isUsed)(struct Tetriminos*);
    void (*setUsed)(struct Tetriminos*, int val);

    int isUsedVal;
};

struct Tetriminos* newTetriminos(void);
void destroyTetriminos(struct Tetriminos* t);
int isUsedTetriminos(struct Tetriminos* t);
void setUsedTetriminos(struct Tetriminos* t, int val);

int put(struct Tetriminos* t, struct Field* f, int x, int y);
int rotate(struct Tetriminos* t);

struct OTetriminos {
    void* base;

    int coords[4][4][2];
    int maxRotation;
    int currentRotation;

    int (*rotate)(struct Tetriminos*);
    int (*put)(struct Tetriminos*, struct Field* f, int x, int y);

    void (*destroy)(struct Tetriminos*);

    int (*isUsed)(struct Tetriminos*);
    void (*setUsed)(struct Tetriminos*, int val);
};

struct Tetriminos* newOTetriminos(void);
void destroyOT(struct Tetriminos* t);
