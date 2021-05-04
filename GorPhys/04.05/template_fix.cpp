#include <iostream>
#include <vector>

using namespace std;

template<class T> void print(vector<T> a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
}

template<class T> void sqr(T& a)
{
	a = a * a;
}

template<class T> vector<T> operator*(vector<T> a, vector<T> b)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = a[i] * b[i];
	}
	return a;
}

int main()
{
	int a = 9;
	sqr(a);
	cout << a << endl;

	vector<int> f(3, 8);
	sqr(f);
	print(f);

	return 0;
}