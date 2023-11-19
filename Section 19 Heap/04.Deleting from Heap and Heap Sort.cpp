using namespace std;
#include<iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Delete(int a[], int n) {
// doubt in my code, also write abdul bari's code
    a[1] = a[n];
    int i = 1;
    a[i] = a[n];
    while (i < n && 2*i < n) {
        if (a[2*i] > a[2*i+1] && a[2*i] > a[i]) {
            swap(a[2*i], a[i]);
            i = 2*i;
        } else if (a[2*i] < a[2*i+1] && a[2*i+1] > a[i]) {
            swap(a[2*i+1], a[i]);
            i = 2*i+1;
        } else break;
    }
}

int main() {
    return 0;
}