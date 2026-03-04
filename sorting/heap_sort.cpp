#include<iostream>
#include<cstdlib>
#include<chrono>
#define Max 500000
using namespace std;
void max_heapify(int a[], int i, int n)
{
    int l=2*i, r=2*i+1, largest=i, temp;
    if (l <= n && a[l] > a[largest]) {
        largest = l;
    }
    if (r <= n && a[r] > a[largest]) {
        largest = r;
    }
    if (i!= largest) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}
void BuildHeap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--) {
        max_heapify(a, i, n);
    }
}
void heap_sort(int a[], int n)
{
    int temp;
    BuildHeap(a, n);
    for (int i = n; i >= 2; i--) {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void display(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int A[Max], i, n;
    time_t t1,t2;
    double d;
    cout<<"Enter the number of elements to sort:";
    cin >> n;
    srand(time(NULL));
    for (i = 1; i <=n; i++) {
        A[i] = rand() % 10000;}
    display(A, n);
    t1=time(NULL);
    heap_sort(A, n);
    t2=time(NULL);
    display(A, n);
    d=difftime(t2,t1);
    cout << "Time taken for heap sort: " << d << " seconds" << endl;
    return 0;
}