#include <stdio.h>
#include <sys/types.h>

#define ANSW 56 // Expected input(answer)

void critic(int n[restrict]);

int main(void) {
  int units = 0;

  printf("=> How many kg does a barrel of butter weight?\n> ");
  scanf("%d", &units);
  while (units != ANSW) {
    critic(&units);
  }
  printf("=> Ya knew it!\n");

  return 0;
}

void critic(int n[restrict]) {
  printf("=> Oh, ya really are an unlucky guy. Try again.\n> ");
  scanf("%d", n);
}
