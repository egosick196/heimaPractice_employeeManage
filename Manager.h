#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Manager: public Worker
{
public:

	void showInfo() override;
	string getDeptID() override;

	Manager(int, string, int);
};

