#include <iostream>
#include <algorithm>

using namespace std;

class Fraction
{
public:
	Fraction() {}

	Fraction(int p) : p(p), q(1) {
		CheckGCD();
	}

	Fraction(int p, int q) : p(p), q(q) {
		CheckGCD();
	}

	void Set(int new_p, int new_q) {
		p = new_p;
		q = new_q;
		CheckGCD();
	}

	double Get() {
		CheckGCD();
		return p / q;
	}

	bool operator== (Fraction other) {
		CheckGCD();
		if (p == other.p and q == other.q) return true;
		return false;
	}

	bool operator== (int value) {
		CheckGCD();
		Fraction other(value);
		if (p == other.p and q == other.q) return true;
		return false;
	}

	Fraction operator+ (Fraction other) {
		CheckGCD();
		return Fraction(p * other.q + q * other.p, q * other.q);
	}

	Fraction operator+ (int other) {
		CheckGCD();
		Fraction tmp(other);
		return *this + tmp;
	}

	void operator+= (Fraction other) {
		int new_p;
		int new_q;

		new_q = q * other.q;
		new_p = p * other.q + q * other.p;
		p = new_p;
		q = new_q;
		CheckGCD();
	}

	void operator+= (int value) {
		CheckGCD();
		Fraction other(value);
		return *this += other;
	}

	Fraction operator- (Fraction other) {
		CheckGCD();
		return Fraction(p * other.q - q * other.p, q * other.q);
	}

	Fraction operator- (int value) {
		CheckGCD();
		Fraction tmp(value);
		return *this - tmp;
	}

	void operator-= (Fraction other) {
		int new_p;
		int new_q;

		new_q = q * other.q;
		new_p = p * other.q - q * other.p;
		p = new_p;
		q = new_q;
		CheckGCD();
	}

	void operator-= (int value) {
		CheckGCD();
		Fraction tmp(value);
		return *this -= tmp;
	}

	Fraction operator* (Fraction other) {
		CheckGCD();
		return Fraction(p * other.p, q * other.q);
	}

	Fraction operator* (int value) {
		CheckGCD();
		Fraction tmp(value);
		return *this * tmp;
	}

	Fraction operator/ (Fraction other) {
		CheckGCD();
		return Fraction(p * other.q, q * other.p);
	}

	Fraction operator/ (int value) {
		CheckGCD();
		Fraction tmp(value);
		return *this / tmp;
	}

	void operator*= (Fraction other) {
		p *= other.p;
		q *= other.q;
		CheckGCD();
	}

	void operator*= (int value) {
		CheckGCD();
		Fraction tmp(value);
		return *this *= tmp;
	}

	void operator/= (Fraction other) {
		p *= other.q;
		q *= other.p;
		CheckGCD();
	}

	void operator/= (int value) {
		CheckGCD();
		Fraction tmp(value);
		return *this /= tmp;
	}

	friend istream& operator>> (istream& str, Fraction& fract) {
		return str >> fract.p >> fract.q;
	}

	friend ostream& operator<< (ostream& str, Fraction& fract) {
		fract.CheckGCD();
		return str << "( " << fract.p << " / " << fract.q << " )";
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
	Fraction a;
	Fraction b;
	cin >> a >> b;
	cout << (a == b) << endl;
	cout << a << endl;
	a = a + 1;
	cout << a << endl;
	a *= 3;
	cout << a << endl;
	a /= 7;
	cout << a << endl;
	a -= 1;
	cout << a << endl;
	a *= b;
	cout << a << endl;
	a /= -15;
	cout << a << endl;
}