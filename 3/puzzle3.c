// answer: P1: 7428, P2: 2650

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sumOfValues (char* string)
{
    //printf("a");
    int value = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (65 <= string[i] && string[i] <=90)
        {
            value += string[i] - 38;
        }
        if (97 <= string[i] && string[i] <=122)
        {
            value += string[i] - 96;
        }
    }

    printf("%i", value);
}

int main ()
{   
    const size_t line_size = 600;
    char* string = malloc(line_size);
    char* stringcommon = malloc(line_size);
    char* stringaux0;
    char* stringaux1;
    char* stringaux2;
    char* commonchar;
    int len=0, len1=0, len2=0, num = 0;
    FILE *f = fopen("input.txt", "r");

    // checks for file.
	if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }


    // PART 1 - TO FINISH
    while (fgets(string, line_size, f) != NULL) 
    {
        len = strlen(string)-1;
        len1 = len/2;
        len2 = len - len1;
        //printf("%i %i %i\n", len, len1, len2);
        stringaux0= malloc(len1+1);
        stringaux1 = malloc(len2+1);
        memcpy(stringaux0,string, len1);
        memcpy(stringaux1,string+len1, len2);
        //printf("%s %s\n", stringaux0, stringaux1);

        for (int i = 0; i < len1; i++)cd
        {
            for (int j = 0; j < len2; j++)
            {
                if (stringaux0[i] == stringaux1[j])
                {
                    
                    stringcommon[strlen(stringcommon)] = stringaux0[i];
                    //printf("%c\n%i\n\n", stringaux0[i], strlen(stringcommon));
                    break;

                }
            }   
        }
        
    }

    //PART 2
    while (fgets(string, line_size, f) != NULL)
    {

    }


    //printf("%s\n%i\n\n", stringcommon, strlen(stringcommon));
    sumOfValues(stringcommon);
    fclose(f);
    return 0;
}