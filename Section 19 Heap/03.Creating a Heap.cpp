using namespace std;
#include<iostream>


/*
Max heap
*/
void Insert(int a[], int n) {
/*
TC = O(log2(n))
*/
    int i = n;
    int temp = a[n];
    while (i > 1 && temp > a[i/2]) {
        a[i] = a[i/2];
        i /= 2;
    }
    a[i] = temp;
}

void createHeap() {
/*
TC = O(nlog2(n))
*/
    int a[] = {0, 10, 20, 30, 25, 5, 40, 35};
    for (int i = 2; i <= 7; i++) {
        Insert(a, i);
    }
}

int main() {
    return 0;
}