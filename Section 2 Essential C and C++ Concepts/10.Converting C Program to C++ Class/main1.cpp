using namespace std;
#include<iostream>

class Rectangle {
private:
    int length, breadth;
public:
    Rectangle(int, int);
    int area();
    void changeLength(int);
};

Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

int Rectangle::area() {
    return length*breadth;
}

void Rectangle::changeLength(int l) {
    length = l;
}

int main() {
    Rectangle r(2,3);
    cout << r.area() << endl;
    r.changeLength(10);
    cout << r.area() << endl;

    return 0;
}