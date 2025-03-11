#include <stdio.h>
#include <stdlib.h>

int My_strlen(const char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        str++;
        count++;
    }
    return count;
}

void reverse_string(char *str)
{
    int PosOfEnd = My_strlen(str) - 1;
    int PosOfStart = 0;
    char tmp;
    while (PosOfStart < PosOfEnd)
    {
        tmp = str[PosOfStart];
        str[PosOfStart] = str[PosOfEnd];
        str[PosOfEnd] = tmp;
        PosOfEnd--;
        PosOfStart++;
    }
}

void Reverse_Words(char str[])
{
    reverse_string(str);
    int LenthgOfString = My_strlen(str);
    int PosOfStart = 0;
    int PosOfEnd = 0;
    int i;
    char tmp;
    for (i = 0; i < LenthgOfString; i++)
    {
        if (str[i] == ' ')
        {
            PosOfEnd = i - 1;
            while (PosOfEnd > PosOfStart)
            {
                tmp = str[PosOfStart];
                str[PosOfStart] = str[PosOfEnd];
                str[PosOfEnd] = tmp;
                PosOfEnd--;
                PosOfStart++;
            }
            PosOfStart = i + 1;
        }
    }
    PosOfEnd = LenthgOfString - 1;
    while (PosOfEnd > PosOfStart)
    {
        tmp = str[PosOfStart];
        str[PosOfStart] = str[PosOfEnd];
        str[PosOfEnd] = tmp;
        PosOfEnd--;
        PosOfStart++;
    }
}
int main(void)
{
    char test1[] = "The dragons are coming";
    char test2[] = "code love I";
    char test3[] = "G";
    printf("Before: %s\n", test1);
    Reverse_Words(test1);
    printf("After: %s\n\n", test1);
    printf("Before: %s\n", test2);
    Reverse_Words(test2);
    printf("After: %s\n\n", test2);

    printf("Before: %s\n", test3);
    Reverse_Words(test3);
    printf("After: %s\n\n", test3);
    return 0;
}
