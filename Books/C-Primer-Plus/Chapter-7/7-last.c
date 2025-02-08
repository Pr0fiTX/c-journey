#include <stdio.h>
#define ARTISHOK 2.05  // За кило
#define BEET 1.15 
#define CARROT 1.09
#define DISCOUNT 0.95  // Заказ свыше $100 (без доставки). Высчитывает итог после применения скидки.
#define DELIVERY_BORDER1 5.0
#define DELIVERY_BORDER2 20.0
#define DELIVERY_UPTO_BD1 6.50
#define DELIVERY_UPTO_BD2 14.00
#define DELIVERY_OVER_BD2 0.50  // За каждый кг
#define EXIT -1

double weight_of_order_menu(double *, double *, double *);
double price_of_order(double, double, double);
double price_of_delivery(double);
double result_price(double, double);
void menu_drawer(void);


int main(void)
{
    double order_price, delivery_price, order_weight, end_price;
    double artishok_weight = 0;
    double beet_weight = 0;
    double carrot_weight = 0;

    while (order_weight != EXIT)
    {
        order_weight = weight_of_order_menu(&artishok_weight, &beet_weight, &carrot_weight);
        if (order_weight == EXIT)
            break;
        order_price = price_of_order(artishok_weight, beet_weight, carrot_weight);
        delivery_price = price_of_delivery(order_weight);
        end_price = result_price(order_price, delivery_price);
        printf("Подтвердить заказ и создать новый / выйти (нажмите <ENTER>).\n");
        getchar();
        getchar();
    }
    return 0;
}

double weight_of_order_menu(double * pa_w, double * pb_w, double * pc_w)
{
    char selected_product;
    double weight, order_weight;
    int i = 0;

    while (1)
    {
        menu_drawer();
        if (i >= 1)  // Костыль для кривого вывода(?)
            getchar();
        printf("Введите номер продукта / действия:\n");
        selected_product = getchar();
        if (selected_product == '4')
        {
            return order_weight;
        }
        if (selected_product != '1' && selected_product != '2' && selected_product != '3' && selected_product != '4')
        {
            printf("Спасибо, что воспользовались нашими услугами!\n");
            order_weight = EXIT;
            return order_weight;
        }
        printf("Отлично, а теперь введите вес: ");
        scanf("%lf", &weight);
        i++;
        if (selected_product == '1')
        {
            *pa_w += weight;
            order_weight += weight;
        }
        if (selected_product == '2')
        {
            *pb_w += weight;
            order_weight += weight;
        }
        if (selected_product == '3')
        {
            *pc_w += weight;
            order_weight += weight;
        }
    }
}

double price_of_order(double a_w, double b_w, double c_w)  // artishok_weight, beet_weight, carrot_weight
{
    double cost_a = 0;  // a - артишок, b - свекла (beet), c - морковь (carrot)
    double cost_b = 0;
    double cost_c = 0;
    double full_cost = 0;
    double discount_cost;

    cost_a = a_w * ARTISHOK;
    cost_b = b_w * BEET;
    cost_c = c_w * CARROT;
    full_cost = cost_a + cost_b + cost_c;
    if (full_cost >= 100.0)
        discount_cost = (1.00 - DISCOUNT) * full_cost;
        full_cost *= DISCOUNT;
        printf("СКИДКА => $%.2lf\n", discount_cost);
    if (cost_a > 0)
        printf("Артишоки => $%.2lf (%.2lf кг)\n", cost_a, a_w);
    if (cost_b > 0)
        printf("Свекла => $%.2lf (%.2lf кг)\n", cost_b, b_w);
    if (cost_c > 0)
        printf("Морковь => $%.2lf (%.2lf кг)\n", cost_c, c_w);

    return full_cost;
}

double price_of_delivery(double weight)
{
    double del_price;
    del_price = 0;

    if (weight > DELIVERY_BORDER1)
    {
        if (weight > DELIVERY_BORDER2)
        {
            del_price = weight - 25;
            del_price *= DELIVERY_OVER_BD2;
            del_price += (5 * DELIVERY_UPTO_BD1) + (20 * DELIVERY_UPTO_BD2);
            printf("Доставка => $%.2lf (%.2lf кг)\n", del_price, weight);
            return del_price;  
        }
        else
        {
            del_price = weight - 5; 
            del_price *= DELIVERY_UPTO_BD2;
            del_price += 5 * DELIVERY_UPTO_BD1;
            printf("Доставка => $%.2lf (%.2lf кг)\n", del_price, weight);
            return del_price;
        }
    }
    else 
        del_price = weight * DELIVERY_UPTO_BD1;
        printf("Доставка => $%.2lf (%.2lf кг)\n", del_price, weight);
        return del_price;
}

double result_price(double o_pr, double d_pr)  // order_price, delivery_price
{
    double end_price = 0;

    end_price = o_pr + d_pr;
    printf("ИТОГО => $%.2lf\n", end_price);

    return end_price;
}

void menu_drawer(void)
{
    for (int i = 0; i <= 60; i++)
    {
        putchar('*');
    }
    printf("\n");
    printf("Введите номер товара и, через пробел, количество (в кг):\n");
    printf("1) Артишок\n2) Свекла\n3) Морковь\n4) Перейти к оплате\n");
    printf("(Любой символ кроме 1,2,3,4) Выход.\n");
    for (int a = 0; a <= 60; a++)
    {
        putchar('*');
    }
    printf("\n");
    return;
}