#include <iostream>

using namespace std;

class arr
{
public:
	arr(size_t size) : Size(size) {
		int *** tmp = new int** [Size];
		int input;

		for (int i = 0; i < Size; ++i)
		{
			tmp[i] = new int* [Size];
			for (int j = 0; j < Size; ++j)
			{
				tmp[i][j] = new int [Size];
				for (int k = 0; k < Size; ++k)
				{
					cin >> input;
					tmp[i][j][k] = input;
				}
			}
		}

		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				for (int k = 0; k < Size; ++k)
				{
				
				}
			}
		}
		Data = tmp;
	}

	void Print() {
		cout << endl;
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				for (int t = 0; t < Size; ++t)
				{
					cout << Data[i][j][t] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}

	~arr() {
		for (int i = 0; i < Size; ++i)
		{
			for (int j = 0; j < Size; ++j)
			{
				delete [] Data[i][j];
			}
			delete [] Data[i];
		}
		delete [] Data;
	}
private:
	int *** Data;
	size_t Size;
};

int main() {
	arr a(2);
	a.Print();
	return 0;
}