//answer: P1: 657; P2: 938
//tried P1: 164583 (too high), 736 (too high), 709 (too high), 657 (correct)
//tried P2: 18643 (too high), 1341 (too high), 684 (too low), 938 (correct)
#include <stdio.h>

int main()
{
    int v1,v2,v3,v4, count = 0, aux0, aux1, part = 2;
    FILE *f = fopen("input.txt", "r");

    // checks for file.
	if (f == NULL)
    {
        printf("File not found.");
        return 1;
    }

    while (!(fscanf(f, "%i-%i,%i-%i\n", &v1, &v2, &v3, &v4)==EOF))
    {     
        if (part==1)
        {
            // Checks if a range is within another range
            //  [v1-------------v2]
            //      [v3-----v4]
            //
            //      [v1-----v2]
            //  [v3-------------v4]
            if (v1<=v3 && v4<=v2)
            {
                count++;
            }
            else if (v3<=v1 && v2<=v4)
            {
                count++;
            }

            
        }
        else
        {
            // Checks if a range overlaps another range
            //  [v1-------------v2]
            //      [v3-------------v4]
            //
            //      [v1-------------v2]
            //  [v3-------------v4]

            // MAX(v1, v3)
            if (v1<=v3)
                aux0=v3;
            else
                aux0=v1;
            
            // MIN(v2,v4)
            if (v2<=v4)
                aux1=v2;
            else
                aux1=v4;

            // MAX(v1, v3) <= MIN(v2,v4)
            if (aux0<=aux1)
            {
                count++;
            }
        }
    }
    
    printf("%i", count);
    fclose(f);
    return 0;
}