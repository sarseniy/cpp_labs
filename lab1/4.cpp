#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string answer = "";
    for (int i = 0; i < n; i++) {
        answer += "*";
        cout << answer + "\n";
    }
    return 0;
}
