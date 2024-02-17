#include<iostream>
#define MAX 10
using namespace std;

/*
to minimize wastage of time(unnecessary processing of non-diagonal elements while adding, multiplying etc matrices) and space(zero elements taking unnecessary space), we implement diagonal matrix using 1D array instead of 2D array
*/
class Diagonal {
    int* a;
    int n;
public:
    Diagonal(int n = MAX) {
        this->n = n;
        a = new int[this->n];
    }
    void set(int i, int j, int x) {
        if (i == j) {
            a[i-1] = x;
        }
    }
    int get(int i, int j) {
        if (i == j) return a[i-1];
        else return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    cout << a[i] << " ";
                } else {
                    cout << "0" << " ";
                }
            }
            cout << endl;
        }
    }
    ~Diagonal() {
        delete [] a;
    }
};

int main() {
    int n, x;
    cout << "Enter number of rows or columns in the matrix : ";
    cin >> n;
    Diagonal m(n);
    cout << "Now enter the elements : " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "Enter a[" << i << ", " << j << "]th element : ";
            cin >> x;
            m.set(i, j, x);
        }
    }
    m.display();
    
    return 0;
}