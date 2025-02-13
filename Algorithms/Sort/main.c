#include "sortalgs.h"
#include <stdio.h>

#define MAX_NUMS 100
#define GEN_STEP 3047
#define GEN_NUM_C 25

enum { STATUS_OK = 0, STATUS_ERR = 1, STATUS_NOGEN = 2, STATUS_INIT = -1 };

void clearbuff(void) {
  while (getchar() != '\n') {
    continue;
  }
}

void outnums(long long *ar, int num_c) {
  for (int c = 0; c < num_c; c++) {
    printf("%d> %lld\n", c + 1, ar[c]);
  }
}

int readnumbers(long long *ar, int limit) {
  int num_c = 0;
  int temp_scnf;

  printf("=> Type some numbers [end -> EOF]:\n");
  for (int c = 0; c < limit; c++) {
    num_c++;
    printf("> ");
    temp_scnf = scanf("%lld", ar + c);
    clearerr(stdin);
    clearbuff();
    if (temp_scnf == 0) {
      fprintf(stderr, "!> Invalid type\n");
      c--;
      num_c--;
    } else if (temp_scnf < 0) {
      printf("=> Written\n");
      num_c--;
      return num_c;
    }
  }
  return num_c;
}

int gennums(long long *ar, int limit) {
  char temp;
  long long gen_temp = 0;

  printf("?> Use auto-generated numbers [n/Y]: ");
  temp = getchar();
  switch (temp) {
  case '\n':
    break;
  case 'y':
    break;
  case 'Y':
    break;
  case 'n':
    return STATUS_NOGEN;
  default:
    return STATUS_ERR;
  }
  for (int c = 0; c < GEN_NUM_C; c++) {
    gen_temp += GEN_STEP * c;
    if ((c % 2) == 0) {
      ar[c] = gen_temp;
    } else {
      ar[(GEN_NUM_C - c) - 1] = gen_temp;
    }
  }
  return STATUS_OK;
}

int main(void) {
  long long array[MAX_NUMS];
  int gen_ret = STATUS_INIT;
  int numbers_cnt = STATUS_INIT;
  char sort_alg_choise = STATUS_INIT;

  printf("=> This program sorts numbers using the most popular sorting "
         "algorithms\n\n");

  while (gen_ret != STATUS_OK && gen_ret != STATUS_NOGEN) {
    gen_ret = gennums(array, MAX_NUMS);
    switch (gen_ret) {
    case STATUS_OK:
      printf("=> The numbers were generated successfully\n");
      numbers_cnt = GEN_NUM_C;
      break;
    case STATUS_ERR:
      fprintf(stderr, "!> Unknown argument\n");
      break;
    case STATUS_NOGEN:
      numbers_cnt = readnumbers(array, MAX_NUMS);
    }
  }
  outnums(array, numbers_cnt);

  while (sort_alg_choise != 'q') {
    printf("=> Choose a sorting algorithm [help -> h]: ");
    sort_alg_choise = getchar();
    clearbuff();
    switch (sort_alg_choise) {
    case 'h':
      printf("=> Help menu:\n"
             "   b <- bubble sort\n"
             "   q <- quit\n"
             "\n");
      break;
    case 'b':
      bubblesort(array, numbers_cnt);
      printf("=> Sorting... Done\n");
      outnums(array, numbers_cnt);
      break;
    case 'q':
      printf("=> Exiting...\n");
      break;
    default:
      fprintf(stderr, "!> Unknown argument\n");
    }
  }
  return STATUS_OK;
}
