#pragma once
#include"Worker.h"
#include<iostream>
#include<string>
using namespace std;


class Employee:public Worker
{
public:
	Employee(int id, string name, int did);

	void ShowInformation();

	string GetDepartmentName();
};