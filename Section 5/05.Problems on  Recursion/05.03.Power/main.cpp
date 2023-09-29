using namespace std;
#include<iostream>

int solution1(int m, int n) {
/* 
TC = O(n)
SC = O(n)
*/
    if (n == 0)
        return 1;
    return solution1(m, n-1) * m;
}

// int solution2(int m, int n) {
/*
TC = O(n)
SC = O(1)
*/
//     if (n == 0)
//         return 1;
//     else {
//         int pow = 1;
//         for (int i = 1; i <= n; i++) {
//             pow *= m;
//         }
//     }
// }

int solution3(int m, int n) {
// for efficiency, this is better
    if (n == 0)
        return 1;
    else if (n%2 == 0)
        return solution3(m*m, n/2);
    else
        return m * solution3(m*m, (n-1)/2);  
}

int main() {
    int x = 5, y = 4;
    cout << solution1(x, y) << endl;
    // cout << solution2(x, y) << endl;
    cout << solution3(x, y) << endl;
    return 0;
}