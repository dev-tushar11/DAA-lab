// Write a program to implement the Activity-Selection problem stated as follows:
// You are given n activities with their start and finish times. Select the maximum
// number of activities that can be performed by a single person, assuming that a
// person can only work on a single activity at a time.

#include <stdio.h>
#include <stdlib.h>

struct activity {
    int activity_no;
    int start;
    int finish;
};

void activity_selection(struct activity *activities, int n, int *solution_vector) {
    for (int i = 0; i < n; i++) {
        solution_vector[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (activities[i].finish > activities[j].finish) {
                struct activity temp = activities[i];
                activities[i] = activities[j];
                activities[j] = temp;
            }
        }
    }

    solution_vector[0] = 1;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            solution_vector[j] = 1;
            i = j;
        }
    }
}

int main() {
    int n = 10;
    // printf("Enter the number of activities: ");
    // scanf("%d", &n);

    struct activity *activities = malloc(n * (sizeof(struct activity)));
    activities[0].activity_no = 1;
    activities[0].start = 1;
    activities[0].finish = 3;

    activities[1].activity_no = 2;
    activities[1].start = 2;
    activities[1].finish = 5;

    activities[2].activity_no = 3;
    activities[2].start = 4;
    activities[2].finish = 5;

    activities[3].activity_no = 4;
    activities[3].start = 3;
    activities[3].finish = 7;

    activities[4].activity_no = 5;
    activities[4].start = 5;
    activities[4].finish = 7;

    activities[5].activity_no = 6;
    activities[5].start = 7;
    activities[5].finish = 9;

    activities[6].activity_no = 7;
    activities[6].start = 8;
    activities[6].finish = 14;

    activities[7].activity_no = 8;
    activities[7].start = 9;
    activities[7].finish = 18;

    activities[8].activity_no = 9;
    activities[8].start = 10;
    activities[8].finish = 11;

    activities[9].activity_no = 10;
    activities[9].start = 12;
    activities[9].finish = 12; 

    int *solution_vector = malloc(n * (sizeof(int)));
    activity_selection(activities, n, solution_vector);

    printf("The activities selected are: ");
    for (int i = 0; i < n; i++) {
        if (solution_vector[i] == 1) {
            printf("%d ", activities[i].activity_no);
        }
    }
    
    return 0;

}