// WAP to search an element key in an array of n inteer using binary search algorithm that uses divide and conquer technique.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int *arr, int low, int high, int key)
{
    if (low > high) return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] > key)
        return binary_search(arr, low, mid - 1, key);
    else
        return binary_search(arr, mid + 1, high, key);
}

int main()
{
    srand(time(0));
    clock_t start, end;
    double cpu_time_used[3];

    int n;
    printf("n: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    int key = rand() % 50;

    // average case
    start = clock();
    int index = binary_search(arr, 0, n - 1, key);
    end = clock();
    cpu_time_used[0] = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu time used in average case: %f\n", cpu_time_used[0]);

    if (index == -1) printf("Not found\n");
    else printf("Found at %d\n", index);

    // best case
    start = clock();
    index = binary_search(arr, 0, n - 1, arr[n / 2]);
    end = clock();
    cpu_time_used[1] = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu time used: %f\n", cpu_time_used[1]);

    if (index == -1) printf("Not found\n");
    else printf("Found at %d\n", index);

    // worst case
    start = clock();
    index = binary_search(arr, 0, n - 1, -1);
    end = clock();
    cpu_time_used[2] = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu time used: %f\n", cpu_time_used[2]);

    if (index == -1) printf("Not found\n");
    else printf("Found at %d\n", index);

    return 0;
}