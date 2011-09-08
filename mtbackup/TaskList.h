#pragma once

#include <vector>

//#include <Poco\Util\IniFileConfiguration.h>
//#include <Poco\Util\PropertyFileConfiguration.h>
#include <Poco\Util\AbstractConfiguration.h>
//#include <Poco\AutoPtr.h>

using namespace Poco;
using namespace Util;


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
	int count() {return Tasks.size();};
	//! �������� �������
	void AddTask(TaskParam &Task);
	//! ������� �������
	void RemoveTask(int index=-1);
	//! ��������� ������� �� ini �����
	void LoadFromIni(const std::string &fileName);
private:
	//int _Count;
	//! �������� ������ ������� �� ������������
	void Load(Poco::Util::AbstractConfiguration *pConf);
	
};

