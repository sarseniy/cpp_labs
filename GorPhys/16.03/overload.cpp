#include <iostream>

using namespace std;

void show(int ** array, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
}

void show(int* array, size_t num) {
	for (size_t i = 0; i < num; i++)
	{
		cout << array[i] << ' ';
	}
}

int main() {
	int* a = new int[5];
	for (size_t i = 0; i < 5; i++)
	{
		a[i] = i * i;
	}

	int** b = new int* [6];
	for (size_t i = 0; i < 6; i++)
	{
		b[i] = new int[6];
		for (size_t j = 0; j < 6; j++)
		{
			b[i][j] = i + j;
		}
	}

	show(a, 5);
	cout << endl << endl;
	show(b, 6, 6);

	delete[] a;
	for (size_t i = 0; i < 6; i++)
	{
		delete[] b[i];
	}
	delete[] b;
}