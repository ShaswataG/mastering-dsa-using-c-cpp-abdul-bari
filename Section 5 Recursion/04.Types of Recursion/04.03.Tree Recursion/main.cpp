using namespace std;
#include<iostream>

/*
Linear Recursion- a recursive function calls itself only once
Tree Recursion- a recursive function calls itself more than once
*/

void func(int n) {
/*
TC = O(2^n), total no. of function calls = 2^(n+1)-1
SC = O(n), max. no. of stacks used = height of recursion tree = n + 1
*/
    if (n > 0) {
        cout << n;
        func(n-1);
        func(n-1);
    }
}

int main() {
    int x = 3;
    func(x);
    return 0;
}