using namespace std;
#include<iostream>

int main() {
    int a[] = {5, 8, 3, 2, 7, 9, 8, 0, 1, -3};
    int max = a[0];
    int min = a[0];
/*
TC = O(n)
best case, array is in decreasing order, no of comparison performed = n-1
worst case, array is in increasing order, no of comparison performed = 2(n-1)
*/
    for (int i = 0; i < 10; i++) {
        if (a[i] < min) {
            min = a[i];
        } else if (a[i] > max) {
            max = a[i];
        }
    }
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    return 0;
}