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

    int productOfAll = 1;
    for (int i = 0; i < n; i++)
    {
        productOfAll *= arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = productOfAll / arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}