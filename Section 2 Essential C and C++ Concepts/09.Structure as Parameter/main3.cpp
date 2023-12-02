using namespace std;
#include<iostream>

struct Rectangle {
    int length, breadth;
};

struct Rectangle * fun() {
    struct Rectangle * t;
    t = new struct Rectangle;
    t->length = 10;
    t->breadth = 20;
    return t;
}

int main() {
    struct Rectangle * p;
    p = fun();
    cout << p->length << endl;
    cout << p->breadth << endl;
    return 0;
}