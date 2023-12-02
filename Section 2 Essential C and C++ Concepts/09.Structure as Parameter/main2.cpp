#include<iostream>
using namespace std;

/*
arrays in a structure are passed by value when structures including the array are passed by value to a function
*/

struct Test
{
    int a[5];
    int n;
};

void fun(Test t1) {
    for (int i = 0; i < 5; i++) {
        t1.a[i] *= 10;
    }
    for (int i = 0; i < 5; i++) {
        cout << t1.a[i] << " ";
    }
    cout << endl;
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    Test t {{1, 2, 3, 4, 5}, 10};
    display(t.a, 5);
    fun(t);     // since t is passed by value, t.a is also passed by value, and so any changes to the array inside fun() will not reflect on t.a
    display(t.a, 5);
    return 0;
}