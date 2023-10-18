using namespace std;
#include<iostream>

int main() {
    int a[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int H[21] = {0};
    for (int i = 0; i < 10; i++) {
        H[a[i]]++;
    }
    for (int i = 0; i < 21; i++) {
        if (H[i] > 1) {
            cout << i << " occurs " << H[i] << " times." << endl;
        }
    }
    return 0;
}