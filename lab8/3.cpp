#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double count = 0;
	double tmp;
	double xSum = 0;
	double x2Sum = 0;
	cin >> tmp;
	while (tmp)
	{
		xSum += tmp;
		x2Sum += tmp * tmp;
		count++;
		cin >> tmp;
	}
	double M = xSum / count;
	double D = x2Sum / count - (xSum / count) * (xSum / count);
	cout << fixed << setprecision(3) << M << ' ' << D;
}