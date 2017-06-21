/**在上面有关折半查找的例子中，while循环语句内共执行了两次测试，其实只要一次就足够。（代价是将更多的测试在循环外执行）。重写该函数，使得在循环内部只执行一次测试。比较两种版本函数的运行时间**/

#include <stdio.h>

/**原函数**/
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

/**新函数**/
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid])
    {
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else 
        return -1;
}

int main()
{
    int v[6] = {1, 2, 3, 4, 5, 6};
    printf("123456(4) -> 3 = %d\n", binsearch(4, v, 6));
    printf("123456(4) -> 3 = %d\n", binsearch2(4, v, 6));
    return 0;
}