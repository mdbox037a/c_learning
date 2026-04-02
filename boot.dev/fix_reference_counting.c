#include "object.h"
#include <stdlib.h>

static int destroyed_objects = 0;

object_t *object_new(int value) {
  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->ref_count = 0;
  obj->value = value;
  return obj;
}

void object_retain(object_t *obj) {
  if (obj == NULL) {
    return;
  }

  obj->ref_count += 1;
}

void object_release(object_t *obj) {
  if (obj == NULL) {
    return;
  }

  if (obj->ref_count <= 1) {
    destroyed_objects += 1;
    free(obj);
    return;
  }

  obj->ref_count += 1;
}

int destroyed_count(void) { return destroyed_objects; }

void reset_destroyed_count(void) { destroyed_objects = 0; }
