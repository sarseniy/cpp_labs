#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>* a) {
	int tmp;
	if (a->size() == 0)
	{
		return;
	}
	for (size_t i = 0; i < a->size() - 1; i++)
	{
		for (size_t j = 0; j < a->size() - i - 1; j++)
		{
			if ((*a)[j] > (*a)[j + 1])
			{
				tmp = (*a)[j];
				(*a)[j] = (*a)[j + 1];
				(*a)[j + 1] = tmp;
			}
		}
	}
}

void print(vector<int> a) {
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << ' ';
	}
}

int main() {
	vector<int> ch;
	vector<int> nch;

	int tmp;

	while (cin >> tmp)
	{
		if (tmp % 2)
		{
			nch.push_back(tmp);
		}
		else
		{
			ch.push_back(tmp);
		}
	}

	sort(&ch);
	sort(&nch);

	print(ch);
	print(nch);

	return 0;
}