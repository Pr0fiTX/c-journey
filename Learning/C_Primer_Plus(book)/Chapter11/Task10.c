#include "stdio.h" // WARN: Решение допилила нейронка
#include <string.h>
#define SIZE 1024
#define EXIT_OK 0
#define SPACE ' '

char *delblanksinstr(char s[]); // INFO: Возвращает -> указатель на начало
                                // переданной строки, иначе -> NULL

int main(void) {
  char string[SIZE];
  char *func_out;

  printf("=> This program removes all spaces from the string\n\n");
  while (1) {
    printf("=> Type the string (or -> qqq): ");
    fgets(string, SIZE, stdin);

    // Удаляем символ новой строки, если он есть
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
      string[len - 1] = '\0';
    }

    if (string[0] == 'q' && string[1] == 'q' && string[2] == 'q' &&
        string[3] == '\0') {
      printf("=> Exit -> %d\n", EXIT_OK);
      return EXIT_OK;
    }
    if (string[0] == '\0') {
      printf("!> The string can't be empty\n");
      continue;
    }

    func_out = delblanksinstr(string);
    printf("=> Строка -> %s\n", func_out);
  }
  return 1; // Завершение программы неожиданным образом
}

char *delblanksinstr(char s[]) {
  int j = 0; // Индекс для записи без пробелов
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != SPACE) {
      s[j++] = s[i]; // Копируем символ, если он не пробел
    }
  }
  s[j] = '\0'; // Завершаем строку
  return s;
}
