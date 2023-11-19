using namespace std;
#include<iostream>

void Insert(int a[], int n) {
    int i = n;
    int temp = a[n];
    while (i > 1 && temp > a[i/2]) {
        a[i] = a[i/2];
        i /= 2;
    }
    a[i] = temp;
}

int main() {
    return 0;
}