#include <stdio.h>
void merge(int A[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    int B[20];

    while (i <= m && j <= r) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= m) {
        B[k++] = A[i++];
    }

    while (j <= r) {
        B[k++] = A[j++];
    }

    for (i = l; i <= r; i++) {
        A[i] = B[i];
    }
}

void mergesort(int A[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(A, l, m);
        mergesort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main() {
    int A[20], n, i;

    printf("Enter number of items you want to sort: ");
    scanf("%d", &n);

    printf("Enter numbers: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    mergesort(A, 0, n - 1);

    printf("Numbers after sorting are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}