#include <stdio.h>
#define START_NUMBER 50 // Первое предпологаемое число
#define STEP 10 // Шаг для более быстрого угадывания

void welcome(void);
void guessAlgoritm(void);

int main(void)
{
    welcome();
    guessAlgoritm();
    printf("Это было легко!\n");
    return 0;
}

void welcome(void)
{
    printf("Загадай число от 1 до 100 и запомни его!\n");
    printf("Теперь, я буду пытаться угадать число, а ты вводи y (yes), s (smaller), b (bigger).\n");
    printf("Начинаем!\n");
}

void guessAlgoritm(void)
{
    int suggessed_num = START_NUMBER;
    int s_cntr = 0;
    int b_cntr = 0;
    int isLast = 0; // Булеан
    char ch = '!';

    printf("Это %d? ", suggessed_num);

    while ((ch = getchar()) != 'y')
    {
        if (isLast)
        {
            if (ch == 's')
            {
                suggessed_num--;
                printf("Это %d? ", suggessed_num);
                while (getchar() != '\n')
                    continue;
                continue;
            }
            if (ch == 'b')
            {
                suggessed_num++;
                printf("Это %d? ", suggessed_num);
                while (getchar() != '\n')
                    continue;
                continue;
            }
        }
        if (ch == 's') 
        {
            s_cntr++;
            if ((b_cntr != 0) && (b_cntr >= s_cntr))
            {
                isLast = 1; // True
                suggessed_num -= (STEP / 2);
                printf("Это %d? ", suggessed_num);
                while (getchar() != '\n')
                    continue;
                continue;
            }
            suggessed_num -= STEP;
            printf("Это %d? ", suggessed_num);
            while (getchar() != '\n')
                continue;
            continue;
        } 
        if (ch == 'b') 
        {
            b_cntr++;
            if ((s_cntr != 0) && (s_cntr >= b_cntr))
            {
                isLast = 1; // True
                suggessed_num += (STEP / 2);
                printf("Это %d? ", suggessed_num);
                while (getchar() != '\n')
                    continue;
                continue;
            }
            suggessed_num += STEP;
            printf("Это %d? ", suggessed_num);
            while (getchar() != '\n')
                continue;
            continue;
        }
    }
    return;
}