using namespace std;
#include<iostream>

/*
arrays can't be passed by value, they are always passed by address (C and C++)
*/

void fun(int a[], int n) {
/*
a is a pointer to the array passed, [] represents that a is a pointer to an array
fun(int* a, int n) can also be used, in this case 'a' can be both pointer to an array or pointer to an integer variable
fun(int a[], int n), here 'a' is specifically a pointer to an integer array
*/
    a[0] = a[1] = 0;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int * fun(int n) {
    int * p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = i+1;
    }
    return p;
}

void display(int * a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {
    int a[] = {2, 3, 5, 7, 11};
    fun(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int * b;
    b = fun(6);     // benefit of dynamic memory, if you create anything in heap, then it can be accessed anywhere in the program, if a pointer to it is available
    display(b, 6);

    int c[5] = {4, 32};
    display(c, 5);

    int d[5];
    d[2] = 1;
    display(d, 5);
    return 0;
}