/*
 * This program compresses a text file by removing every 3rd character. Doesn't
 * modify the original file and creates a copy with a .red extension.
 *
 * Author: Lyovkin Oleg (Pr0fiTX)
 * Date of last modification: 24.03.2025
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_MAX_SIZE                                                     \
  1024 // In Bytes (Corresponding for all existing limits)
#define COMPRESS_BUFFER_SIZE 4096 // In Bytes (Enough for the string buffer)

/*
 * Reading SOURCE file content to the array -> copying to the COMPRESSED FILE
 * every 3rd caharcter
 * @args: pointer to the SOURCE file, path to the SOURCE file (changing)
 */
void compress_and_copy_in_file(FILE *source_fp, char *s_path) {
  FILE *c_fp; // Pointer to the COMPRESSED file
  char cmprs_buff[COMPRESS_BUFFER_SIZE];

  // Making new path to the COMPRESSED file
  strcat(s_path, ".red");

  // Creating&Opening the COMPRESSED file, exiting if error occured
  if (!(c_fp = fopen(s_path, "w"))) {
    perror("!> fopen() error");
    exit(EXIT_FAILURE);
  }
  printf("=> File %s created & opened.\n", s_path);

  // Reading, compressing and writting to the COMPRESSED file string by string
  printf("=> Compressing...\n");
  while (fgets(cmprs_buff, COMPRESS_BUFFER_SIZE, source_fp)) {
    for (int i = 0; cmprs_buff[i] != '\0'; i++) {
      if ((i + 1) % 3 == 0) { // Writting every 3rd character
        fputc(cmprs_buff[i], c_fp);
      }
    }
    fputc('\n', c_fp); // Ending the string
  }
  printf("=> Done!\n");

  fclose(c_fp);
}

int main(void) {
  char source_file_name[FILE_NAME_MAX_SIZE];
  FILE *source_fp;

  // Requesting the SOURCE file path from the user
  printf("?> Enter the path to the file you want to compress: ");
  //                          Reserving place for ".red"
  if (!fgets(source_file_name, FILE_NAME_MAX_SIZE - 5, stdin)) {
    fprintf(stderr, "!> Can't read name of file.\n");
    return EXIT_FAILURE;
  }

  // Cutting '\n' from the given path string
  source_file_name[strcspn(source_file_name, "\n")] = '\0';

  // Opening the SOURCE file
  if (!(source_fp = fopen(source_file_name, "r"))) {
    perror("!> fopen() error");
    return EXIT_FAILURE;
  }
  printf("=> File %s opened.\n", source_file_name);

  // See definition of the function for more information
  compress_and_copy_in_file(source_fp, source_file_name);

  fclose(source_fp);
  return EXIT_SUCCESS;
}
