#include "create_point.h"
#include <stdlib.h>

point_t *new_point(int x, int y) {
        point_t *point = malloc(sizeof(point_t));
        if (point == NULL) {
                return NULL;
        }
        point->x = x;
        point->y = y;

        return point;
}
