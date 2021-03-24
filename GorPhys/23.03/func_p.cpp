#include <iostream>
#include <vector>

using namespace std;

bool decr(int x, int y) {
	return x < y;
}

bool incr(int x, int y) {
	return x > y;
}

void sort(bool (*p)(int x, int y), vector<int>* a) {
	int tmp;
	if (a->size() == 0)
	{
		return;
	}
	for (size_t i = 0; i < a->size() - 1; i++)
	{
		for (size_t j = 0; j < a->size() - i - 1; j++)
		{
			if (p((*a)[j], (*a)[j + 1]))
			{
				tmp = (*a)[j];
				(*a)[j] = (*a)[j + 1];
				(*a)[j + 1] = tmp;
			}
		}
	}
}

int main() {
	vector<int> a = { 8, 6, 4, 7, 2, 1, 3, 5, 9 };
	sort(incr, &a);

	sort(decr, &a);

	return 0;
}