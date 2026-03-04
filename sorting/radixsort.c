#include<stdio.h>
#define max 100
int findMax(int A[], int n)
{
   int l=A[0];
   for(int i=1;i<n;i++)
   {
    if(A[i]>l)
    l=A[i];
   }
   return l;
}
void CountSort(int A[], int n, int dp)
{
   int count[10]={0};
   int output[n],j;
   for(int j=0;j<n;j++)
     count[(A[j]/dp)%10]++;
   for(j=1;j<10;j++)
     count[j]+=count[j-1];
   for(j=n-1;j>=0;j--)
   {
     int digit = (A[j]/dp)%10;
     output[count[digit]-1] = A[j];
     count[digit]--;
   }
    for(int i=0; i<n; i++){
    A[i] = output[i];
}
}
void radixSort(int A[], int n)
{
    int l =findMax(A, n);
    for(int dp=1;l/dp>0;dp=dp*10)
     CountSort(A, n, dp);
}

void display(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = 10 ;
    printf("Original array:\n");
    display(A, n);
    radixSort(A, n);
    printf("Sorted array using Radix Sort:\n");
    display(A, n);
    return 0;
}
