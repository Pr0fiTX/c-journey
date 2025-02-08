// INFO: This alorithm sorts numbers in different orders

#include <stdio.h>

#define MAX_NUMS 10000 // max count of numbers read

int readnumbers(int *ar, int limit) {
  int numbers_readed = 0; // count of readed numbers
  int scan_temp;          // scanf() return to check

  printf("=> Type numbers [end input -> EOF, use built-in numbers -> b]:\n");
  for (int c = 0; c < limit; c++) {
    printf("> ");
    scan_temp = scanf("%d", ar + c);
    if (scan_temp == 0) {
      printf("!> Wrong data type\n");
      c--;
      continue;
    } else if (scan_temp == EOF) {
      printf("!> Ending input...\n");
      break;
    } else {
      numbers_readed++;
    }
  }
  return numbers_readed;
}

int main(void) {
  int array[MAX_NUMS];
  int numbers_count;

  printf("=> This program sorts entered numbers in various orders (using "
         "bubble sort)\n\n");

  numbers_count = readnumbers(
      array,
      MAX_NUMS); // write numbers -> array and return count of written numbers

  return 0;
}
