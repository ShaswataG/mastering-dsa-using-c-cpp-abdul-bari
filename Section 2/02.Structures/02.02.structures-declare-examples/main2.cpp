using namespace std;
#include<iostream>

struct Student {
    int roll;
    char name[25];
    char dept[10];
    char address[50];
};

int main() {
    struct Student s1 = {12, "John", "CSE", "221B Baker Street"};
    cout << s1.address << endl;
    return 0;
}