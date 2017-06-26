/**编写函数expand(s1, s2)，将字符串s1中类似于a-z一类的速记符号在字符串s2中扩展为等价的完整列表abc...xyz。该函数可以处理大小写字母和数字。并可以处理a-b-c、a-z0-9与**/
/*
#include <stdio.h>

void expand(char s1[], char s2[])
{
    char c;
    int i, j;
    i = j = 0;
    while ((c = s1[i++]) != '\0')
    {
        if (s1[i] =='-' && s1[i+1] >= c)
        {
            i++;
            while (c < s1[i])
                s2[j++] = c++;
        }
        else 
            s2[j++] = c;
    }
    s2[j] ='\0';
    printf("s1 = %s s2 = %s", s1, s2);
}

int main()
{
    char s1[] = "a-a-ab";
    char s2[10];
    expand(s1, s2);
}
*/

/*练习3-4 在数的对二的补码表示中，我们编写的itoa函数不能处理最大的负数，即n等于-(2指数（字长-1))的情况。请解释其原因。修改函数，使它在任何机器上运行时都能打印出正确的值*/

#define abs(x)  ((x) < 0 ? -(x) : (x))

void itoa(int n ,char s[])
{
    int i , sign;
    sign = n;
    i = 0;
    do 
    {
        s[i++] = abs(n % 10) + '0';
    }
    while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

//对二的补码所能表示的最大正数是2(字长-1) -1    如8位 -128~127 不能直接 n = -n n无法表示128因为超过范围了

/*练习3-5 编写函数itob(n, s, b)，将整数n转换为以b为底的数，并将转换结果以字符的形式保存到字符串s中。例如itob(n, s, 16)把整数n格式化成十六进制整数保存在s中。*/

void itob(int n, char s[], int b)
{
    int i, j , sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do 
    {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j - 10 + 'a';
    }
    while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/*练习3-6 修改itoa函数，使得该函数可以接受三个参数。其中，第三个参数为最小字段宽度。为了保证转换后所得的结果至少具有三个参数指定的最小宽度，在必要时影在所得结果的左边填充一定的空格。*/

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w)
{
    int i, sign;
    sign = n;
    i = 0;
    do 
    {
        s[i++] = abs(n % 10) + '0';
    }
    while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}