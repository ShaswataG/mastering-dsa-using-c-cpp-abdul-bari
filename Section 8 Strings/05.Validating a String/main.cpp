using namespace std;
#include<iostream>

bool validate_string1(char* name) {
    bool validate = false;
    for (int i = 0; name[i] != '\0'; i++) {
        if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 48 && name[i] <= 57)) {
            validate = true;
        } else {
            return false;
        }
    }
    return validate;
}

int validate_string2(char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 48 && name[i] <= 57)) {
            return false;
        }
    }
    return true;
}

int main() {
    char name1[] = "Master2";
    char name2[] = "hgi!ggk";
    cout << validate_string1(name1) << endl;
    cout << validate_string1(name2) << endl;
    cout << endl;
    cout << validate_string2(name1) << endl;
    cout << validate_string2(name2) << endl;
    return 0;
}