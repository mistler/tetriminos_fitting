#include "field.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int is_empty(const struct Field* self, int x, int y) {
   if (x < 0 || x >= self->n) {
       return 0;
   }
   if (y < 0 || y >= self->m) {
       return 0;
   }
   return !self->field[x + y * self->n];
}

static void put(struct Field* self, int x, int y, int value) {
    if (value) {
        if (!is_empty(self, x, y)) {
            return;
        }
    }
    self->field[x + y * self->n] = value;
}

static void show(const struct Field* self) {
    for (int x = 0; x < self->n + 4; ++x) {
        printf("-");
    }
    printf("\n");

    for (int y = self->m - 1; y >= 0; --y) {
        printf("%2d|", y);
        for (int x = 0; x < self->n; ++x) {
            char out = is_empty(self, x, y) ? '*' : self->field[x + y * self->n];
            printf("%c", out);
        }
        printf("|\n");
    }

    printf("---");
    for (int x = 0; x < self->n; ++x) {
        printf("%d", x);
    }
    printf("-");
    printf("\n");

    for (int x = 0; x < self->n + 4; ++x) {
        printf("-");
    }

    printf("\n");
}

struct Field* field_init(int n, int m) {
    assert(n > 0);
    assert(m > 0);

    struct Field* self = malloc(sizeof(struct Field));
    assert(self);
    self->n = n;
    self->m = m;
    self->field = calloc(n * m, sizeof(int));
    assert(self->field);

    self->is_empty = &is_empty;
    self->put = &put;
    self->show = &show;
    return self;
}

void field_destroy(struct Field* self) {
    free(self->field);
    free(self);
}
