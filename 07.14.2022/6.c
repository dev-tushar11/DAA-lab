// even followed by odd ele

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

    for (int i = 0, j = n - 1; i < j; i++)
    {
        if (arr[i] % 2 != 0)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j--] = tmp;

            i--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}