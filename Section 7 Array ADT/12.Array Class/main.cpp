using namespace std;
#include<iostream>

template<class T>
class Array {
    private:
        T* A;
        int size;
        int length;
    public:
        Array(int a = 10) {
            size = a;
            length = 0;
            A = new T[size];
        }
        ~Array() {
            delete []A;
        }
        void Display();
        void Insert(int, T);
        int Delete(int);
};

template<class T>
void Array<T>::Display() {
    cout << "Elements are : ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--) {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

template<class T>
int Array<T>::Delete(int index) {
    T x = 0;
    if (index >= 0 && index <length) {
        x = A[index];
        for (int i = index; i < length-1; i++) {
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

int main() {
    Array<int> a;
    cout << "Press 1 to insert element in the array." << endl << "Press 2 to display array." << endl << "Press 3 to delete an element from the array." << endl;
    int c;
    while(true) {
        switch (c) {
            case 1 : {
                cout << "Enter index you want to enter element at: ";
                int index, x;
                cin >> index;
                cout << "Enter element you want to insert: ";
                cin >> x;
                a.Insert(index, x);
            }
            break;
            case 2 : {
                a.Display();
            }
            break;
            case 3 : {
                int index;
                cout << "Enter index you want to delete element from: ";
                cin >> index;
                a.Delete(index);
            }
        }
    }
    return 0;
}