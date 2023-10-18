using namespace std;
#include<iostream>

/*
TC = Order of n
for minimizing time, hashing is useful, but it has a limitation i.e. it takes a lot of space
so hashing is used mostly when there is abundant space
size of hash table = maximum element of given array + 1
*/

int main() {
    int a[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int l = 1;
    int h = 12;
    int n = 10;
    int H[h+1] = {0};    // h is a hash table or bitset
    for (int i = 0; i < n; i++) {
        H[a[i]]++;
    }
    for (int i = l; i <= h; i++) {
        if (H[i] == 0)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}