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

struct Tetriminos* newTetriminos(void);
void destroyTetriminos(struct Tetriminos* t);
int isUsedTetriminos(struct Tetriminos* t);
void setUsedTetriminos(struct Tetriminos* t, int val);

struct Tetriminos {
    void* derived;

    int (*rotate)(struct Tetriminos*);
    int (*put)(struct Tetriminos*, struct Field* f, int x, int y);

    void (*destroy)(struct Tetriminos*);

    int (*isUsed)(struct Tetriminos*);
    void (*setUsed)(struct Tetriminos*, int val);

    int currentRotation;
    int isUsedVal;
};

struct Tetriminos* newOTetriminos(void);
void destroyOT(struct Tetriminos* t);

int rotateOT(struct Tetriminos*);
int putOT(struct Tetriminos* t, struct Field* f, int x, int y);

struct OTetriminos {
    void* base;

    int (*rotate)(struct Tetriminos*);
    int (*put)(struct Tetriminos*, struct Field* f, int x, int y);

    void (*destroy)(struct Tetriminos*);

    int (*isUsed)(struct Tetriminos*);
    void (*setUsed)(struct Tetriminos*, int val);
};

struct Tetriminos* newOTetriminos(void);
void destroyOT(struct Tetriminos* t);

int rotateOT(struct Tetriminos*);
int putOT(struct Tetriminos* t, struct Field* f, int x, int y);
