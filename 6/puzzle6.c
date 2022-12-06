#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkChars(int count, char* string, int size)
{
    // char j to char j+2
    for (int j = 0; j < size-1; j++)
    {
        // from char j to char j+3
        for (int k = j+1; k < size; k++)
        {
            if (string[count+j] == string[count+k])
                return 1;
        } 
    }
    return 0;
}

int counting(char* string, int size)
{
    int count = 0, flag = 0;
    // Entire line
    for (int i = 0; i <= (strlen(string)); i++)
    {
        flag  = checkChars(count, string, size);
        count += flag;
        if (flag == 0)
            return count + size;
    }
    return 0;
}

int main()
{
    ssize_t read;
    size_t len = 0;
    char* string;
    int count = 0, part = 2;
    FILE *f = fopen("input.txt", "r");

    if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }

    while ((read = getline(&string, &len, f)) != -1)
    {
        // the chars of the solution wont trigger the funtion
        if (part ==1)
            printf("%i", counting(string, 4));
        else
            printf("%i", counting(string, 14));
            
    }

    fclose(f);
    return 0;
}