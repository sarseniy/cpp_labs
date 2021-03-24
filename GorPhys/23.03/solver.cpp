#include <iostream>
#include <vector>

using namespace std;

class Solver
{
public:
	Solver() {
		for (size_t i = 0; i < 2; i++)
		{
			vector<double> tmp;
			solution.push_back(tmp);
			for (size_t j = 0; j < 11; j++)
			{
				if (!i)
				{
					solution[i].push_back((double)j / 10);
				}
				else
				{
					solution[i].push_back(f_0);
				}
			}
		}
	}
	void Solve() {
		double y = f_0;
		for (double x = 1; x < 11; x += 1)
		{
			solution[1][x] = solution[1][x - 1] + h * func(solution[0][x - 1], solution[1][x - 1]);
		}
	}

private:
	double func(double x, double y) {
		return x * x - 2*y;
	}
	double h = 0.1;
	double start = 0;
	double end = 1;
	double f_0 = 1;
	vector<vector<double>> solution;
};

int main() {
	Solver mine;
	mine.Solve();

	return 0;
}