#include"Manager.h"

Manager::Manager(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void Manager::ShowInformation() {
	cout << "职工编号： " << this->m_id <<
		"\t职工姓名： " << this->m_name <<
		"\t岗位： " << this->GetDepartmentName() <<
		"\t岗位职责：完成老板交给你的任务" << endl;
}

string Manager::GetDepartmentName() {
	return string("经理");
}