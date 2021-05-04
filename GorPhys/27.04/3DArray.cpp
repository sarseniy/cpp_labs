#include <iostream>

using namespace std;

class ThreeD_Array
{
	int*** Data;
	size_t x;
	size_t y;
	size_t z;
public:
	ThreeD_Array(size_t x1, size_t y1, size_t z1) : x(x1), y(y1), z(z1)
	{
		Data = new int** [x];

		for (size_t i = 0; i < x; i++)
		{
			Data[i] = new int* [y];
			for (size_t j = 0; j < y; j++)
			{
				Data[i][j] = new int[z];
				for (size_t k = 0; k < z; k++)
				{
					Data[i][j][k] = i + j + k;
				}
			}
		}
	}
	ThreeD_Array(const ThreeD_Array& a) : x(a.x), y(a.y), z(a.z)
	{
		Data = new int** [x];

		for (size_t i = 0; i < x; i++)
		{
			Data[i] = new int* [y];
			for (size_t j = 0; j < y; j++)
			{
				Data[i][j] = new int[z];
				for (size_t k = 0; k < z; k++)
				{
					Data[i][j][k] = a.Data[i][j][k];
				}
			}
		}
	}
	void show() 
	{
		for (size_t i = 0; i < x; i++)
		{
			for (size_t j = 0; j < y; j++)
			{
				for (size_t k = 0; k < z; k++)
				{
					cout << Data[i][j][k] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	void change(int x_ind, int y_ind, int z_ind, int val)
	{
		Data[x_ind][y_ind][z_ind] = val;
	}
	~ThreeD_Array()
	{
		for (size_t i = 0; i < x; i++)
		{
			for (size_t j = 0; j < y; j++)
			{
				delete[] Data[i][j];
			}
			delete[] Data[i];
		}
		delete[] Data;
	}
};

int main() {
	ThreeD_Array a(3, 3, 3);
	ThreeD_Array b = a;
	a.show();
	a.change(0, 1, 2, 50);
	a.show();

	b.show();
	b.change(0, 1, 1, 20);
	b.show();
	return 0;
}