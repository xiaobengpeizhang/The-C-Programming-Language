/**统计数字空白符及其他字符**/

#include <stdio.h>

int main()
{
    int c, digits[10], nwhite, nothers, i;
    for (i = 0; i < 10; i++)
        digits[i] = 0;
    nwhite = nothers = 0;
    while ((c = getchar()) != 'p')
    {
        switch (c) 
        {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                digits[c-'0']++;
                break;
            case ' ': case '\n': case '\t':
                nwhite++;
                break;
            default:
                nothers++;
                break;
        }
    }

    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d ", digits[i]);
    printf("white = %d, others = %d", nwhite, nothers);

    return 0;
}