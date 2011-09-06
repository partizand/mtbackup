#pragma once

#include <vector>

#include "TaskParam.h"

const int InitTaskCount=10; // начальная размерность вектора

//! Список заданий
class TaskList
{
public:
	TaskList(void);
	~TaskList(void);

	
	vector<TaskParam> Tasks; 
	//! Получить количество заданий
	int count() {return _Count;};
	//! Добавить задание
	void AddTask(TaskParam &Task);
	//! Удалить задание
	void RemoveTask(int index=-1);

private:
	int _Count;
	
	
};

