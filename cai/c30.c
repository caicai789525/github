#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isSafePassword(const char* password) {
    int length = strlen(password);
    if (length < 8 || length > 45) {
        return false;
    }

    int charCategories = 0;

    for (int i = 0; i < length; i++) {
        char ch = password[i];
        if (isupper(ch)) {
            charCategories |= 1;
        } else if (islower(ch)) {
            charCategories |= 2;
        } else if (isdigit(ch)) {
            charCategories |= 4;
        } else if (strchr("~!@#$^%", ch)) {
            charCategories |= 8;
        }
    }

    return __builtin_popcount(charCategories) >= 3;
}

int main() {
    char password[60];
    printf("请输入密码: ");
    scanf("%s", password);

    if (isSafePassword(password)) {
        printf("密码安全。\n");
    } else {
        printf("密码不安全。\n");
    }

    return 0;
}
//经过chatgpt辅助