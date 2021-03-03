#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
	void SetName(string name) {
		Name = name;
	}

	void SetMarks(vector<int> new_marks) {
		Marks = new_marks;
		RefreshAverageMark();
	}

	string GetName() {
		return Name;
	}

	vector<int> GetMarks() {
		return Marks;
	}

	double GetAverageMark() {
		return AverageMark;
	}


private:
	void RefreshAverageMark() {
		int t = 0;
		for (int & a : Marks)
		{
			t += a;
		}
		AverageMark = t / Marks.size();
	}

	string Name;
	vector <int> Marks;
	double AverageMark;
};

int main()
{
	Student first;
	first.SetName("Vlad");
	first.SetMarks({0, 1, 2, 3, 4});
	cout << first.GetName() << ' ' << first.GetAverageMark() << endl;

	vector<Student> Students;
	for (int i = 0; i < 3; ++i)
	{
		Student tmp;
		Students.push_back(tmp);

		string new_name;
		cin >> new_name;
		Students[i].SetName(new_name);

		vector<int> t;
		for (int j = 0; j < 5; ++j)
		{
			int new_mark;
			cin >> new_mark;
			t.push_back(new_mark);
		}
		Students[i].SetMarks(t);
	}

	return 0;
}