#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[7];
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }

    for (auto e : a) {
        cout << e << " ";
    }
    cout << endl;

    int b[] = {4, 2, 2, 8, 9, 6};
    b[0] = 77;
    for (int e : b) cout << e << " ";
    cout << endl;

    int c[6] = {5};     // inserts 5 at the first index, and rest of the elements are set as 0 
    for (auto e : c) cout << e << " ";
    cout << endl;
    return 0;
}