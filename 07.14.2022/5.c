// WAP to store nums into an arr of n ints, where arr must contain duplicates. find num of dups and their repetations and most number of repetation

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

    // int count = 0;

    int most_repetation = -1;
    int most_repeat_num;
    for (int i = 0; i < tmp_n; i++)
    {
        if (tmp[i] > 0)
        {
            printf("%d: %d\n", i, tmp[i]);
        }
        if (tmp[i] > most_repetation)
        {
            most_repetation = tmp[i];
            most_repeat_num = i;
        }
    }

    printf("\n");
    printf("%d: %d\n", most_repeat_num, most_repetation);

    return 0;
}