#pragma once
#include "Building.h"
#include "Fabrica.h"
#include <iostream>
using namespace std;

class Panel :public Build, Fabrika
{
public:
	void house() override { cout << "PANEL!\n\n"; }
	int Gethouse() override { return 4; }
	string House() override { return "panel"; }
	Build * create_build() { return new Panel; }
};