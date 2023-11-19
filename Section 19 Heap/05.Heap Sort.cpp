using namespace std;
#include<iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Insert(int H[], int n) {
    int i = n;
    int temp = H[i];
    while (i > 1 && temp > H[i/2]) {
        H[i] = H[i/2];
        i /= 2;
    }
    H[i] = temp;
}

int Delete(int a[], int n) {
    int i, j, x, val;
    val = a[1];
    x = a[n];
    a[1] = a[n];
    a[n] = val;
    i = 1, j = 2*i;

    while (j < n-1) {
        if (a[j+1] > a[j]) {
            j++;
        }
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            i = j;
            j = 2*j;
        } else {
            break;
        }
    }
    return val;
}

int main() {
    int H[] = {0, 2, 5, 8, 9, 4, 10, 7};
    for (int i = 2; i <= 7; i++) {
        Insert(H, i);
    }
    for (int i = 1; i <= 7; i++) {
        cout << H[i] << " ";
    }
    cout << endl;
    // cout << "Deleted element is : " << Delete(H, 7) << endl;
    for (int i = 7; i > 1; i--) {
        Delete(H, i);
    }
    for (int i = 1; i <= 7; i++) {
        cout << H[i] << " ";
    }
    cout << endl;
    return 0;
}