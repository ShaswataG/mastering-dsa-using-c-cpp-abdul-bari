using namespace std;
#include<iostream>

/*
for iterative version of two way merge sort, TC = O(nlog2(n))
*/

void merge(int a[], int l, int mid, int h) {
    int i = l, j = mid+1, k = l;
    int b[h+1];     // auxillary array
    while (i <= mid && j <= h) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= h) {
        b[k++] = a[j++];
    }
    for (i = l; i <= h; i++) a[i] = b[i];
}

void IMergeSort(int a[], int n) {
    int i, p, l, h, mid;
    for (p = 2; p <= n; p *= 2) {
        for (int i = 0; i+p-1 < n; i += p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a, l, mid, h);
        }
    }
    if (p/2 < n) {
        merge(a, 0, p/2+1, n-1);
    }
}


//Abdul bari's version, doubt?

void IMergeSort2(int a[], int n) {
    int i, p, l, h, mid;
    for (p = 2; p <= n; p *= 2) {
        for (int i = 0; i+p-1 < n; i += p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a, l, mid, h);
        }
        if (n-i > p/2) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a, l, mid, n-1);
        }
    }
    if (p/2 < n) {
        merge(a, 0, p/2-1, n-1);
    }
}



void RMergeSort(int a[], int l, int h) {
/*
TC = O(nlog2(n))    (no best or worst case, this is the average TC)
SC = O(n+log2(n))
In comparison based sorting, merge sort is the only algo that requires extra space
*/
    int mid;
    if (l < h) {
        mid = (l+h)/2;
        RMergeSort(a, l, mid);
        RMergeSort(a, mid+1, h);
        merge(a, l, mid, h); 
    }
}


void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {5, 2, 3, 1, 9, 7, 0}, n = 6;
    display(a, n);
    IMergeSort(a, n);
    // RMergeSort(a, 0, 6);
    display(a, n);
    return 0;
}