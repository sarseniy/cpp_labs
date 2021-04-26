#include <iostream>
#include <vector>

using namespace std;

/*
d0[i] -- колличество i-значных чисел, оканчивающихся на 0. (d0[1] = 0, т.к. число не должно начинаться на 0)
d[i] -- колличество i-значных чисел, НЕ оканчивающихся на 0. (d[1] = k - 1)
Тогда очевидно, что d[i] = (d0[i - 1] + d[i - 1]) * (k - 1);
					d0[i] = d[i - 1];
В итоге колличество возможных чисел будет равно d[n] + d0[n].
*/

int main() {
	int n;
	int k;
	
	cin >> n >> k;
	vector<int> d(n + 1);
	vector<int> d0(n + 1);

	d0[1] = 0;
	d[1] = k - 1;
	for (int i = 2; i < n + 1; i++)
	{
		d[i] = (d[i - 1] + d0[i - 1]) * (k - 1);
		d0[i] = d[i - 1];
	}
	cout << d[n] + d0[n];
	return 0;
}