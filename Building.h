#pragma once
#include <string>
#include < iostream>
using namespace std;
class Build
{
	private:
		string color;
		string floor;
		string number;
		string area;
		string address;
		string year;
public:
	Build() : color(""), floor(""), number(""), area(""), address(""), year("") {}
	~Build(){}

	void set_color(string c) { color = c; }
	void set_floor(string f) { floor = f; }
	void set_number(string n) { number = n; }
	void set_area(string a) { area = a; }
	void set_address(string ad) { address = ad; }
	void set_year(string y) { year = y; }

	string get_color() { return color ; }
	string get_floor() { return floor ; }
	string get_number() { return number ; }
	string get_area() { return area ; }
	string get_address() { return address ; }
	string get_year() { return year; }

	virtual void modify(int ch, string inf);

	virtual void set_inf();
	virtual void show_inf();
	virtual void write_inf();

	

	virtual void house() = 0;  
	virtual int Gethouse() = 0; 
	virtual string House() = 0;
};