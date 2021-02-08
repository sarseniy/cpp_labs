#include <iostream>

using namespace std;

int main() {
    int a;
    int count = 0;
    cin >> a;
    while (a != 0) {
        if (a % 2 == 0) {
            count++;
        }
        cin >> a;
    }
    cout << count;
    return 0;
}
