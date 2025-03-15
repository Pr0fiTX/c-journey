// INFO:
// This program copies all the data from the first
// file to the second one
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
  FILE *fp_from;
  FILE *fp_to;
  int ch, fread_ret;
  int buff[BUFF_SIZE];

  if (argc >= 2) {
    if (!strncmp(argv[1], "help", 4)) {
      printf(
          " Help Menu:\n   Usage -> program_name [PATH_FROM] [PATH_TO]\n");
      return EXIT_SUCCESS;
    }
  }
  if (argc != 3) {
    printf("!> 2 arguments expexted. Type help as argument for help.\n");
    return EXIT_FAILURE;
  }

  fp_from = fopen(argv[1], "rb");
  if (!fp_from) {
    printf("!> Incorrect PATH_FROM value. Check the path to the file:\n-> %s\n",
           argv[1]);
    return EXIT_FAILURE;
  } else {
    printf("=> Successfully opened the file \"FROM\"\n");
  }
  fp_to = fopen(argv[2], "wb");
  if (!fp_to) {
    printf("!> Incorrect PATH_TO value. Check the path to the file:\n-> %s\n",
           argv[2]);
  } else {
    printf("=> Successfully opened the file \"TO\"\n");
  }

  printf("?> Do you wish to continue? This action may overwrite all your data "
         "in the file \"TO\"[y/N]: ");
  if (getchar() == 'y') {
    printf("=> Starting...\n");
  } else {
    printf("=> Program stoped!\n");
    return EXIT_SUCCESS;
  }
  while ((fread_ret = fread(buff, 1, BUFF_SIZE, fp_from)) > 0) {
    fwrite(buff, 1, fread_ret, fp_to);
  }
  printf("=> Copied successfylly.\n");

  return EXIT_SUCCESS;
}
