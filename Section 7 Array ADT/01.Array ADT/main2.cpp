using namespace std;
#include<iostream>

struct Array {
    int A[20], size, length;
};

void display(struct Array a) {
    cout << "Elements of the array are: " << endl;
    for (int i = 0; i < a.size; i++) {
        cout << "arr[" << i << "] = " <<  a.A[i] << endl;
    }
    cout << endl << "Size of array: " << a.size;
}

int main() {
    Array arr = {{2, 3, 5, 7, 9}, sizeof(int), 5};
    display(arr);
    return 0;
}