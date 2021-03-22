#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getDigit(int x, int digit) {
	return (int) (x / pow(10, digit)) % 10;
}

void print(vector<vector<int>> table) {
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < table[i].size(); j++)
		{
			cout << table[i][j] << ' ';
		}
	}
	cout << endl;
}

int main() {
	vector<int> a;

	int tmp;

	while (cin >> tmp)
	{
		a.push_back(tmp);
	}

	vector<vector<int>> table(2);

	for (size_t i = 0; i < a.size(); i++)
	{
		if (getDigit(a[i], 0) == 0)
		{
			table[0].push_back(a[i]);
		}
		else
		{
			table[1].push_back(a[i]);
		}
	}
	print(table);
	int digit = 0;
	while (!table[1].empty())
	{
		bool f = false;
		digit++;
		vector<vector<int>> tmp(2);
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < table[i].size(); j++)
			{
				if (getDigit(table[i][j], digit) == 0)
				{
					tmp[0].push_back(table[i][j]);
				}
				else
				{
					tmp[1].push_back(table[i][j]);
				}
				if (table[i][j] >= pow(10, digit))
				{
					f = true;
				}
			}
		}
		table = tmp;
		if (!f)
		{
			continue;
		}
		print(table);
	}

	return 0;
}