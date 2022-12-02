// answer: 64929

#include <stdio.h>
#include <string.h>

int main(){

    int maiorCaloria = 0, aux0 = 0, aux1 = 1;
    FILE *f = fopen("input.txt", "r");
    char stringaux[15];
    // aux0 and aux1 are auxiliary variables. They are used to read and store the values from input.txt, respectively.
    // stringaux is an auxiliary variable used on the fgets function.
    // maiorCaloria (translates to "biggestCalorie" from Portuguese -> English) will store the biggest amount of calories found.

    // checks for file.
	if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }

    while (fgets(stringaux, sizeof(stringaux), f))
    {
        // checks if the current line is empty (is equal to "\n").
        //
        // strcmp outputs a value of 0 if both strings are equal,
        // which means the if statement reads it as FALSE instead of TRUE if they are equal.
        if ((strcmp(stringaux, "\n")))
        {
            aux0 = atoi(stringaux);
            aux1 += aux0;
        }
        else
        {
            if (maiorCaloria < aux1)
            {
                maiorCaloria = aux1;
            }
            aux1 = 0;
        }
    }

    fclose(f);
    printf("%d\n", maiorCaloria);
    return 0;
}