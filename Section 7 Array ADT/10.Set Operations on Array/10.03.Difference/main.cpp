using namespace std;
#include<iostream>

struct Array {
    int A[10], size, length;
};

Array* Difference_sorted(Array a, Array b) {
    int i, j, k;
    i = j = k = 0;
    Array* c = new Array;
    while(i < a.length && j < b.length) {
        if (a.A[i] < b.A[j]) {
            c->A[k] = a.A[i];
            i++;
            k++;
        } else if (a.A[i] > b.A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    c->length = k;
    c->size = 10;
}

void display(struct Array a) {
    cout << "Elements of the array are: " << endl;
    for (int i = 0; i < a.length; i++) {
        cout << a.A[i] << " ";
    }
    cout << endl;
}

int main() {
    Array a1, a2, a3;
    a1 = {{2, 3, 5, 7, 9}, 10, 5};
    a2 = {{2, 4, 6, 7, 8}, 10, 5};
    a3 = *Difference_sorted(a1, a2);
    display(a3);   
    return 0;
}