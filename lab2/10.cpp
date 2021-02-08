#include <iostream>

using namespace std;

int main() {
    string answer;
    string sub_answer;
    int number;
    int ost;
    cin >> number;
    while (number != 0) {
        sub_answer = "";
        ost = number % 60;
        sub_answer.append(ost / 10, '<');
        sub_answer.append(ost % 10, 'v');
        number /= 60;
        if (number != 0) {
            answer.insert(0,"." + sub_answer);
        } else {
            answer.insert(0, sub_answer);
        }
    }
    cout << answer;
    return 0;
}
