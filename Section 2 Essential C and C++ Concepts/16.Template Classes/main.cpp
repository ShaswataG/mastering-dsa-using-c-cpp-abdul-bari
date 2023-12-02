#include<iostream>
using namespace std;

template<class T>
class Arithmetic {
private:
    T a, b;
public:
    Arithmetic(T, T);
    T add();
    T subtract();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add() {
    return a+b;
}

template<class T>
T Arithmetic<T>::subtract() {
    return a-b;
}

int main() {
    Arithmetic<int> a(2, 3);
    cout << "Add : " << a.add() << endl;
    cout << "Subtract : " << a.subtract() << endl;

    Arithmetic<float> b(3.3, 4.7);
    cout << "Add : " << b.add() << endl;
    cout << "Subtract : " << b.subtract() << endl;
}