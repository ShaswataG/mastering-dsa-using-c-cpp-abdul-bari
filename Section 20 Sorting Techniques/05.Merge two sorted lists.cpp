using namespace std;
#include<iostream>

void merge1(int a[], int b[], int m, int n) {
    int i = 0, j = 0, k = 0;
    int c[m+n];
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < m) {
        c[k++] = a[i++];
    }
    while (j < n) {
        c[k++] = b[j++];
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge2(int a[], int l, int mid, int h) {
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

/*
suppose, we need to merge 4 sorted lists (4-way merging)
we can do it in many ways-
i) instead of comparing an element of one array to element of another, finding the minimum element of all the given arrays, then inserting it in the new array
ii) or we can merge two lists at a time, and then merge the resulting two lists into a single list or any other possible combinations

similarly, we can merge m sorted lists (m-way merging) in many possible ways
*/

int main() {
    return 0;
}