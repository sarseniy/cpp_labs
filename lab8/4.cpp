#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Citizen {
	Citizen(string name, bool knight) : name(name), knight(knight)
	{}

	string name;
	bool knight;
};

int main() {
	int count;
	bool news;
	cin >> count >> news;

	string name;
	bool type;

	vector<Citizen> a;

	for (size_t i = 0; i < count; i++)
	{
		cin >> name >> type;
		a.push_back(Citizen(name, type));
	}

	int days;
	cin >> days;
	int i = -1;
	for (int day = 0; day < days; day++)
	{
		i++;
		if (a.size() == 1)
		{
			continue;
		}
		if (a[i % a.size()].knight and news)
		{}
		else if (a[i % a.size()].knight and !news)
		{
			a.erase(a.begin() + i % a.size());
			i--;
		}
		else if (!a[i % a.size()].knight)
		{
			if (!news)
			{
				a[i % a.size()].knight = true;
			}
			news = !news;
		}
	}
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i].knight)
		{
			cout << a[i].name << ' ' << 1 << '\n';
		}
		else
		{
			cout << a[i].name << ' ' << 0 << '\n';
		}
	}
	return 0;
}