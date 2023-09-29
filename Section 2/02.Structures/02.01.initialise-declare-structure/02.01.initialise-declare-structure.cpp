using namespace std;
#include<iostream>

struct Rectangle {
    int length, breadth;
    char c;     // padding of memory- it will take 3*4=12bytes but use only 9bytes, its done so that its easier for the processor to read the entire structure at once 
};

int main() {
    struct Rectangle r;
    r = {10, 5};
    cout << r.length << endl;
    cout << r.breadth << endl;
    r.length = 15;
    cout << r.length << endl;
    cout << "Area of rectangle = " << r.length * r.breadth << endl;
    cout << "sizeof(Rectangle) = " << sizeof(Rectangle) << "bytes" << endl;
    return 0;
}