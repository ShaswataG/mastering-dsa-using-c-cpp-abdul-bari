using namespace std;
#include<iostream>

struct Rectangle
{
    int length, breadth;
};

void initialize(Rectangle * r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int area(Rectangle r) {
    return r.length*r.breadth;
}

int perimeter(Rectangle r) {
    return 2*(r.length+r.breadth);
}

int main() {
    Rectangle r = {0, 0};
    int a, b;
    cout << "Enter length : ";
    cin >> a;
    cout << "Enter breadth : ";
    cin >> b;

    initialize(&r, a, b);
    cout << "Area : " << area(r) << endl;
    cout << "Perimeter : " << perimeter(r) << endl;
    return 0;
}