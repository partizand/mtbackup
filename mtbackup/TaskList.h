#pragma once

#include <vector>

//#include <Poco\Util\IniFileConfiguration.h>
//#include <Poco\Util\PropertyFileConfiguration.h>
#include <Poco\Util\AbstractConfiguration.h>
//#include <Poco\AutoPtr.h>

using namespace Poco;
using namespace Util;


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
	int count() {return Tasks.size();};
	//! Добавить задание
	void AddTask(TaskParam &Task);
	//! Удалить задание
	void RemoveTask(int index=-1);
	//! Загрузить задания из ini файла
	void LoadFromIni(const std::string &fileName);
private:
	//int _Count;
	//! Загрузка списка заданий из конфигурации
	void Load(Poco::Util::AbstractConfiguration *pConf);
	
};

