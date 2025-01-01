#include <stdio.h>
void fibonacci(int i);

int main(void)
{
    int fib;

    printf("=> Это программа для вычисления чисел Фибоначчи.\n");
    while (1)
    {
        printf("?> Введите число Фибоначии: ");
        scanf("%d", &fib);
        printf("=> Число Фибоначчи %d в переводе на обычные -> ", fib);
        fibonacci(fib);
    }
}

void fibonacci(int i)
{
    int ar[3] = {0, 1};
    int curs = 1;

    for (; i > 1; i--)
    {
        if (curs != 2) curs++;
        else curs = 0;

        if (curs == 0) ar[0] = ar[1] + ar[2];
        if (curs == 1) ar[1] = ar[2] + ar[0];
        if (curs == 2) ar[2] = ar[0] + ar[1];
    }
    printf("%d\n", ar[curs]);
    return;
}