#include <stdio.h>

int main() {
  int weight;
  int planet;
  float modified_weight;

  printf("---Space Weight Calculator---\n");
  printf("What is your weight in pounds? ");
  scanf("%i", &weight);
  printf("Which planet will you be visiting?\n");
  printf("1 = Mercury, 2 = Venus, 3 = Mars, 4 = Earth, 5 = Jupiter, 6 = "
         "Saturn, 7 = Uranus, 8 = Neptune\n");
  printf("Your choice? ");
  scanf("%i", &planet);

  switch (planet) {
  case 1:
    modified_weight = weight * 0.38;
    break;
  case 2:
    modified_weight = weight * 0.91;
    break;
  case 3:
    modified_weight = weight * 0.38;
    break;
  case 4:
    modified_weight = weight * 1.00;
    break;
  case 5:
    modified_weight = weight * 2.34;
    break;
  case 6:
    modified_weight = weight * 1.06;
    break;
  case 7:
    modified_weight = weight * 0.92;
    break;
  case 8:
    modified_weight = weight * 1.19;
    break;
  default:
    printf("error!");
  }

  printf("Your weight on that planet would be %.2f!\n", modified_weight);
}
