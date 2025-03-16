#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 100

void cut_new_line(char *s) {
  char *nl_char;

  nl_char = strchr(s, '\n');
  if (nl_char) {
    *nl_char = '\0';
  }
}

void clear_buff(void) {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
  }
}

int main(void) {
  char file_name[FILE_NAME_SIZE];
  FILE *fp;
  size_t counter = 0;
  int ch;

  while (true) { // Body of entire program
    printf("?> Type the name of the file to be opened: ");
    if (fgets(file_name, FILE_NAME_SIZE, stdin) == NULL) {
      printf("!> An error occurred while reading the file name.\n");
      clear_buff();
      continue;
    }
    cut_new_line(file_name);

    fp = fopen(file_name, "r");
    if (fp == NULL) {
      printf("!> The file doesn't exist or is unreadable.\n");
      continue;
    }
    printf("=> File opened succesfuly.\n");

    while ((ch = getc(fp)) != EOF) {
      counter++;
    }
    printf("=> File: %s\n> Count of characters -> %zu\n", file_name, counter);
    fclose(fp);
    return EXIT_SUCCESS;
  }
}
