#pragma once

using namespace std;

namespace Action
{
//! Действие
	enum TAction{None,Copy,Sync,Mirr,Arh};

}
//! Параметры одногозадания
class TaskParam
{

public:
	
	//! Имя задания
	string NameTask; 
	//! Разрешена
	bool IsEnabled;
	//! Источник
	string Source;
	//! Приемник
	string Dest;
	//! Действие
	Action::TAction action;
	TaskParam(string &taskName,Action::TAction action,string &source,string &dest);

	TaskParam(void);
	~TaskParam(void);
};


