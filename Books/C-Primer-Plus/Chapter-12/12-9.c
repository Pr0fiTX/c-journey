#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void cbuff(void) {
  while (getchar() != '\n') {
    continue;
  }
}

int main(void) {
  unsigned int words_cnt = 0;
  int temp;
  char **ptr_ar;

  while (true) {
    printf("?> Введите, сколько слов Вы хотите ввести (букву для выхода): ");
    temp = scanf("%u", &words_cnt);
    cbuff();
    if (!temp) {
      printf("=> Завершение...\n");
      return 0;
    }

    ptr_ar = (char **)malloc(sizeof(char *) * words_cnt);
    if (ptr_ar == NULL) {
      printf("!> Ошибка выделения памяти!\n");
      for (int i = 0; i < words_cnt; i++) {
        free(ptr_ar[i]);
      }
      free(ptr_ar);
    }

    printf("=> Теперь введите %u слов(-о/-а):\n> ", words_cnt);
    for (int c = 0; c < words_cnt; c++) {
      ptr_ar[c] = (char *)malloc(sizeof(char) * 30);
      scanf("%29s", ptr_ar[c]);
    }
    cbuff();

    for (int c = 0; c < words_cnt; c++) {
      printf("%s\n", ptr_ar[c]);
    }

    for (int i = 0; i < words_cnt; i++) {
      free(ptr_ar[i]);
    }
    free(ptr_ar);
  }
  return 0;
}
