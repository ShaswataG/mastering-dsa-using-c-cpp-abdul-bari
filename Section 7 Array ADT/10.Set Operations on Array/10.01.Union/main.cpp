using namespace std;
#include<iostream>

struct Array {
    int A[10], size, length;
};

Array* Union_unsorted(Array a, Array b) {
    Array* c = new Array;
    for (int i = 0; i < a.length; i++) {
        c->A[i] = a.A[i];
    }
    int k = 0;
    for(int i = 0; i < b.length; i++) {
        int found = 0;
        for (int j = 0; j < a.length; j++) {
            if (b.A[i] == c->A[j]) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            c->A[k+a.length] = b.A[i];
            k++;
        }
    }
}

Array* Union_sorted(Array a, Array b) {
    int i, j, k;
    i = j = k = 0;
    Array* c = new Array;
    while(i < a.length && j < b.length) {
        if (a.A[i] < b.A[j]) {
            c->A[k++] = a.A[i++];
        } else if (a.A[i] > b.A[j]) {
            c->A[k++] = a.A[j++];
        } else {
            // c->A[k] = a.A[i];
            c->A[k++] = a.A[i++];
            // i++;
            j++;
            // k++;
        }
    }
    for(; i < a.length; i++) {
        // c->A[k] = a.A[i];
        c->A[k++] = a.A[i];
        // k++;
    }
    for(; j < b.length; j++) {
        // c->A[k] = b.A[j];
        c->A[k++] = b.A[j];
        // k++;
    }
    c->length = k;
    c->size = 10;
    return c;
}

void display(struct Array a) {
    cout << "Elements of the array are:" << endl;
    for (int i = 0; i < a.length; i++) {
        cout << a.A[i] << " ";
    }
    cout << endl;
}

int main() {
    Array a1 = {{2, 6, 10, 15, 25}, 10, 5};
    Array a2 = {{3, 6, 7, 15, 20}, 10, 5};
    Array* a3 = Union_sorted(a1, a2);
    display(*a3);
    return 0;
}