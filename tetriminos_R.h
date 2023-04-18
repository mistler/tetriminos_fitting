struct RTetriminos {
    void* base;

    int coords[4][4][2];
    int maxRotation;
    int currentRotation;

    int (*rotate)(struct Tetriminos*);
    int (*put)(struct Tetriminos*, struct Field* f, int x, int y, int value);

    void (*destroy)(struct Tetriminos*);

    int (*isUsed)(struct Tetriminos*);
    void (*setUsed)(struct Tetriminos*, int val);
};

struct Tetriminos* newRTetriminos(void);
void destroyRT(struct Tetriminos* t);
