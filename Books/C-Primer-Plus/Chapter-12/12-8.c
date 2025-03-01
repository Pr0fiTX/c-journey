#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void show_array(int *ar, unsigned int size) {
  int ctr = 0;

  for (int c = 0; c < size; c++) {
    if (!(ctr % 8) && ctr != 0) {
      putchar('\n');
    }
    printf("[%d]", *(ar + c));
    ctr++;
  }
  putchar('\n');
}

int *create_fill_array(unsigned int size, int value) {
  int *ptr;

  ptr = (int *)malloc((int)sizeof(value) * size);

  for (int c = 0; c < size; c++) {
    *(ptr + c) = value;
  }

  return ptr;
}

void cbuff(void) {
  while (getchar() != '\n') {
    continue;
  }
}

int main(void) {
  int temp;
  unsigned int numbers_cnt;
  int value;
  int *array;

  while (true) {
    printf(
        "?> Введите количество элементов в массиве (или букву для выхода): ");
    temp = scanf("%u", &numbers_cnt);
    cbuff();
    if (!temp) {
      printf("=> Завершение...\n");
      return 0;
    }
    printf("?> Чем заполнить массив: ");
    temp = scanf("%d", &value);
    cbuff();
    if (!temp) {
      printf("!> Неверный тип! Введите ЧИСЛО.\n");
      continue;
    }

    array = create_fill_array(numbers_cnt, value);

    show_array(array, numbers_cnt);
    free(array);
  }
  return 0;
}
