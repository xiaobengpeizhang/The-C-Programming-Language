/**重新编写将大写字母转换为小写字母的函数lower，并用条件表达式替代其中的if-else结构**/

#include <stdio.h>

int lower(int c)
{
    if (c > 'A' && c <'Z')
        return c + 'a' - 'A';
    else 
        return c;
}

int lower2(int c)
{
    return (c > 'A' && c < 'Z') ? (c + 'a' - 'A') : c;
}

int main()
{
    printf("lower(D) = %c\n", lower('D'));
    printf("lower2(D) = %c\n", lower2('D'));
}