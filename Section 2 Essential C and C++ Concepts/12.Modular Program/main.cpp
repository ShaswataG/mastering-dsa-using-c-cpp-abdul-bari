using namespace std;
#include<iostream>

int area(int l, int b) {
    return l*b;
}

int perimeter(int a, int b) {
    return 2*(a+b);
}

int main() {
    int length = 0, breadth = 0;
    cout << "Enter length : ";
    cin >> length;
    cout << "Enter breadth : ";
    cin >> breadth;
    cout << "Area : " << area(length, breadth) << endl;
    cout << "Perimeter : " << perimeter(length, breadth) << endl;
    return 0;
}