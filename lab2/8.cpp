#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    while (number != 1) {
        for (int i = 2; i <= number; i++) {
            if (number % i == 0) {
                number /= i;
                if (number == 1) {
                    cout << i;
                } else {
                    cout << i << endl;
                }
                break;
            }
        }
    }
    return 0;
}
