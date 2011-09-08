#pragma once
#include "TaskParam.h"
#include "TaskList.h"
#include <vector>

#include <Poco\Logger.h>


using namespace std;

class Backup
{
public:
	
	Backup(Poco::Logger &logger);
	~Backup(void);
	//! Запустить задания
	void start();

	//! Список заданий
	TaskList taskList;

private:
	
	//! Ссылка на логер
	Poco::Logger *AppLogger;
	
};

