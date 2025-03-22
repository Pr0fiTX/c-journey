// This program prints the files data into terminal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

void open_and_print_file(const char *path) {
  FILE *fp;
  char buff[BUFF_SIZE];

  printf("-= %s =-\n", path);
  fp = fopen(path, "r");
  if (!fp) {
    perror("!> fopen() failed");
    putc('\n', stdout);
    return;
  }
  while (fgets(buff, BUFF_SIZE, fp)) {
    fputs(buff, stdout);
  }
  putc('\n', stdout);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("!> Not enough arguments. Try \"%s help\" for help.\n", argv[0]);
    return EXIT_FAILURE;
  }
  if (!strcmp(argv[1], "help")) {
    printf("Help Menu:\n   Usage: %s \"FILE_NAME1\" ...\n", argv[0]);
    return EXIT_SUCCESS;
  }

  for (int i = 1; i < argc; i++) {
    open_and_print_file(argv[i]);
  }
  return EXIT_SUCCESS;
}
