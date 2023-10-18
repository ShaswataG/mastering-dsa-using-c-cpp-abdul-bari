using namespace std;
#include<iostream>

int main() {
    char c1 = 'A';
    char c2 = 65;
    // cout << c1 << " " << c2 << endl;
    char c3[] = {'a', 'b', 'c', 'd', 'e'};
    
    char c4[4];
    char c5[10] = {'a', 'b', 'c', 'd'};
    for (auto it : c5)
        cout << it << " ";
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << c5[i] << " ";
    cout << endl;

    // string
    char s1[10] = {'J', 'o', 'h', 'n', '\0'};
    char s2[] = {'J', 'o', 'h', 'n', '\0'};     // here, size = 5, since null character i.e. '\0' also occupies space   
    char s3[] = "Mike";
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}