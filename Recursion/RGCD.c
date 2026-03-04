#include<stdio.h>
int iGCD(a,b)
{
    int r;
    if(b==0)
        return a;
    else
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
    return a;
}
int rGCD(int a, int b)
{
    if (b == 0)
        return a;
    return rGCD(b, a % b);
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, iGCD(a, b));
    printf("GCD of %d and %d using recursion is %d\n", a, b, rGCD(a, b));
    return 0;
}