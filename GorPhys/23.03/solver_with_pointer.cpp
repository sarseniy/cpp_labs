#include <iostream>
#include <vector>

typedef double (*f_p)(double, double);

using namespace std;

class Solver
{
public:
	Solver(f_p p, double f_0, double start = 0, double end = 1, double h = 0.1) : func(p), f_0(f_0), start(start), end(end), h(h)
	{
		for (size_t i = 0; i < 2; i++)
		{
			vector<double> tmp;
			solution.push_back(tmp);
			for (double j = start; j < end; j += h)
			{
				if (!i)
				{
					solution[i].push_back(j);
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
	f_p func;
	double h;
	double start;
	double end ;
	double f_0;
	vector<vector<double>> solution;
};

double f_1(double x, double y) {
	return 9 * x * x - y;
}

double f_2(double x, double y) {
	return x * x - 2 * y;
}

int main() {
	Solver a(f_1, 1);
	Solver b(f_2, 1);

	a.Solve();
	b.Solve();

	return 0;
}