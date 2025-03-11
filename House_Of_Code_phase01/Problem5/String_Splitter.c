#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int NumberOfWordInString(const char *str, char delimiter)
{
    int LengthOfString = My_strlen(str);
    int count = 0;
    for (int i = 0; i < LengthOfString; i++)
    {
        if (i != 0 && str[i] == delimiter)
        {
            count++;
        }
    }
    count++;
    return count;
}

void AddSubStringInVector(char *vector, const char *str, int PosOfStart, int PosOfEnd)
{
    int LengthOfSubString = PosOfEnd - PosOfStart;
    int i = 0;
    for (i = 0; i <= LengthOfSubString; i++)
    {
        if (PosOfEnd >= PosOfStart)
        {
            vector[i] = str[PosOfStart];
            PosOfStart++;
        }
    }
    vector[i] = '\0';
}

char **split_str(const char *str, char delimiter)
{
    int LengthOfString = My_strlen(str);
    int NumberOfWordInStr = NumberOfWordInString(str, delimiter);
    char **vector = NULL;
    vector = (char **)malloc(sizeof(char *) * (NumberOfWordInStr + 1));
    if (vector == NULL)
    {
        perror("\n\nErreur d'allocation mémoire\n\n");
        return NULL;
    }
    for (int i = 0; i < NumberOfWordInStr + 1; i++)
    {
        vector[i] = "NULL";
    }
    int Pos_Of_Start_In_SubString = 0;
    int Pos_Of_End_In_SubString = 0;
    int Pos_Of_Word_In_Vector = 0;
    for (int i = 0; i < LengthOfString; i++)
    {
        if (i != 0 && str[i] == delimiter)
        {
            Pos_Of_End_In_SubString = i - 1;
            AddSubStringInVector(vector[Pos_Of_Word_In_Vector], str, Pos_Of_Start_In_SubString, Pos_Of_End_In_SubString);
            Pos_Of_Start_In_SubString = i + 1;
            Pos_Of_Word_In_Vector++;
        }
    }
    Pos_Of_End_In_SubString = LengthOfString - 1;
    AddSubStringInVector(vector[Pos_Of_Word_In_Vector], str, Pos_Of_Start_In_SubString, Pos_Of_End_In_SubString);
    Pos_Of_Word_In_Vector++;
}

int main(void)
{
    char *str = "IAE ,CLUB ,CHALLANGE";
    char **vector = split_str(str, ',');
    int i;
    i = 0;
    while (vector[i] != NULL)
    {
        printf("Substring %d : %s\n", i + 1, vector[i]);
        i++;
    }
    while (vector[i] != NULL)
    {
        free(vector[i]);
        i++;
    }
    free(vector);
    return 0;
}