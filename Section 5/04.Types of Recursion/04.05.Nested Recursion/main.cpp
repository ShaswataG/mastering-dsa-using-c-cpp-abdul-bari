using namespace std;
#include<iostream>

/*
Nested Recursion- In nested recursion, a recursive function will pass parameter as a recursive call
*/

int fun(int n) {
    if (n > 100)
        return n-10;
    return fun(fun(n+11));
}

int main() {
    int r;
    r = fun(95);
    cout << r << endl;
    return 0;
}