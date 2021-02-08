#include <iostream>
#include <string>

using namespace std;

int main() {
    int speed;
    string num;
    int salary = 0;
    cin >> speed >> num;
    while (num != "A999AA") {
        if (speed > 60) {
            if ((num[1] == num[2]) && (num[2] == num[3])) {
                salary += 1000;
            } else if ((num[1] == num[2]) || (num[2] == num[3]) || (num[1] == num[3])) {
                salary += 500;
            } else {
                salary += 100;
            }
        }
        cin >> speed >> num;
    }
    cout << salary;
    return 0;
}
