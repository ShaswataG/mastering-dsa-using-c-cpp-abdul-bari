using namespace std;
#include<iostream>

/*
Tail Recursion- a function where recursive call is the last statement in the function
Here, everything is performed at calling time only
at returning time, it doesn't peform anything at all

Every recursive function can be written in the form of a loop, also vice-versa is true
Here TC(tail recusion) = TC(loop)
But SC(tail recursion) = O(n), whereas SC(loop) = O(1)

Conclusion- in case of tail recursion, its better to use loops instead of recursive function
*/

void func1(int n) {
    while (n > 0) {
        cout << n;
        n--;
    }
}

void func2(int n) {
    if (n > 0) {
        cout << n;
        func2(n-1);
    }
}

/*
folowing function is not a tail recusive function
int func3(int n) {
    if (n > 0) {
        return func3(n) + n;
    }
    return 0;
}
*/

int main() {
    int x = 4;
    func1(x);
    func2(x);
    return 0;
}