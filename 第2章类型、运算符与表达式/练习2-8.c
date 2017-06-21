/**编写一个函数rightrot(x, n)，该函数返回将x循环右移（即从最右端移出的位将从最左端移入）n（二进制）位后所得到的值**/
/*
 *闁告帒妫欓悗浠嬫晬濮濓拷(1001) n(2) -> 1000 0000 ... 0000 0100 -> 0100 ... 0010
 *2婵炲棌鈧啿绀佺紒澶庮嚙閹﹪鎮抽敓锟�
 * 0100 | 1000 -> 1100
 * 1000闁汇垼椴稿锟�: ~0 -> 1111 << 1 -> 1110 | 0001 -> 1111 << 3 -> 1000
 * 0001闁汇垼椴稿锟� 1001 & ~(~0 << 1) -> 0001
 *缂佹鎷�2婵炲棌鈧櫕鍎曢柣婊愭嫹: 1100 -> 0110 | 0000 -> 0110
 */

#include <stdio.h>

int wordlength(void)
{
    int i;
    unsigned v = (unsigned)~0;
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}

 unsigned rightrot(unsigned x, int n)
 {
     unsigned temp = 0;
     for (int i = 0; i < n; ++i)
     {
         temp = ((x & 1) << 31);
         x = x >> 1;
         x = x | temp;
     }
     return x;
 }

 unsigned rightrot2(unsigned x, int n)
 {
    int rabit = 0;
    // printf("wordlength = %d\n", wordlength());
    while (n-- > 0)
    {
        rabit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rabit;
    }
    return x;
 }

/*
  *闁哄倽顫夌涵锟�3闁挎稒鐭粭澶愭閳ь剛鎲版担鍛婂剷闁绘粣鎷�
  *1001 -> 0010
  *0010 | 0100 == 0110
  *0100闁哄鍎茬花顕€鏁嶉敓锟�(1001 & ~(~0 << 2)) << 15 - 2
  */
  unsigned rightrot3(unsigned x, int n)
  {
      if ((n = n % wordlength()) > 0)
      {
          x = (x >> n) | ((x & ~(~0 << n)) << (wordlength() - n));
      } 
      return x;
  }

 int main()
 {
     printf("2闁哄鏅滅粙鎴﹀春閿燂拷1001闂佹寧鍐婚幏锟�8 + 1 == 9闂佹寧鍐婚幏锟�-> 2闁哄鏅滅粙鎴﹀春閿燂拷0110闂佹寧鍐婚幏锟�4 + 2 ==6闂佹寧鍐婚幏锟� = %u\n", rightrot(9, 2));
     printf("2闁哄鏅滅粙鎴﹀春閿燂拷1001闂佹寧鍐婚幏锟�8 + 1 == 9闂佹寧鍐婚幏锟�-> 2闁哄鏅滅粙鎴﹀春閿燂拷0110闂佹寧鍐婚幏锟�4 + 2 ==6闂佹寧鍐婚幏锟� = %u\n", rightrot2(9, 2));
     printf("2闁哄鏅滅粙鎴﹀春閿燂拷1001闂佹寧鍐婚幏锟�8 + 1 == 9闂佹寧鍐婚幏锟�-> 2闁哄鏅滅粙鎴﹀春閿燂拷0110闂佹寧鍐婚幏锟�4 + 2 ==6闂佹寧鍐婚幏锟� = %u\n", rightrot3(9, 2));

     return 0;
 }



