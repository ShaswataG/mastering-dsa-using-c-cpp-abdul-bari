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
    cout << endl << "Length of array: " << a.length << endl;
}

void append(struct Array* a, int element) {
    if (a->length < a-> size) {
        a->A[a->length] = element;
        a->length++;
    }
}

void insert(struct Array* a, int index, int x) {
    if (index >= 0 && index <= a->length) {
        for (int i = a->length; i > index; i--) {
            a->A[i] = a->A[i-1];
        }
    }
    a->A[index] = x;
    a->length++;
}


int main() {
    Array arr = {{2, 3, 5, 7, 9}, 20, 5};
    display(arr);
    append(&arr, 99);
    display(arr);
    insert(&arr, 2, 43);
    display(arr);
    return 0;
}