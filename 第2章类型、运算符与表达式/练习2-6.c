/**编写一个函数setbits(x,p,n,y),该函数返回对x执行下列操作后的结果：将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，x的其余各位保持不变**/

/*
 *题目分析：假如setbits(1010（2进制）, 2, 2, 1111（2进制）) -> 1110
 *对y: ~(~0 << n) & y -> 最后n位的值。 -> y:0011
 *对x: 因为任何位|0都为自身 所以想办法将x(1010)变为1 00 0 即目标的那两位变为0。将此时的y(0011)变为0 11 0
 *原则就是为了保证是自身就要|0，谁要是保留自身就让它|0。  两者|运算。 1000|0110 == 1110
 *将x从1010变为1000 必须1010&1001,要得到1001，必须~(~(~0<<n)<<p+1-n) & x
 */

#include <stdio.h>

unsigned setbits(x, p, n, y)
{
    return ((~(~0 << n) & y) << (p + 1 - n)) | (x & ~(~(~0 << n) << (p + 1 - n)));
}

int main()
{
    printf("2进制1010和2进制1111得到2进制1110==8+4+2==14 = %d", setbits(10, 2, 2, 15));
    return 0;
}
