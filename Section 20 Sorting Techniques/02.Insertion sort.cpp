using namespace std;
#include<iostream>
/*
void insertSorted(int a[], int n, int key) {
    int i;
    for (int i = n; key < a[i]; i--) {
        a[i+1] = a[i];
    }
    a[i] = key; 
}
*/

void insertionSort(int a[], int n) {
/*
TC = O(n^2),    worst case, list is in descending order
TC = omega(n),  best case, list is already sorted
insertion sort is adaptive by nature
insertion sort is stable
k passes dont give useful results
max swaps = O(n^2)
min swaps = O(1)
max comparison = O(n^2)
min comparison = O(n)
*/ 
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        for (j = i-1; j >= 0 && temp < a[j]; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {4, 2, 4, 9, 3, 0, 11};
    display(a, 7);
    insertionSort(a, 7);
    display(a, 7);
    return 0;
}