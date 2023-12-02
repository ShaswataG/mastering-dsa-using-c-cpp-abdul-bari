using namespace std;
#include<iostream>

struct Test {
    int n;
    int * a;
};

struct Test * fun(int n) {
    struct Test * p = new struct Test;
    p->n = n;
    p->a = new int[n];
    for (int i = 0; i < n; i++) {
        p->a[i] = (i+1)*10;
    }
}

void display(struct Test * t) {
    for (int i = 0; i < t->n; i++) {
        cout << t->a[i] << " ";
    }
    cout << endl;
}

int main() {
    struct Test * t1;
    t1 = fun(7);
    display(t1);     // segmentation fault
}