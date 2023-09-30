using namespace std;
#include<iostream>

int main() {

    int *p;
    // pointer variable p is in stack, but the array is in heap
    p = new int[5];
    p[0] = 2, p[1] = 4, p[2] = 6, p[3] = 8, p[4] = 10;
    for (int i = 0; i < 5; i++) {
        cout << "p[" << i << "] = " << p[i] << endl;
    }
    cout << endl << "Array is :" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(p+" << i << ") = " << *(p+i) << " " << endl;
    }
    delete [] p;
    return 0;
}