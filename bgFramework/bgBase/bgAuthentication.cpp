#include "bgAuthentication.h"
#include "bgBase.h"
#include <tchar.h>
#include <atlstr.h>
#include <Windows.h>

#include "Poco/Net/NTPClient.h"
#include "Poco/DigestEngine.h"
#include "Poco/SHA1Engine.h"

bgAuthentication authenticater;

bgAuthentication::bgAuthentication()
{

}

bgAuthentication::~bgAuthentication()
{

}

bool bgAuthentication::CheckAuthentication()
{
	bool ret = false;

	// ���Ȼ�ȡ�����Ļ�����
	std::string machine_code = GetMachineCode();

	// �����ݿ�ȡ����֤��
	std::string authen_info = GetAuthenticateInfo();

	// ����base64��ԭΪ��������֤�롱
	int cipher_authen_code_len = 1024;
	char *cipher_authen_code = new char[cipher_authen_code_len];
	int errCode = bgBase::Base64Decode(authen_info, (unsigned char *)cipher_authen_code, cipher_authen_code_len);
	if (errCode == -1)
	{
	}

	// Ȼ�󽫡�������֤�롱����

	// �ȶԻ����룬��֤��Ȩ���Ƿ�Ϸ����Ƿ���ͬһ̨������

	// ��֤��Ȩ����

	// �ڴ滺����Ȩ����

	return ret;
}

std::string bgAuthentication::GetNewAuthenRequestCode()
{
	std::string ret;

	return ret;
}

bool bgAuthentication::VerifyAuthenticateResponseCode(std::string response_code)
{
	bool ret = false;

	return ret;
}

__int64 bgAuthentication::GetCurrentFromNTPServer()
{
	__int64 current_time = 0;

	// ʹ��Poco��NtpClient����ȡʱ����Ϣ

	return current_time;
}

std::string bgAuthentication::GetMachineCode()
{
	std::string ret;

	// ��ȡCPU��Ϣ
	std::string processor_identifier = GetProcessorIdentifier();
	std::string processor_name = GetProcessorProcessorNameString();
	std::string processor_vendor_identifier = GetProcessorVendorIdentifier();

	// ��ȡBIOS��Ϣ
	std::string bios_vendor = GetBIOSVendor();
	std::string bios_version = GetBIOSVersion();

	// ��ȡӲ����Ϣ��������ֿɲ���豸��ֱ�Ӳ�����ʹ�ã�
	std::string disk_identifier = GetDiskIdentifier();

	// SHA-256ɢ��
	std::string all_info = processor_identifier;
	all_info += processor_name;
	all_info += processor_vendor_identifier;
	all_info += bios_vendor;
	all_info += bios_version;
	all_info += disk_identifier;

	Poco::SHA1Engine sha1_engine;
	sha1_engine.updateImpl(all_info.data(), all_info.length());
	Poco::DigestEngine::Digest digist = sha1_engine.digest();
	ret = Poco::DigestEngine::digestToHex(digist);

	return ret;
}

std::string bgAuthentication::GetAuthenticateInfo()
{
	int errCode = 0;
	std::string ret = "";

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\LRHW", 0, NULL, 0, KEY_READ, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return ret;
	}

	DWORD dwType = 0;
	char tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegQueryValueExA(hKey, "AU_CODE", NULL, &dwType, (LPBYTE)tszValue, &dwValueLen);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return ret;
	}

	ret = tszValue;
	return ret;
}

bool bgAuthentication::SetAuthenticateInfo(std::string authen_code)
{
	int errCode = 0;
	bool ret = false;

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\LRHW"), 0, NULL, 0, KEY_READ|KEY_WRITE, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return false;
	}

	DWORD dwType = REG_SZ;
	TCHAR tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegSetValueExA(hKey, "AU_CODE", NULL, &dwType, (LPBYTE)authen_code.c_str(), authen_code.size() + 1);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return false;
	}

	return true;
}

std::string bgAuthentication::GetProcessorIdentifier()
{
	int errCode = 0;
	std::string ret = "";

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\CentralProcessor\\0", 0, NULL, 0, KEY_READ, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return ret;
	}

	DWORD dwType = 0;
	char tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegQueryValueExA(hKey, "Identifier", NULL, &dwType, (LPBYTE)tszValue, &dwValueLen);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return ret;
	}

	ret = tszValue;
	return ret;
}

std::string bgAuthentication::GetProcessorProcessorNameString()
{
	int errCode = 0;
	std::string ret = "";

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\CentralProcessor\\0", 0, NULL, 0, KEY_READ, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return ret;
	}

	DWORD dwType = 0;
	char tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegQueryValueExA(hKey, "ProcessorNameString", NULL, &dwType, (LPBYTE)tszValue, &dwValueLen);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return ret;
	}

	ret = tszValue;
	return ret;
}

std::string bgAuthentication::GetProcessorVendorIdentifier()
{
	int errCode = 0;
	std::string ret = "";

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\CentralProcessor\\0", 0, NULL, 0, KEY_READ, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return ret;
	}

	DWORD dwType = 0;
	char tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegQueryValueExA(hKey, "VendorIdentifier", NULL, &dwType, (LPBYTE)tszValue, &dwValueLen);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return ret;
	}

	ret = tszValue;
	return ret;
}

std::string bgAuthentication::GetBIOSVendor()
{
	int errCode = 0;
	std::string ret = "";

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\BIOS", 0, NULL, 0, KEY_READ, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return ret;
	}

	DWORD dwType = 0;
	char tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegQueryValueExA(hKey, "BIOSVendor", NULL, &dwType, (LPBYTE)tszValue, &dwValueLen);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return ret;
	}

	ret = tszValue;
	return ret;
}

std::string bgAuthentication::GetBIOSVersion()
{
	int errCode = 0;
	std::string ret = "";

	// �����ݿ��ȡ����
	HKEY hKey = NULL;
	DWORD dwDisposition = 0;
	LONG lret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\BIOS", 0, NULL, 0, KEY_READ, NULL, &hKey, &dwDisposition);
	if (lret != ERROR_SUCCESS)
	{
		errCode = GetLastError();
		return ret;
	}

	DWORD dwType = 0;
	char tszValue[4096] = {0};
	DWORD dwValueLen = 4096;
	lret = RegQueryValueExA(hKey, "BIOSVersion", NULL, &dwType, (LPBYTE)tszValue, &dwValueLen);
	errCode = GetLastError();

	RegCloseKey(hKey);
	hKey = NULL;

	if (lret != ERROR_SUCCESS)
	{
		return ret;
	}

	ret = tszValue;
	return ret;
}
