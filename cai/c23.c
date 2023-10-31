#include <stdio.h>

double customPow(double base, int exponent) {
    double result = 1.0;

    if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else if (exponent < 0) {
        for (int i = 0; i > exponent; i--) {
            result /= base;
        }
    }

    return result;
}

int main() {
    double base;
    printf("double base\n");
    scanf("%lf",&base);
    int exponent;
    printf("exponent\n");
    scanf("%d",&exponent);

    double result = customPow(base, exponent);

    printf("%lf^%d = %lf\n", base, exponent, result);

    return 0;
}
