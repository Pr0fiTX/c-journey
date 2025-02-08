#include <stdio.h>
#define SIZE 11 // Size of array[]

int main(void)
{
    char array[SIZE];

    printf("=> Это программа для считывания определённого кол-ва символов");
    printf(" и записи их в массив.\n\n");
    while (1)
    {
        printf("?> Введите любую строку: ");
        fgets(array, SIZE - 1, stdin); // Need space for /0, so (SIZE - 1)
        putchar('\n');
        printf("=> Вот ваша строка (было считано только %d символов): ", SIZE - 1);
        fputs(array, stdout);

        return 0;
    }
}