using namespace std;
#include<iostream>

/*
Indirect recursion- there are more than one function, and they are calling one another in a circular fashion
*/
void funcB(int n);
void funcA(int n) {
    if (n > 0) {
        cout << n << " ";
        funcB(n-1);
    }
}


void funcB(int n) {
    if (n > 1) {
        cout << n << " ";
        funcA(n/2);
    }
}
int main() {
    funcA(20);
    return 0;
}