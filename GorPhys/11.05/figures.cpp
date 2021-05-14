#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Figure
{
public:
	virtual double Perimeter() = 0;

	virtual double Area() = 0;

	virtual string Name() = 0;
};

class Rect : public Figure
{
	double a;
	double b;
public:
	Rect(int a, int b) : a(a), b(b)
	{}

	double Perimeter()
	{
		return a * 2 + b * 2;
	}

	double Area()
	{
		return a * b;
	}

	string Name()
	{
		return "Rect";
	}
};

class Triangle : public Figure
{
	double a;
	double b;
	double c;
public:
	Triangle(double a, double b, double c) : a(a), b(b), c(c)
	{}

	double Perimeter()
	{
		return a + b + c;
	}

	double Area()
	{
		double tmp = this->Perimeter();
		tmp /= 2;
		return sqrt(tmp * (tmp - a) * (tmp - b) * (tmp - c));
	}

	string Name()
	{
		return "Triangle";
	}
};

class Circle : public Figure
{
	double r;
public:
	Circle(double r) : r(r)
	{}

	double Perimeter()
	{
		return 2 * 3.14 * r;
	}

	double Area()
	{
		return 3.14 * r * r;
	}

	string Name()
	{
		return "Circle";
	}
};


int main()
{
	Figure* p = 0;
	int tmp;
	cin >> tmp;
	if (tmp == 1)
	{
		p = new Rect(3, 4);
	}
	else if (tmp == 2)
	{
		p = new Triangle(3, 4, 5);
	}
	else if (tmp == 3)
	{
		p = new Circle(9);
	}
	cout << p->Perimeter() << ' ' << p->Area() << ' ' << p->Name() << '\n';
	delete p;
	return 0;
}
