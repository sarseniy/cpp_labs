#include <iostream>

using namespace std;

class base1
{
public:
	base1()
	{
		cout << "base1 was created" << endl;
	}

	~base1()
	{
		cout << "base1 was destroyed" << endl;
	}
};

class base2
{
public:
	base2()
	{
		cout << "base2 was created" << endl;
	}

	~base2()
	{
		cout << "base2 was destroyed" << endl;
	}
};

class base3
{
public:
	base3()
	{
		cout << "base3 was created" << endl;
	}

	~base3()
	{
		cout << "base3 was destroyed" << endl;
	}
};

class derived : public base2, public base3, public base1
{
public:
	derived()
	{
		cout << "derived was created" << endl;
	}

	~derived()
	{
		cout << "derived was destroyed" << endl;
	}
};

int main()
{
	derived a;
}