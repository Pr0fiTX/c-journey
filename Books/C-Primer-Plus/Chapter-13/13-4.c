// This program prints the files data into terminal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

void open_and_print_file(char *path) {
  FILE *fp;
  char buff[BUFF_SIZE];

  printf("-= %s =-\n", path);
  fp = fopen(path, "r");
  if (!fp) {
    printf("!> Incorrect path, permissions issue or buy more ram.\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(buff, BUFF_SIZE, fp)) {
    fputs(buff, stdout);
  }
  putc('\n', stdout);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("!> Not enough argumets. Try \"./[program_name] help\" for help.\n");
    return EXIT_FAILURE;
  }
  if (!strcmp(argv[1], "help")) {
    printf("Help Menu:\n   Usage: program_name \"FILE_NAME1\" "
           "...\n");
    return EXIT_SUCCESS;
  }

  for (int i = 1; i < argc; i++) {
    open_and_print_file(argv[i]);
  }
  return EXIT_SUCCESS;
}
