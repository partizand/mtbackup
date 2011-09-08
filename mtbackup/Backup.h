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
	//! ��������� �������
	void start();

	//! ������ �������
	TaskList taskList;

private:
	
	//! ������ �� �����
	Poco::Logger *AppLogger;
	
};

