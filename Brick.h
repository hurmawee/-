#pragma once
#include "Building.h"
#include "Fabrica.h"
#include <iostream>
using namespace std;

class Brick :
	public Build, Fabrika
{
public: 
	Build * create_build() { return new Brick; }

	void house() override { cout << "BRICK!\n\n"; } 
	int Gethouse() override { return 1; }
	string House() override { return "brick"; } 
	

};

