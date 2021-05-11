#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T> class Stack
{
	vector<T> a;
public:
	Stack(vector<T> a_t) : a(a_t)
	{};

	T pop()
	{
		T tmp;
		tmp = a.back();
		a.pop_back();
		return tmp;
	}

	void push(T elem)
	{
		a.push_back(elem);
	}

	T pick()
	{
		return a.back();
	}


	template<class T> friend ostream& operator<<(ostream& out, Stack<T> a);
};

template<class Ttype> ostream& operator<<(ostream& out, Stack<Ttype> vec)
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
	Stack<int> a = vector<int>{ 1, 2, 3 };
	cout << a;
	cout << a.pop() << '\n';
	cout << a;
	a.push(12);
	cout << a.pick() << '\n';
	cout << a;

	cout << '\n';

	Stack<double> b = vector<double>{ 1.7, 2.2, 3.8 };
	cout << b;
	cout << b.pop() << '\n';
	cout << b;
	b.push(12.12);
	cout << b.pick() << '\n';
	cout << b;

	cout << '\n';

	Stack<string> c = vector<string>{ "Hello,", "world", "!!!" };
	cout << c;
	cout << c.pop() << '\n';
	cout << c;
	c.push("?");
	cout << c.pick() << '\n';
	cout << c;

	return 0;
}