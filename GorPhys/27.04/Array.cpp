#include <iostream>

using namespace std;

class Array
{
	int* Data;
	size_t Size;
public:
	Array(int Size) : Size(Size)
	{
		Data = new int[Size];
		for (size_t i = 0; i < Size; i++)
		{
			Data[i] = i;
		}
	}
	Array(const Array& a) : Size(a.Size)
	{
		Data = new int[a.Size];
		for (size_t i = 0; i < Size; i++)
		{
			Data[i] = a.Data[i];
		}
	}
	void show() 
	{
		for (size_t i = 0; i < Size; i++)
		{
			cout << Data[i] << ' ';
		}
		cout << '\n';
	}
	void change(int ind, int val)
	{
		Data[ind] = val;
	}
	~Array()
	{
		delete[] Data;
	}
};

int main() {
	Array a(5);
	a.show();
	a.change(1, 50);
	a.show();
	return 0;
}