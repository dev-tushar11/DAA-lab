// Write a menu driven program as given below, to sort an array of n integers in ascending
// order by insertion sort algorithm and determine the time required (in terms of step/frequency
// count) to sort the elements. Repeat the experiment for different values of n and different
// nature of data (i.e.apply insertion sort algorithm on the data of array that are already sorted,
// reversly sorted and random data). Finally plot a graph of the time taken versus n for each
// type of data. The elements can be read from a file or can be generated using the random
// number generator.

// INSERTION SORT
// 0. Quit
// 1. n Random numbers=>Array
// 2. Display the Array
// 3. Sort the Array in Ascending Order by using Insertion Sort
// Algorithm
// 4. Sort the Array in Descending Order by using any sorting
// algorithm
// 5. Time Complexity to sort ascending of random data
// 6. Time Complexity to sort ascending of data already sorted in
// ascending order
// 7. Time Complexity to sort ascending of data already sorted in
// descending order
// 8. Time Complexity to sort ascending of data for all Cases (Data
// Ascending, Data in Descending & Random Data) in Tabular form
// for values n=5000 to 50000, step=5000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// insertion sort (ascending order)
void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// display array
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// generate random array
void fillRandom(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

// insertion sort (descending order)
void insertionSortDesc(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// // generate array in ascending order
// void fillAscending(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = i;
//     }
// }

// // generate array in descending order
// void fillDescending(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = n - i;
//     }
// }

int main()
{
    srand(time(0));
    int n;
    printf("n: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    clock_t start, end;
    int choice;

    do
    {
        printf("\n0. Quit\n");
        printf("1. n Random numbers=>Array\n");
        printf("2. Display the Array\n");
        printf("3. Sort the Array in Ascending Order by using Insertion Sort\n");
        printf("4. Sort the Array in Descending Order by using any sorting\n");
        printf("5. Time Complexity to sort ascending of random data\n");
        printf("6. Time Complexity to sort ascending of data already sorted in ascending order\n");
        printf("7. Time Complexity to sort ascending of data already sorted in descending order\n");
        printf("8. Time Complexity to sort ascending of data for all Cases (Data\n");
        printf("Ascending, Data in Descending & Random Data) in Tabular form\n");
        printf("for values n=5000 to 50000, step=5000\n");

        printf("\nchoice: ");
        scanf("%d", &choice);

        double time_taken[3];
        switch (choice)
        {
        case 0:
            break;
        case 1:
            fillRandom(arr, n);
            break;
        case 2:
            display(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            insertionSortDesc(arr, n);
            break;
        case 5:
            // fillRandom(arr, n);
            start = clock();
            insertionSort(arr, n);
            end = clock();
            time_taken[0] = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        case 6:
            // fillAscending(arr, n);
            start = clock();
            insertionSort(arr, n);
            end = clock();
            time_taken[1] = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        case 7:
            // fillDescending(arr, n);
            insertionSortDesc(arr, n);
            start = clock();
            insertionSort(arr, n);
            end = clock();
            time_taken[2] = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        case 8:
            printf("n\t Ascending\t Descending\t Random\n");
            printf("----------------------------------------------------\n");
            printf("%d\t %f\t %f\t %f\n", n, time_taken[1], time_taken[2], time_taken[0]);
            return 0;
        }

    } while (choice != 0);

    return 0;
}