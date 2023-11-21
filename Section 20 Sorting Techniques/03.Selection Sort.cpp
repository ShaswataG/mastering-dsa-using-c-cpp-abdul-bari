using namespace std;
#include<iostream>

void swap(int& a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
 
void selectionSort(int a[], int n) {
/*
TC = O(n^2)     always
no. of swaps = O(n)     minimum compared to bubble and insertion
intermediate results give useful results, k passes gives k smallest elements
selection sort is not adaptive
selection sort is not stable
*/
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3}, n = 10;
    display(a, n);
    selectionSort(a, n);
    display(a, n);
    return 0;
}