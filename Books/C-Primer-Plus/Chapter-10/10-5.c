#include <stdio.h>
#define SIZE 5
double diff_arr(double [], int);

int main(void)
{
    double array[SIZE] = {1.5, 5.7, 6.8, 12.5, 0.24};
    double answ;

    printf("=> Это программа для вывода разности между наибольшим и наименьшим элементом массива.\n");
    answ = diff_arr(array, SIZE);
    printf("=> Ответ -> %lf\n", answ);
    return 0;
}

double diff_arr(double ar[], int size)
{
    double h_num, m_num, answer;

    for (int i = 0; i < (size - 1); i++)
    {
        if (ar[i] < ar[i + 1]) h_num = ar[i + 1];
        else continue;
    }
    for (int a = 0; a < (size - 1); a++)
    {
        if (ar[a] > ar[a + 1]) m_num = ar[a + 1];
        else continue;
    }
    printf("=> Наибольшое число -> %lf\n", h_num);
    printf("=> Наименьшее число -> %lf\n", m_num);
    answer = h_num - m_num;
    return answer;
}