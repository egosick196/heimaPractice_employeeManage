#include "Manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId)
{
	m_ID = id;
	m_name = name;
	m_deptID = dId;
}

void Manager::showInfo()
{
	cout << "职工编号： " << m_ID << endl
		<< "职工姓名： " << m_name << endl
		<< "岗位： " << getDeptID() << endl
		<< "职责：完成老板交代的任务，分发任务给员工。\n" << endl;
}

string Manager::getDeptID()
{
	return string("经理");
}