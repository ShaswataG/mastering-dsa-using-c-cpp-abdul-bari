using namespace std;
#include<iostream>

struct Array {
    int A[10];
    int size;
    int length;
};

int search(struct Array a, int key) {
/*
n = size of array
worst case, O(n)
best case, omega(1)
for average case, 
    Total time taken for all cases/Total number of cases
    = (1+2+3+4+.....+n)/n
    = (n(n+1)/2)/n
    = (n+1)/2
so, average case, O(n)
*/
    for (int i = 0; i < a.length; i++) {
        if (key == a.A[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Array arr = {{2, 6, 3, 11, 22, 0, 7}, 10, 7};
    int key;
    // cout << "Enter the element you wqant to search: ";
    // cin >> key;
    key = 99;
    cout << search(arr, key);
}