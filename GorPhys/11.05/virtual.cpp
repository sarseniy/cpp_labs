#include <iostream>

using namespace std;

class Base
{
public:
	virtual void show()
	{
		cout << "It's Base" << '\n';
	}
};

class First_d : public Base
{
public:
	void show()
	{
		cout << "It's First_d" << '\n';
	}
};

class Second_d : public First_d
{};

int main()
{
	Base Base_obj;
	First_d First_obj;
	Second_d Second_obj;

	Base* Base_p = &Base_obj;
	Base_p->show();

	Base_p = &First_obj;
	Base_p->show();

	Base_p = &Second_obj;
	Base_p->show();

	return 0;
}