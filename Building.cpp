#include "stdafx.h"
#include "Building.h"
#include "Brick.h"
#include "Cottage.h"
#include "Monolithic.h"
#include "Panel.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "Fabrica.h"
#include <fstream>
using namespace std;

void Build::modify(int ch, string inf) {
	if (ch == 1) 
	{ 
		this->set_color(inf); 
	} 
	else if (ch == 2) 
	{
		this->set_floor(inf); 
	} 
	else if (ch == 3)
	{ 
		this->set_number(inf);
	} 
	else if (ch == 4)
	{
		this->set_area(inf);
	} 
	else if (ch == 5)
	{ 
		this->set_address(inf); 
	} 
	else if (ch == 6)
	{ 
		this->set_year(inf); 
	} 
	else 
	{ 
		throw"ÍÅÂÅĞÍÎ ÓÊÀÇÀÍÀ ÊÎÌÀÍÄÀ!!!\n"; 
	} 
}


void Build::set_inf() {
	string nam = "", col = "", sz = "";  cout << ">>> Âåäèòå èíôîğìàöèş\n\n";

	cout << "Color: "; 
	SetConsoleCP(1251);
	//cin.clear();  
	cin.ignore(7777, '\n');  
	getline(cin, col);  
	SetConsoleCP(866);  
	this->set_color(col);  
	col = "";   

	cout << "\nFloor: ";  
	SetConsoleCP(1251);  
	cin.clear();  
	getline(cin, col);  
	SetConsoleCP(866);  
	this->set_floor(col); 

	cout << "\nNumber: ";  
	SetConsoleCP(1251);  
	cin.clear(); 
	getline(cin, sz); 
	SetConsoleCP(866); 
	this->set_number(sz); 
	sz = "";  

	cout << "\nArea: "; 
	SetConsoleCP(1251);
	cin.clear(); 
	getline(cin, sz); 
	SetConsoleCP(866);
	this->set_area(sz); 
	sz = ""; 

	cout << "\nAddreess: "; 
	SetConsoleCP(1251); 
	cin.clear(); 
	getline(cin, sz); 
	SetConsoleCP(866); 
	this->set_address(sz); 
	sz = ""; 

	cout << "\nYear: "; 
	SetConsoleCP(1251);
	cin.clear(); 
	getline(cin, sz);
	SetConsoleCP(866); 
	this->set_year(sz);
	sz = "";  

	cout << "\n";
}


void Build::show_inf() {
	cout << ">>> INFO\n";  
	this->house();  
	cout << "COLOR: " << this->get_color() << "\n";  
	cout << "FLOOR: " << this->get_floor() << "\n";
	cout << "NUMBER: " << this->get_number() << "\n"; 
	cout << "AREA: " << this->get_area() << "\n"; 
	cout << "ADDRESS: " << this->get_address() << "\n";
	cout << "YEAR: " << this->get_year() << "\n";
	cout << "\n";
}


void Build::write_inf() {

	fstream f;  f.open("Build.txt", fstream::in | fstream::out | fstream::app);    
	f << this->House() << "\n";

	f << this->get_color() << "\n";   
	f << this->get_floor() << "\n"; 
	f << this->get_number() << "\n";
	f << this->get_area() << "\n";
	f << this->get_address() << "\n";
	f << this->get_year() << "\n";

	f.close();
}