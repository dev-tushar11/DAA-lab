// Given a set S of n integers and another integer x, determine whether or not there exist two elements in S whose sum is exactly x. Describe a Θ(nlogn) time algorithm for the above problem.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quicksort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int main()
{
    srand(time(0));

    int n;
    printf("enter n: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("S: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int x;
    printf("enter x: ");
    scanf("%d", &x);

    quicksort(arr, 0, n - 1);

    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
        {
            printf("found %d + %d = %d", arr[i], arr[j], x);
            return 0;
        }
        else if (arr[i] + arr[j] < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    printf("not found\n");

    return 0;
}