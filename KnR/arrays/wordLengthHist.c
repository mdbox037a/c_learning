#include <stdio.h>

#define IN 1
#define OUT 0
#define GO 0
#define STOP 1

int main() {
  int c, i, j, last_entry, stopper, state, length;
  int lengths[22];

  state = OUT;
  length = 0;

  // write all 0's to locations at each index
  for (i = 0; i < 22; ++i)
    lengths[i] = 0;

  while ((c = getchar()) != '\n') {
    if ((c == ' ' || c == '\t') && state == IN) {
      state = OUT;
      ++lengths[0]; // I count the spaces, but don't present them later in the
                    // histogram - maybe we'll use them later
      ++lengths[length];
      length = 0;
    } else if ((c == ' ' || c == '\t') && state == OUT) {
      ++lengths[0];
    } else if (state == OUT) {
      state = IN;
      ++length; // TODO: this creates an array overflow if the word is more than
                // 21 characters long - need to fix in next update
    } else { // TODO: this could be interesting to compare machine code length
             // between have elseif/else for characters vs. just else and always
             // setting state
      ++length;
    }
  }

  // printf("debug: %d\n", length);
  // dump the very last word length into the array
  ++lengths[length];

  // TODO: once you reach the last array counter, stop printing histogram

  // find the highest word length in the array in order to use it later to stop
  // the histogram there
  stopper = GO;
  last_entry = 21;

  while (stopper == GO) {
    if (lengths[last_entry] == 0)
      --last_entry;
    else
      stopper = STOP;
  }

  // debug
  // printf("last entry: %d\n", last_entry);

  printf("======Word Lengths Histogram=====\n");

  for (i = 1; i < (last_entry + 1); ++i) {
    if (i == 21)
      printf("21+:");
    else
      printf("%3d:", i);

    if (lengths[i] != 0) {
      for (j = 0; j < lengths[i]; ++j) {
        printf("|");
      }
    } else {
      ;
    }
    printf("\n");
  }
}

/* Okay, this is just v1 to get tracking of word lengths, but I already think v2
 * is going to be almost a complete rewrite, so I may copy and edit in a new
 * file...  I think it might work if I can create an array for each word length
 * maybe?  make that dynamic somehow - like maybe initialize with a length once
 * the word has already been counted.  I don't know.  Just a thought - need to
 * come back */
