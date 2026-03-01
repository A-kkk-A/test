#include<iostream>
using namespace std;
#include"WorkerManage.h"
#include"Worker.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"


int main() {
	WorkerManage wm;
	int choice;
	/*Worker* wk1 = NULL;
	Worker* wk2 = NULL;
	Worker* wk3 = NULL;
	wk1 = new Employee(1, "张三", 1);
	wk2 = new Manager(1, "张三", 1);
	wk3 = new Boss(1, "张三", 1);
	wk1->ShowInformation();
	wk2->ShowInformation();
	wk3->ShowInformation();*/

	while (true) {
		wm.Show_Menu();
		cout << "请输入你的选项：" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			wm.ExitSystem();
			break;//退出系统
		case 1:
			wm.Add_Emp();
			break;//添加新职员
		case 2:
			wm.Show_Emp();
			break;//显示所有职员
		case 3:
			wm.Del_Emp();
			break;//删除职员
		case 4:
			wm.Mod_Emp();
			break;//修改职工信息
		case 5:
			wm.Find_Emp();
			break;//查找职工信息
		case 6:
			wm.String();
			break;//按照编号排序
		case 7:
			wm.Clean_Emp();
			break;//清空
		default:
			system("cls");
			break;
		}
	}









	system("pause");


	return 0;
}