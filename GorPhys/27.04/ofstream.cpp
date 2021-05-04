#include <iostream>
#include <fstream>

using namespace std;

double g(double x)
{
	return x * x;
}

int main() {
	ofstream f;
	f.open("output.txt");
	for (double i = 0; i < 2; i += 0.1)
	{
		f << i << '\t' << g(i) << '\n';
	}
	f.close();
	return 0;
}