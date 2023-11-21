using namespace std;
#include<iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Insert(int a[], int n) {
    int temp = a[n];
    int i = n;
    while (i > 1 && temp > a[i/2]) {
        a[i] = a[i/2];
        i /= 2;
    }
    a[i] = temp;
}

int Delete(int a[], int n) {
    int x = a[1];
    a[1] = a[n];
    a[n] = x;
    int i = 1, j = 2*i;
    while (j <= n-1) {
        if (j < n-1 && a[j+1] > a[j]) j++;
        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            i = j;
            j = 2*i;
        } else
            break;
    }
    return x;
}

int main() {
    int a[] = {0, 12, 2, 45, 34, 3, 10, 11};
    for (int i = 2; i <= 7; i++) {
        Insert(a, i);
    }
    
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 7; i > 1; i--) {
        Delete(a, i);
    }

    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}