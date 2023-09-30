using namespace std;
#include<iostream>
// #include<stdio.h>
// #include<stdlib.h>

struct Array {
    int* A;
    int size;
    int length;
};

void display(struct Array a) {
    cout << "Elements of the array are:" << endl;
    for (int i = 0; i < a.size; i++) {
        cout << "A[" << i << "] = " << a.A[i] <<endl;
        a.length++;
    }
    cout << endl << "Size of array: " << a.size << endl;
}

int main() {
    Array arr;
    cout << "Enter size of an array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    // arr.A = (int*) malloc(arr.size * sizeof(int));
    arr.length = 0;
    cout << "Now enter " << arr.size << " elements in the array: ";
    for (int i = 0; i < arr.size; i++) {
        cin >> *(arr.A+i);
    }
    display(arr);
    return 0;
}