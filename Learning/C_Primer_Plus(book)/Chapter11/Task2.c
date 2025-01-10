#include <stdio.h>
#define SIZE 11 // Size of array[]
#define BLANK ' '

int main(void)
{
    char array[SIZE];
    int i = 0;

    printf("=> Эта программа прекращает считывание ввода по достижении ограничения");
    printf(" или при встречи пробела, табуляции или символа новой строки.\n\n");

    printf("?> Введите любую строку: ");
    fgets(array, SIZE - 1, stdin);
    putchar('\n');
    printf("=> Ваша строка -> ");
    while (i < SIZE && array[i] != '\n' && array[i] != BLANK && array[i] != '\t')
    {
        putchar(array[i]);
        i++;
    }

    return 0;
}