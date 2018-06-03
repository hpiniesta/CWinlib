#include "stdafx.h"
#include "Register.h"
#include <map>
#include <algorithm>

using namespace std;

namespace CWINLIB
{
	const std::map<wstring, HKEY> c_mapRootKeys =
	{
		{ L"HKEY_CLASSES_ROOT", HKEY_CLASSES_ROOT },
		{ L"HKEY_CURRENT_USER", HKEY_CURRENT_USER },
		{ L"HKEY_LOCAL_MACHINE", HKEY_LOCAL_MACHINE },
		{ L"HKEY_USERS", HKEY_USERS },
		{ L"HKEY_PERFORMANCE_DATA", HKEY_PERFORMANCE_DATA },
		{ L"HKEY_CURRENT_CONFIG", HKEY_CURRENT_CONFIG },
		{ L"HKEY_DYN_DATA", HKEY_DYN_DATA }
	};

	HKEY CWINLIB::strToRootKey(const std::wstring &str)
	{
		auto it = c_mapRootKeys.find(str);
		if (it != c_mapRootKeys.end())
			return it->second;
		else
			return HKEY_CLASSES_ROOT;
	}

	std::wstring rootKeyToStr(HKEY hKey)
	{
		auto it = std::find_if(c_mapRootKeys.cbegin(), c_mapRootKeys.cend(),
			[hKey](const std::pair<wstring, HKEY>&pair)
		{
			return hKey == pair.second;
		});
		if (it != c_mapRootKeys.end())
			return it->first;
		else
			return L"HKEY_CLASSES_ROOT";
	}

}

