#include"Boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void Boss::ShowInformation() {
	cout << "职工编号： " << this->m_id <<
		"\t职工姓名： " << this->m_name <<
		"\t岗位： " << this->GetDepartmentName() <<
		"\t岗位职责：完成公司的业务" << endl;
}

string Boss::GetDepartmentName() {
	return string("老板");
}