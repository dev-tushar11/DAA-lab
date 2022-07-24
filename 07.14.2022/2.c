// WAP to store the nums into an array of n ints and then find out the 2nd smallest and 3rd largest num stored in it where n is the user input

#include <stdio.h>

void func(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }

    printf("%d %d", arr[1], arr[n - 3]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             int tmp = arr[j];
    //             arr[j] = arr[i];
    //             arr[i] = tmp;
    //         }
    //     }
    // }

    // printf("%d %d", arr[1], arr[n - 3]);

    func(arr, n);

    return 0;
}