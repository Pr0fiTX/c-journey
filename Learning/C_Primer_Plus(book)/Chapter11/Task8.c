#include <stdio.h>
#include <string.h>
#define SIZE_S1_S2                                                             \
  1024 // WARN: Программа не расчитана на ввод строк без \n (т.е. все строки
       // должны быть длинной <1022 символа)!!!
char *string_in(
    char s1[],
    const char s2[]); // -> ищет строку 2 в строке 1. При нахождении возвращает
                      // указатель на начало 2 строки в 1, в ином случае NULL

int main(void) {
  char string1[SIZE_S1_S2];
  char string2[SIZE_S1_S2];
  char *func_out;

  printf("=> Эта программа ищет строку внутри другой строки и возвращает место "
         "её вхождения\n\n");
  while (1) { // Есть точка выхода внутри цикла
    printf("=> Введите строку в которой ищем (выход -> qqq ): ");
    fgets(string1, SIZE_S1_S2 - 1, stdin);
    if (string1[0] == 'q' && string1[1] == 'q' && string1[2] == 'q') {
      printf("=> Завершение программы...\n");
      return 0;
    }
    printf("=> Введите строку, которую ищем: ");
    fgets(string2, SIZE_S1_S2, stdin);

    func_out = string_in(string1, string2);
    if (func_out == NULL) {
      printf("=> Совпадений НЕ найдено\n");
    } else {
      printf("=> Совпадение найдено\n");
    }
  }
}

char *string_in(char s1[], const char s2[]) {
  int cr = -1;   // -> Курсор
  int m_cnt = 0; // -> Кол-во совпавших символов
  int l_s2;

  for (int c = 0; s2[c] != '\0';
       c++) { // Вычисление длинны 2 строки (\n не учитывается)
    l_s2 = c;
  }
  for (int c = 0; s1[c] != '\0' && m_cnt != l_s2; c++) {
    if (s1[c] == s2[m_cnt]) {
      m_cnt++;
      if (m_cnt == 1) {
        cr = c;
      }
    } else {
      m_cnt = 0;
    }
  }
  if (m_cnt == l_s2) {
    return s1 + cr;
  } else {
    return NULL;
  }
}
