#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int max = 0;
    int number;
    cin >> number;
    while (number != 0) {
        if (number >= max) {
            if (number > max) {
                max = number;
                count = 1;
            } else {
                count++;
            }
        }
        cin >> number;
    }
    cout << count;
    return 0;
}
