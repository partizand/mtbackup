#pragma once

using namespace std;

namespace Action
{
//! ��������
	enum TAction{None,Copy,Sync,Mirr,Arh};

}
//! ��������� �������������
class TaskParam
{

public:
	
	//! ��� �������
	string NameTask; 
	//! ���������
	bool IsEnabled;
	//! ��������
	string Source;
	//! ��������
	string Dest;
	//! ��������
	Action::TAction action;
	TaskParam(string &taskName,Action::TAction action,string &source,string &dest);

	TaskParam(void);
	~TaskParam(void);
};


