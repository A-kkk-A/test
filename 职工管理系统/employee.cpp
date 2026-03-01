#include"employee.h"

Employee::Employee(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void Employee::ShowInformation() {
	cout << "职工编号： " <<this-> m_id <<
		"\t职工姓名： " << this->m_name <<
		"\t岗位： " <<  this->GetDepartmentName()<<
		"\t岗位职责：完成经理交给你的任务" << endl;
}

string Employee::GetDepartmentName() {
	return string("员工");
}
