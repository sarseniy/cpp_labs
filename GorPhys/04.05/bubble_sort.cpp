#include <iostream>
#include <vector>

using namespace std;

template <class T> class Vec
{
	vector<T> a;
public:
	Vec(vector<T> a_t) : a(a_t)
	{};

	void bubble_sort()
	{
		for (size_t i = 1; i < a.size(); i++)
		{
			for (size_t j = 0; j < a.size() - 1; j++)
			{
				if (a[j] > a[i])
				{
					swap(a[i], a[j]);
				}
			}
		}
	}
	template<class T> friend ostream& operator<<(ostream& out, Vec<T> a);
};

template<class Ttype> ostream& operator<<(ostream& out, Vec<Ttype> vec)
{
	for (size_t i = 0; i < vec.a.size(); i++)
	{
		out << vec.a[i] << ' ';
	}
	out << '\n';
	return out;
}

int main()
{
	vector<int> a = { 5, 9, 7, 3, 8 };

	Vec<int> b(a);
	cout << b;
	b.bubble_sort();
	cout << b;

	vector<double> c = { 7.5, 8.8, 3.5, 6.7, 9.2 };
	Vec<double> d(c);
	cout << d;
	d.bubble_sort();
	cout << d;

	return 0;
}