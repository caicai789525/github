#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i; j++) {
            printf("   "); 
        }
        for (int j = 0; j <= i; j++) {
            int coef = binomialCoefficient(i, j);
            printf("%6d   ", coef);
        }
        printf("\n");
    }
}

int main() {
    int numRows;
    printf("输入要生成的杨辉三角的行数: ");
    scanf("%d", &numRows);
    printPascalTriangle(numRows);
    return 0;
}
