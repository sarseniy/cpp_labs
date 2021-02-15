#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n += 2;
    m += 2;
    int **a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int [m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    int num, x, y;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        a[x][y] = -1;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if ((a[i + dx][j + dy] == -1) && (a[i][j] != -1)) {
                        a[i][j] += 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (j == m - 2) {
                cout << a[i][j];
            }
            else {
                cout << a[i][j] << ' ';
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        delete [] a[i];
    }
    delete [] a;
    return 0;
}
