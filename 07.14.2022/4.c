// WAP to store nums into an arr of n ints, where arr must contain duplicates. find num of times ele appeared

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

    int tmp_n = largest + 1;
    int tmp[tmp_n];

    for (int i = 0; i < tmp_n; i++)
    {
        tmp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        tmp[arr[i]]++;
    }

    int count = 0;

    for (int i = 0; i < tmp_n; i++)
    {
        if (tmp[i] > 0)
        {
            printf("%d: %d\n", i, tmp[i]);
        }
    }

    // printf("%d", count);

    return 0;
}