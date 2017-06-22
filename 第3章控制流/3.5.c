/*atod函数，将s转换为整型数版本2*/

#include <ctype.h>
#include <stdio.h>

int atod(char s[])
{
    int i = 0 ;
    for (i = 0; isspace(s[i]); i++)
        ;
    int sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    int n = 0;
    for(n = 0; isdigit(s[i]); i++)
        n = n * 10 + s[i] - '0';
    return sign * n;
}

/*Shell排序算法*/
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >=0 && v[j] > v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

/*
 * Shell排序算法中j -= gap的原因就是要照顾到往前回数gap位置的重复比较。而且gap会变小。所以回数的间隔变小次数会增多。
 */

int main()
{
    int v[7] = {3, 2, 1, 4, 5, 6, 8};
    shellsort(v, 7);
    for (int i = 0; i < 7; i++)
        printf(" %d ", v[i]);
    return 0;
}
