#include "12-2a.h"
#include <stdio.h>

int mode = 0;
double distance = 0.0;
double consumption = 0.0;
double fuel_cons = 0.0;

void get_info(int mode, double *dist, double *cons) {
  printf("=> Введите пройденное расстояние ");
  if (mode) {
    printf("в милях: ");
  } else {
    printf("в километрах: ");
  }
  scanf("%lf", dist);

  printf("=> Введите объём израсходованого топлива ");
  if (mode) {
    printf("в галлонах: ");
  } else {
    printf("в литрах: ");
  }
  scanf("%lf", cons);
}

void show_info(int mode, double dist, double cons, double *fuel_cons) {
  if (mode) {
    *fuel_cons = dist / cons;
    printf("=> Расход топлива составляет %.2lf мили на галлон.\n", *fuel_cons);
  } else {
    *fuel_cons = cons / (dist / 100.0);
    printf("=> Расход топлива составляет %.2lf литров на 100 км.\n",
           *fuel_cons);
  }
}
