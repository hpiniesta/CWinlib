#pragma once
#include <string>
#include <Windows.h>

namespace CWINLIB {

	/*
	@brief:�ַ���ת��ע������
	*/
	HKEY strToRootKey(const std::wstring &str);

	/*
	@brief:ע������ת���ַ���
	*/
	std::wstring rootKeyToStr(HKEY hKey);

};


