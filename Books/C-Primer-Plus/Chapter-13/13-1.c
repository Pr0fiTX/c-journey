#include <stdbool.h>
#include <stdio.h>

const short FILE_NAME_SIZE = 100;

void cutnewline(char *s) {
  int c = 0;

  while (s[c] != '\n' && s[c] != '\0') {
    c++;
  }
  if (s[c] == '\n') {
    s[c] = '\0';
  }
  return;
}

void cbuff(void) {
  while (getchar() != '\n') {
    continue;
  }
}

int main(void) {
  char file_name[FILE_NAME_SIZE];
  FILE *file_p;
  unsigned long counter = 0;
  int ch;

  while (true) { // Body of entire program
    printf("?> Type the name of the file to be opened: ");
    if (fgets(file_name, FILE_NAME_SIZE, stdin) == NULL) {
      printf("!> An error occurred while reading the file name.\n");
      cbuff();
      continue;
    }
    cutnewline(file_name);

    file_p = fopen(file_name, "r");
    if (file_p == NULL) {
      printf("!> The file doesn't exist or is unreadable.\n");
      continue;
    }
    printf("=> File opned succesfuly.\n");

    ch = getc(file_p);
    while (ch != EOF) {
      ch = getc(file_p);
      counter++;
    }
    printf("=> File: %s\n> Count of letters -> %lu\n", file_name, counter);
    return 0;
  }
  return 0;
}
