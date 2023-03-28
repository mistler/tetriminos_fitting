#pragma once

#include <stddef.h>

struct Field;

struct Field* init(int n, int m);
void destroy(struct Field*);

int is_empty(const struct Field*, int x, int y);
void put(struct Field*, int x, int y);

void show(const struct Field*);
