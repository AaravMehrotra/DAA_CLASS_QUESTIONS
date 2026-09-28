#include <stdio.h>
long long power(int x, int n)
{
    if (n == 0)
        return 1;
    long long half = power(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}
int main()
{
    int x, n;
    printf("Enter the number: ");
    scanf("%d", &x);
    printf("Enter the power: ");
    scanf("%d", &n);
    printf("%d^%d = %lld", x, n, power(x, n));
    return 0;
}