#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(string& a, string& b) {
	if (a.size() > b.size())
	{
		return false;
	}
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

int main() {
	int m;
	cin >> m;
	vector<string> data(m);
	for (size_t i = 0; i < m; i++)
	{
		cin >> data[i];
	}

	vector<int> d(m);

	for (int i = 0; i < m; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (compare(data[j], data[i]))
			{
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int res = d[0];
	for (size_t i = 0; i < m; i++)
	{
		res = max(res, d[i]);
	}
	cout << res;
	return 0;
}