#pragma once

#include <vector>

#include "TaskParam.h"

const int InitTaskCount=10; // ��������� ����������� �������

//! ������ �������
class TaskList
{
public:
	TaskList(void);
	~TaskList(void);

	
	vector<TaskParam> Tasks; 
	//! �������� ���������� �������
	int count() {return _Count;};
	//! �������� �������
	void AddTask(TaskParam &Task);
	//! ������� �������
	void RemoveTask(int index=-1);

private:
	int _Count;
	
	
};

