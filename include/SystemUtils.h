#pragma once
#include <Windows.h>

namespace CWINLIB
{
	/*
	@brief:ȡ�õ�ǰϵͳ�İ汾��
	*/
	bool getSystemOSVersion(OSVERSIONINFOEX &os);

	bool fileExist(const wstring &fileName);

	bool directoryExist(const wstring &dirPath);
};
