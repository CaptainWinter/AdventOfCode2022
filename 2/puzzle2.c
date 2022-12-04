// answer: 12276

#include <stdio.h>
#include <string.h>


// returns the value of each possible play
int valueOf (char ch)
{
    switch (ch)
    {
        case 'A':
            return 1;
            break;
        case 'X':
            return 1;
            break;

        case 'B':
            return 2;
            break;
        case 'Y':
            return 2;
            break;

        case 'C':
            return 3;
            break;
        case 'Z':
            return 3;
            break;
            
        default:
            break;
    }
    return 0;
}

// returns the value of each possible outcome
int roundState (char ch1, char ch2)
{
    switch (ch1)
    {
    case 'A':                   // Elve picks Rock
        if (ch2 =='Y')          // We win
            return 6;
        else if (ch2=='Z')      // We lose
            return 0;
        else                    // Draw
            return 3;
        break;

    case 'B':                   // Elve picks Paper
        if (ch2=='Z')           // We win
            return 6;
        else if (ch2=='X')      // We lose
            return 0;
        else                    // Draw
            return 3;
        break;

    case 'C':                   // Elve picks Scissors
        if (ch2=='X')           // We win
            return 6;
        else if (ch2=='Y')      // We lose
            return 0;
        else                    // Draw
            return 3;
        break;

    default:
        break;
    }
    return 0;
}

int main ()
{
    // A / X-> Rock
    // B / Y-> Paper
    // C / Z-> Scissors

    char ch1, ch2; // ch1 stores elve's play, ch2 stores our play
    int totalValue = 0;
    FILE *f = fopen("input.txt", "r");

    // checks for file.
	if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }
    
    while (!(fscanf(f, "%c %c\n", &ch1, &ch2)==EOF))
    {
        totalValue += valueOf(ch2) + roundState(ch1, ch2);
    }

    fclose(f);
    printf("%i", totalValue); 
    return 0;
}