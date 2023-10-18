using namespace std;
#include<iostream>
#include<typeinfo>
struct Array {
    int A[10], size, length;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool check_sorted(struct Array a) {
    for (int i = 0; i < a.length-1 ; i++) {
        if (a.A[i] > a.A[i+1])
            return false;
    }
    return true;
}

void insert_sorted(struct Array* a, int x) {
    int i = a->length-1;
    if (a->size == a->length)
        return;
    while (i >= 0 && x < a->A[i]) {
        a->A[i+1] = a->A[i];
        i--;
    }
    a->A[i+1] = x;
    a->length++;
}

void Rearrange(struct Array* a) {
    int i, j;
    i = 0;
    j = a->length-1;
    while(i < j) {
        while(a->A[i] < 0) i++;
        while(a->A[i] >= 0) j--;
        if (i < j) swap(&a->A[i], &a->A[j]);
    }
}

void display(struct Array a) {
    cout << "Elements of the array are:" << endl;
    for (int i = 0; i < a.length; i++) {
        cout << "A[" << i << "] = " << a.A[i] <<endl;
    }
}

int main() {
    Array arr = {{2, 3, 5, 7, 9}, 10, 5};
    display(arr);
    int element;
    cin >> element;
    // cout << typeid(check_sorted(arr)).name() << endl;
    if(check_sorted(arr) == true)
        insert_sorted(&arr, element);
    // insert_sorted(&arr, element);
    Rearrange(&arr);
    display(arr);
    return 0;
}