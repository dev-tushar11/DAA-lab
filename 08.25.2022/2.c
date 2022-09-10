// WAP to use divide and conquer method to determine the time required to find maximum element and minimum element in an array of n integers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void findMinMax(int *arr, int low, int high, int *min, int *max)
{
    if(low > high) return;

    if (low == high)
    {
        if (arr[low] < *min)
            *min = arr[low];
        if (arr[low] > *max)
            *max = arr[low];
    }

    if (high - low == 1)
    {
        if (arr[low] < arr[high])
        {
            if (arr[low] < *min)
                *min = low;
            if (arr[high] > *max)
                *max = high;
        }
        else
        {
            if(arr[high] < *min) *min = arr[high];
            if(arr[low] > *max) *max = arr[low];
        }
    }

    int mid = (low + high) / 2;

    findMinMax(arr, low, mid - 1, min, max);
    findMinMax(arr, mid + 1, high, min, max);
}

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    int min = INT_MAX, max = INT_MIN;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);

    return 0;
}