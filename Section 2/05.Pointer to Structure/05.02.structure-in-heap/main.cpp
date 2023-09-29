using namespace std;
#include<iostream>

struct Rectangle {
    int length, breadth;
};

int main() {
    Rectangle *p;
    p = new Rectangle;
    
    (*p).length = 15;
    p->breadth = 90;
    cout << "Length if reactangle *p = " << p->length << endl;
    cout << "Breadth of rectangle *p = " << p->breadth << endl;
    cout << "Area of rectangle *p = " << p->length * p->breadth << endl;
    return 0;
}