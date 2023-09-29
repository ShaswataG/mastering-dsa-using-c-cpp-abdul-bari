using namespace std;
#include<iostream>

int main() {
    int b[6] = {2, 4, 6, 8, 10, 12};
    int* ptr_b;
    // ptr_b = &b; // error
    ptr_b = b;  
    // ptr_b = &b[0];  // no error
    ptr_b = b;
    for (int i = 0; i < 6; i++) {
        cout << ptr_b[i] << " ";
    }
    return 0;
}