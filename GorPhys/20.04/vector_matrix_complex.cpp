#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class mySize
{
protected:
	int Size;
public:
	mySize(int size) : Size(size)
	{}
};

class Matrix : public mySize
{
public:
	Matrix() : mySize(5)
	{
		std::vector<std::vector<double>> a(5, std::vector<double>(5, 0));
		Data = a;
	}

	Matrix(std::vector<std::vector<double>> new_data, int size) : Data(new_data), mySize(size)
	{}

	void SetData(std::vector<std::vector<double>> new_data) {
		Data = new_data;
		Size = Data.size();
	}

	int GetSize() {
		return Size;
	}

	std::vector<std::vector<double>> GetData() {
		return Data;
	}

	void PrintData() {
		for (int i = 0; i < Size; ++i)
		{
			std::cout << "* ";
			for (int j = 0; j < Size; ++j)
			{
				std::cout << Data[i][j] << ' ';
			}
			std::cout << "*\n";
		}
	}

	void operator+=(Matrix mtr) {
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				Data[i][j] += mtr.Data[i][j];
			}
		}
	}

	Matrix operator+(Matrix mtr) {
		Matrix tmp = *this;
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				tmp.Data[i][j] += mtr.Data[i][j];
			}
		}
		return tmp;
	}

	void operator-=(Matrix mtr) {
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				Data[i][j] -= mtr.Data[i][j];
			}
		}
	}

	Matrix operator-(Matrix mtr) {
		Matrix tmp = *this;
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				tmp.Data[i][j] -= mtr.Data[i][j];
			}
		}
		return tmp;
	}

	void operator*=(Matrix mtr) {
		Matrix OldMatrix = *this;
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				double tmp = 0;
				for (int k = 0; k < Size; ++k)
				{
					tmp += OldMatrix.Data[i][k] * mtr.Data[k][j];
				}
				Data[i][j] = tmp;
			}
		}
	}

	Matrix operator*(Matrix mtr) {
		Matrix OldMatrix = *this;
		Matrix result = *this;
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				double tmp = 0;
				for (int k = 0; k < Size; ++k)
				{
					tmp += OldMatrix.Data[i][k] * mtr.Data[k][j];
				}
				result.Data[i][j] = tmp;
			}
		}
		return result;
	}

	Matrix operator*(double n) {
		Matrix tmp = *this;
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				tmp.Data[i][j] *= n;
			}
		}
		return tmp;
	}

	void operator*=(double n) {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				Data[i][j] *= n;
			}
		}
	}

	~Matrix()
	{}

protected:
	std::vector<std::vector<double>> Data;
};

class Vector : public Matrix
{
public:
	Vector() : Matrix()
	{
		for (size_t i = 1; i < Size; i++)
		{
			Data.pop_back();
		}
	}

	Vector(std::vector<double> new_data, int size) : Matrix(std::vector<std::vector<double>>(size, new_data), size)
	{
		for (size_t i = 1; i < Size; i++)
		{
			Data.pop_back();
		}
	}

	std::vector<double> GetData() {
		return Data[0];
	}

	int GetSize() {
		return Size;
	}

	void SetData(std::vector<double> new_data)
	{
		Data[0] = new_data;
		Size = Data.size();
	}

	void PrintData() {
		for (double& a : Data[0])
		{
			std::cout << "* " << a << " *" << '\n';
		}
		std::cout << '\n';
	}

	void operator+=(Vector vect) {
		for (int i = 0; i < Size; ++i)
		{
			Data[0][i] += vect.Data[0][i];
		}
	}

	Vector operator+(Vector vect) {
		Vector tmp = *this;
		for (size_t i = 0; i < Size; i++)
		{
			tmp.Data[0][i] += vect.Data[0][i];
		}
		return tmp;
	}

	void operator-=(Vector vect) {
		for (int i = 0; i < Size; ++i)
		{
			Data[0][i] -= vect.Data[0][i];
		}
	}

	Vector operator-(Vector vect) {
		Vector tmp = *this;
		for (size_t i = 0; i < Size; i++)
		{
			tmp.Data[0][i] -= vect.Data[0][i];
		}
		return tmp;
	}

	double operator*(Vector vect) {
		double result = 0;
		for (int i = 0; i < Size; ++i)
		{
			result += Data[0][i] * vect.Data[0][i];
		}
		return result;
	}

	Vector operator*(double n) {
		Vector tmp = *this;
		for (int i = 0; i < Size; ++i)
		{
			tmp.Data[0][i] *= n;
		}
		return tmp;
	}

	void operator*=(double n) {
		for (int i = 0; i < Size; ++i)
		{
			Data[0][i] *= n;
		}
	}

	~Vector()
	{}
};

int main() {

	std::vector<double> a;
	for (size_t i = 0; i < 5; i++)
	{
		a.push_back(i * i);
	}
	Vector first(a, a.size());


	std::vector<std::vector<double>> b;
	for (int i = 0; i < 5; i++)
	{
		std::vector<double> tmp;
		b.push_back(tmp);
		for (int j = 0; j < 5; j++)
		{
			b[i].push_back(i * j);
		}
	}

	Matrix second(b, b.size());

	Vector third;
	third = first * 2;

	third.PrintData();
	first.PrintData();
}