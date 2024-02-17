using namespace std;
#include<iostream>
// In transposition, there is a slow reduction in time taken for searching 

struct Array {
    int A[10];
    int size;
    int length;
};

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int search(struct Array* a, int key) {
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
    for (int i = 0; i < a->length; i++) {
        if (key == a->A[i] && i != 0) {
            swap(a->A[i], a->A[i-1]);
            return i;
        } else if (key == a->A[i] && i == 0) {
            return i;
        }
    }
    return -1;
}
void display(struct Array a) {
    cout << "Elements of the array are: " << endl;
    for (int i = 0; i < a.length; i++) {
        cout << "arr[" << i << "] = " <<  a.A[i] << endl;
    }
    cout << endl << "Length of array: " << a.length << endl;
}
int main() {
    struct Array arr = {{2, 6, 3, 11, 22, 0, 7}, 10, 7};
    display(arr);
    int key;
    // cout << "Enter the element you wqant to search: ";
    // cin >> key;
    key = 3;
    cout << search(&arr, key);
    display(arr);
}