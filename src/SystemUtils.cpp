#include "stdafx.h"
#include "SystemUtils.h"
#include <tchar.h>

namespace CWINLIB
{
	bool CWINLIB::getSystemOSVersion(OSVERSIONINFOEX &os)
	{
		ZeroMemory(&os, sizeof(OSVERSIONINFO));
		os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
		if (GetVersionEx((OSVERSIONINFO *)&os))
		{
			HMODULE hModNtdll = NULL;
			if (hModNtdll = ::LoadLibrary(_T("ntdll.dll")))
			{
				typedef void (WINAPI *pfRTLGETNTVERSIONNUMBERS)(DWORD*, DWORD*, DWORD*);
				pfRTLGETNTVERSIONNUMBERS pfRtlGetNtVersionNumbers;
				pfRtlGetNtVersionNumbers = (pfRTLGETNTVERSIONNUMBERS)::GetProcAddress(hModNtdll, "RtlGetNtVersionNumbers");
				if (pfRtlGetNtVersionNumbers)
				{
					pfRtlGetNtVersionNumbers(&os.dwMajorVersion,
						&os.dwMinorVersion, &os.dwBuildNumber);
					os.dwBuildNumber &= 0x0ffff;
				}
				::FreeLibrary(hModNtdll);
				hModNtdll = NULL;
			}
			return true;
		}
		return false;
	}

	bool fileExist(const wstring &fileName)
	{
		DWORD dRet = GetFileAttributes(fileName.c_str());
		return ((INVALID_FILE_ATTRIBUTES != dRet) && !(dRet & FILE_ATTRIBUTE_DIRECTORY));
	}

	bool directoryExist(const wstring &dirPath)
	{
		DWORD dRet = GetFileAttributes(dirPath.c_str());
		return ((INVALID_FILE_ATTRIBUTES != dRet) && (dRet & FILE_ATTRIBUTE_DIRECTORY));
	}

};
