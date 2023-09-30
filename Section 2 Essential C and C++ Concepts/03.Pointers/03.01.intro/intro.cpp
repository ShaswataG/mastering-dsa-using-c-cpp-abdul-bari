using namespace std;
#include<iostream>

int main() {
    int a = 5;
    int* ptr_a;
    ptr_a = &a;
    cout << "Address : " << &a << " stores the value : " << a << endl;
    cout << "Address : " << ptr_a << " stores the value : " << *ptr_a << endl;
    
    return 0;
}