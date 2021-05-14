#include <iostream>
#include <vector>

using namespace std;

class Ascillation
{
public:
	int frequency;
	int number;
	Ascillation(int f, int n) : frequency(f), number(n)
	{

	}
	bool Check(Ascillation second, Ascillation third)
	{
		if ((frequency + second.frequency == third.frequency) and (number + second.number == third.number))
		{
			return true;
		}
		if ((frequency + third.frequency == second.frequency) and (number + third.number == second.number))
		{
			return true;
		}
		if ((second.frequency + third.frequency == frequency) and (second.number + third.number == number))
		{
			return true;
		}
		return false;
	}
};

void sort(vector<Ascillation>& a)
{
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		for (size_t j = 0; j < a.size(); j++)
		{
			if (a[i].frequency > a[j].frequency)
			{
				swap(a[i], a[j]);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<Ascillation> Data;
	for (size_t i = 0; i < n; i++)
	{
		int m, k;
		cin >> m >> k;
		Data.push_back(Ascillation(m, k));
	}

	sort(Data);
	bool f = false;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				if (Data[i].frequency + Data[j].frequency < Data[k].frequency)
				{
					break;
				}
				else if (Data[i].frequency + Data[j].frequency > Data[k].frequency)
				{
					continue;
				}
				else if (Data[i].Check(Data[j], Data[k]))
				{
					f = true;
					break;
				}
			}
			if (f)
			{
				break;
			}
		}
		if (f)
		{
			break;
		}
	}


	//bool f = false;
	/*for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			for (size_t k = j + 1; k < n; k++)
			{
				if (Data[i].Check(Data[j], Data[k]))
				{
					f = true;
					break;
				}
			}
		}
	}
	if (f)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}*/
	if (f)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}