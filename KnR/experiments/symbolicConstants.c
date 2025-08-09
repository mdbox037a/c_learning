#include <stdio.h>

// symbolic constants
/* any occurance of that *name* (outside of quotes or as part of another name)
 * will be replaced by the corresponding replacement text; can be any sequence
 * of characters (not limited to numbers); usually written in UPPER_CASE; no
 * ";"*/

#define LOWER 0
#define UPPER 100

int main() {
  for (int i = LOWER; i <= UPPER; i++)
    printf("%d", i);
}
