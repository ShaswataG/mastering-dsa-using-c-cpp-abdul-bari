using namespace std;
#include<iostream>

int main() {
    int a[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int n = 10;
    int count = 0;
// TC = O(n^2)
    for (int i = 0; i < n-1; i++) {
        count = 1;
        if (a[i] != -1) {
            for (int j = i+1; j < n; j++) {
                if (a[i] == a[j]) {
                    count++;
                    a[j] = -1;
                }
            }
            if (count > 1)
                cout << a[i] << " occurs " << count << " times." << endl;
        }
    }
    cout << endl;

// Using hashing
// TC = O(n)
    int b[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int max = 8;
    int H[max+1] = {0};
    for (int i = 0; i < max+1; i++) {
        H[b[i]]++;
    }
    for (int i = 0; i < max+1; i++) {
        if (H[i] > 1) {
            cout << i << " occurs " << H[i] << " times." << endl;
        }
    }
    return 0;
}