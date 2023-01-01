// Write a program to implement the Fractional Knapsack algorithm.

#include <stdio.h>
#include <stdlib.h>

struct item {
    int item_no;
    int profit;
    int weight;
    float ratio;
};

void greedy_knapsack(struct item *items, int n, int capacity, float *solution_vector) {
    for (int i = 0; i < n; i++) {
        solution_vector[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int i = 0;
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            solution_vector[items[i].item_no - 1] = 1;
            capacity -= items[i].weight;
        } else break;
    }

    if (i < n) {
        solution_vector[items[i].item_no - 1] = (float)capacity / items[i].weight;
    }
}

int main() {
    int n = 8;
    // printf("Enter the number of items: ");
    // scanf("%d", &n);

    int m = 17; // knapsack capacity
    // printf("Enter the capacity of the knapsack: ");
    // scanf("%d", &m);

    struct item *items = malloc(n * (sizeof(struct item)));
    items[0].item_no = 1;
    items[0].profit = 10;
    items[0].weight = 5;

    items[1].item_no = 2;
    items[1].profit = 15;
    items[1].weight = 4;

    items[2].item_no = 3;
    items[2].profit = 8;
    items[2].weight = 3;

    items[3].item_no = 4;
    items[3].profit = 7;
    items[3].weight = 7;

    items[4].item_no = 5;
    items[4].profit = 3;
    items[4].weight = 2;

    items[5].item_no = 6;
    items[5].profit = 15;
    items[5].weight = 3;

    items[6].item_no = 7;
    items[6].profit = 8;
    items[6].weight = 2;

    items[7].item_no = 8;
    items[7].profit = 27;
    items[7].weight = 6;

    float *solution_vector = malloc(n * sizeof(float));
    greedy_knapsack(items, n, m, solution_vector);

    for (int i = 0; i < n; i++) {
        printf("item %d: %f\n", items[i].item_no, solution_vector[i]);
    }

    printf("\n");

    // sort items by item number
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].item_no > items[j].item_no) {
                struct item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float max_profit = 0;
    for (int i = 0; i < n; i++) {
        max_profit += solution_vector[i] * items[i].profit;
    }
    printf("Maximum profit: %f\n", max_profit);

    return 0;
}