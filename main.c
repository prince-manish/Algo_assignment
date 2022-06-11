#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int n;
void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void print(int a[], int n) {
    int i;
    printf("\n");
    for (i = 0; i < n; ++i)
        printf("%d,", a[i]);
}

void quicksort3PivotBasic(int A[], int lo, int hi) {
    int length = hi - lo + 1;
    int midpoint;
    int x, y, z;
    int a, b, c, d;
    int t;
    if (hi - lo < 1 || lo < 0 || hi < 0)
        return;
    midpoint = (lo + hi) / 2;
    if (A[midpoint] < A[lo]) {
        t = A[midpoint];
        A[midpoint] = A[lo];
        A[lo] = t;
    }
    if (A[hi] < A[midpoint]) {
        t = A[hi];
        A[hi] = A[midpoint];
        A[midpoint] = t;
        if (t < A[lo]) {
            A[midpoint] = A[lo];
            A[lo] = t;
        }
    }
    x = A[lo];
    y = A[midpoint];
    z = A[hi];
    swap(A, lo + 1, midpoint);
    a = lo + 2;
    b = lo + 2;
    c = hi - 1;
    d = hi - 1;
    while (b <= c) {
        while (A[b] < y && b <= c) {
            if (A[b] < x) {
                swap(A, a, b);
                a++;
            }
            b++;
        }
        while (A[c] > y && b <= c) {
            if (A[c] > z) {
                swap(A, c, d);
                d--;
            }
            c--;
        }
        if (b <= c) {
            if (A[b] > z) {
                if (A[c] < x) {
                    swap(A, b, a);
                    swap(A, a, c);
                    a++;
                } else {
                    swap(A, b, c);
                }
                swap(A, c, d);
                b++;
                c--;
                d--;
            } else {
                if (A[c] < x) {
                    swap(A, b, a);
                    swap(A, a, c);
                    a++;
                } else {
                    swap(A, b, c);
                }
                b++;
                c--;
            }
        }
    }
    a--;
    b--;
    c++;
    d++;
    swap(A, lo + 1, a);
    swap(A, a, b);
    a--;
    swap(A, lo, a);
    swap(A, hi, d);
    quicksort3PivotBasic(A, lo, a - 1);
    quicksort3PivotBasic(A, a + 1, b - 1);
    quicksort3PivotBasic(A, b + 1, d - 1);
    quicksort3PivotBasic(A, d + 1, hi);
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();
    int sz;
    printf("Enter the size of array::");
    scanf("%d", &sz);
    int randArray[sz], i;
    for (i = 0; i < sz; i++)
        randArray[i] = rand() % 1000;
    print(randArray, sz);
    //printf("\*******************");
    printf("\n3 PIVOT");
    quicksort3PivotBasic(randArray, 0, sz - 1);
    print(randArray, sz);
    clock_t end = clock();
    time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nTotal time elapsed for 3 piovt is %f seconds", time_spent);
    return 0;
}