#include "StdAfx.h"
#include "TaskParam.h"

//using namespace std;

TaskParam::TaskParam(void)
	:NameTask(""),Dest("")
{
	//NameTask="";
	//Dest="";
	action=Action::None;
}

TaskParam::TaskParam(string &nameTask,Action::TAction action,string &source,string &dest)
	:NameTask(nameTask),Source(source),Dest(dest)
{
	//this->NameTask=taskName;
	this->action=action;
	//this->Source=source;
}

TaskParam::~TaskParam(void)
{
}
