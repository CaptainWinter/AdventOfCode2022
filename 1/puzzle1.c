#include <stdio.h>
#include <string.h>

int main(){
    int maiorCaloria = 0, aux0 = 0, aux1 = 1, c = 0;
    FILE *f = fopen("input.txt", "r");
    char stringaux[15];

	if (f == NULL)
    {
        printf("Ficheiro nao encontrado");
        return 1;
    }

    while (fgets(stringaux, sizeof(stringaux), f))
    {
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