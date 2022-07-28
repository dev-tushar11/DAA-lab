#include <stdio.h>
#include <stdlib.h>

int nonZero(int **arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    return count;
}

int sumOfElementsAboveLeadingDiagonal(int **arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

void displayElementsBelowTheMinorDiagonal(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}

int productOfDiagonalElements(int **arr, int n)
{
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod *= arr[i][i];
    }

    return prod;
}

int main()
{
    int n;
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("no. of non-zero: %d\n", nonZero(arr, n));
    printf("sum of elements above leading diagonal: %d\n", sumOfElementsAboveLeadingDiagonal(arr, n));
    printf("elements below minor diagonal: ");
    displayElementsBelowTheMinorDiagonal(arr, n);
    printf("product of diagonal elements: %d\n", productOfDiagonalElements(arr, n));
}