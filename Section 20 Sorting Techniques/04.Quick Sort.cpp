using namespace std;
#include<iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
when pivot-> first element
    TC = O(nlog(n))     (best case, when partition is done at the middle)
    TC = O(n^2)     (worst case, when partition is done at any end, list is in either ascending or descending order)

when pivot-> middle element
    TC = O(nlog(n))     (best case, when partition is done at the middle, list is in either ascending or descending order)
    TC = O(n^2)     (worst case, when partion is done at any end)

when pivot-> random element (randomized quick sort)
    TC = O(nlog(n))     (best case, when partition is done at the middle)
    TC = O(n^2)     (worst case, when partition is done at any end)

comparison of selection and quick sort-
    selection sort- selecting an position and finding an element for it
    quick sort- selecting an element and finding a position for it 
so, quick sort is also called as selection exchange sort, partition exchange sort
*/

int partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;
    while (i < j) {
        do {i++;} while (a[i] <= pivot);
        do {j--;} while (a[j] > pivot);
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}

void QuickSort(int a[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j+1, h);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {4, 2, 1 ,5 ,2, 7, 9, 11, 3, 1, INT32_MAX}, n = 10;
    display(a, n);
    QuickSort(a, 0, n);
    display(a, n);
    return 0;
}