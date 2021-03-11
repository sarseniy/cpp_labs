#include <iostream>
#include <algorithm>

using namespace std;

class Fraction
{
public:
	Fraction(int p, int q) : p(p), q(q) {
		CheckGCD();
	}

	Fraction(int p) : p(p), q(1) {}

	void Set(int new_p, int new_q) {
		p = new_p;
		q = new_q;
		CheckGCD();
	}

	double Get() {
		return p / q;
	}

	void Print() {
		cout << "(" << p << " / " << q << ")";
	}

	bool CheckEqual(Fraction other) {
		if (p == other.p and q == other.q) return true;
		return false;
	}

	void Sum(Fraction other) {
		int new_p;
		int new_q;

		new_q = q * other.q;
		new_p = p * other.q + q * other.p;
		p = new_p;
		q = new_q;
		CheckGCD();
	}

	void Subtract(Fraction other) {
		int new_p;
		int new_q;

		new_q = q * other.q;
		new_p = p * other.q - q * other.p;
		p = new_p;
		q = new_q;
		CheckGCD();
	}

	void Multiply(Fraction other) {
		p *= other.p;
		q *= other.q;
		CheckGCD();
	}

	void Divide(Fraction other) {
		p *= other.q;
		q *= other.p;
		CheckGCD();
	}

	~Fraction() {

	}
private:
	void CheckGCD() {
		if (__gcd(p, q) != 1)
		{
			int tmp = __gcd(p, q);
			p /= tmp;
			q /= tmp;
		}
		if (q < 0)
		{
			p *= -1;
			q *= -1;
		}
	}

	int p;
	int q;
};

int main() {
	Fraction a(-2, -4);

	a.Print();

	Fraction b(38, 76);
	cout << ' ';
	b.Print();

	a.Sum(b);
	cout << '\n';
	a.Print();

	b.Subtract(a);
	cout << '\n';
	b.Print();

	b.Multiply(b);
	cout << '\n';
	b.Print();

	a.Divide(b);
	cout << '\n';
	a.Print();

	b.Set(4, 1);

	cout << endl << a.CheckEqual(b);

	cout << endl;
	return 0;
}