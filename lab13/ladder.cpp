#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	a[0] = -1001;
	for (size_t i = 1; i < n + 1; i++)
	{
		cin >> a[i];
	}

	vector<int> ways(n + 1, 0);

	vector<int> d(n + 1, 0);
	d[0] = 0;
	d[1] = a[1];
	for (int i = 2; i < n + 1; i++)
	{
		if (d[i-1] > d[i-2])
		{
			d[i] = d[i - 1] + a[i];
			ways[i] = i - 1;
		}
		else
		{
			d[i] = d[i - 2] + a[i];
			ways[i] = i - 2;

		}
	}
	cout << d[n] << '\n';

	vector<int> way;
	way.push_back(n);
	int k = n;
	while (k > 1)
	{
		way.push_back(ways[k]);
		k = ways[k];
	}

	for (int i = way.size() - 1; i >= 0; i--)
	{
		cout << way[i] << ' ';
	}
	return 0;
}