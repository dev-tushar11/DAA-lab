// Write a program to test whether a number n, entered through keyboard is prime or not

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int n, int *count)
{
    int i;
    for (i = 2; i < n; i++)
    {
        (*count)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isPrime2(int n, int *count2)
{
    int i;
    for (i = 2; i <= n / 2; i++)
    {
        (*count2)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isPrime3(int n, int *count3)
{
    int i;
    for (i = 2; i * i <= n; i++)
    {
        (*count3)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // srand(time(0));
    int arr[10];

    // printf("intput:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
        // arr[i] = rand() % 100000;
    }

    printf("sl no.\t input\t algo1\t algo2\t algo3\t algo1 time\t algo2 time\t algo3 time\t fastest\n");
    for (int i = 0; i < 10; i++)
    {
        int count = 0;
        int count2 = 0;
        int count3 = 0;

        printf("%d\t %d\t", i + 1, arr[i]);
        if (isPrime(arr[i], &count))
        {
            printf(" p\t");
        }
        else
        {
            printf(" np\t");
        }
        if (isPrime2(arr[i], &count2))
        {
            printf(" p\t");
        }
        else
        {
            printf(" np\t");
        }
        if (isPrime3(arr[i], &count3))
        {
            printf(" p\t");
        }
        else
        {
            printf(" np\t");
        }
        printf("\t%d\t\t %d\t\t %d\t\t", count, count2, count3);
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
}