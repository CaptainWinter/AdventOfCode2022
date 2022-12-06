// 1892
// sqzgdbflhvpwcr
// 2313

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    ssize_t read;
    size_t len = 0;
    char* string;
    int count = 0, flag = 0, part = 2;
    FILE *f = fopen("input.txt", "r");

    if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }

    while ((read = getline(&string, &len, f)) != -1)
    {
        if (part ==1)
        {
            // Entire line
            for (int i = 0; i <= (strlen(string)); i++)
            {
                flag  = 0;
                // char j to char j+2
                for (int j = 0; j < 3; j++)
                {
                    // from char j to char j+3
                    for (int k = j+1; k < 4; k++)
                    {
                        if (string[count+j] == string[count+k])
                            flag = 1;
                    } 
                }
                count += flag;
                if (flag == 0)
                    break;
            }
        }
        else
        {
            // Entire line
            for (int i = 0; i <= (strlen(string)); i++)
            {
                flag  = 0;
                // char j to char j+2
                for (int j = 0; j < 13; j++)
                {
                    // from char j to char j+3
                    for (int k = j+1; k < 14; k++)
                    {
                        if (string[count+j] == string[count+k])
                            flag = 1;
                    } 
                }
                count += flag;
                if (flag == 0)
                    break;
            }
        }
        
        
    }
    
    // the chars of the solution wont trigger the funtion
    if (part == 1)
        count += 4;
    else
        count += 14;
    
    printf("%i", count);
    fclose(f);
    return 0;
}