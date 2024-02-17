using namespace std;
#include<iostream>

struct Array {
    int A[10], size, length;
};

void Reverse1(struct Array* a) {
/*
TC = O(n)
SC = O(n)
AS = O(n)
*/
    int* b = new int[a->length];
    for (int i = 0; i < a->length; i++) {
        b[i] = a->A[a->length - i - 1];
    }
    for (int i = 0; i < a->length; i++) {
        a->A[i] = b[i];
    }
}

void Reverse2(struct Array* a) {
/*
TC = O(n)
SC = O(n)
AS = O(1)
*/
    for (int  i = 0; i < a->length/2; i++) {
        int temp = a->A[i];
        a->A[i] = a->A[a->length-i-1];
        a->A[a->length-i-1] = temp;
    }
}

void Rotate1(struct Array* a) {
    int c = a->A[0];
    for (int i = 0; i < a->length-1; i++) {
        a->A[i] = a->A[i+1];
    }
    a->A[a->length-1] = c;
}

void display(struct Array a) {
    cout << "Elements of the array are:" << endl;
    for (int i = 0; i < a.length; i++) {
        cout << "A[" << i << "] = " << a.A[i] <<endl;
    }
}

int main() {
    Array arr = {{2, 7, 3, 6, 10, 1}, 10, 6};
    display(arr);
    Reverse2(&arr);
    // Rotate1(&arr);
    display(arr);
    return 0;
}


// h/w do the rotation yourself