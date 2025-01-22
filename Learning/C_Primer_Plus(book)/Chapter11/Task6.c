#include <stdio.h>
#define SIZE 101
// void stringcleaner(char target[]); // Забивает массив нулями для повторного
//  использования в одном запуске программы
int ischarinstr(
    char,
    char string[]); // Возвращает 1 в случае наличия символа и NULL в противном

int main(void) {
  short unsigned prog_exit = 0; // Выход из программы
  char in_string[SIZE];         // Вводимая пользователем строка
  char in_character;            // Вводимый пользователем символ
  int iter_cntr = 0;            // Количество итераций -> main()

  printf("=> Эта программа проверяет наличие переданного символв в переданной "
         "строке (для выхода вместо строки введите -> q)\n");
  while (!prog_exit) {
    printf("?> Введите строку: ");
    fgets(in_string, SIZE - 1, stdin);
    if (in_string[0] == 'q') {
      printf("!> Завершение программы...\n");
      return 0;
    } else if (in_string[0] == '\n' ||
               in_string[0] == '\0') { // Проверка на пустой ввод
      printf("!> Строка не может быть пустой\n");
      continue;
    }
    printf("?> Введите символ, который нужно найти: ");
    in_character = getchar();
    while (getchar() != '\n')
      continue;

    if (ischarinstr(in_character,
                    in_string) == 1) { // Вернёт -> 1 при нахождении символа
      printf("=> В этой строке присутствует символ -> %c !\n", in_character);
    } else {
      printf("=> Символ -> %c , НЕ замечен!\n", in_character);
    }
    iter_cntr++;
  }
  printf("!> Программа завершена выходом из цикла\n");
  return 1;
}

int ischarinstr(char ch, char ar[]) {
  int i = 0; // Курсор

  while (ch != ar[i] && ar[i] != '\0') {
    i++;
  }
  if (ar[i] == ch) {
    return 1;
  } else if (ar[i] == '\0') {
    return 0;
  } else {
    printf("!> Ошибка в функции -> ischarinstr() , возвращён -> 0 !\n");
    return 0;
  }
}
