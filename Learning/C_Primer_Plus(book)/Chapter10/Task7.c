#include <stdio.h>
#define SIZE_0 3
#define SIZE_1 2
void cpy_arr(const double [][SIZE_1], double [][SIZE_1], int);

int main(void)
{
    const double array[SIZE_0][SIZE_1] = {{1.5, 2.1}, {3.8, 4.98}, {5.01, 6.22}};
    double to_copy[SIZE_0][SIZE_1];

    printf("=> Это программа для копирования содержания одного");
    printf(" двумерного массива в другой.\n");
    cpy_arr(array, to_copy, SIZE_0);
    for (int a = 0; a < SIZE_0; a++)
    {
        for (int b = 0; b < SIZE_1; b++)
        {
            printf("=> to_copy[%d][%d] -> %lf\n", a, b, to_copy[a][b]);
        }
    }
    return 0;
}

void cpy_arr(const double ar[][SIZE_1], double to_copy[][SIZE_1], int rows)
{
    for (int a = 0; a < rows; a++)
    {
        for (int b = 0; b < SIZE_1; b++)
        {
            to_copy[a][b] = ar[a][b];
        }
    }
    return;
}