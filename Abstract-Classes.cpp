// Abstract-Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
using namespace std;

class Area
{
protected:
	double first;
	double second;
public:
	Area(double x, double y);
	double Get_x() { return first; }
	double Get_y() { return second; }
	virtual void show_area() = 0;
	~Area()
	{
		delete &first, &second;
	}
	Area & operator = (Area & op2)
	{
		first = op2.Get_x();
		second = op2.Get_y();
		return*this;
	}
};
Area::Area(double x, double y)
{
	first = x;
	second = y;
}

class addition :public Area {
public:

	addition(double x, double y);
	void show_area() {
		cout << "The mathematical expression ";
		cout << first << " + " << second;
		cout << " = ";
		cout << first + second << ".\n";
	}
};

addition::addition(double x, double y) :Area(x, y) {}

class subtraction :public Area {
public:

	subtraction(double x, double y);
	void show_area() {
		cout << "The mathematical expression ";
		cout << first << " - " << second;
		cout << " = ";
		cout << first - second << ".\n";
	}
};

subtraction::subtraction(double x, double y) :Area(x, y) {}

class multiplication :public Area {
public:

	multiplication(double x, double y);
	void show_area() {
		cout << "The mathematical expression ";
		cout << first << " * " << second;
		cout << " = ";
		cout << first*second << ".\n";
	}
};

multiplication::multiplication(double x, double y) :Area(x, y) {}

int main()
{
	Area*p;
	addition a(5.0, 1.4);
	subtraction s(4.5, 0.5);
	multiplication m(3.1, 2.8);
	p = &a;
	p->show_area();
	p = &s;
	p->show_area();
	p = &m;
	p->show_area();

	system("pause");
	return 0;
}

