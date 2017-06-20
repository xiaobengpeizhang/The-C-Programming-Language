/**编写一个程序以确定分别由signed及unsigned限定的char、short、int与long类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。**/

#include <stdio.h>
#include <limits.h>
int main()
{
    /**方法1**/
    printf("***********方法1************\n");
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("signed long min = %ld\n", LONG_MIN);
    printf("signed long max = %ld\n", LONG_MAX);
    
    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned long max = %lu\n", ULONG_MAX);

    /*
     *方法2
     *由于补码规则，导致有符号n位的取值范围为 -(2的n-1次方) ~ (2的n-1次方 - 1)
     */
    printf("***********方法2************\n");
    printf("signed char min = %d\n", -(signed char)((unsigned char)~0 >> 1) - 1);
    printf("signed char max = %d\n", (signed char)((unsigned char)~0 >> 1));
    printf("signed short min = %d\n", -(signed short)((unsigned short)~0 >> 1) - 1);
    printf("signed short max = %d\n", (signed short)((unsigned short)~0 >> 1));
    printf("signed int min = %d\n", -(signed int)((unsigned int)~0 >> 1) - 1);
    printf("signed int max = %d\n", (signed int)((unsigned int)~0 >> 1));
    printf("signed long min = %ld\n", -(signed long)((unsigned long)~0 >> 1) - 1);
    printf("signed long max = %ld\n", (signed long)((unsigned long)~0 >> 1));
    
    printf("unsigned char max = %u\n", (unsigned char)~0);
    printf("unsigned short max = %u\n", (unsigned short)~0);
    printf("unsigned int max = %u\n", (unsigned int)~0);
    printf("unsigned long max = %lu\n", (unsigned long)~0);

    /*
     *方法3
     *根据补码规则，8位的有符号最小值为1000 0000 16位的有符号最小值为1000 0000 0000 0000 
     *因此可以左移得到相应值
     */
    printf("***********方法3************\n");
    printf("signed char min = %d\n", (signed char)((unsigned char)~0 << 7));
    printf("signed char max = %d\n", (unsigned char)((unsigned char)~0 >> 1));
    printf("signed short min = %d\n", (signed short)((unsigned short)~0 << 15));
    printf("signed short max = %d\n", (signed short)((unsigned short)~0 >> 1));
    printf("signed int min = %d\n", (signed int)((unsigned int)~0 << 31));
    printf("signed int max = %d\n", (signed int)((unsigned int)~0 >> 1));
    printf("signed long min = %ld\n", (signed long)((unsigned long)~0 << 31));
    printf("signed long max = %ld\n", (signed long)((unsigned long)~0 >> 1));

    printf("unsigned char max = %u\n", (unsigned char)~0);
    printf("unsigned short max = %u\n", (unsigned short)~0);
    printf("unsigned int max = %u\n", ~0);
    printf("unsigned long max = %lu\n", (unsigned long)~0);
}