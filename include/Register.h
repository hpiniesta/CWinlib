#pragma once
#include <string>
#include <Windows.h>

namespace CWINLIB {

	/*
	@brief:字符串转成注册表根键
	*/
	HKEY strToRootKey(const std::wstring &str);

	/*
	@brief:注册表根键转成字符串
	*/
	std::wstring rootKeyToStr(HKEY hKey);

};


