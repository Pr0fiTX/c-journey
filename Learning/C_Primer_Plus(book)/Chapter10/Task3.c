#include <stdio.h>
#define SIZE 10
double higher_of_arr(const double arr[], int size);

int main(void)
{
    const double arr[SIZE] = {1.0, 2.0, 5.0, 78.2, 6.0, 548.0, 45.24, 4224.11, 1.21, 10000.01};
    double higher_num;

    printf("=> Это программа для вывода большего из чисел в массиве.\n");
    higher_num = higher_of_arr(arr, SIZE);
    printf("=> Наибольшее число массива -> %lf\n", higher_num);
    return 0;
}

double higher_of_arr(const double arr[], int size)
{
    double answ = arr[0];

    for (int i = 0; i < (size - 1); i++)
    {
        printf("=> Сейчас i = %d, arr[%d] = %lf\n", i, i, arr[i]);
        if (arr[i] < arr[i + 1]) answ = arr[i + 1];
        else continue;
    }
    printf("=> Сейчас i = 9, arr[9] = %lf\n", arr[9]);
    return answ;
}