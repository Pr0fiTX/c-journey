#include "printer.h"
#include <stdio.h>

void print_a_string(int c_chr, int c_str, const char ar[][c_chr]) {
  for (int c = 0; c < c_str; c++) {
    printf("%d> %s", c + 1, ar[c]);
  }
  return;
}
