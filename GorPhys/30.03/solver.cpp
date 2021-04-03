#include <iostream>
#include <vector>

using namespace std;

class Solver
{
public:
	Solver(double c, double T, double L = 1, double N = 100) : c(c), T(T), L(L), N(N)
	{
		h = L / N;
		t = h / c / 2;
		for (double i = 0; i <= L; i += h)
		{
			if (i < 0.2 or i > 0.4)
			{
				U0.push_back(0);
			}
			else
			{
				U0.push_back(1);
			}
		}
	}

	void Solve() {
		vector<vector<double>> tmp(2);
		tmp[0] = U0;
		tmp[1] = U0;

		int t_count = 1;
		for (double current_t = t; current_t <= T; current_t += t)
		{
			int x_count = 0;
			for (double x = 0; x <= L; x += h)
			{
				tmp[t_count % 2][x_count] = tmp[(t_count - 1) % 2][x_count] - (c*t/h) * 
					(tmp[(t_count - 1) % 2][x_count] - ((x_count == 0) ? 0 : tmp[(t_count - 1) % 2][x_count - 1]));
				x_count++;
			}
			t_count++;
		}
		result = tmp[(t_count - 1) % 2];
	}

	vector<double> GetResult() {
		return result;
	}

	~Solver() {

	}

private:
	vector<double> U0;
	vector<double> result = {};

	double h;
	double N;
	double L;

	double t;
	double T;

	double c;

};

int main() {
	Solver solver(0.1, 5);
	solver.Solve();

	vector<double> a;
	a = solver.GetResult();
}