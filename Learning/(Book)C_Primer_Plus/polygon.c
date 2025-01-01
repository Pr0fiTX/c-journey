#include <stdio.h>

// Рекурсивная функция для возведения числа x в степень n
double power(double x, int n) {
    // Базовый случай: любое число в степени 0 равно 1
    if (n == 0) {
        printf("n == 0 (up)\n"); // Debug
        return 1;
    }
    // Если n отрицательное, меняем x и берем обратную степень
    else if (n < 0) {
        return 1 / power(x, -n);
    }
    // Рекурсивный случай: x в степени n равно x умножить на x в степени n-1
    else {
        return x * power(x, n - 1);
    }
}

int main() {
    double x;
    int n;

    printf("Введите число: ");
    scanf("%lf", &x);
    printf("Введите степень: ");
    scanf("%d", &n);

    double result = power(x, n);
    printf("%lf в степени %d равно %lf\n", x, n, result);

    return 0;
}
