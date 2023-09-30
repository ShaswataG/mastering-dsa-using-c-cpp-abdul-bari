using namespace std;
#include<iostream>

struct Rectangle {
    int length, breadth;
};

int main() {
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    // whatever be the type of pointer, it takes up same amount of memory
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;    
    return 0;
}