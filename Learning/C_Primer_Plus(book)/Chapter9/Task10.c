#include <stdio.h>
void to_base_n(unsigned long num, unsigned long base);

int main(void)
{
    unsigned long number_main, base_main;

    printf("=> Эта программа приводит любое целое не отриц. число из 10 СС к СС с основанием от 2 до 10.\n");
    while (1)
    {
        printf("?> Введите число и, через пробел, систему счисления: ");
        scanf("%lu %lu", &number_main, &base_main);
        if (base_main < 2 || base_main > 10)
        {
            printf("ERR> Программа работает только с СС в диапозоне от 2 до 10.\n");
            continue;
        }
        printf("=> Перевести число %lu в %lu систему счисления -> ", number_main, base_main);
        to_base_n(number_main, base_main);
    }
    return 0;
}

// void to_base_n(unsigned long num, unsigned long base) // Примитивная реализация
// {
//     unsigned long answ = 0;

//     printf("=> ");
//     while (num > base)
//     {
//         answ = num % base;
//         num = num / base;
//         printf("%lu", answ);
//     }
//     printf("%lu <- читать наоборот(!!!)\n", num);
//     return;
// }

void to_base_n(unsigned long num, unsigned long base) // Релизация с использованием массива
{
    unsigned long buffer[100];
    unsigned long answ = 0;
    int i = 0;

    while (num >= base)
    {
        answ = num % base;
        num = num / base;
        buffer[i] = answ;
        i++;
    }
    buffer[i] = num; 
    for (; i >= 0; i--)
    {
        printf("%lu", buffer[i]);
    }
    putchar('\n');
    return;
}