#include "sortalgs.h"

void bubblesort(long long *ar, int num_c) {
  int temp;

  for (int c = 0; c < num_c - 1; c++) {
    for (int s = 0; s < num_c - c - 1; s++) {
      if (ar[s] > ar[s + 1]) {
        temp = ar[s];
        ar[s] = ar[s + 1];
        ar[s + 1] = temp;
      }
    }
  }
}
