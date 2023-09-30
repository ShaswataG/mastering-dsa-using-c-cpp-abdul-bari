using namespace std;
#include<iostream>

int main() {
    int a = 4;
    // reference variables must be initialized at the time of declaring
    int &r_a = a;
    cout << "Address of a : " << &a <<  endl;
    cout << "Address of r_a : " << &r_a << endl;
    int b = 25;

    // reference doesn't consume any memory unlike pointer, it shares the same, r_a uses the same memory of a

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