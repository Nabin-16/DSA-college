#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define Max 200000
void BubbleSort(int A[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(){
    int A[Max], i, n;
    time_t t1,t2;
    double d;
    printf("Enter the number of elements to sort: ");
    srand(time(NULL));
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        A[i] = rand() % 1000;}
    display(A, n);
    t1=time(NULL);
    BubbleSort(A, n);
    t2=time(NULL);
    display(A, n);
    d=difftime(t2,t1);
    printf("The time is %lf", d);
    return 0;
    

}

