#include <stdio.h>
#define ROWS 3
#define COLUMNS 5
void print_array(double [][COLUMNS], int);
void double_array(double [][COLUMNS], int);

int main(void)
{
    double array[ROWS][COLUMNS] = 
    {
        {65.46, 654.5, 48.646, 4.32, 55.0},
        {654.332, 44.1133, 46456.55, 44.0, 878.2},
        {561.33, 48785.5, 444.2, 74215.111, 1.0}
    };

    printf("=> Это программа для умножения каждого элемента массива");
    printf(" на 2 и их вывода.\n\n");

    print_array(array, ROWS);
    double_array(array, ROWS);
    print_array(array, ROWS);

    return 0;
}

void double_array(double ar[][COLUMNS], int rows)
{
    printf("=> Умножаю...\n\n");
    for (int c = 0; c < rows; c++)
    {
        for (int a = 0; a < COLUMNS; a++)
        {
            ar[c][a] = (ar[c][a] * 2);
        }
    }
    return;
}

void print_array(double ar[][COLUMNS], int rows)
{
    for (int c = 0; c < rows; c++)
    {
        for (int a = 0; a < COLUMNS; a++)
        {
            printf("=> array[%d][%d] -> %lf\n", c, a, ar[c][a]);
        }
    }
    putchar('\n');
    return;
}