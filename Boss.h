#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Boss: public Worker
{
public:

	Boss(int, string, int);

	void showInfo() override;
	string getDeptID() override;
};

