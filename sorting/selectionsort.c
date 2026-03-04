#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define Max 200000
void selection_sort(int A[], int n)
{
    int i,j,pos,least,temp;
    for(i=0;i<n;i++)
    {
        least=A[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<least)
            {
                least=A[i];
                pos=j;
            }
        }
        if(i!=pos)
            A[i]=A[pos];
    }
   

}
void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
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
    selection_sort(A, n);
    t2=time(NULL);
    display(A, n);
    d=difftime(t2,t1);
    printf("The time is %lf", d);
    return 0;
}