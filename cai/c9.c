#include<stdio.h>
#include<string.h>
    int ans = 0;
int romanToInt(char* s) {
    printf("输入罗马数字：");       scanf("%d",*s);
    int values[26];
    values['I' - 'A'] = 1;
    values['V' - 'A'] = 5;
    values['X' - 'A'] = 10;
    values['L' - 'A'] = 50;
    values['C' - 'A'] = 100;
    values['D' - 'A'] = 500;
    values['M' - 'A'] = 1000;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int v = values[s[i] - 'A'];
        if (i < n - 1 && v < values[s[i + 1] - 'A']) {
            ans -= v;
        } else {
            ans += v;
        }
    }
    return ans;
}

int main(){
    romanToInt;
    printf("%d",ans);
}
