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

void Reverse_Words(char str[])
{

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
