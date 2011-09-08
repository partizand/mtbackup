// mtbackup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TaskParam.h"
#include <locale.h>

#include <Poco\File.h>
//#include <Poco\UnicodeConverter.h>
//#include <Poco\UTF8Encoding.h>
//#include <Poco\UTF16Encoding.h>
//#include <Poco\TextConverter.h>
#include <Poco\Util\IniFileConfiguration.h>
#include <Poco\AutoPtr.h>

#include "Poco/Logger.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Message.h"


using namespace std;
using namespace Poco;
using namespace Util;

int _tmain(int argc, _TCHAR* argv[])
{
	//UTF8Encoding utf8;
	//UTF16Encoding utf16;
	//setlocale(LC_ALL,"Rus");
	//setlocale(LC_ALL,"Utf-8");

	//std::locale loc("Russian");
//std::locale::global(loc);

	AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("test.ini"));

	string fPath1=pConf->getString("Path.File1");
	string fPath2=pConf->getString("Path.File2");
	
// Вывод списка корневых ключей
	AbstractConfiguration::Keys RootKeys;

pConf-> keys("",RootKeys);

if (!RootKeys.empty())
{
	cout<<"RootKeys:"<<endl;
	for (AbstractConfiguration::Keys::const_iterator it = RootKeys.begin(); it != RootKeys.end(); ++it)
			{
				//std::string fullKey = base;
				cout<< *it << endl;
			
			}
	
}


	//TextConverter converter(utf16,utf8);
	
	//wstring wfPath1=L"d:\\temp\\тест\\test.txt";
	//wstring wfPath1=L"d:\\temp\\тест\\test.txt";

	//converter.convert( wfPath1,fPath1);

//UnicodeConverter.toUTF8(wfPath1,fPath1);
//	Poco::UnicodeConverter.toUTF8(wfPath2,fPath2);

	Poco::File pFile(fPath1);
	pFile.copyTo(fPath2);

	//cout<<fPath1<<endl;
	//cout<<fPath2<<endl;

	//wcout << fPath1.c_str()<<endl;
	

	//printf(fPath1.c_str());
	
	//cout<<"Русский";

	// Проба Logging

		// set up two channel chains - one to the
	// console and the other one to a log file.
	FormattingChannel* pFCConsole = new FormattingChannel(new PatternFormatter("%s: %p: %t"));
	pFCConsole->setChannel(new ConsoleChannel);
	pFCConsole->open();
	
	FormattingChannel* pFCFile = new FormattingChannel(new PatternFormatter("%Y-%m-%d %H:%M:%S.%c %N[%P]:%s:%q:%t"));
	pFCFile->setChannel(new FileChannel("sample.log"));
	pFCFile->open();

	// create two Logger objects - one for
	// each channel chain.
	Logger& consoleLogger = Logger::create("ConsoleLogger", pFCConsole, Message::PRIO_INFORMATION);
	Logger& fileLogger    = Logger::create("FileLogger", pFCFile, Message::PRIO_WARNING);
	
	

	// log some messages
	consoleLogger.error("An error message");
	fileLogger.error("An error message");
	
	consoleLogger.warning("A warning message");
	fileLogger.error("A warning message");
	
	consoleLogger.information("An information message");
	fileLogger.information("An information message");
	
	poco_information(consoleLogger, "Another informational message");
	poco_warning_f2(consoleLogger, "A warning message with arguments: %d, %d", 1, 2);
	
	Logger::get("ConsoleLogger").error("Another error message");

	poco_information_f2(consoleLogger,"File %s copied to %s",fPath1,fPath2);
	//consoleLogger.information("File copied.",fPath1);

	



	return 0;
}

