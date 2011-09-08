#include "StdAfx.h"
#include "Backup.h"


Backup::Backup(Poco::Logger &logger):
taskList(logger)
{
	AppLogger=&logger;
	//Tasks=new vector<TaskParam>();
	//tasks.Tasks[0].
	//string tmpstr=Tasks[0].NameTask;
	//Tasks.s
	//string str="asfsad";
	//TaskParam tmp(str,Action::Copy,"c:\\temp","d:\\temp");
	//TaskParam tmp(str,Action::Copy,str,_T("dfgdfg"));
	//tasks.AddTask(tmp);
	//taskList.loadFromFile("test.properties");
	
	
	//taskList.deb_tocout();
}

Backup::~Backup(void)
{
}
//! Запустить задания
void Backup::start()
{
int i;
for (i=0;i<taskList.count();++i) // Перебираем задания
{
	AppLogger->information("Task list:");
	if (taskList.Tasks[i].IsEnabled)
	{
		poco_information_f1(*AppLogger,"Task name: ",taskList.Tasks[i].NameTask);
		poco_information_f1(*AppLogger,"Source: ",taskList.Tasks[i].Source);
		poco_information_f1(*AppLogger,"Dest: ",taskList.Tasks[i].Dest);
	}
}
}