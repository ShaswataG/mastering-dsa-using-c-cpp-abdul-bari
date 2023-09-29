using namespace std;
#include<iostream>

struct Complex {
    double real, imaginary;
} c1, c2, c3;

struct Complex c4;

int main() {
    struct Complex c5;
    c5 = {3, 4};
    cout << "c5 = " << c5.real << "+" << c5.imaginary << "i" << endl;
}