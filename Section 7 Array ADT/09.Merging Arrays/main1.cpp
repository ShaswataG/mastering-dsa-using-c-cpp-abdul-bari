using namespace std;
#include<iostream>

struct Array {
    int A[10], size, length;
};

Array* Merge(struct Array* a, struct Array* b) {
    struct Array* c = new (struct Array);
    int i, j, k;
    i = j = k = 0;
    while(i < a->length && j < b->length) {
        if (a->A[i] < b->A[j]) {
            c->A[k] = a->A[i];
            i++;
            k++;
            // c->A[k++] = a->A[i++];
        } else {
            c->A[k] = b->A[j];
            j++;
            k++;
        }
    }
    for (; i < a->length; i++) {
        c->A[k] = a->A[i];
    }
    for (; i < b->length; j++) {
        c->A[k] = b->A[j];
    }
    c->length = a->length+b->length;
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
    Array a = {{2, 3, 5, 9, 11}, 10, 5};
    Array b = {{2, 4, 6, 8, 10}, 10, 5};
    Array* c;
    c = Merge(&a, &b);
    display(*c);
    return 0;
}