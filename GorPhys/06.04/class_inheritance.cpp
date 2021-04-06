#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
public:
    void set_wheels(int wh)
    {
        wheels = wh;
    }
    void set_passengers(int pass)
    {
        passengers = pass;
    }

    int get_wheels()
    {
        return wheels;
    }

    int get_passengers()
    {
        return passengers;
    }

private:
    int wheels;
    int passengers;
};

class Truck : public Vehicle
{
public:
    void set_cargo(int c)
    {
        cargo = c;
    }

    int get_cargo()
    {
        return cargo;
    }

    void show()
    {
        cout << get_wheels() << ' ' << get_passengers() << ' ' << get_cargo() << '\n';
    }

private:
    int cargo;
};

class Automobile : public Vehicle
{
public:
    void set_type(string c)
    {
        type = c;
    }

    string get_type()
    {
        return type;
    }

    void show()
    {
        cout << get_wheels() << ' ' << get_passengers() << ' ' << get_type() << '\n';
    }

private:
    string type;
};

int main() {
    Truck a;
    Automobile b;

    a.set_wheels(8);
    a.set_passengers(1);
    a.set_cargo(15000);

    b.set_wheels(4);
    b.set_passengers(3);
    b.set_type("Nissan");

    a.show();
    b.show();

    return 0;
}