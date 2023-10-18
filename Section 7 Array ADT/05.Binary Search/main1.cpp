using namespace std;
#include<iostream>

/*
for both iterative and recursive functions,

n/2/2/2/2.... until it gives 1
let n = 16
(((16/2)/2)/2)/2 = 16/2^4 = 1
2^x = 16 => x = log2(16) => x = 4

therefore, x = log2(n+1)
ignoring constants we get,
worst case, O(log(n))
best case, O(1) when key is at the middle of the array
for average case,
let n = 15
1 + 1 * 2 + 2 * 4 + 3 * 8
= 1 + 1 * 2 + 2 * 2^2 + 3 * 2^3
= i=1(Sigma)log(n) (i * 2^i)/n = (log(n) * 2^(log(n)))/n = (n * log(n))/n = log(n)
therefore, average case, O(log(n))
*/

struct Array {
    int A[20];
    int size, length;
};

int BinarySearch(struct Array a, int key) {
    int l = 0;
    int h = a.length-1;
    int mid;
    while (l <= h) {
        mid = (l+h)/2;
        if (key == a.A[mid]) {
            return mid;
        } else if (key < a.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int RBinarySearch(int l, int h, int key, struct Array a) {
    int mid;
    if (l <= h) {
        mid = (l+h)/2;
        if (key == a.A[mid]) {
            return mid;
        } else if (key < a.A[mid]) {
            return RBinarySearch(l, mid-1, key, a);
        } else {
            return RBinarySearch(mid+1, h, key, a);
        }
    }
    return -1;
}

int main() {
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    cout << BinarySearch(arr, 2) << endl;
    cout << RBinarySearch(0, 4, 8, arr);
    return 0;
}

/*



*/