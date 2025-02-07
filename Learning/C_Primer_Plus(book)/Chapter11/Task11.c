#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR 10
#define NUM_CHAR 128
#define EXIT_MENU 5 // <- символ для выхода

void sortstrings(int action, int n_ch, int n_str, char ar[][n_ch]) { // TODO:
  int curs_3;
  int str_by_lenght_3[n_str];

  if (action == 1) { // <- out original Strings
    printf("=> Strings:\n");
    for (int c = 0; c < n_str; c++) {
      printf("%d> ", c + 1);
      fputs(ar[c], stdout);
    }
  } else if (action == 2) { // out all strings by they ASCII numbers
    return;
  } else if (action == 3) { // out all strings by they lenght
    printf("=> Strings (by lenght)\n");
    for (int s = 0; s < n_str; s++) {
      str_by_lenght_3[s] =
          (strlen(ar[s]) - 1); // НЕ учитывается '\n' (который присутствует)
      printf("=> lenght of %d str -> %d\n", s + 1, str_by_lenght_3[s]); // WARN:
    }
    for (int c = 1; c < n_str; c++) {
      curs_3 = str_by_lenght_3[0];
      for (int s = 0; s < (n_str - 1); s++) {
        if (str_by_lenght_3[curs_3] > str_by_lenght_3[s + 1]) {
          curs_3 = (s + 1);
        }
      }
      printf("%d> %s", c + 1, ar[curs_3]);
      str_by_lenght_3[curs_3] = (NUM_CHAR + 1 + c);
    }
  } else if (action == 4) { // out all strings by lenght of first word
    return;
  } else {
    printf("!> Wrong option, try again!\n");
    return;
  }
  return;
}

int readstrings(int n_chars, char ar[][n_chars], int max_strings) {
  char *ifNull;
  int readed_str = 0;

  printf("=> Type 10 strings (or EOF for end)\n");
  for (int s = 0; s < max_strings; s++) {
    printf("> ");
    ifNull = fgets(ar[s], n_chars - 1, stdin);
    if (ifNull == NULL) {
      break;
    }
    readed_str += 1;
  }
  clearerr(
      stdin); // <- Нужно для обработки EOF (я не е** как это чинить по другому)
  return readed_str;
}

int actmenu(void) {
  int answ;

  putchar('\n');
  printf("    ~*MENU*~   \n");
  printf("1 <- out all strings\n2 <- out all strings by their ASCII number\n3 "
         "<- out all strings by their lenght\n4 <- out all srings by lenght of "
         "first word\n%d <- exit\n> ",
         EXIT_MENU);
  scanf("%d", &answ);
  while (getchar() != '\n')
    continue;
  return answ;
}

int main(void) {
  char array[MAX_STR][NUM_CHAR];
  int action;
  bool exit = false;
  int readed_str;

  printf("=> This program read 10 strings and suggest you many different "
         "operations with them\n");                   // <- приветствие
  readed_str = readstrings(NUM_CHAR, array, MAX_STR); // <- читаем строки
  if (readed_str == 0) {
    printf("!> You must input at least 1 string\n");
    return 1;
  }
  while (!exit) { // <- работа с введённымы строками
    action = actmenu();
    if (action == EXIT_MENU) { // INFO: ТОЧКА ВЫХОДА ПРОГРАММЫ
      printf("=> Exiting...\n");
      return 0;
    }
    sortstrings(action, NUM_CHAR, readed_str,
                array); // <- непосредственно действия над строками
  }
  return 0;
}
