#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    float middle;
    middle = (float)sum / (float)n;
    int greater_sum = 0;
    for (int i = 0; i < n; i++) {
        if ((float)a[i] > middle) {
            greater_sum += a[i];
        }
    }
    cout << greater_sum;
    return 0;
}
