/**编写一个函数escape(s, t),将字符串t复制到字符串s中，并在复制过程中将换行符，制表符等不可见字符分别转换为\n,\t等相应的可见的转义字符序列。要求使用switch语句。再编写一个具有相反功能的函数，再复制过程中将转义字符序列转换为实际字符。**/

#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    for (i = j = 0; t[i] != '\0'; ++i)
    {
        switch (t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
    printf("s: %s", s);
}

void unescape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\\':
                switch (t[++i])
                {
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                }
                break;
            default: 
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
    printf("s: %s", s);
}

int main()
{
    // escape("ab", "c\tde");
    unescape("ab", "c\\t\\ade");
    return 0;
}