// Multitasking01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <future>
#include <mutex> 
#include <condition_variable>
#include <iostream>

using namespace std;
mutex mut1;
condition_variable con_var;


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
		cout << endl;

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


void thread1()
{
	Area*p;
	addition a(5.0, 1.4);
	p = &a;
	p->show_area();
	cout << endl;
	con_var.notify_one();

}

void thread2()
{
	Area*p;
	subtraction s(4.5, 0.5);
	p = &s;
	p->show_area();
	cout << endl;
	unique_lock<mutex> lock(mut1);
	con_var.wait(lock);


}

void thread3()
{
	Area*p;
	multiplication m(3.1, 2.8);
	p = &m;
	p->show_area();
	cout << endl;
	unique_lock<mutex> lock(mut1);
	con_var.wait(lock);
} 


void main()
{
	auto f1 = async(launch::async, thread1);
	auto f2 = async(launch::async, thread2);
	auto f3 = async(launch::async, thread3);
	system("pause");
}

