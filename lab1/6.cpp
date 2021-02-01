#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string answer = "";
    for (int i = 0; i < n; i += 2) {
        answer = "";
        for (int j = 0; j < n; j++){
            if ((j < i/2) || (j >= n - i/2)) {
                answer += " ";
            } else {
                answer += "*";
            }
        }
        cout << answer + "\n";
    }
}
