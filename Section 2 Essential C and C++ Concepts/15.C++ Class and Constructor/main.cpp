#include<iostream>
using namespace std;

class Rectangle {
private:
    int length, breadth;
public:
    Rectangle() {length = breadth = 1;}
    Rectangle(int, int);
    int area();
    int perimeter();
    int getLength();
    int getBreadth();
    void setLength(int);
    void setBreadth(int);
    ~Rectangle();
};

// using scope resolution outside the class
Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

int Rectangle::area() {
    return length*breadth;
}

int Rectangle::perimeter() {
    return 2*(length+breadth);
}

int Rectangle::getLength() {
    return length;
}

int Rectangle::getBreadth() {
    return breadth;
}

void Rectangle::setLength(int l) {
    length = l;
}

void Rectangle::setBreadth(int b) {
    length = b;
}

Rectangle::~Rectangle() {
    cout << "Destructor" << endl;
}

int main() {
    Rectangle r;
    cout << r.area() << endl;
    return 0;
}