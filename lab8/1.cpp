#include <iostream>

using namespace std;

int main() {
	int a;
	int b;
	int c;
	int d;
	int x;
	cin >> a >> b >> c >> d >> x;
	
	bool f1;
	bool f2;

	f1 = (a + x == b);
	f2 = (c * x == d);

	if (f1 and f2)
	{
		cout << 5;
	}
	else if (f1 or f2)
	{
		cout << 4;
	}
	else if (x == 1024) 
	{
		cout << 3;
	}
	else
	{
		cout << 2;
	}
	return 0;
}