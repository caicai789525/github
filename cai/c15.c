#include <stdio.h>

char findAddedLetter(char *s, char *t) {
    int charCount[26] = {0}; 

    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i] - 'a']--;
    }

    for (int i = 0; t[i] != '\0'; i++) {
        charCount[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (charCount[i] > 0) {
            return (char)('a' + i);
        }
    }

    return '\0'; 
}

int main() {
    char s[1000];
    char t[1000];
    printf("请输入s:\n");   scanf("%s",&s);
    printf("请输入t:\n");  scanf("%s",&t);
    char addedLetter = findAddedLetter(s, t);

    if (addedLetter != '\0') {
        printf("被添加的字母是: %c\n", addedLetter);
    } else {
        printf("没有找到被添加的字母\n");
    }

    return 0;
}
