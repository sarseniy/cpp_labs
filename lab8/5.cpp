#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<vector<int>> a;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		vector<int> x;
		a.push_back(x);
		for (size_t j = 0; j < n; j++)
		{
			a[i].push_back(NULL);
			cin >> a[i][j];
		}
	}
	vector<vector<int>> res = a;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			res[j][n - i - 1] = a[i][j];
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}