#pragma once
#include <Windows.h>

namespace CWINLIB
{
	/*
	@brief:取得当前系统的版本号
	*/
	bool getSystemOSVersion(OSVERSIONINFOEX &os);

	bool fileExist(const wstring &fileName);

	bool directoryExist(const wstring &dirPath);
};
