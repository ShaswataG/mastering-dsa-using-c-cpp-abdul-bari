using namespace std;
#include<iostream>

/*
structures can be passed by value, reference or pointer to a function
*/
struct Rectangle {
    int length, breadth;
};

// int area(struct Rectangle r1) {
//     // r1.breadth = 10;
//     // cout << r1.breadth << endl;
//     return r1.length*r1.breadth;
// }

int area(struct Rectangle& r1) {
    r1.breadth = 10;
    return r1.length*r1.breadth;
}

void changeLength(struct Rectangle* r1, int l) {
    r1->length = l;
}

int main() {
    struct Rectangle r;
    r.length = 2;
    r.breadth = 3;
    cout << r.length << endl;
    cout << r.breadth << endl;
    // cout << "Area : " << area(r) << endl;
    changeLength(&r, 10);
    cout << r.length << endl;
    cout << r.breadth << endl;
    return 0;
}