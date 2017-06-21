/**返回x中从右边数第p位开始向右数n位的字段。假定最右边的一位是第0位，n与p都是合理的正值。例如getbits(x, 4, 3)返回x中第4、3、2三位的值。**/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main()
{
    printf("2����1101: %d", getbits(13, 2, 2));   //����Ӧ��Ϊ2����10 10����Ϊ2
    return 0;
}