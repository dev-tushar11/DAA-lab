// WAP that takes three variable (a,b,c) as separate parameters and rotates the values stored so that value a goes to b, b to c and c to a by using SWAP(x,y) func that swaps/exchanges the numbers x & y.

#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    swap(&a, &b);
    swap(&a, &c);

    printf("%d %d %d", a, b, c);

    return 0;
}