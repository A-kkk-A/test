#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include<string>

class Manager :public Worker
{
public:

	Manager(int id, string name, int did);

	void ShowInformation();

	string GetDepartmentName();
};