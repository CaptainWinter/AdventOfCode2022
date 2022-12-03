// answer: 64929

#include <stdio.h>
#include <string.h>

int main(){

    int maiorCaloria = 0, aux = 0;
    FILE *f = fopen("input.txt", "r");
    char stringaux[15];
    // aux is a auxiliary variable. It's used to read and store the values from input.txt.
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
        if ((strcmp(stringaux, "\n")))
            aux += atoi(stringaux);

        // stores the calorie value if it's the highest so far.    
        else
        {
            if (maiorCaloria < aux)
            {
                maiorCaloria = aux;
            }
            aux = 0;
        }
    }

    fclose(f);
    printf("%d\n", maiorCaloria);
    return 0;
}