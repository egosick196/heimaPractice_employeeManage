#include <iostream>
#include "WorkerManager.h"
#include <cstdlib>
using namespace std;

int main()
{
	WorkerManager manager;
	int choice = -1;

	while (true)
	{
		manager.showMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;  int position;

		switch (choice)
		{
		case 0:
			manager.exitSystem();
			break;
		case 1: //添加职工
			manager.addMember();
			break;
		case 2: //显示职工
			manager.showEmp();
			break;
		case 3: //删除职工
			position = manager.findPosition();
			if (position == -1) break;
			manager.delEmp(position);
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			position = manager.findPosition();
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");  //清屏
			break;
		}
	}

	system("pause");

	return 0;
}