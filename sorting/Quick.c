#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define Max 500000
int partition(int a[], int l, int r)
{
    int x=l, y=r, pivot=a[l], temp;
    while(x<y)
    {
        while (a[x]<=pivot&&x<=r)
        {
            x++;
        }
        while (a[y]>pivot&&y>=l)
        {
            y--;
        }
        if(x<y)
        {
        temp=a[x];
        a[x]=a[y];
        a[y]=temp;
        }
  
    }
    temp=a[l];
    a[l]=a[y];
    a[y]=temp;
    a[y]=pivot;
    return y;
}
void quickshort(int a[],int l, int r)
{
    int p;
    if(l<r)
    {
        p= partition(a,l,r);
        quickshort(a, l, p-1);
        quickshort(a, p+1,r);

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
    quickshort(A, 0,n-1);
    t2=time(NULL);
    display(A, n);
    d=difftime(t2,t1);
    printf("The time is %lf", d);
    return 0;
}