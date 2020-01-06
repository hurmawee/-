#pragma once
#include "Building.h"
#include "Fabrica.h"
#include <iostream>
using namespace std;

class Monolithic :public Build, Fabrika
{
public:
	void house() override { cout << "MONOLITHIC!\n\n"; }
	int Gethouse() override { return 3; }
	string House() override { return "monolithic"; }
	Build * create_build() { return new Monolithic; }
};
