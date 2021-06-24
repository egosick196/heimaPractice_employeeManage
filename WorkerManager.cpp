#include "WorkerManager.h"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"

WorkerManager::WorkerManager()
{
	ifstream fileIn(FILENAME, ios::in);  //用ifstream而不是fstream

	if (!fileIn.is_open())  //文件不存在，区别于文件为空
	{
		cout << "未读取到系统文件" << endl;
		fileIn.close();
		return;
	}

	char ch;  fileIn >> ch;
	if (fileIn.eof())
	{
		cout << "系统文件为空，待输入" << endl;
		fileIn.close();
		return;
	}

	cout << "读取系统文件" << endl;
	int initNum = getEmpNum();
	m_preArray = new Worker*[initNum];
	cout << "读取到 " << initNum << " 个员工信息" << endl;
	initEmp();
	cout << "初始化系统信息完毕" << endl;
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎您下次使用本系统" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addMember()
{
	cout << "请输入需要增加的员工数量： " << endl;
	int newNum = 0;  cin >> newNum;
	if (newNum <= 0)
	{
		cout << "增加的员工数量需为正数！" << endl;
		return;
	}

	int currNum = m_preNum;
	Worker **array = new Worker *[m_preNum];

	for (int i = 0; i < m_preNum; i++)  //移入旧数据
	{
		array[i] = m_preArray[i];
	}

	int id = 0; string name = "xxx"; int dId = 1;
	Worker *worker = nullptr;
	for (int i = 0; i < newNum; i++)
	{
		cout << "请输入第 " << i + 1 << " 个新员工编号" << endl;
		cin >> id;
		cout << "请输入第 " << i + 1 << " 个新员工姓名" << endl;
		cin >> name;
		cout << "请输入第 " << i + 1 << " 个新员工职务" << endl
			<< "1: 老板" << endl
			<< "2: 经理" << endl
			<< "3: 员工" << endl;
		cin >> dId;

		switch (dId)
		{
		case 1:
			worker = new Boss(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Employee(id, name, dId);
			break;
		default:
			cout << "请输入正确的员工职务编号！" << endl;
			i--;
			continue;
			break;
		}
		array[i + m_preNum] = worker;
	}

	currNum += newNum;
	delete[] m_preArray;  //清空指向的内存，但空间还在
	m_preArray = array;
	m_preNum = currNum;
	saveFile();
	system("pause");
	system("cls");  //清屏
}

void WorkerManager::saveFile()
{
	if (m_preNum <= 0)
	{
		cout << "当前系统中无员工信息" << endl;
		return;
	}

	ofstream fileOut;
	fileOut.open(FILENAME, ios::out);

	for (int i = 0; i < m_preNum; i++)
	{
		fileOut << m_preArray[i]->m_ID << " "
			<< m_preArray[i]->m_name << " "
			<< m_preArray[i]->m_deptID << endl;

		m_fileIsEmpty = false;
	}
	fileOut.close();
}

int WorkerManager::getEmpNum()
{
	ifstream fileIn(FILENAME, ios::in);

	int id; string name; int did;
	int num = 0;
	while (fileIn >> id >> name >> did)
	{
		num++;
	}
	fileIn.close();
	return num;
}

void WorkerManager::initEmp()
{
	ifstream fileIn(FILENAME, ios::in);

	int id; string name; int did;
	Worker *worker = nullptr;
	while (fileIn >> id >> name >> did)
	{
		switch (did)
		{
		case 1:
			worker = new Boss(id, name, did);
			break;
		case 2:
			worker = new Manager(id, name, did);
			break;
		case 3:
			worker = new Employee(id, name, did);
			break;
		default:
			cout << "请输入正确的员工职务编号！" << endl;
			continue;
			break;
		}
		m_preArray[m_preNum++] = worker;
	}
}

WorkerManager::~WorkerManager()
{
	delete[] m_preArray;
}