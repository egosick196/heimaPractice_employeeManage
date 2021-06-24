#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:

	virtual void showInfo() = 0;  //个人信息
	virtual string getDeptID() = 0;  //岗位名称

	int m_ID;
	string m_name;
	int m_deptID;
};

