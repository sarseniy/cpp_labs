#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void print(const vector<double>& vec) {
	cout.setf(ios::fixed);
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << fixed << setprecision(3) << vec[i] << ' ';
	}
	cout << endl;
}

class Scheme
{
protected:
	double h;
	double N;
	double L;

	double t;
	double T;

	double c;
};

class CIR: public Scheme
{
public:
	CIR(double c0, double T0, double L0 = 1, double N0 = 100)
	{
		c = c0;
		T = T0;
		L = L0;
		N = N0;
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
				tmp[t_count % 2][x_count] = tmp[(t_count - 1) % 2][x_count] - (c * t / h) *
					(tmp[(t_count - 1) % 2][x_count] - ((x_count == 0) ? 0 : tmp[(t_count - 1) % 2][x_count - 1]));
				x_count++;
			}
			print(tmp[t_count % 2]);
			t_count++;
		}
		result = tmp[(t_count - 1) % 2];
	}

	vector<double> GetResult() {
		return result;
	}

private:
	vector<double> U0;
	vector<double> result = {};

};

int main() {
	CIR solver(0.1, 5);
	solver.Solve();

	vector<double> a;
	a = solver.GetResult();
}