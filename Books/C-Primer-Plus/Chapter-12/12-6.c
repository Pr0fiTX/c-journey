#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000
#define MAX_C_SEED 10

int num_counter[10];

void num_gen(unsigned int seed, int max) {
  unsigned int temp;

  srand(seed);
  for (int s = 0; s < max; s++) {
    temp = (rand() % 10) + 1;
    num_counter[temp - 1] += temp;
  }
}

int main(void) {
  unsigned int seed = 0;

  printf("=> Эта программа генерирует %d случайных чисел из %d сидов.\n",
         (MAX_NUM * MAX_C_SEED), MAX_C_SEED);
  for (int c = 0; c < MAX_C_SEED; c++) {
    printf("?> Введите сид: ");
    scanf("%ud", &seed);
    num_gen(seed, MAX_NUM);
  }
  printf("=> Таблица чисел:\n");
  for (int c = 0; c < 10; c++) {
    num_counter[c] /= c + 1;
    printf("%d -> %d раз(-а)\n", (c + 1), num_counter[c]);
  }
  return 0;
}
