using namespace std;
#include<iostream>

// int x = 0;

int func(int n) {
    static int x = 0;
    if (n > 0) {
        x++;
        return func(n-1) + x;
    }
}

int main() {
    int a = 5;
    cout << func(a) << endl;
    return 0;
}