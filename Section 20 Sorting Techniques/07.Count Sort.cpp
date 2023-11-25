using namespace std;
#include<iostream>

int findMax(int a[], int n) {
    int max = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

void CountSort(int a[], int n) {
/*
TC = O(n)
SC = O(n)
*/
    int max = findMax(a, n);
    int* c = new int[max+1];
    for (int i = 0; i <= max; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]]++; 
    }
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    int i = 0, j = 0;
    while (i <= max) {
        if (c[i] > 0) {
            a[j++] = i;
            c[i]--;
        } else {
            i++;
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {5, 11, 5, 1, 6, 3, 9, 2}, n = 8;
    display(a, n);
    CountSort(a, n);
    display(a, n);
    return 0;
}