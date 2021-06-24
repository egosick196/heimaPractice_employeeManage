#include "Employee.h"
using namespace std;

Employee::Employee(int id, string name, int dId)
{
	m_ID = id;
	m_name = name;
	m_deptID = dId;
}

void Employee::showInfo()
{
	cout << "职工编号： " << m_ID << endl
		<< "职工姓名： " << m_name << endl
		<< "岗位： " << getDeptID() << endl
		<< "职责：完成经理交代的任务。\n" << endl;
}

string Employee::getDeptID()
{
	return string("员工");
}