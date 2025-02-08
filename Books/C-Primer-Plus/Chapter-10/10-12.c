#include <stdio.h>
#define YEARS 5
#define MONTHS 12
void precip_per_year(const double [][MONTHS], int, double []);
void av_year_precip(int, double []);
void av_mon_precip(const double [][MONTHS], int, double []);

int main(void)
{
    const double rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 4.3, 3.0, 2.0, 2.4, 3.5, 6.6, 8.2, 1.2},
        {4.3, 4.3, 3.0, 2.0, 0.9, 0.3, 0.9, 1.2, 1.6, 2.4, 0.0, 3.3},
        {8.5, 8.2, 1.2, 2.0, 2.4, 3.5, 3.5, 6.6, 8.2, 1.2, 1.2, 1.6}
    }; // Данные просто рандомные, не из листинга 10.7
    double all_prec_year[YEARS];
    double av_month[MONTHS];

    printf("=> Это программа для вывода количества осадков по годам,");
    printf(" среднегодового количества осадков и среденемесячного");
    printf(" количества осадков.\n\n");

    precip_per_year(rain, YEARS, all_prec_year);
    av_year_precip(YEARS, all_prec_year);
    av_mon_precip(rain, YEARS, av_month);

    return 0;
}

void av_mon_precip(const double ar[][MONTHS], int yr, double av_m[])
{
    double buff;

    printf("СРЕДНЕМЕСЯЧНОЕ КОЛ-ВО ОСАДКОВ:\n\n");
    printf("Янв Фев Мар Апр Май Июн Июл Авг Сен Окт Ноя Дек\n");
    for (int c = 0; c < MONTHS; c++)
    {
        buff = 0;
        for (int i = 0; i < YEARS; i++)
        {
            buff += ar[i][c];
        }
        av_m[c] = buff;
        buff /= YEARS;
        printf("%.1lf ", buff);
    }
    putchar('\n');
    return;
}

void av_year_precip(int yr, double all_prec_year[])
{
    double buff = 0;
    for (int c = 0; c < YEARS; c++)
    {
        buff += all_prec_year[c];
    }
    buff /= YEARS;
    printf("Среднегодовое кол-во осадков -> %.1lf\n\n", buff);
    return;
}

void precip_per_year(const double ar[][MONTHS], int yr, double all_prec_year[])
{
    int year = 2010;
    double n_precip;

    printf("ГОД     КОЛ-ВО ОСАДКОВ\n");
    for (int c = 0; c < yr; c++)
    {
        n_precip = 0;
        printf("%d        ", (year + c));
        for (int i = 0; i < MONTHS; i++)
        {
            n_precip = n_precip + ar[c][i];
        }
        all_prec_year[c] = n_precip;
        printf("%.1lf\n", n_precip);
    }
    putchar('\n');
    return;
}