#include "field.h"
#include "tetriminos.h"

#include <stdio.h>
#include <stdlib.h>

int fillField(struct Field* f, struct Tetriminos** ts, int nFigures, int placedFigures, int n, int m) {
    if (placedFigures == nFigures) {
        f->show(f);
        return 1;
    }
    struct Tetriminos* t = ts[placedFigures];
    for (int rot = 0; rot < 4; ++rot) {
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                const int isPlaced = t->put(t, f, x, y, placedFigures + 1 + 'a');
                if (isPlaced) {
                    const int isFilled = fillField(f, ts, nFigures, placedFigures + 1, n, m);
                    if (isFilled) {
                        return 1;
                    }
                    t->put(t, f, x, y, 0);
                }
            }
        }
        const int isRotated = t->rotate(t);
        if (!isRotated) {
            break;
        }
    }
    return 0;
}

#define ADD_FIGURE(nFigures, ts, figGenerator) do { \
        ts[nFigures++] = figGenerator(); \
    } while (0)


int main(void) {
    const int n = 4;
    const int m = 4;

    struct Field* f = field_init(n, m);

    int nFigures = 0;
    struct Tetriminos** ts = malloc(sizeof(struct Tetriminos*) * 100);

    ADD_FIGURE(nFigures, ts, newSTetriminos);
    ADD_FIGURE(nFigures, ts, newTTetriminos);
    ADD_FIGURE(nFigures, ts, newTTetriminos);
    ADD_FIGURE(nFigures, ts, newRTetriminos);

#if 0
    for (int i = 0; i < 3; ++i) {
        ADD_FIGURE(nFigures, ts, newITetriminos);
        ADD_FIGURE(nFigures, ts, newLTetriminos);
        ADD_FIGURE(nFigures, ts, newOTetriminos);
        ADD_FIGURE(nFigures, ts, newRTetriminos);
        ADD_FIGURE(nFigures, ts, newSTetriminos);
        ADD_FIGURE(nFigures, ts, newTTetriminos);
        ADD_FIGURE(nFigures, ts, newZTetriminos);
    }
#endif


    const int ret = fillField(f, ts, nFigures, 0, n, m);
    printf("ret %d\n", ret);


    for (int i = 0; i < nFigures; ++i) {
        free(ts[i]);
    }
    free(ts);

    field_destroy(f);
    return 0;
}
