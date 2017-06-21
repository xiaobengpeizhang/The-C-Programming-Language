/**一个折半查找函数，用来判定已排序的数组v是否存在摸个特定的值x。数组v的元素必须以升序排列。如果v中包含x。则该函数返回x在v中的位置（介于0~n-1之间的一个整数），否则返回-1. 在折半查找时候，首先将输入值x与数组y的中间元素进行比较。如果x小于中间元素的值。则在该数组的前半段部分查找。否则，在该数组的后半部分查找。在这两种情况下，下一步都是将x与所选部分的中间元素进行比较。这个过程一直进行下去，直到找到指定的值或查找范围为空**/

/*
 *分析： 1234  0 + 3  = 3 / 2 = 1
 * 12345 0 +4 = 4 / 2 = 2
 */
#include <stdio.h>

int binsearch(int x, int v[], int n)
{
     int low, high, mid;
     low = 0;
     high = n - 1;

     while (low <= high)
     {
        mid = (low + high) / 2;
        if (x == v[mid])
            return mid;
        else if (x > v[mid])
            low = mid + 1;
        else 
            high = mid - 1;
     }
     
     return -1;
}

int main()
{
    int v[6] = {1, 2, 3, 4, 5, 6};
    printf("123456(4) -> 3 = %d\n", binsearch(4, v, 6));
    int v2[11] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6};
    printf("11223334456(3) -> 4 = %d\n", binsearch(3, v2, 11)); // 有局限，这种情况下效果就不好了。
    return 0;
}