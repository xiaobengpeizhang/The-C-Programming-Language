/**��дһ��������ȷ���ֱ���signed��unsigned�޶���char��short��int��long���ͱ�����ȡֵ��Χ�����ô�ӡ��׼ͷ�ļ��е���Ӧֵ�Լ�ֱ�Ӽ������ַ�ʽʵ�֡���һ�ַ�����ʵ�ֽ�����һЩ����ΪҪȷ�����ָ������͵�ȡֵ��Χ��**/

#include <stdio.h>
#include <limits.h>
int main()
{
    /**����1**/
    printf("***********����1************\n");
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
     *����2
     *���ڲ�����򣬵����з���nλ��ȡֵ��ΧΪ -(2��n-1�η�) ~ (2��n-1�η� - 1)
     */
    printf("***********����2************\n");
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
     *����3
     *���ݲ������8λ���з�����СֵΪ1000 0000 16λ���з�����СֵΪ1000 0000 0000 0000 
     *��˿������Ƶõ���Ӧֵ
     */
    printf("***********����3************\n");
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