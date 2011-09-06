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
	
	//TextConverter converter(utf16,utf8);
	
	//wstring wfPath1=L"d:\\temp\\тест\\test.txt";
	//wstring wfPath1=L"d:\\temp\\тест\\test.txt";

	//converter.convert( wfPath1,fPath1);

//UnicodeConverter.toUTF8(wfPath1,fPath1);
//	Poco::UnicodeConverter.toUTF8(wfPath2,fPath2);

	Poco::File pFile(fPath1);
	pFile.copyTo(fPath2);

	cout<<fPath1<<endl;
	cout<<fPath2<<endl;

	wcout << fPath1.c_str()<<endl;
	

	//printf(fPath1.c_str());
	
	cout<<"Русский";

	return 0;
}

