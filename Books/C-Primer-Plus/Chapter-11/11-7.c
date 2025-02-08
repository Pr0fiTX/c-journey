#include <stdio.h>
#define SIZE 1024 // по 1kB на строку
char *mystrncpy(char s1[], const char s2[],
                int n); // s1: строка в которую копируем | s2: строку которую
                        // копируем в s1 | n: кол-во копируемых символов

int main(void) {
  char string1[SIZE];
  char string2[SIZE];
  int cpy_num;    // Число копируемых символов -> mystrncpy()
  char *func_out; // Вывод функции -> mystrncpy()

  printf("=> Эта программа копирует определённое количество символов из одной "
         "строки в другую (для выхода введите вместо строки -> qqq )\n\n");
  while (1) { // Есть точки выхода в теле
    printf("?> Введите строку в которую копируем (или qqq): ");
    while (getchar() != '\n') {
      continue;
    }
    fgets(string1, SIZE - 1, stdin);
    if (string1[0] == 'q' && string1[1] == 'q' && string1[2] == 'q') {
      printf("=> Завершение программы...\n");
      return 0;
    }
    printf("?> Введите строку которую копируем: ");
    fgets(string2, SIZE - 1, stdin);
    printf("?> Сколько символов из 2-ой строки копируем: ");
    scanf("%d", &cpy_num);
    if ((SIZE - 1) < cpy_num) {
      printf("!> Строка -> 1 слишком мала\n");
      continue;
    }

    func_out = mystrncpy(string1, string2, cpy_num);
    fputs(string1, stdout);
  }
}

char *mystrncpy(char s1[], const char s2[], int n) {
  int c = 0;      // -> Курсор
  int l_s1, l_s2; // -> длинны строк

  while (s1[c] != '\n' && s1[c] != '\0') { // -> поиск длинны строки
    c++;
  }
  l_s1 = c;
  c = 0;
  while (s2[c] != '\n' && s2[c] != '\0') { // -> поиск длинны строки
    c++;
  }
  l_s2 = c;
  c = 0;

  for (int i = 0; i < n; i++) {
    s1[i] = s2[i];
  }
  return s1;
}
