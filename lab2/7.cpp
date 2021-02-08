#include <iostream>

using namespace std;

int main() {
    int number;
    bool flag = true;
    cin >> number;
    for (int i = 2; (i * i) <= number; i++) {
        if (number % i == 0) {
            flag = false;
        }
    }
    if (flag) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
