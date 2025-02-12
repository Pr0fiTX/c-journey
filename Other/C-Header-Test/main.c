#include "printer.h"
#include <stdio.h>

#define MAX_STR 10
#define MAX_CHARS 128

int main(void) {
  char array[MAX_STR][MAX_CHARS];

  printf("=> Type some strings\n");
  for (int s = 0; s < MAX_STR; s++) {
    putchar('>');
    fgets(array[s], MAX_CHARS - 1, stdin);
  }
  print_a_string(MAX_CHARS, MAX_STR, array);
}
