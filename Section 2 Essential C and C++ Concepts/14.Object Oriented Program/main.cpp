using namespace std;
#include<iostream>

class Rectangle {
private:
    int length, breadth;
public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    void initialize(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() {
        return length*breadth;
    }
    int perimeter() {
        return 2*(length+breadth);
    }
};

int main() {
    Rectangle r(0, 0);
    int a, b;
    cout << "Enter length and breadth : ";
    cin >> a >> b;

    r.initialize(a, b);
    cout << "Area : " << r.area() << endl;
    cout << "Perimeter : " << r.perimeter() << endl;
    return 0;
}