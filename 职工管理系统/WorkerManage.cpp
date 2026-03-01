#include"WorkerManage.h"
#include<iostream>
using namespace std;
#include<fstream>
#define FILENAME "empFile.txt"
#include<string>





//构造函数
WorkerManage::WorkerManage() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//第一种情况：文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化人数
		this->m_EmpNum = 0;
		//初始化职工数组
		this->m_EmpArray = NULL;
		this->fileisempty = true;
		ifs.close();
		return;
	}
	//第二种情况：文件存在但被清空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		//初始化属性
		//初始化人数
		this->m_EmpNum = 0;
		//初始化职工数组
		this->m_EmpArray = NULL;
		this->fileisempty = true;
		ifs.close();
		return;
	}
	//第三种情况：文件存在且记录数据
	int num = this->get_Empnum();
	cout << "有" << num << "个职工" << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	
	this->init_Emp();
	//测试：
	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << "职工编号：" << this->m_EmpArray[i]->m_id
			<< " 姓名：" << this->m_EmpArray[i]->m_name
			<< " 部门编号：" << this->m_EmpArray[i]->m_did << endl;
	}*/
}

//菜单展示函数
void WorkerManage:: Show_Menu() {
	cout << "|------------------------------------------|" << endl;
	cout << "|----------欢迎登陆职工管理系统！----------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------0.退出管理程序---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------1.添加职工信息---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------2.显示职工信息---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------3.删除职工信息---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------4.修改职工信息---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------5.查找职工信息---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------6.按照编号排序---------------|" << endl;
	cout << "|                                          |" << endl;
	cout << "|-------------7.清空所有文档---------------|" << endl;
	cout << "|------------------------------------------|" << endl;
}

//退出系统
void WorkerManage::ExitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//保存数据
void WorkerManage::Save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_did << endl;
	}
	ofs.close();
}

//读取职工信息
void WorkerManage::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index=0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		if (did == 1) {
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else if (did == 3) {
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//获取职工人数
int WorkerManage::get_Empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	return num;
}

//添加新职工
void WorkerManage::Add_Emp() {
	int add_num = 0;
	cout << "请输入要添加新职工的个数：" << endl;
	cin >> add_num;


	if (add_num > 0) {
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + add_num;

		//创建新空间
		Worker ** NewSpace= new Worker*[newSize];
		//将原有数据复制到新空间里
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				NewSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < add_num; i++) {
			int id = 0;
			string name;
			int Dselect;
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个新职工的岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> Dselect;
			Worker* worker=NULL;
			switch (Dselect) {
			case 1:
				worker = new Employee(id, name, Dselect);
				break;
			case 2:
				worker = new Manager(id, name, Dselect);
				break;
			case 3:
				worker = new Boss(id, name, Dselect);
				break;
			default :
				break;
			}
			NewSpace[this->m_EmpNum + i] = worker;
		}
		
		//清空原有数据占用的空间
		delete[]this->m_EmpArray;
		//让旧数组等于新数组
		this->m_EmpArray = NewSpace;
		this->m_EmpNum = newSize;
		cout << "成功添加" << add_num << "位新职工！" << endl;
		this->fileisempty = false;
		this->Save();
	}
	else cout << "输入数据有误" << endl;
	system("pause");
	system("cls");
}

//显示现有职工
void WorkerManage::Show_Emp() {
	if (this->fileisempty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArray[i]->ShowInformation();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void WorkerManage::Del_Emp() {
	if (this->fileisempty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		int id;
		cout << "请输入你要删除的编号：" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {//该职工存在
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败！该编号不存在" << endl;
		}
		this->Save();
	}
	system("pause");
	system("cls");

}

//判断职工是否存在
int WorkerManage::IsExist(int id) {
	//初始化index为-1
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (id == this->m_EmpArray[i]->m_id) {
			index = i;
			break;
		}
	}
	return index;
}

//修改职工信息
void WorkerManage::Mod_Emp() {
	if (this->fileisempty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		int id;
		cout << "请输入职工编号：" << endl;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			cout << "找到了该职工！" << endl;
			//修改职工具体信息
			int newid;
			string newname;
			int newdid;
			cout << "请输入该职工的新信息：" << endl;
			cout << "职工编号：" << endl;
			cin >> newid;

			cout << "职工姓名：" << endl;
			cin >> newname;

			cout << "岗位编号：" << endl;
			cin >> newdid;
			//删除原来的信息
			delete this->m_EmpArray[ret];

			Worker* worker = NULL;
			switch (newdid) {
			case 1:
				worker =new Employee(newid, newname, newdid);
				break;
			case 2:
				worker =new Manager(newid, newname, newdid);
				break;
			case 3:
				worker =new Boss(newid, newname, newdid);
				break;
			default:break;
			}
			//修改为刚输入的信息
			this -> m_EmpArray[ret] = worker;
			cout << "修改成功！" << this->m_EmpArray[ret]->m_did << endl;
			//保存到文件中
			this->Save();
		}
		else {
			cout << "该职工编号不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工信息
void WorkerManage::Find_Emp() {
	if (this->fileisempty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		cout << "请选择你查找的方式：" << endl
			<< "1、职工编号" << endl
			<< "2、职工姓名" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			int find_id;
			cout << "请输入要查找的编号：" << endl;
			cin >> find_id;
			int ret = this->IsExist(find_id);
			if (ret != -1) {
				cout << "找到了该职工！" << endl;
				this->m_EmpArray[ret]->ShowInformation();
			}
			else {
				cout << "操作失败！未找到该职工！" << endl;
			}
		}
		else if (choice == 2) {
			string find_name;
			cout << "请输入要查找的姓名：" << endl;
			cin >> find_name;
			int ret = -1;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (find_name == this->m_EmpArray[i]->m_name) {
					ret = i;
					break;
				}
			}
			if (ret != -1) {
				cout << "找到了该职工！" << endl;
				this->m_EmpArray[ret]->ShowInformation();
			}
			else {
				cout << "操作失败！未找到该职工！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//通过编号排序
void WorkerManage::String() {
	if (this->fileisempty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		cout << "请选择你排序的方式：" << endl
			<< "1、升序排序" << endl
			<< "2、降序排序" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			for (int j = 0; j < this->m_EmpNum; j++) {
				for (int i = 0; i < this->m_EmpNum-1; i++) {
					if (this->m_EmpArray[i]->m_id > this->m_EmpArray[i + 1]->m_id) {
						Worker* worker = NULL;
						worker = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[i + 1];
						this->m_EmpArray[i + 1] = worker;
					}
				}
			}
			cout << "升序排序操作成功！" << endl;
		}
		else if (choice == 2) {
			for (int j = 0; j < this->m_EmpNum; j++) {
				for (int i = 0; i < this->m_EmpNum - 1; i++) {
					if (this->m_EmpArray[i]->m_id < this->m_EmpArray[i + 1]->m_id) {
						Worker* worker = NULL;
						worker = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[i + 1];
						this->m_EmpArray[i + 1] = worker;
					}
				}
			}
			cout << "降序排序操作成功！" << endl;

		}
		this->Save();
	}
	system("pause");
	system("cls");
}

//清空文件
void WorkerManage::Clean_Emp() {
	cout << "确定要清空文件吗?" << endl;
	cout << "1、确定" << endl 
		<< "2、返回" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete [] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->fileisempty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}


//析构函数
WorkerManage::~WorkerManage() {
	if (this->m_EmpArray != NULL) {
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}