#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include<string>

class Boss :public Worker
{
public:
	Boss(int id, string name, int did);

	void ShowInformation();

	string GetDepartmentName();
};
