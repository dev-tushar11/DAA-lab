// WAP using a function for computing square root for a positive integer. Besides assignment and comparison, your algorithm may only use the four basic arithmetic operations: addition, subtraction, multiplication, and division.

#include <stdio.h>

int squareRoot(int n)
{
    int i = 1;
    while(i * i <= n)
    {
        i++;
    }
    return i - 1;
}

int main()
{
    int num;
    printf("num: ");
    scanf("%d", &num);
    printf("square root: %d\n", squareRoot(num));

    return 0;
}