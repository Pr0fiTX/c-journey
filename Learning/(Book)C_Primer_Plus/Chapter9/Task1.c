#include <stdio.h>
double min(double x, double y);

int main(void)
{
    double num1 = 0;
    double num2 = 1;
    double answer_main;

    printf("=> Это программа для вывода меньшего из 2-х чисел.\n");
    while (num1 != num2)
    {
        printf("?> Введите 2 числа (через пробел) или 2 идентичных числа для завершения программы (прим: 1 1): ");
        scanf("%lf %lf", &num1, &num2);
        if (num1 == num2)
        {
            printf("!> Завершение программы...\n");
            continue;
        }
        printf("=> Ваши числа %lf и %lf.\n", num1, num2);
        answer_main = min(num1, num2);
        printf("=> Наименьшее из чисел -> %lf <-\n", answer_main);
    }
    return 0;
}

double min(double num1, double num2)
{
    double answ;

    if (num1 < num2) answ = num1;
    if (num1 > num2) answ = num2;

    return answ;
}