#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int tmp;
	vector<int> a;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp % 4 == 0 and !(tmp / 1000 == 4 or tmp / 1000 == 5))
		{
			a.push_back(tmp);
		}
		else if (tmp % 7 == 0 and !(tmp / 1000 == 7 or tmp / 1000 == 1))
		{
			a.push_back(tmp);
		}
		else if (tmp % 9 == 0 and !(tmp / 1000 == 9 or tmp / 1000 == 8))
		{
			a.push_back(tmp);
		}
	}
	if (a.empty())
	{
		cout << 0;
	}
	else
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			cout << a[i] << endl;
		}
	}
}