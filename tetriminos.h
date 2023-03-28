#pragma once

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
    void (*rotate)(struct Tetriminos*);

    enum TetriminosType type;
    int current_rotation;
};

struct Tetriminos* tetriminos_init(enum TetriminosType type);
void tetriminos_destroy(struct Tetriminos*);
