#include <stdio.h>

int main()
{
    unsigned int x = 9;
    x >>= 1; // 0100
    printf("x:1001(9) -> 0100(4) = %d\n", x);
    return 0;
}