#include "neces-stuff.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int temp;
  unsigned int throws, facets, dices;

  while (true) {
    printf("?> Введите количество бросаний (или q для завершения): ");
    temp = scanf("%ud", &throws);
    buffc();
    if (!temp) {
      printf("=> Завершение...\n");
      return 0;
    }
    printf("?> Сколько граней: ");
    temp = scanf("%ud", &facets);
    buffc();
    if (!temp) {
      printf("!> Неверный тип! Попробуйте ещё раз.\n");
      continue;
    }
    printf("?> Сколько костей: ");
    temp = scanf("%ud", &dices);
    buffc();
    if (!temp) {
      printf("!> Неверный тип! Попробуйте ещё раз.\n");
      continue;
    }
    /* printf("[DEBUG]: %u | %u | %u\n", throws, facets, dices); // WARN:DEBUG
     */

    roll_the_dice(throws, facets, dices);
  }
  return 0;
}
