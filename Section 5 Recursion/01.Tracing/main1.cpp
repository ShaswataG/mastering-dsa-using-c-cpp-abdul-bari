using namespace std;
#include<iostream>

// ascending recursion
// printing while calling

void func1(int n) {
    if (n > 0) {
        cout << n << " ";
        func1(n-1);
    }
}

int main() {
    int x = 3;
    func1(x);
    return 0;
}