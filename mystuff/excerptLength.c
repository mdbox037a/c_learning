#include <stdio.h>

// a small experimental program to help predict how long it takes to play an
// excerpt

int main() {

  printf("### Excerpt Timer v1 ###\n");

  int tempo;
  int meter;
  int measures;

  printf("What is the tempo of the excerpt? ");
  scanf("%d", &tempo);

  printf("How many beats per bar are there (mostly)? ");
  scanf("%d", &meter);

  printf("How many measures are there in the excerpt? ");
  scanf("%d", &measures);

  int excerpt_beats = meter * measures;
  int excerpt_seconds = (excerpt_beats * 60) / tempo;
  int excerpt_minutes = excerpt_seconds / 60;
  int remainder = excerpt_seconds - (excerpt_minutes * 60);

  printf("---------------------------------------\n");
  printf("The excerpt should take about %i minutes and %i seconds to play\n",
         excerpt_minutes, remainder);

  // check values for debugging
  // printf("%d\n", tempo);
}
