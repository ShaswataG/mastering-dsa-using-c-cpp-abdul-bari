using namespace std;
#include<iostream>

void swap(int a, int b) {
    cout << "a=" << a << ", b= " << b << endl; 
    int temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << ", b= " << b << endl;
}

int main() {
    int num1 = 2, num2 = 3;
    swap(num1, num2);
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}