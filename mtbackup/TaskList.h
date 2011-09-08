#pragma once

#include <vector>

//#include <Poco\Util\IniFileConfiguration.h>
//#include <Poco\Util\PropertyFileConfiguration.h>
#include <Poco\Util\AbstractConfiguration.h>
#include <Poco\Logger.h>
//#include <Poco\AutoPtr.h>

//using namespace Poco;
//using namespace Util;


#include "TaskParam.h"

const int InitTaskCount=10; // начальная размерность вектора

//! Список заданий
class TaskList
{
public:
	TaskList(Poco::Logger &logger);
	~TaskList(void);

	
	vector<TaskParam> Tasks; 
	//! Получить количество заданий
	int count() {return Tasks.size();};
	//! Добавить задание
	void addTask(TaskParam &Task);
	//! Удалить задание
	void removeTask(int index=-1);
	//! Загрузить задания из ini файла
	void loadFromFile(const std::string &fileName);
	//! Отладочная, вывести все задания на консоль
	void deb_tocout();
private:
	//int _Count;
	//! Загрузка списка заданий из конфигурации
	void load(const Poco::Util::AbstractConfiguration *pConf);
	//! Ссылка на логер
	Poco::Logger *AppLogger;
};

