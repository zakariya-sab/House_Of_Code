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

int main()
{
    char test1[] = "edoc fo esuoH oT emocleW";
    char test2[] = "uoy pleh lliw ti ;3 melborp ni noitcnuf siht esU";
    char test3[] = "Hello World";
    char test4[] = "G";
    printf("Before: %s\n", test1);
    reverse_string(test1);
    printf("After: %s\n\n", test1);
    printf("Before: %s\n", test2);
    reverse_string(test2);
    printf("After: %s\n\n", test2);
    printf("Before: %s\n", test3);
    reverse_string(test3);
    printf("After: %s\n\n", test3);
    printf("Before: %s\n", test4);
    reverse_string(test4);
    printf("After: %s\n\n", test4);
    return 0;
}