#pragma once
#include "Building.h"
#include "Fabrica.h"
#include <iostream>

using namespace std;

class Cottage :public Build, Fabrika
{
public:
	Build * create_build() { return new Cottage; }

	void house() override { cout << "COTTAGE!\n\n"; }
	int Gethouse() override { return 2; }
	string House() override { return "cottage"; }
	
};
