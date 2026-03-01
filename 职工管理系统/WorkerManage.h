#pragma once
#include<iostream>
using namespace std;
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Worker.h"

class WorkerManage
{
public:
	//构造函数
	WorkerManage();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//添加新职工
	void Add_Emp();

	//保存职工数据
	void Save();

	//读取职工数据
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在		存在返回所在数组的下标，不存在返回-1
	int IsExist(int id);

	//修改职工信息
	void Mod_Emp();

	//查找职工信息
	void Find_Emp();
	
	//通过编号排序
	void String();

	//清空文件
	void Clean_Emp();

	int get_Empnum();//获取职工人数
	bool fileisempty;
	int m_EmpNum = 0;//职工现有数量
	Worker** m_EmpArray;//职工数组

	~WorkerManage();//析构函数
};