#ifndef _bgAuthentication_H_
#define _bgAuthentication_H_

#include <string>

class bgAuthentication
{
public:
	bgAuthentication();
	~bgAuthentication();

public:
	// ��鱾���������Ȩ��Ϣ���Ƿ�����Ȩ��Χ��
	// ���ؽ��
	bool CheckAuthentication();

	// �����µ���Ȩ������
	std::string GetNewAuthenRequestCode();

	// ��֤����Ա���ص���Ȩ��
	bool VerifyAuthenticateResponseCode(std::string response_code);

private:
	// ץȡ��ʰ��������ʱ��
	__int64 GetCurrentFromNTPServer();

	// ��ȡ������
	std::string GetMachineCode();

	// ��ȡ���ر������Ȩ��Ϣ
	std::string GetAuthenticateInfo();
	
	// ����֤������Ȩ��Ϣд�뱾��
	bool SetAuthenticateInfo(std::string authen_code);

private:
	std::string GetProcessorIdentifier();
	std::string GetProcessorProcessorNameString();
	std::string GetProcessorVendorIdentifier();

	std::string GetBIOSVendor();
	std::string GetBIOSVersion();

	std::string GetDiskIdentifier();
};

// ����һ����������
extern bgAuthentication authenticater;

#endif//_bgAuthentication_H_
