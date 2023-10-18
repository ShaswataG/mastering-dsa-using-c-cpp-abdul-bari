using namespace std;
#include<iostream>

int main() {
    int a[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int n = 10;
    int k = 10;
/*
i = 0->n-1, i = 1->n-2, ......i = n-2->1;
(n-1)+(n-2)+(n-3)+......+3+2+1 = ((n-1)n)/2 = n^2/2 + n/2
TC = O(n^2)
*/
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] + a[j] == k) {
                cout << a[i] << "+" << a[j] << "=" << k << endl;
            }
        }
    }
    cout << endl;
// Using Hashing, TC = O(n)
    int H[15] = {0};
    for (int i = 0; i < n; i++) {
        // H[a[i]]++;
        if (H[k-a[i]] != 0)
            cout << a[i] << "+" << k-a[i] << "=" << k << endl;
        H[a[i]]++;
    }
    return 0;
}