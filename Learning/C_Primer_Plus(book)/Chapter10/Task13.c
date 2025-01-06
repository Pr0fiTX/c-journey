#include <stdio.h> 
#define SIZE_0 3
#define SIZE_1 5
void ask_array(double [][SIZE_1], int);
void f_av_size0(double [][SIZE_1], int, double []);
double av_all(double [][SIZE_1], int);
double h_of_arr(double [][SIZE_1], int);
void out_data(double [][SIZE_1], int, double, double [], double);

int main(void)
{
    double array[SIZE_0][SIZE_1];
    double av_size0[SIZE_0]; // av_size0_0, av_size0_1, av_size0_2;
    double average_all;
    double h_num;

    printf("=> Это программа для сохранения информации в массив,");
    printf(" вычисление среднего значения для каждого подмассива,");
    printf(" вычисление среднего значения для всего двумерного массива и");
    printf(" определение наибольшего значения в массиве.\n\n");

    ask_array(array, SIZE_0);
    f_av_size0(array, SIZE_0, av_size0);
    average_all = av_all(array, SIZE_0);
    h_num = h_of_arr(array, SIZE_0);
    out_data(array, SIZE_0, average_all, av_size0, h_num);

    return 0;
}

void out_data(double ar[][SIZE_1], int s_0, double av_all, double av_s0[], double h_n)
{
    putchar('\n');
    printf("=> Сам двумерный массив:\n");
    for (int c = 0; c < s_0; c++)
    {
        printf("%d:{", c);
        for (int i = 0; i < SIZE_1; i++)
        {
            printf("%.3lf, ", ar[c][i]);
        }
        printf("}\n");
    }
    putchar('\n');

    printf("=> Среднее для каждого подмассива:\n");
    for (int c = 0; c < s_0; c++)
    {
        printf("%d: %.3lf\n", c, av_s0[c]);
    }
    putchar('\n');

    printf("=> Среднее для всего двумерного массива:\n");
    printf("%.3lf\n", av_all);
    putchar('\n');

    printf("=> Наибольшее значение во всём массиве:\n");
    printf("%.3lf\n", h_n);
    putchar('\n');

    return;
}

double h_of_arr(double ar[][SIZE_1], int s_0)
{
    double h_num = 0;

    for (int c = 0; c < s_0; c++)
    {
        for (int i = 0; i < SIZE_1; i++)
        {
            if (h_num < ar[c][i]) h_num = ar[c][i];
            else continue;
        }
    }
    return h_num;
}

double av_all(double ar[][SIZE_1], int s_0)
{
    int buff = 0;
    
    for (int c = 0; c < s_0; c++)
    {
        for (int i = 0; i < SIZE_1; i++)
        {
            buff += ar[c][i];
        }
    }
    buff /= (s_0 * SIZE_1);
    return buff;
}

void f_av_size0(double ar[][SIZE_1], int s_0, double av_s[])
{
    double buff;

    for (int c = 0; c < s_0; c++)
    {
        buff = 0;
        for (int i = 0; i < SIZE_1; i++)
        {
            buff += ar[c][i];
        }
        buff /= SIZE_1;
        av_s[c] = buff;
    }
    return;
}

void ask_array(double ar[][SIZE_1], int s_0)
{
    for (int c = 0; c < s_0; c++)
    {
        printf("?> Введите 5 чисел через пробел (ещё %d раз): ", (s_0 - (c + 1)));
        scanf("%lf %lf %lf %lf %lf", &ar[c][0], &ar[c][1], &ar[c][2], &ar[c][3], &ar[c][4]);
        while (getchar() != '\n') continue;
    }
    return;
}