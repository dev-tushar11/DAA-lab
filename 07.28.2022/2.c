/* Write a program to find out GCD (greatest common divisor) using the following three
algorithms.
1. Euclid's algorithm
2. Consecutive integer checking algorithm.
3. Middle school procedure which makes use of common prime factors. For finding list
of primes implement sieve of Eratosthenes algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Euclid(int a, int b, int *count)
{
    while (b != 0)
    {
        (*count)++;
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    // printf("%d\n", (*count));
    return a;
}

int Consecutive(int a, int b, int *count2)
{
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        (*count2)++;
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int MiddleSchool(int a, int b, int *count3)
{
    int factors1[a + 1];
    int factors2[b + 1];

    int max = -1;
    for (int i = 0; i < a + 1; i++)
    {
        (*count3)++;
        factors1[i] = 0;
    }

    if (*count3 > max)
        max = *count3;
    *count3 = 0;

    for (int i = 0; i < b + 1; i++)
    {
        (*count3)++;
        factors2[i] = 0;
    }

    if (*count3 > max)
        max = *count3;
    *count3 = 0;

    for (int i = 1; i <= a; i++)
    {
        (*count3)++;
        if (a % i == 0)
        {
            factors1[i]++;
        }
    }

    if (*count3 > max)
        max = *count3;
    *count3 = 0;

    for (int i = 1; i <= b; i++)
    {
        (*count3)++;
        if (b % i == 0)
        {
            factors2[i]++;
        }
    }

    if (*count3 > max)
        max = *count3;
    *count3 = 0;

    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        (*count3)++;
        if (factors1[i] != 0 && factors1[i] == factors2[i])
        {
            gcd = i;
        }
    }

    if (*count3 > max)
        max = *count3;
    *count3 = max;

    return gcd;
}

int main()
{
    int arr[6][2];
    for (int i = 0; i < 6; i++)
    {
        printf("a: ");
        scanf("%d", &arr[i][0]);
        printf("b: ");
        scanf("%d", &arr[i][1]);
    }

    printf("sl. no.\t input\t\t algo1\t algo2\t algo3\t algo1 time\t algo2 time\t algo3 time\t fastest\n");
    for (int i = 0; i < 6; i++)
    {
        int count = 0;
        int count2 = 0;
        int count3 = 0;

        printf("%d\t (%d,%d)\t %d\t %d\t %d\t ", i + 1, arr[i][0], arr[i][1], Euclid(arr[i][0], arr[i][1], &count), Consecutive(arr[i][0], arr[i][1], &count2), MiddleSchool(arr[i][0], arr[i][1], &count3));
        printf("%d\t\t %d\t\t %d\t\t ", count, count2, count3);
        if (count < count2)
        {
            if (count < count3)
            {
                printf("1\n");
            }
            else
            {
                printf("3\n");
            }
        }
        else
        {
            if (count2 < count3)
            {
                printf("2\n");
            }
            else
            {
                printf("3\n");
            }
        }
    }

    return 0;
}