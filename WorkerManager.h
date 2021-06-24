#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	void showMenu();
	void exitSystem();
	void addMember();
	void saveFile();
	int getEmpNum();
	void initEmp();
	void showEmp();
	void delEmp(int);
	int findPosition();

	~WorkerManager();

private:
	int m_preNum = 0;
	Worker **m_preArray = nullptr;
	const string FILENAME = "empInfo.txt";
	bool m_fileIsEmpty = true;
};

