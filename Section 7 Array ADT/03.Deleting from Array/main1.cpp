using namespace std;
#include<iostream>

struct Array {
    int A[20], size, length;
};

void display(struct Array a) {
    cout << "Elements of the array are: " << endl;
    for (int i = 0; i < a.length; i++) {
        cout << "arr[" << i << "] = " <<  a.A[i] << endl;
    }
    cout << endl << "Length of array: " << a.length << endl << endl;
}

int Delete(struct Array* a, int index) {
/*
Best case, TC = O(1)
Worst case, TC = O(n) where n = length of array
*/
    int x = 0;
    if (index >= 0 && index < a->length) {
        x = a->A[index];
        for (int i = index; i < a->length; i++) {
            a->A[i] = a->A[i+1];
        }
        a->length--;
        return x;
    }
    return 0;
}
   
int main() {
    Array arr = {{2, 3, 5, 7, 9}, 20, 5};
    display(arr);
    cout << Delete(&arr, 2) << endl << endl;
    display(arr);

    // cout << arr.A[4] << endl;    // prints 9 (since in Delete method i < a->length-1, for it to print 0, i < a->length)
    // cout << arr.A[5] << endl;    // prints 0
    return 0;
}