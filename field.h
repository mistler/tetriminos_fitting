#pragma once

#include <stddef.h>

struct Field{
    int (*is_empty)(const struct Field*, int x, int y);
    void (*put)(struct Field*, int x, int y);

    void (*show)(const struct Field*);

    int n, m;
    int* field;
};

struct Field* field_init(int n, int m);
void field_destroy(struct Field*);
