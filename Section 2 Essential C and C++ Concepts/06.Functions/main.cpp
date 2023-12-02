using namespace std;
#include<iostream>

int add(int a, int b) {
/*
a and b are called formal parameters, they are temporary
when function is called, a and b are used
when function ends, a and b are destroyed
*/
    int c = a+b;
    return c;
}

int main() {
    int num1, num2, sum;
    num1 = 2, num2 = 3;
    sum = add(num1, num2);  // here, num1 and num2 are actual parameters
    cout << "Sum : " << sum << endl;
    return 0;
}