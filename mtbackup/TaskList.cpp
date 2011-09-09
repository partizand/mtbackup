#include "StdAfx.h"
#include "TaskList.h"

#include <Poco\Util\IniFileConfiguration.h>
#include <Poco\Util\PropertyFileConfiguration.h>
#include <Poco\Util\XMLConfiguration.h>
#include <Poco\Util\AbstractConfiguration.h>
#include <Poco\AutoPtr.h>
#include <Poco\Path.h>
#include <Poco\String.h>
#include <Poco\File.h>

using namespace Poco;
using namespace Util;


TaskList::TaskList(Poco::Logger &logger)
{
	
	AppLogger=&logger;
	Tasks.reserve(InitTaskCount);
	//_Count=0;
}


TaskList::~TaskList(void)
{
}
//! Добавить задание
void TaskList::addTask(TaskParam &Task)
{
	Tasks.push_back(Task);	
}

//! Загрузка списка заданий из конфигурации
void TaskList::load(const Poco::Util::AbstractConfiguration *pConf)
{
	TaskParam tmpTask;
	
	AbstractConfiguration::Keys RootKeys;
pConf-> keys("",RootKeys); // Список корневых ключей
if (!RootKeys.empty())
 {
	string KeyName,KeyValue;
	int i;
	for (i=0;i<RootKeys.size();++i)
	
	 //for (AbstractConfiguration::Keys::const_iterator it = RootKeys.begin(); it != RootKeys.end(); ++it)
			{
				//KeyName=*it+".source";
				KeyName=RootKeys.at(i)+".enabled";
				tmpTask.IsEnabled=pConf->getBool(KeyName,true);
				
				KeyName=RootKeys.at(i)+".source";
				tmpTask.Source=pConf->getString(KeyName,"");
				if (tmpTask.Source=="") 
				{
					poco_error_f1(*AppLogger,"Source missing in config %s",RootKeys.at(i));
					continue;
				}
				KeyName=RootKeys.at(i)+".dest";
				tmpTask.Dest=pConf->getString(KeyName,"");
				if (tmpTask.Dest=="") 
				{
					poco_error_f1(*AppLogger,"Destination missing in config %s",RootKeys.at(i));
					continue;
				}
				KeyName=RootKeys.at(i)+".nametask";
				tmpTask.NameTask=pConf->getString(KeyName,"");
				if (tmpTask.NameTask=="") 
				{
					tmpTask.NameTask=RootKeys.at(i);
				}
				//cout<< *it<<endl;
			addTask(tmpTask);
			}
 }
}


//! Загрузить задания из ini файла
void TaskList::loadFromFile(const std::string &fileName)
{
	// Определение типа файла по расширению
	Poco::Path pPath(fileName);
	Poco::File pFile(pPath);

	if (!pFile.exists()) return; // Файла нет
	if (!pFile.canRead()) return; // Файл не может быть прочитан

	string Ext=pPath.getExtension();
	toLowerInPlace(Ext); // Расширение маленькими буквами

	AutoPtr<AbstractConfiguration> pConf;

	if (Ext.compare("xml")==0) // Конфигурация xml
	{
		pConf=new XMLConfiguration(fileName);
	}
	if (Ext.compare("ini")==0) // Конфигурация ini
	{
		pConf=new IniFileConfiguration(fileName);
	}
	if (Ext.compare("properties")==0) // Конфигурация prop
	{
		pConf=new PropertyFileConfiguration(fileName);
	}
	if (pConf.isNull()) return; // Нет нужного расширения
	poco_information_f1(*AppLogger,"Loading task file %s",fileName);
	load(pConf);

}

//! Оператор []
TaskParam& TaskList::operator[] (int index)
{
	
	return Tasks[index];
	
}

//! Отладочная, вывести все задания на консоль
void TaskList::deb_tocout()
{
	for (int i=0;i<Tasks.size();++i)
	{
		poco_information_f1(*AppLogger,"Task %s",Tasks[i].NameTask);
		poco_debug_f1(*AppLogger,"Source: %s",Tasks[i].Source);
		poco_debug_f1(*AppLogger,"Dest: %s",Tasks[i].Dest);
		AppLogger->information("Hello from tasklist");
		//cout << "Task "+Tasks[i].NameTask<<endl;
		//cout << "Source: "+Tasks[i].Source << endl;
		//cout << "Dest: "+Tasks[i].Dest << endl;
	}
}