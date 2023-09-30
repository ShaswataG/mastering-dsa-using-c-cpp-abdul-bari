using namespace std;
#include<iostream>

struct Rectangle {
    int length, breadth;
};

int main() {
    // in c++ struct is not mandatory, unlike c
    Rectangle r = {3, 8};
    Rectangle *p = &r;
    // also you can use p->breadth instead of (*p).breadth
    p->breadth = 7;
    // order of precedence : . > *, so enclose *p within ( and )
    cout << "Length of rectangle r = " << p->length << endl;
    cout << "Breadth of rectangle r = " << p->breadth << endl;
    
    return 0;
}