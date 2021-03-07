#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class Vector
{
public:
	Vector(std::vector<double> new_data) : Data(new_data)
	{
		Size = Data.size();
	}

	std::vector<double> GetData() {
		return Data;
	}

	int GetSize() {
		return Size;
	}

	void SetData(std::vector<double> new_data)
	{
		Data = new_data;
		Size = Data.size();
	}

	void PrintData() {
		for (double & a: Data)
		{
			std::cout << "* " << a << " *" << '\n';
		}
		std::cout << '\n';
	}

	void Sum(Vector vect) {
		for (int i = 0; i < Size; ++i)
		{
			Data[i] += vect.Data[i];
		}
	}

	void Subtract(Vector vect) {
		for (int i = 0; i < Size; ++i)
		{
			Data[i] -= vect.Data[i];
		}
	}

	double Multiply(Vector vect) {
		double result = 0;
		for (int i = 0; i < Size; ++i)
		{
			result += Data[i] * vect.Data[i];
		}
		return result;
	}

	~Vector() 
	{}

private:
	std::vector<double> Data;
	int Size;
};

class Matrix
{
public:
	Matrix(std::vector<std::vector<double>> new_data) : Data(new_data)
	{
		Size = Data.size();
	}

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

	void Sum(Matrix mtr) {
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				Data[i][j] += mtr.Data[i][j];
			}
		}
	}

	void Subtract(Matrix mtr) {
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				Data[i][j] -= mtr.Data[i][j];
			}
		}
	}

	void Multiply(Matrix mtr) {
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

	~Matrix()
	{}

private:
	std::vector<std::vector<double>> Data;
	int Size;
};

int main() {
	std::string answer;
	std::cout << "Choose test (type \"matrix\" or \"vector\"): ";
	std::cin >> answer;
	if (answer == "vector")
	{
		std::cout << "Vector test" << '\n' << "Enter vector: ";

		std::vector<double> temp;
		double new_value;

		while (std::cin >> new_value)
		{
			temp.push_back(new_value);
		}

		Vector first_vector(temp);
		std::cout << "First vector:\n";
		first_vector.PrintData();

		Vector second_vector(temp);
		std::cout << "Second vector:\n";
		second_vector.PrintData();

		first_vector.Sum(second_vector);
		std::cout << "First vector + second vector:\n";
		first_vector.PrintData();

		std::cout << "Multiply:\n";
		std::cout << first_vector.Multiply(second_vector) << '\n' << '\n';

		second_vector.Subtract(first_vector);
		std::cout << "Second vector - first vector:\n";
		second_vector.PrintData();

	} else if (answer == "matrix") {

		double new_value;
		std::cout << "Matrix test\n\nEnter matrix by rows:\n"; 

		std::vector<double> new_input;

		while (std::cin >> new_value) {
			new_input.push_back(new_value);
		}

		std::vector<std::vector<double>> new_matrix;

		for (int i = 0; i < sqrt(new_input.size()); ++i)
		{
			std::vector<double> tmp;
			new_matrix.push_back(tmp);
			for (int j = 0; j < sqrt(new_input.size()); ++j)
			{
				new_matrix[i].push_back(0);
			}
		}

		for (int i = 0; i < new_input.size(); ++i)
		{
			new_matrix[i / (int)sqrt(new_input.size())][i % (int)sqrt(new_input.size())] = new_input[i];
		}

		Matrix first_matrix(new_matrix);
		std::cout << "First matrix:\n";
		first_matrix.PrintData();

		Matrix second_matrix(new_matrix);
		std::cout << "Second matrix:\n";
		second_matrix.PrintData();

		std::cout << "First matrix + second matrix:\n";
		first_matrix.Sum(second_matrix);
		first_matrix.PrintData();

		std::cout << "First matrix * second matrix:\n";
		first_matrix.Multiply(second_matrix);
		first_matrix.PrintData();
	}
	std::cout << std::endl;
	return 0;
}