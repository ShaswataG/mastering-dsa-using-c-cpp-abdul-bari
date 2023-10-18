using namespace std;
#include<iostream>

int main() {
    int a[] = {3, 6, 8, 8, 10, 11, 11, 11, 12, 13, 13, 15, 20, 20};
    // int a[] = {0, 0, 8, 8, 10, 11, 11, 11, 12, 13, 13, 15, 20, 20};     // doesn't work since first element i.e. 0 is repeated
    int ld = 0;
    for (int i = 0; i < 14; i++) {
        if (a[i] == a[i+1] && a[i] != ld) {
            cout << a[i] << " ";
            ld = a[i];
        }
    }
    cout << endl;
// Counting duplicates
    int j = 0;
    for (int i = 0; i < 14; i++) {
        if (a[i] == a[i+1]) {
            j = i+1;
            while (a[j] == a[i]) j++;
            cout << a[i] << " occurs " << j-i << " times." << endl;
            i = j-1;
        }
    }

    return 0;
}