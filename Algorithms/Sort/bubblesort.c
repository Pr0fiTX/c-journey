// INFO: This alorithm sorts numbers in different orders using "bubble" sorting
// algorithm

#include <stdio.h>
#define MAX_NUMS 10000    // max count of numbers read
#define AUTOGEN_STEP 3847 // step in auto-generated array
#define AUTOGEN_NUM_C 25  // count of numbers in auto-generated array

void outarray(int *ar, int size) {
  for (int c = 0; c < size; c++) {
    printf("%d> %d\n", c + 1, ar[c]);
  }
  return;
}

void bubblesort(int *ar, int size) {
  char choice_temp;
  int sort_temp_l, sort_temp_b, is_sorted_l, is_sorted_b;

  while (1) { // exit POINT inside cycle
    printf("=> Choose sort order [all options -> h]: ");
    choice_temp = getchar();
    while (getchar() != '\n') {
      continue;
    }
    switch (choice_temp) {
    case 'h': // help menu
      printf("=> Help menu:\n     min->max --- l\n     max->min --- b\n     "
             "quit     --- q\n");
      break;
    case 'q': // INFO: EXIT POINT
      printf("=> Stoping...\n");
      return;
    case 'l': // min -> max
      for (int c = 0; c < size - 1; c++) {
        is_sorted_l = 0;
        for (int s = 0; s < size - 1 - c; s++) {
          if (ar[s] > ar[s + 1]) {
            sort_temp_l = ar[s];
            ar[s] = ar[s + 1];
            ar[s + 1] = sort_temp_l;
            is_sorted_l = 1;
          }
        }
        if (is_sorted_l == 0) {
          break;
        }
      }
      outarray(ar, size);
      break;
    case 'b': // max -> min
      for (int c = 0; c < size - 1; c++) {
        is_sorted_b = 0;
        for (int s = 0; s < size - 1 - c; s++) {
          if (ar[s] < ar[s + 1]) {
            sort_temp_b = ar[s];
            ar[s] = ar[s + 1];
            ar[s + 1] = sort_temp_b;
            is_sorted_b = 1;
          }
        }
        if (is_sorted_b == 0) {
          break;
        }
      }
      outarray(ar, size);
      break;
    default:
      fprintf(stderr, "!> Unknown option\n");
    }
  }
}

int readnumbers(int *ar, int limit) {
  int numbers_readed = 0; // count of readed numbers
  int scan_temp;          // scanf() return to check

  printf("?> Use auto-generated numbers? [Y/n]: ");
  scan_temp = getchar();
  if (scan_temp == 'Y' || scan_temp == 'y' || scan_temp == '\n') {
    printf("=> Generating numbers...\n");
    return (-1);
  }
  printf("=> Type numbers [end input -> EOF]:\n");
  for (int c = 0; c < limit; c++) {
    printf("> ");
    scan_temp = scanf("%d", ar + c);
    clearerr(stdin);
    while (getchar() != '\n') {
      continue;
    }
    if (scan_temp == 0) {
      fprintf(stderr, "!> Wrong data type\n");
      c--;
      continue;
    } else if (scan_temp == EOF) {
      printf("=> Input ended\n");
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
  int agen_temp = 0;

  printf("=> This program sorts entered numbers in various orders (using "
         "bubble sort)\n\n");

  numbers_count = readnumbers(
      array,
      MAX_NUMS); // write numbers to array and return count of written numbers
  if (numbers_count == (-1)) {
    numbers_count = 0;
    for (int c = 0; c < AUTOGEN_NUM_C; c++) {
      agen_temp += (AUTOGEN_STEP * c);
      array[c] = agen_temp;
      numbers_count++;
    }
  }
  for (int i = 0; i < numbers_count; i++) { // WARN:DB
    printf("%d\n", array[i]);
  }
  putchar('\n');

  bubblesort(array, numbers_count);

  return 0;
}
