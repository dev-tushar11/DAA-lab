// Write a program to sort a list of n elements using the Merge Sort method and determine the time required to sort the elements. Repeat the experiment for different values of n and different nature of data (random data, sorted data, reversely sorted data) in the list. n is the user input and n integers can be generated randomly. Finally plot a graph of the time taken versus n.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int*, int, int, int);

void mergeSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int m = l + (h - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

void merge(int *arr, int l, int m, int h)
{
    int i = l, j = m + 1, k = 0;
    int *temp = malloc(sizeof(int) * (h - l + 1));

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= h)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= h; i++, k++)
        arr[i] = temp[k];
}

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Time taken: %f", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}