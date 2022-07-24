// WAP to store nums into an arr of n ints, where arr must contain duplicates. find num of dups

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }

    int tmp[largest + 1];

    for (int i = 0; i < largest + 1; i++)
    {
        tmp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        tmp[arr[i]]++;
    }

    int count = 0;

    for (int i = 0; i < largest + 1; i++)
    {
        if (tmp[i] > 1)
            count += tmp[i];
    }

    printf("%d", count);

    return 0;
}