#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_the_dice(unsigned int throws, unsigned int facets,
                   unsigned int dices) {
  int temp;
  unsigned int results[throws];

  for (int c = 0; c < throws; c++) {
    results[c] = 0;
  }

  srand((unsigned int)time(0));
  for (int t = 0; t < throws; t++) {
    for (int d = 0; d < dices; d++) {
      results[t] += (rand() % facets) + 1;
    }
  }

  for (int c = 0; c < throws; c++) {
    printf("[%u]", results[c]);
  }
  putchar('\n');
}

void buffc(void) {
  while (getchar() != '\n')
    continue;
}
