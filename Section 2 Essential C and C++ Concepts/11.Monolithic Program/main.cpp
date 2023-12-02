using namespace std;
#include<iostream>

int main() {
    int length = 0, breadth = 0;
    cout << "Enter length : ";
    cin >> length;
    cout << "Enter breadth : ";
    cin >> breadth;
    int area = length*breadth;
    cout << "Area : " << area << endl;
    int perimeter = 2*(length+breadth);
    cout << "Perimeter : " << perimeter << endl;
}