using namespace std;
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

/* in C, array size must be decided at compile time
 in C++, array size can be decided at run time also
 in both C and C++, array are created in stack

 size of stack array can't be changed
 size of heap array can be changed
*/
int main() {
    int a[5] = {2, 4, 6, 8, 10};
    int* p;
    p = new int[5];
    // p = (int*) malloc(5 * sizeof(int));  // malloc returns void type of pointer, so we typecast it into int type pointer
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;
    // cout << "a[4] = " << a[4] << " or *(a+4) = " << *(a+4) << endl;
    // cout << "p[4] = " << p[4] << " or *(p+4) = " << *(p+4) << endl;
    for (auto i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    for (auto i : a) {
        cout << i << " ";
    }
    
    return 0;
}