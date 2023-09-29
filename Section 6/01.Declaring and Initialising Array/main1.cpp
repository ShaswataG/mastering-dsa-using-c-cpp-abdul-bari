using namespace std;
#include<iostream>

int main() {
    int a[5];   // all elements initialized with garbage values
    int b[5] = {1, 2, 3, 4, 5};     // {1,2,3,4,5}
    int c[5] = {2, 4};      // {2, 4, 0, 0, 0}
    int d[5] = {0};     // {0, 0, 0, 0, 0}
    int e[] = {2, 4, 6, 8, 10, 12};     // {2, 4, 6, 8, 10, 12}


    for (int i = 0; i < 5; i++) {
        cout << c+i << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << &c[i] << " ";
    }
    cout << endl;
    // cout << &c[5];
    return 0;
}