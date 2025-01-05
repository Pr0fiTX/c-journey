#include <stdio.h>
#define SIZE 5
void reverse_ar(double [], int);

int main(void)
{
    double array[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};

    printf("=> Эта программа изменяет порядок следования содержимого");
    printf(" массива на противоположный.\n");
    reverse_ar(array, SIZE);
    for (int s = 0; s < SIZE; s++)
    {
        printf("=> array[%d] -> %lf\n", s, array[s]);
    }
}

void reverse_ar(double ar[], int size)
{
    double buffer;
    int last_n = (size - 1);

    size -= 1;
    if ((size % 2) == 0) size += 1; // Проверка чётности/нечётности для size
    size = size / 2;
    for (int i = 0; i < size; i++)
    {
        buffer = ar[0 + i];
        ar[0 + i] = ar[last_n - i];
        ar[last_n - i] = buffer;
    }
    return;
}