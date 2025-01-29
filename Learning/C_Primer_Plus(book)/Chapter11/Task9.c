#include <stdio.h>
#define SIZE 101
#define EXIT_POINT 1    // Выход из программы пользователем
char *revstr(char s[]); // INFO: Возвращает указатель на строку -> s

int main(void) {
  char array[SIZE];
  char *out_revstr;

  printf("=> Эта программа выводит строку в обратном порядке.\n\n");
  while (1) {
    printf("?> Введите строку (или -> qqq): ");
    fgets(array, SIZE - 1, stdin);
    if (array[0] == 'q' && array[1] == 'q' && array[2] == 'q') {
      printf("=> Завершение программы...\n");
      return EXIT_POINT;
    } else if (array[0] == '\n') {
      printf("!> Строка не может быть пустой.\n");
      continue;
    }

    out_revstr = revstr(array);
    printf("=> Ваша строка: ");
    for (int c = 0; array[c] != '\0'; c++) {
      putchar(array[c]);
    }
  }
  return 0;
}

char *revstr(char s[]) {
  char buffer;
  int size = 0;

  for (int c = 0; s[c] != '\n' && s[c] != '\0';
       c++) { // Ищет действительную длинну
    size = c;
  }
  for (int c = 0; c <= (size / 2); c++) {
    buffer = s[c];
    s[c] = s[size - c];
    s[size - c] = buffer;
  }
  return s;
}
