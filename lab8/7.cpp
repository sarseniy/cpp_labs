#include <iostream>

using namespace std;

double eps = 1e-6;

double find_root(double f(double), double a, double b, double tol=eps) {
	double mid = (b + a) / 2;
	if (f(mid) < tol and f(mid) > -tol)
	{
		return mid;
	}
	if (f(a) < 0)
	{
		if (f(mid) > 0)
		{
			return find_root(f, a, mid, tol);
		}
		if (f(mid) < 0)
		{
			return find_root(f, mid, b, tol);
		}
	}
	if (f(a) > 0)
	{
		if (f(mid) < 0)
		{
			return find_root(f, a, mid, tol);
		}
		if (f(mid) > 0)
		{
			return find_root(f, mid, b, tol);
		}
	}
}

double func(double x) {
	return x*x*x*x*x*x*x + x*x*x*x*x*x + 100*x*x*x*x - 47*x*x*x;
}

int main() {
	cout << find_root(func, 0.2, 1);
	return 0;
}