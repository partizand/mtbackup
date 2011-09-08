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

const int InitTaskCount=10; // ��������� ����������� �������

//! ������ �������
class TaskList
{
public:
	TaskList(Poco::Logger &logger);
	~TaskList(void);

	
	vector<TaskParam> Tasks; 
	//! �������� ���������� �������
	int count() {return Tasks.size();};
	//! �������� �������
	void addTask(TaskParam &Task);
	//! ������� �������
	void removeTask(int index=-1);
	//! ��������� ������� �� ini �����
	void loadFromFile(const std::string &fileName);
	//! ����������, ������� ��� ������� �� �������
	void deb_tocout();
private:
	//int _Count;
	//! �������� ������ ������� �� ������������
	void load(const Poco::Util::AbstractConfiguration *pConf);
	//! ������ �� �����
	Poco::Logger *AppLogger;
};

