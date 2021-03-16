#include <iostream>

using namespace std;

class Vector
{
private:
	double x;
	double y;
	double z;
public:
	Vector(double x, double y, double z) : x(x), y(y), z(z)
	{}

	Vector operator+ (Vector other) {
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	Vector operator- (Vector other) {
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	double operator* (Vector other) {
		return x * other.x + y * other.y + z * other.z;
	}

	friend ostream& operator<< (ostream& out, const Vector vect) {
		return out << "Vector(" << vect.x << ", " << vect.y << ", " << vect.z << ")\n";
	}
};

struct SubVector
{
	double x;
	double y;
	double z;

	SubVector(double x, double y, double z) : x(x), y(y), z(z) {}
};

SubVector operator+ (SubVector first, SubVector second) {
	return SubVector(first.x + second.x, first.y + second.y, first.z + second.z);
}

SubVector operator- (SubVector first, SubVector second) {
	return SubVector(first.x - second.x, first.y - second.y, first.z - second.z);
}

double operator* (SubVector first, SubVector second) {
	return first.x * second.x + first.y * second.y + first.z * second.z;
}

int main() {
	Vector a(3, 4, 5);
	Vector b(6, 7, 8);
	cout << a;
	cout << a + b;
	cout << a * b;
}