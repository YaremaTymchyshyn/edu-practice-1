#include <iostream>
using namespace std;

class Car
{
public:
	void Drive()
	{
		cout << "*driving*" << endl;
	}
};

class Plane
{
public:
	void Fly()
	{
		cout << "*flying*" << endl;
	}
};

class Ship
{
public:
	void Sail()
	{
		cout << "*sailing*" << endl;
	}
};

class FlyingCar : public Car, public Plane {};

class Amphibian : public Ship, public Car {};

int main()
{
	FlyingCar fc;
	fc.Drive();
	fc.Fly();

	cout << endl;

	Amphibian a;
	a.Drive();
	a.Sail();
}