#pragma once
#include "TaskParam.h"
#include "TaskList.h"
#include <vector>


using namespace std;

class Backup
{
public:
	
	Backup(void);
	~Backup(void);
private:
	//! ������ �������
	TaskList tasks;  
	
};

