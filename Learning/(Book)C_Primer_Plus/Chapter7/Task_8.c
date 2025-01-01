#include <stdio.h>
#define FIRST_RATE 8.75
#define SECOND_RATE 9.33
#define THIRD_RATE 10.00
#define FOURTH_RATE 11.20
#define OVER_MAIN 1.5  // Коэфф. свыше 40 часов в неделю.
#define TAX_300 0.85  // Налог на первые 0 - 300
#define TAX_450 0.80    // Налог на следующие 300 - 450
#define TAX_LAST 0.75   // Налог на всё свыше 450 - x

double menu_for_rate(void);
double clear_salary_and_tax(double);
void stars(void);

int main(void)
{
    double hours = 0;
    double money = 0;

    while (money != (-1))
    {
        money = menu_for_rate();
        if (money == (-1))
            break;
        clear_salary_and_tax(money);
    }
    return 0;
}

double menu_for_rate(void)
{
    char answer_menu = 0;
    double rate_menu = 0;
    double money_menu = 0;
    double hours_menu = 0;

    while (1)
    {
        stars();
        printf("Введите число, соотв. желаемой тарифной ставке или действию:\n");
        printf("1) $8.75/h              2) $9.33/h\n");
        printf("3) $10.00/h             4) $11.20/h\n");
        printf("5) Exit\n");
        stars();
        answer_menu = getchar(); 
        if (answer_menu != '1' && answer_menu != '2' && answer_menu != '3' && answer_menu != '4' && answer_menu != '5')
        {
            printf("Введите число от 1 до 5!!!\n");
            continue;
        }
        switch (answer_menu)
        {
            case '1': rate_menu = FIRST_RATE;
                break;
            case '2': rate_menu = SECOND_RATE;
                break;
            case '3': rate_menu = THIRD_RATE;
                break;
            case '4': rate_menu = FOURTH_RATE;
                break;
            case '5': return (-1);
        }
        if (rate_menu == (-1))
            break;
        printf("Отлично! Ваша текущая ставка => %lf. Теперь, введите кол-во отработаных за неделю часов:\n", rate_menu);
        scanf("%lf", &hours_menu);
        if (hours_menu > 40)
        {
            hours_menu -= 40;
            hours_menu *= (rate_menu * OVER_MAIN);
            hours_menu += (40 * rate_menu);
            printf("Всего заработано => %lf\n", hours_menu);
            return hours_menu;    
        }
        else
        {
            hours_menu *= rate_menu;
            printf("Всего заработано => %lf\n", hours_menu);
            return hours_menu;
        }
    }
}

double clear_salary_and_tax(double money)
{
    double tax_priv = 0;
    double input_money;
    double money_priv;

    input_money = money;
    if (money > 300)
    {
        if (money > 450)
        {
                money -= 450;
                money *= TAX_LAST;
                money += (300 * TAX_300) + (150 * TAX_450);
                tax_priv = input_money - money;
                money_priv = money;
                printf("Чистыми => %lf\n", money_priv);
                printf("Налог => %lf\n", tax_priv);
                return money_priv, tax_priv;
        }
        else
        {
            money -= 300;
            money *= TAX_450;
            money += (300 * TAX_300);
            tax_priv = input_money - money;
            money_priv = money;
            printf("Чистыми => %lf\n", money_priv);
            printf("Налог => %lf\n", tax_priv);
            return money_priv, tax_priv;
        }
    }
    else
        money *= TAX_300;
        tax_priv = input_money - money;
        money_priv = money;
        printf("Чистыми => %lf\n", money_priv);
        printf("Налог => %lf\n", tax_priv);
        return money_priv, tax_priv;
}

void stars(void)
{
    for (int i = 0; i <= 40; i++)
    {
        putchar('*');
    }
    printf("\n");
    return;
}
