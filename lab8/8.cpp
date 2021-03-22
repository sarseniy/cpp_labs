#include <iostream>
#include <vector>

using namespace std;

int main() {
	int count;
	cin >> count;

	vector<int> a;
	for (int i = 0; i < count; i++)
	{
		a.push_back(NULL);
		cin >> a[i];
	}

	int min_d = count + 1;
	for (int i = 0; i < count - 1; i++)
	{
		if (a[i] > 0)
		{
			continue;
		}
		int d = 0;
		if (a[i] > 0)
		{
			continue;
		}
		int real_d = count + 1;;
		for (int j = i + 1; j < count; j++)
		{
			d++;
			if (-a[j] == a[i])
			{
				real_d = d;
				break;
			}
			if (a[j] < 0)
			{
				continue;
			}
		}
		if (real_d < min_d)
		{
			min_d = d;
		}
	}
	if (min_d == count + 1)
	{
		cout << 0;
	}
	else
	{
		cout << min_d;
	}
	return 0;
}