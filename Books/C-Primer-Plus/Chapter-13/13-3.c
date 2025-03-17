// This program asks the user for the file paths and copies data from the first
// to the second + upper all letters :)
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LEN 1024
#define BUFF_SIZE 512

void copy_upper_put(FILE *fp_from, FILE *fp_to) {
  char buff[BUFF_SIZE];

  printf("?> Do you wish to continue? [y/N]: ");
  if (getchar() == 'y') {
    printf("=> Starting...\n");
  } else {
    printf("=> Stopped.\n");
    return;
  }

  while (fgets(buff, BUFF_SIZE, fp_from) != NULL) {
    for (int i = 0; buff[i] != '\0'; i++) {
      buff[i] = toupper(buff[i]);
      putc(buff[i], fp_to);
    }
  }
  printf("=> Done!\n");
}

FILE *open_from(char *path) {
  FILE *fp;

  printf("?> The path to the file to copy from: ");
  fgets(path, MAX_PATH_LEN, stdin);
  for (int i = 0; i < MAX_PATH_LEN; i++) {
    if (path[i] == '\n') {
      path[i] = '\0';
      break;
    }
  }
  if (!(fp = fopen(path, "r"))) {
    printf("!> File doesn't exist.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("=> File opened successfully.\n");
  }
  return fp;
}

FILE *open_to(char *path) {
  FILE *fp;

  printf("?> Path to the file to copy to: ");
  fgets(path, MAX_PATH_LEN, stdin);
  for (int i = 0; i < MAX_PATH_LEN; i++) {
    if (path[i] == '\n') {
      path[i] = '\0';
      break;
    }
  }
  if (!(fp = fopen(path, "w"))) {
    printf("!> Directory doesn't exist or permissions issue.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("=> File opened successfully.\n");
  }
  return fp;
}

int main(void) {
  char path_from[MAX_PATH_LEN];
  char path_to[MAX_PATH_LEN];
  FILE *fp_from;
  FILE *fp_to;

  fp_from = open_from(path_from);
  fp_to = open_to(path_to);
  copy_upper_put(fp_from, fp_to);

  fclose(fp_from);
  fclose(fp_to);
  return EXIT_SUCCESS;
}
