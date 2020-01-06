#pragma once
#include "Building.h"

using namespace std;

class Fabrika
{
public:
	virtual ~Fabrika(){};
	virtual Build* create_build()=0;
};