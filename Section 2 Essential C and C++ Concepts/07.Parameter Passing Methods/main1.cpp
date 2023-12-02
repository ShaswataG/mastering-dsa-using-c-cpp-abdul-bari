using namespace std;
#include<iostream>

// Pass by value: any changes done with formal parameters will not reflect in actual parameters
// Mostly used when a function does computations and then returns a value. ex: add two numbers
// void swap(int a, int b) {
//     // cout << "a=" << a << ", b= " << b << endl; 
//     int temp = a;
//     a = b;
//     b = temp;
//     // cout << "a=" << a << ", b= " << b << endl;
// }

// Call by address: any changes done with formal parameters will reflect in actual parameters
// pointer a and b are indirectly accessing the values num1 and num2 (by using their addresses)
// Used when a function needs to work upon the actual parameters
// Also used when we want to get more than one results from a function, since using return we can get only one result
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Call by reference: any changes done with formal parameters will reflect in actual parameters
// doesn't consume extra memory since existing variables num1 and num2 are given alias names a and b respectively
// so, in some cases, this function may work as an inline function (depends on the compiler whether it converts the references to pointers or treat them like alias names and make the function inline)
// num1 and num2 actually belong to main(), main() is calling them as num1 and num2, whereas swap() is calling them as a and b
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
Call by reference is not preferred (especially in case of large programs), as it is monolythic program(makes the function inline) and not modular program. doubt?
if a function takes both parameter by reference and parameter by value, then conceptually (not always true, depends on compiler) it is not an inline function (note that is still depends on the compiler, whether it wants to treat the function as inline or not)
*/

int main() {
    int num1 = 2, num2 = 3;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    swap(num1, num2);
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    swap(&num1, &num2);     // passing the address of actual parameters to the formal parameters (pointers a and b) of the function swap
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}