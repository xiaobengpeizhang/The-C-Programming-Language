/**bitcount函数，统计x中值为1的二进制位数**/
#include <stdio.h>

int bitcount(unsigned x)
{
    int b = 0;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int main()
{
    printf("1101 == 8 + 4 + 2 == 14 (3) = %d\n", bitcount(14));
    return 0;
}
