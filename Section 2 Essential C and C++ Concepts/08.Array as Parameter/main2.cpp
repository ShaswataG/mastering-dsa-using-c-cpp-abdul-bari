using namespace std;
#include<iostream>

void fun(int a[]) {
    // cout << sizeof(a)/sizeof(int) << endl;  // sizeof(a) rteturn size of pointer variable 'a', as arrays are always passed by address
    // we can't use for each loop upon an array declared in another function, since arrays are alsways passed by address, and so, its not possible for a for each loop to determine the size of the array
    // so usually while passing array as a parameter to a function, we also pass the size of the array as a parameter
    // for (int i : a) {    here a is a pointer to an array, so for each loop can't determine the size of the array
    //     cout << i << " ";
    // }
}

int main() {
    int a[] = {2, 3, 5, 7, 11};
    // fun(a);
    cout << sizeof(a)/sizeof(int) << endl;  // sizeof(a) returns size of the array, but inside fun(int a[]) sizeof(a) returns size of pointer variable 'a', as arrays are always passed by address
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}