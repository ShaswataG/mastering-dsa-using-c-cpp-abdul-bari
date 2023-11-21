using namespace std;
#include<iostream>

/*
1+2+3+4+.....+(n-1)     (for n elements, there are n-1 passes)
= n(n-1)/2

so, TC = O(n^2)     (worst case)
    TC = omega(n)   (best case, when list is already sorted)
bubble sort is not adaptive by nature, we had to make it adaptive, by using flag variable
bubble sort is stable
intermediate results give useful results, k passes gives k greates elements
max swaps = O(n^2)
min swaps = O(1)
max comparison = O(n^2)
min comparison = O(n)
*/
void bubbleSort1(int a[], int n) {
    int m = n-1;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; i < m; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        m--;
    }
}

void bubbleSort2(int a[], int n) {
    int flag = 0;
    for (int i = 0; i < n-1; i++) {
        flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {3, 1, 5, 3, 9, 11, 17, 7}, n = 8;
    cout << "Before sorting, list : ";
    display(a, n);
    bubbleSort2(a, n);
    cout << "After sorting, list : ";
    display(a, n);
    return 0; 
}