#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define IF_DEBUG_MODE                                                          \
  0 // <- Place 1 to enable all debug inserts (0 in other case)
    // You can find them in the code like this: "// DEBUG INSERT"
#define BIN_FILE_NAME "numbers.dat"
#define NUMBERS_COUNT 1000

FILE *open_dat_file(const char *mode) { // Opens BIN_FILE_NAME in given mode
  FILE *fp;

  fp = fopen(BIN_FILE_NAME, mode);
  if (!fp) {
    perror("!> fopen() error");
    return NULL;
  }
  return fp;
}

void generate_numbers(FILE *fp) {
  int gen_buff[NUMBERS_COUNT];

  srand((unsigned int)time(NULL));
  for (int i = 0; i < NUMBERS_COUNT; i++) {
    gen_buff[i] = rand();
    if (IF_DEBUG_MODE) { // DEBUG INSERT
      printf("%d ", gen_buff[i]);
    }
  }
  if (fwrite(gen_buff, sizeof(int), NUMBERS_COUNT, fp) != NUMBERS_COUNT) {
    printf("!> Count of written numbers != expected.\n");
  }
}

int main(int argc, char *argv[]) {
  FILE *dat_fp;
  int r_buff[NUMBERS_COUNT]; // buffer for '-r' piece of code
  unsigned long num_index = 0;
  int num;

  if (argc != 2) {
    printf("!> Invalid count of arguments. Try '%s -h' for more information.\n",
           argv[0]);

    return EXIT_FAILURE;
  }
  if (!strcmp(argv[1], "-h")) {
    printf("Help Menu:\n   Usage: %s [FLAG | INDEX]\nFLAGS:\n   -g - "
           "generate/regenerate all numbers\n   -r - print .dat file numbers\n "
           "  -h - print this menu\nINDEX:\n "
           "  Number in range 0 - %d. Program will print number from .dat "
           "file with this index.\n",
           argv[0], NUMBERS_COUNT - 1);

    return EXIT_SUCCESS;
  }
  if (!strcmp(argv[1], "-g")) {
    printf("=> Generating numbers...\n");
    if (!(dat_fp =
              open_dat_file("wb"))) { // If func. returned NULL (error occured)
      return EXIT_FAILURE;            // killing the program
    }
    generate_numbers(dat_fp);
    printf("=> Done!\n");

    fclose(dat_fp);
    return EXIT_SUCCESS;
  }
  if (!strcmp(argv[1], "-r")) {
    printf("%s\n", BIN_FILE_NAME);
    if (!(dat_fp =
              open_dat_file("rb"))) { // If func. returned NULL (error occured)
      return EXIT_FAILURE;            // killing the program
    }
    fread(r_buff, sizeof(int), NUMBERS_COUNT, dat_fp);
    for (int i = 0; i < NUMBERS_COUNT; i++) {
      printf("%d ", r_buff[i]);
    }
    putchar('\n');

    fclose(dat_fp);
    return EXIT_SUCCESS;
  }
  if ((num_index = strtoul(argv[1], NULL, 10)) && num_index < 1000) {
    printf("=> Searching...\n");
    if (!(dat_fp = open_dat_file("rb"))) {
      return EXIT_FAILURE;
    }
    if (fseek(dat_fp, sizeof(int) * num_index, SEEK_SET)) {
      printf("!> Error when setting position in .dat file.\n");
      return EXIT_FAILURE;
    }
    if (fread(&num, sizeof(int), 1, dat_fp) != 1) {
      printf("!> Error when reading opened file.\n");
      return EXIT_FAILURE;
    }
    printf("==> Your number: %d\n", num);
    printf("=> Done!\n");

    fclose(dat_fp);
    return EXIT_SUCCESS;
  }

  printf("!> Invalid flag/index.\n");
  return EXIT_FAILURE;
}
