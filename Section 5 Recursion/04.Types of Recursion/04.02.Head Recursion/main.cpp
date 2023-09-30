using namespace std;
#include<iostream>

/*
Head Recursion- a function where recursive call is the first statement in the function
Here, everything is performed at returning time only
at calling time, it doesn't peform anything at all

Conclusion- head recursion can be written in the form of loop, but its not easy
*/

void func1(int n) {
    int i = 1;
    while (i <= n) {
        cout << i << " ";
        i++;
    }
    cout << endl;
}

void func2(int n) {
    if (n > 0) {
        func2(n-1);
        cout << n << " ";
    }
}

int main() {
    int x = 4;
    func1(x);
    func2(x);
    return 0;
}