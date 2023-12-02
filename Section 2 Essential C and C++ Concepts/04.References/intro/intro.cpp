using namespace std;
#include<iostream>

int main() {
    int a = 4;
    // reference are alias, another name or nickname to a variable
    // reference variables must be initialized at the time of declaring
    // reference dont't consume memory, since existing variable are given another name
    int &r_a = a;
    cout << "Address of a : " << &a <<  endl;
    cout << "Address of r_a : " << &r_a << endl;
    int b = 25;

    // references don't consume any memory like pointers, it shares same memory, r_a uses the same memory of a

    // reference can't be changed once initialized
    // below statement assigns the value 25 to r_a or a, it doesn't change the reference of r_a
    r_a = b;
    cout << "Address of b : " << &b <<  endl;
    cout << "Address of r_a : " << &r_a << endl;

    r_a = 39;
    cout << "a = " << a << endl;
    a =99;
    cout << "r_a = " << r_a << endl; 
   return 0;
}