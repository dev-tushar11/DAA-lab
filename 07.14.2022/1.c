// WAP to store the nums into an array of n ints and then find out the smallest and largest num stored in it where n is the user input

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

    int smallest, largest;
    smallest = largest = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    printf("%d %d", smallest, largest);

    return 0;
}