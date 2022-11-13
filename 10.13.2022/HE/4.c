// Refer the following new sort algorithm for sorting an array A of n numbers. The
// algorithm is described below:

// (i) If there is only one number, return.
// (ii) If there are two numbers, perform a single comparison to determine the order.
// (iii) If there are more than two numbers, then first sort the top two-thirds of the elements recursively. Follow this by sorting the bottom two-thirds of the elements recursively and then sorting the top two-thirds of the elements again.
// a) Write a program that uses a recursive algorithm to implement the above strategy.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void new_sort(int *arr, int low, int high)
{
    printf("[sub-array:%d to %d]",low,high);
    if (low > high)
        return;

    // If there is only one number, return.
    if (low == high)
    {
        return;
    }
    // If there are two numbers, perform a single comparison to determine the order.
    else if (low + 1 == high)
    {
        if (arr[low] > arr[high])
        {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    // If there are more than two numbers, then first sort the top two-thirds of the elements recursively. Follow this by sorting the bottom two-thirds of the elements recursively and then sorting the top two-thirds of the elements again.
    else
    {
        new_sort(arr, low, low + (2 * (high - low)) / 3);

        new_sort(arr, low + (high - low) / 3, high);

        new_sort(arr, low, low + (2 * (high - low)) / 3);
    }
}

int main()
{
    srand(time(0));
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int *A = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
    }

    printf("before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    new_sort(A, 0, n - 1);

    printf("after sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}