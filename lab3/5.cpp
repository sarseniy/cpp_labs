#include <iostream>

using namespace std;

int do_some_awesome_work(int* a, int* b) {
	int result = *a + *b;
	return result;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << do_some_awesome_work(&a, &b);
}
