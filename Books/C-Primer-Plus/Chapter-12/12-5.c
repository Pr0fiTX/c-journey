#include <stdio.h>

#define NUM_COUNT 100

void num_gen(unsigned short ar[], unsigned short max) {
  unsigned long long temp;

  for (int c = 0; c < max; c++) {
    temp = 13099 * 1204 % (c + 1);
    temp = (temp % 9) + 1;
    ar[c] = (unsigned short)temp;
  }
  for (int c = 0; c < max - 1; c++) {
    for (int s = 0; s < max - 1 - c; s++) {
      if (ar[s] > ar[s + 1]) {
        temp = ar[s];
        ar[s] = ar[s + 1];
        ar[s + 1] = temp;
      }
    }
  }
}

int main(void) {
  unsigned short array[NUM_COUNT];

  num_gen(array, NUM_COUNT);
  for (int c = 0; c < NUM_COUNT; c++) {
    if (c % 10 == 0) {
      putchar('\n');
    }
    printf("%d, ", array[c]);
  }
  return 0;
}
