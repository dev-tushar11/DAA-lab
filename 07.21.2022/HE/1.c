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

    int key = -1;
    for (int i = 1; i < n - 1; i++)
    {
        if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) key = i;
    }
    
    printf("key: %d", key);

    return 0;
}