using namespace std;
#include<iostream>

int solution1(int n) {
/*
TC = O(n)
SC = O(n)
*/

// modify it to handle negative value of n
    if (n == 0)
        return 1;
    else
        return solution1(n-1) * n;
}

int solution2(int n) {
/*
TC = O(n)
SC = O(1), 3 variables
*/
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int x = 5;
    cout << solution1(x) << endl;
    cout << solution2(x) << endl;
    return 0;
}