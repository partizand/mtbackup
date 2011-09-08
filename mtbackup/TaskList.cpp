#include "StdAfx.h"
#include "TaskList.h"

#include <Poco\Util\IniFileConfiguration.h>
#include <Poco\Util\PropertyFileConfiguration.h>
#include <Poco\AutoPtr.h>

using namespace Poco;
using namespace Util;


TaskList::TaskList(void)
{
	Tasks.reserve(InitTaskCount);
	//_Count=0;
}


TaskList::~TaskList(void)
{
}
//! Добавить задание
void TaskList::AddTask(TaskParam &Task)
{
	Tasks.push_back(Task);	
}

//! Загрузка списка заданий из конфигурации
void TaskList::Load(Poco::Util::AbstractConfiguration *pConf)
{
	TaskParam tmpTask;
	
	AbstractConfiguration::Keys RootKeys;
pConf-> keys("",RootKeys); // Список корневых ключей
if (!RootKeys.empty())
 {
	string KeyName,KeyValue;
	
	
	 for (AbstractConfiguration::Keys::const_iterator it = RootKeys.begin(); it != RootKeys.end(); ++it)
			{
				KeyName=*it+".source";
				tmpTask.Source=pConf->getString(KeyName,"");
				if (tmpTask.Source=="") 
				{
					continue;
				}
				KeyName=*it+".dest";
				tmpTask.Dest=pConf->getString(KeyName,"");
				if (tmpTask.Dest=="") 
				{
					continue;
				}
				cout<< *it<<endl;
			
			}
 }
}


//! Загрузить задания из ini файла
void TaskList::LoadFromIni(const std::string &fileName)
{
AutoPtr<PropertyFileConfiguration> pConf;

pConf=new PropertyFileConfiguration("test.property");

AbstractConfiguration::Keys RootKeys;

pConf-> keys("",RootKeys);

if (!RootKeys.empty())
for (AbstractConfiguration::Keys::const_iterator it = RootKeys.begin(); it != RootKeys.end(); ++it)
			{
				//std::string fullKey = base;
				cout<< *it<<endl;
			
			}
	

	string fPath1=pConf->getString("Path.File1");
	string fPath2=pConf->getString("Path.File2");


}
