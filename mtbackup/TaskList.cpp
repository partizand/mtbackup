#include "StdAfx.h"
#include "TaskList.h"



TaskList::TaskList(void)
{
	Tasks.reserve(InitTaskCount);
	_Count=0;
}


TaskList::~TaskList(void)
{
}
//! �������� �������
void TaskList::AddTask(TaskParam &Task)
{
	Tasks.push_back(Task);	
}
