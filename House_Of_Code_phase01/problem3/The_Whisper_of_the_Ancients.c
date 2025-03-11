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
    int LenthgOfString = My_strlen(str);
    char *Ptr_str;
    Ptr_str = str + (LenthgOfString - 1); // pointe sur la dernier element
    char *Tmp_str = malloc(LenthgOfString * 1);
    for (int i = 0; i < LenthgOfString; i++)
    {
        Tmp_str[i] = *Ptr_str;
        Ptr_str--;
    }
    for (int i = 0; i < LenthgOfString; i++)
    {
        *str = Tmp_str[i];
        str++;
    }
    // free
    free(Tmp_str);
    Tmp_str = NULL;
    Ptr_str = NULL;
}

void put_str1_in_str2(char *str1, char *str2, int BeginingOfString, int lengthOfSTr)
{

    if (BeginingOfString != 0)
    {
        *(str2 + BeginingOfString - 1) = ' ';
    }
    int count = BeginingOfString;
    while (BeginingOfString != lengthOfSTr)
    {
        *(str2 + BeginingOfString) = *str1;
        str1++;
        str2++;
        BeginingOfString++;
    }
}

void Reverse_Words(char str[])
{
    int LengthOfStr = My_strlen(str);
    char *Sub_Str = NULL;
    char *Tmp_Str = NULL;
    // Variable Sub_Str contine the word in string
    Sub_Str = (char *)malloc(LengthOfStr);
    // variable Tmp_str contine the reverse word
    Tmp_Str = (char *)malloc(LengthOfStr);

    int BeginingOfString = LengthOfStr;
    for (int i = 0; i < LengthOfStr; i++)
    {
        if (str[i] == ' ' || i == LengthOfStr - 1)
        {
            put_str1_in_str2(Sub_Str, Tmp_Str, BeginingOfString, LengthOfStr); //
            Sub_Str = '\0';
        }
        else
        {
            BeginingOfString--;
            *(Sub_Str + i) = str[i];
        }
    }

    // free
    free(Sub_Str);
    free(Tmp_Str);
    Sub_Str = NULL;
    Tmp_Str = NULL;
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
