// In a social gathering, there are b boys and g girls (b > g) of different ages. You have two
// unsorted arrays giving their ages (one for the boys, the other for the girls). Write a program
// by devising an efficient O(b log g) algorithm to find out the ages that are common between
// both the boys and girls.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quicksort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int main()
{
    srand(time(0));
    int b, g;
    printf("enter b: ");
    scanf("%d", &b);

    printf("enter g: ");
    scanf("%d", &g);

    if (b < g)
    {
        printf("wrong input");
        return 1;
    }

    int *boys = malloc(b * sizeof(int));
    int *girls = malloc(g * sizeof(int));

    for (int i = 0; i < b; i++)
    {
        boys[i] = rand() % 25;
    }

    for (int i = 0; i < g; i++)
    {
        girls[i] = rand() % 25;
    }

    quicksort(girls, 0, g - 1);

    int n = girls[g - 1] + 1;
    int *common = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        common[i] = 0;
    }

    for (int i = 0; i < b; i++)
    {
        int j = 0, k = g - 1;
        while (j <= k)
        {
            int mid = (j + k) / 2;
            if (girls[mid] == boys[i])
            {
                common[girls[mid]]++;
                break;
            }
            else if (girls[mid] < boys[i])
            {
                j = mid + 1;
            }
            else
            {
                k = mid - 1;
            }
        }
    }

    printf("\ncommon ages: ");

    for (int i = 0; i < n; i++)
    {
        if (common[i] > 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}