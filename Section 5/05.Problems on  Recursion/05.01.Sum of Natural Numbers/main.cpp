using namespace std;
#include<iostream>

int solution1(int n) {
    if (n > 0) {
        return solution1(n-1) + n;
    }
    return 0;
}

int solution2(int n) {
/*
TC = O(n)
SC = O(n)
*/
    if (n == 0)
        return 0;
    else
        return solution2(n-1) + n;
}

int solution3(int n) {
/*
TC = O(n)
SC = O(1), 3 variables
*/
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s+= i;
    }
    return s;
}

int solution4(int n) {
/*
TC = O(1)
SC = O(1), 1 variable only
*/
    return (n*(n+1))/2;
}

int main() {
    cout << solution1(4) << endl;
    cout << solution2(4) << endl;
    cout << solution3(4) << endl;
    cout << solution4(4) << endl;
    return 0;
}