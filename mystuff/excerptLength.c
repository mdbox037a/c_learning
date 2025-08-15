#include <stdio.h>
#include <string.h>

// a small experimental program to help predict how long it takes to play an
// excerpt

int main() {

  int choice = 1;

  int tempo;
  int meter;
  int measures;

  int excerpt_beats;
  int excerpt_seconds;
  int excerpt_minutes;
  int excerpt_remainder;

  char min_unit[8];
  char sec_unit[8];

  int total_seconds = 0;
  int total_minutes;
  int total_remainder;

  int retry = 1;
  int counter = 0;

  printf("\n### Excerpt Timer v2.3 ###\n"); // TODO: create variable for version

  while (choice == 1) {

    printf("\nWhat is the tempo of the excerpt? ");
    scanf("%d", &tempo);

    printf("How many beats per bar are there (mostly)? ");
    scanf("%d", &meter);

    printf("How many measures are there in the excerpt? ");
    scanf("%d", &measures);

    // this is a bit bulky, but I have some plans for the intermediate variables
    // in future updates

    excerpt_beats = meter * measures;
    excerpt_seconds = (excerpt_beats * 60) / tempo;
    excerpt_minutes = excerpt_seconds / 60;
    excerpt_remainder = excerpt_seconds - (excerpt_minutes * 60);

    total_seconds += excerpt_seconds;
    total_minutes = total_seconds / 60;
    total_remainder = total_seconds - (total_minutes * 60);

    printf("---------------------------------------\n");

    if (excerpt_minutes == 1) {
      strcpy(min_unit, "minute");
    } else {
      strcpy(min_unit, "minutes");
    }

    if (excerpt_remainder == 1) {
      strcpy(sec_unit, "second");
    } else {
      strcpy(sec_unit, "seconds");
    }

    printf("The excerpt should take about %i %s and %i %s to play\n\n",
           excerpt_minutes, min_unit, excerpt_remainder, sec_unit);

    if (total_minutes == 1) {
      strcpy(min_unit, "minute");
    } else {
      strcpy(min_unit, "minutes");
    }

    if (total_remainder == 1) {
      strcpy(sec_unit, "second");
    } else {
      strcpy(sec_unit, "seconds");
    }

    if (counter > 0) {
      printf("Together, these %i excerpts should take about %i %s and %i "
             "%s to play\n",
             counter, total_minutes, min_unit, total_remainder, sec_unit);
    }

    retry = 1;

    while (retry == 1) {
      printf("Would you like to add another excerpt time to this total?\n [1 = "
             "yes, 2 = no] ");
      scanf("%d", &choice);

      if (choice == 2) {
        printf("\n### Thank you for using excerptTimer! ###\n");
        retry = 0;
      } else if (choice == 1) {
        counter++;
        retry = 0;
      } else {
        printf("\nThat is not a valid choice...\n");
        retry = 1;
      }
    }
  }

  // check values for debugging
  // printf("%d\n", tempo);
}
