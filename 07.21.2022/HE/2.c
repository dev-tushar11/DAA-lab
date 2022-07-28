#include<stdio.h>
#include<stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j] && i < j)
            {
                count++;
            }
        }
    }

    printf("inversions: %d", count);

    return 0;
}