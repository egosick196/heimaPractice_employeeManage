#include "Boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId)
{
	m_ID = id;
	m_name = name;
	m_deptID = dId;
}

void Boss::showInfo()
{
	cout << "职工编号： " << m_ID << endl
		<< "职工姓名： " << m_name << endl
		<< "岗位： " << getDeptID() << endl
		<< "职责：统管公司事务。" << endl;
}

string Boss::getDeptID()
{
	return string("总裁");
}