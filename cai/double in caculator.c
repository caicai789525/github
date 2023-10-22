#include<stdio.h>
int main(void)
{
    double vx,vy,result;
    char operator;

    printf("请输入运算符号(+,-,*,/):\n");    scanf("%c",&operator);
    printf("请输入数字：\n");                scanf("%lf%lf",&vx,&vy);
    switch(operator)
    {
        case '+':
        result=vx+vy;
        break;
        case '-':
        result=vx-vy;
        break;
        case '*':
        result=vx*vy;
        break;
        case '/':
        result=vx/vy;
        break;
        default:
        printf("无效运算符号！！！");
        return 1;
    }
    printf("%.2lf %c %.2lf=%.2lf\n",vx,operator,vy,result);

    return 0;
}
