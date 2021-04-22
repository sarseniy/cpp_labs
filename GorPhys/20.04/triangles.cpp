#include <iostream>
#include <string>

using namespace std;

class TwoDShape
{
protected:
	int width;
	int height;
public:
	TwoDShape(int width, int height) : width(width), height(height)
	{}

	void show2D()
	{
		cout << "Name: TwoDShape; width: " << width << "; height: " << height << ";\n";
	}
};

class Triangle : public TwoDShape
{
protected:
	string style;
public:
	Triangle(int width, int height, string style) : TwoDShape(width, height), style(style)
	{}

	void showTriangle()
	{
		cout << "Name: Triangle; width: " << width << "; height: " << height << "; style: " << style << ";\n";
	}
};

class ColorTriangle : public Triangle
{
protected:
	string color;
public:
	ColorTriangle(int width, int height, string style, string color) : Triangle(width, height, style), color(color)
	{}
	void showColorTriangle()
	{
		cout << "Name: ColoredTriangle; width: " << width << "; height: " << height << "; style: " << style << "; color: " << color << ";\n";
	}
};

int main()
{
	TwoDShape two_d(4, 5);
	Triangle my_triangle(4, 5, "isosceles");
	ColorTriangle colored_triangle(4, 5, "isosceles", "red");

	two_d.show2D();
	my_triangle.showTriangle();
	colored_triangle.showColorTriangle();
}