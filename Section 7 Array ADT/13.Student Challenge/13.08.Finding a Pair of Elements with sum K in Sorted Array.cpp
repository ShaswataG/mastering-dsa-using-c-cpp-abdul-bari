using namespace std;
#include<iostream>

int main() {
    int a[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
// TC = O(n), (both while & for loop) since we are traversing through array, partially from left, partially from right
// using while loop
    int k = 10;
    int i = 0, j = 9;
    while(i < j) {
        if (a[i]+a[j] == k) {
            cout << a[i] << "+" << a[j] << "=" << k << endl;
            i++;
            j--;
        } else if (a[i]+a[j] < k) {
            i++;
        } else {
            j--;
        }
    }
// using for loop
    for (int i = 0, j = 9; i < j;) {
        if (a[i]+a[j] == k) {
            cout << a[i] << "+" << a[j] << "=" << k << endl;
            i++;
            j--;
        } else if (a[i]+a[j] < k) {
            i++;
        } else {
            j--;
        }        
    }
    return 0;
}