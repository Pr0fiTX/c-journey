#include <stdio.h>

void self_counter(void) {
  static int counter = 0;
  printf("Меня вызвали -> %d раз!", ++counter);
}

int main(void) {
  printf("=> Просто бей по Return, а для выхода по чему-то другому)))\n");
  while (getchar() == '\n') {
    self_counter();
  }
  printf("=> Конец.\n");
  return 0;
}
