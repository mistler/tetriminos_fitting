#include "field.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Field {
    int n, m;
    int* field;
};

struct Field* init(int n, int m) {
    struct Field* f = malloc(sizeof(struct Field));
    assert(f);
    f->n = n;
    f->m = m;
    f->field = calloc(n * m, sizeof(int));
    assert(f->field);
    return f;
}

void destroy(struct Field* f) {
    free(f->field);
    free(f);
}

int is_empty(const struct Field* f, int x, int y) {
   if (x < 0 || x >= f->n) {
       return 0;
   }
   if (y < 0 || y >= f->m) {
       return 0;
   }
   return !f->field[x + y * f->n];
}

void put(struct Field* f, int x, int y) {
    if (!is_empty(f, x, y)) {
        return;
    }
    f->field[x + y * f->n] = 1;
}

void show(const struct Field* f) {
    for (int x = 0; x < f->n + 4; ++x) {
        printf("-");
    }
    printf("\n");

    for (int y = f->m - 1; y >= 0; --y) {
        printf("%2d|", y);
        for (int x = 0; x < f->n; ++x) {
            char out = is_empty(f, x, y) ? '*' : 'X';
            printf("%c", out);
        }
        printf("|\n");
    }

    printf("---");
    for (int x = 0; x < f->n; ++x) {
        printf("%d", x);
    }
    printf("-");
    printf("\n");

    for (int x = 0; x < f->n + 4; ++x) {
        printf("-");
    }

    printf("\n");
}
