#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    int max_2 = 0;
    while (number != 0) {
        if ((number > max_2) && (number % 2 == 0)) {
            max_2 = number;
        }
        cin >> number;
    }
    cout << max_2;
    return 0;
}
