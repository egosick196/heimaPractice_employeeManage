#pragma once
#include "Worker.h"

class Employee: public Worker
{
public:

	void showInfo() override;  //个人信息
	string getDeptID() override;  //岗位名称

	Employee(int, string, int);
};

