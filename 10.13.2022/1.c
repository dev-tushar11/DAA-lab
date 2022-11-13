#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int min = -1000000000;
    int max = 1000000000;

    printf("%d, %d\n", max, min);
    int key;
    int guesses = 0;
    int guess;
    do
    {
        guess = min + (max - min) / 2;
        guesses++;
        printf("guess: %d\n\n", guess);
        printf("1. Try a bigger number\n");
        printf("2. Try a smaller number\n");
        printf("3. You got it\n");

        printf("\nresponse: ");
        scanf("%d", &key);
        printf("\n");

        if (key == 1)
        {
            min = guess;
        }
        else if (key == 2)
        {
            max = guess;
        }
        else if (key == 3)
        {
            printf("You got it in %d guesses", guesses);
            return 0;
        }
        else
        {
            printf("wrong input");
            return 1;
        }
    } while (1);

    return 0;
}