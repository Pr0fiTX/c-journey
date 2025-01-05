#include <stdio.h> 
#define SIZE 10
void sum_arr(const double [], const double [], double [], int);

int main(void)
{
    const double arr1[SIZE] = 
    {
        321.312, 489.584, 19.1594, 35.6119, 54.21, 54.987,
        654312.312, 4.35, 435.3, 78.87
    };
    const double arr2[SIZE] =
    {
        645.31, 987.3, 64545, 6543.222, 645.312, 987.91,
        324.345, 54.353, 43.32, 8484.4
    };
    double s_arr[SIZE];

    printf("=> Это программа для сложения элементов из двух массивов");
    printf(" и записи результата в другой.\n\n");
    sum_arr(arr1, arr2, s_arr, SIZE);
    for (int c = 0; c < SIZE; c++)
    {
        printf("=> s_arr[%d] -> %lf\n", c, s_arr[c]);
    }
    return 0;
}

void sum_arr(const double ar1[], const double ar2[], double answ[], int size)
{
    for (int c = 0; c < size; c++)
    {
        *(answ + c) = *(ar1 + c) + *(ar2 + c); 
    }
    return;
}