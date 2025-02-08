#include <stdio.h>
#define SIZE 5
int indx_of_higher(const double [], int);

int main(void)
{
    const double arrow[SIZE] = {5.3, 16.98, 24.8732, 45.222, 166.5666};
    int h_index;

    printf("=> Это программа для вывода индекса наибольшего числа в массиве.\n");
    h_index = indx_of_higher(arrow, SIZE);
    printf("=> Индекс наибольшего числа -> %d и само число -> %lf\n", h_index, arrow[h_index]);
}

int indx_of_higher(const double arr[], int size)
{
    int i = 0;
    int h_num, h_index;
    for (; i < (size - 1); i++)
    {
        // printf("=> Сейчас i = %d\n", i); // debug
        if (arr[i] < arr[i + 1]) 
        {
            h_num = arr[i + 1];
            h_index = (i + 1);
        }
        else continue;
    }
    return h_index;
}