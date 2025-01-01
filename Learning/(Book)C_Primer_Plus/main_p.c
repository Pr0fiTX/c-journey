// #include <stdio.h>
// #include <ctype.h>
// double power(double, int);

// int main(void)
// {
//     double number;
//     int degree;
//     double answer_main;

//     printf("=> Это программа для возведения чисел с , и без в + и - степени.\n");

//     while (1)
//     {
//         printf("?> Введите число и степень: ");

//         scanf("%lf %d", &number, &degree);
//         while (getchar() != '\n') continue;
//         // if (!isdigit(number))
//         // {
//         //     printf("ERR> Проверте правильность ввода! Ожидаемый тип данных: double.\n");
//         //     continue;
//         // }
//         // if (!isdigit(degree))
//         // {
//         //     printf("ERR> Проверте правильность ввода! Ожидаемый тип данных: int.\n");
//         //     continue;
//         // }
//         // printf("<- Сканированние и запись чисел: успех\n"); // Debug
//         printf("=> Возвести число %lf в %d степень.\n", number, degree);
//         answer_main = power(number, degree);
//         printf("=> Результат: %lf\n", answer_main);
//     }
//     return 0;
// }

// // double power(double num, int b) // Реализация циклом
// // {
// //     double answer = 1.0;

// //     if (b == 0)
// //     {
// //         printf("!> Любое число в степени 0 - это 1\n");
// //         answer = 1.0;
// //         return answer;
// //     }
// //     if (num == 0)
// //     {
// //         printf("!> Число 0 в любой степени (кроме 0) будет равно 0.\n");
// //         answer = 0.0;
// //         return answer;
// //     }
// //     if (b > 0)
// //     {
// //         for (int i = 0; i < b; i++)
// //             answer *= num;
// //         return answer;
// //     }
// //     if (b < 0)
// //     {
// //         // printf("<- Внутри условия (b < 0)\n"); // Debug
// //         for (int i = 0; i > b; i--)
// //             answer *= num;
// //         answer = 1 / answer;
// //         return answer;
// //     }
// //     printf("ERR> Произошла непредвиденная ошибка в фунции power()\n");
// // }
// double power(double num, int b)
// {
//     if (b == 0)
//     {
//         // printf("<- В b == 0\n"); // debug
//         return 1;
//     }   
//     if (b < 0)
//     {
//         // printf("<- В (b < 0) при b == %d\n", b); // debug
//         return 1 / power(num, -b);
//     }
//     else
//     {
//         // printf("<- В else (b == %d)\n", b); // debug
//         return num * power(num, b - 1);
//     }
// }
#include <stdio.h>
void to_binary(unsigned long num);
void to_base_n(unsigned long num, int base);

int main(void)
{
    unsigned long number_main;
    int base;

    printf("=> Эта программа переводит заданное число в систему счисления (в пределах от 2 до 10).\n");
    while(1)
    {
        printf("?> Введите натуральное целое число: ");
        scanf("%ud", &number_main);
        while (getchar() != '\n') continue;
        printf("?> Введите основание системы счисления: ");
        scanf("%d", &base);
    }
}

void to_binary(unsigned long num)
{
    int r;
    r = num % 2;
    if (num >= 2)
        to_binary(num / 2);
    putchar(r == 0 ? '0' : '1');
    return;
}