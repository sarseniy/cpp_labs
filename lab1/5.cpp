#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string answer = "";
    for (int i = 0; i < n; i++) {
        answer += "*";
    }
    for (int i = 0; i < n; i++) {
        answer.erase(answer.size() - 1);
        cout << answer + "\n";
    }
    return 0;
}
