struct STetriminos {
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

struct Tetriminos* newSTetriminos(void);
void destroyST(struct Tetriminos* t);
