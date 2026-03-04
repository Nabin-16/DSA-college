# include<stdio.h>
int Fibo(int n) {
    if (n == 1|| n == 2)
        return 1;
    else
        return Fibo(n - 1) + Fibo(n - 2);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 1)
        printf("Please enter a positive integer.\n");
    printf("Fibonacci of %d is %d\n", n, Fibo(n));
    return 0;
}