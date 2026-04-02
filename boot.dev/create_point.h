#pragma once
#include <stdlib.h>

typedef struct Point {
        int x;
        int y;
} point_t;

point_t *new_point(int x, int y);
