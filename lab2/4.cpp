#include <iostream>

using namespace std;

int main() {
    bool flag = false;
    int number;
    cin >> number;
    for (int i = 1; i <= number; i *= 2) {
        if (i == number) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
