#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Client
{
public:
	string name;
	string num;
	int rub;
	Client(string n, string nu, int r) : name(n), num(nu), rub(r)
	{

	}
};

void sort(vector<Client>& a)
{
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		for (size_t j = i + 1; j < a.size(); j++)
		{
			if (a[i].rub < a[j].rub)
			{
				swap(a[i], a[j]);
			}
			else if (a[i].rub == a[j].rub)
			{
				if (a[i].name > a[j].name)
				{
					swap(a[i], a[j]);
				}
				else if (a[i].name == a[j].name)
				{
					if (a[i].num > a[j].num)
					{
						swap(a[i], a[j]);
					}
				}
			}
		}
	}
}

void print(Client f)
{
	cout << f.name << ' ' << f.num << ' ' << f.rub << '\n';
}

int main()
{
	int n;
	cin >> n;
	vector<Client> Data;
	for (size_t i = 0; i < n; i++)
	{
		string m;
		string k;
		int r;
		cin >> m >> k >> r;
		Data.push_back(Client(m, k, r));
	}

	sort(Data);

	for (size_t i = 0; i < 10; i++)
	{
		print(Data[i]);
	}
	
	return 0;
}