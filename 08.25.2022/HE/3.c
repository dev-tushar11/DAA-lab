// WAP that uses a divide and conquer algorithm/user defined function for the exponentiation problem of computing a^n where a > 0 and n is a positive integer.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func(int a, int n)
{
    if(n == 0) return 1;
    if(n == 1) return a;
    
    if(n % 2 == 0) return func(a, n/2) * func(a, n/2);
    else return func(a, n/2) * func(a, n/2) * a; 
}

int main()
{
    int a;
    printf("a: ");
    scanf("%d", &a);

    int n;
    printf("n: ");
    scanf("%d", &n);

    printf("%d\n", func(a, n));
}