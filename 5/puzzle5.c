#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, begin, end;
    char* finalMessage;
    char* straux;
    char crane;
    char* piles[9]={"FCPGQR",
                    "WTCP",
                    "BHPMC",
                    "LTQSMPR",
                    "PHJZVGN",
                    "DPJ",
                    "LGPZFJTR",
                    "NLHCFPTJ",
                    "GVZQHTCW"};
    FILE *f = fopen("input.txt", "r");

    if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", piles[i]);
    }  

    while (!(fscanf(f, "move %i from %i to %i\n", &num, &begin, &end)==EOF))
    {
        printf("%i %i\n", begin, end);
        begin-=1;
        end-=1;

        for (int i = 0; i < num; i++)
        {
            piles[end] = malloc((strlen(piles[end])+1)*sizeof(char));
            printf("%s\n", piles[end]);
            strcpy(straux,piles[end][i]);
            strcpy(straux, piles[end]);
            straux[strlen(piles[end])] = piles[begin][strlen(piles[begin])];
            straux[strlen(piles[end])+1] = '\0';
            //piles[end][strlen(piles[end])] = piles[begin][strlen(piles[begin])];
            piles[begin][strlen(piles[begin]-1)] = '\0';
        }
    }

    for (int i = 0; i < 9; i++)
    {
        finalMessage = malloc((strlen(finalMessage)+1)*sizeof(char));
        finalMessage[strlen(finalMessage)] = piles[i][strlen(piles[i])];
    }   
}