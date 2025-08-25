#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, i, state, length;
  int lengths[22];

  state = OUT;
  length = 0;

  // write all 0's to locations at each index
  for (i = 0; i < 22; ++i)
    lengths[i] = 0;

  while ((c = getchar()) != '\n') {
    if ((c == ' ' || c == '\t') && state == IN) {
      state = OUT;
      ++lengths[0];
      ++lengths[length];
      length = 0;
    } else if ((c == ' ' || c == '\t') && state == OUT) {
      ++lengths[0];
    } else if (state == OUT) {
      state = IN;
      ++length;
    } else { // TODO: this could be interesting to compare machine code length
             // between have elseif/else for characters vs. just else and always
             // setting state
      ++length;
    }
  }

  // printf("debug: %d\n", length);
  // dump the very last word length into the array
  ++lengths[length];

  // TODO: instead of printing numbers, print a histogram
  for (i = 0; i < 22; ++i) {
    printf("%d: %d\n", i, lengths[i]);
  }
}

/* Okay, this is just v1 to get tracking of word lengths, but I already think v2
 * is going to be almost a complete rewrite, so I may copy and edit in a new
 * file...  I think it might work if I can create an array for each word length
 * maybe?  make that dynamic somehow - like maybe initialize with a length once
 * the word has already been counted.  I don't know.  Just a thought - need to
 * come back */
