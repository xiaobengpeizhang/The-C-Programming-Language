/*
 * 逗号运算符是C语言中优先级最低的运算符。被逗号分隔的一对表达式，将按照从左到右的顺序进行求职。逗号表达式的值和类型是右边表达式的值和类型.
 */

/**函数reverse(s)该函数用于倒置字符串s中各个字符的位置*/
#include <string.h>
#include <stdio.h>
void reverse (char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/*简化版*/
void reverse2 (char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--;)
        c = s[i], s[i] = s[j], s[j] = c;
    
}

int main()
{
    int i, j;
    i = j = 0;
    printf("%d %d", (--j, ++i));
    return 0;
}