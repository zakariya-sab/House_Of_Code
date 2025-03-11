#include <stdio.h>
#include <stdbool.h>
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

bool isValid(const char *str)
{
    int size = My_strlen(str);
    if (size == 0)
    {
        return false;
    }
    char *stack = (char *)malloc(sizeof(char) * size);
    int CurrentPosition = 1;
    stack[0] = str[0]; // pour la premier fois
    int i = 1;
    while (CurrentPosition != size)
    {
        stack[i] = str[CurrentPosition];
        if (i == 0)
        {
            CurrentPosition++;
            i++;
        }
        else if ((stack[i] == '}' && stack[i - 1] == '{') || (stack[i] == ']' && stack[i - 1] == '[') || (stack[i] == ')' && stack[i - 1] == '('))
        {
            i--;
            CurrentPosition++;
        }
        else if ((stack[i] != '}' && stack[i] != '{') && (stack[i] != ']' && stack[i] != '[') && (stack[i] != ')' && stack[i] != '('))
        {
            CurrentPosition++;
        }
        else
        {
            CurrentPosition++;
            i++;
        }
    }

    if (i == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *CheckIsValid(const char *str)
{
    if (isValid(str) == true)
    {
        return "True";
    }
    else
    {
        return "False";
    }
}

int main(void)
{
    const char *test1 = "()";
    const char *test2 = "[{()}]";
    const char *test3 = "{[(a+b) * x}";
    const char *test4 = "{[a+b]*(x/y)}";
    printf("Test 1: %s\n", test1);
    printf("Is valid: %s\n", CheckIsValid(test1));
    printf("Test 2: %s\n", test2);
    printf("Is valid: %s\n", CheckIsValid(test2));
    printf("Test 3: %s\n", test3);
    printf("Is valid: %s\n", CheckIsValid(test3));
    printf("Test 4: %s\n", test4);
    printf("Is valid: %s\n", CheckIsValid(test4));
    return 0;
}
