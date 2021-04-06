#include <iostream>

using namespace std;

class base
{
protected:
    int b = 7;
};

class derived1 : public base
{};

class derived2 : public derived1
{
private:
    int m = 0;
public:
    void set_m()
    {
        m = b * b;
    }

    void show_m()
    {
        cout << m << '\n';
    }
};

int main() {
    derived2 a;
    a.set_m();
    a.show_m();

    return 0;
}