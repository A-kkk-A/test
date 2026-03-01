#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker
{
public:
	virtual void ShowInformation() = 0;

	virtual string GetDepartmentName() = 0;


	int m_id;
	string m_name;
	int m_did;
};