#include "12-2a.h"
#include <stdio.h>

extern int mode;
extern double distance;
extern double consumption;
extern double fuel_cons;

int main(void) {
  printf("Введите 0 для метрического режима или 1 для американского режима: ");
  scanf("%d", &mode);
  while (mode >= 0) {
    get_info(mode, &distance, &consumption);
    show_info(mode, distance, consumption, &fuel_cons);
    printf("Введите 0 для метрического режима или 1 для американского режима "
           "(-1 для завершения): ");
    scanf("%d", &mode);
  }

  printf("Программа завершена!\n");
  return 0;
}
