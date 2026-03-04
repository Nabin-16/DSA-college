#include<stdio.h>
#define max 100
long table[max];
void initialize_memo() {
    for (int i = 0; i < max; i++)
        table[i] = -1;
}
long int Fibom(int n) {
    if (n == 1 || n == 2)
        return 1;
    if (table[n] != -1)
        return table[n];
    table[n] = Fibom(n - 1) + Fibom(n - 2);
    return table[n];
}
int main() {
    int n;
    printf( "Enter a number: ");
    scanf("%d", &n);
    if (n < 0 || n >= max)
       printf("Please enter a number between 0 and %d.\n", max - 1);
    initialize_memo();
    printf("%ld\n", Fibom(n));
    return 0;
}