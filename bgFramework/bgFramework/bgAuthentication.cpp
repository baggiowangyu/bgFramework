#include "bgAuthentication.h"
#include "bgBase.h"

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
	int errCode = bgBase::Base64Decode(authen_info, cipher_authen_code, cipher_authen_code_len);
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

	return current_time;
}

std::string bgAuthentication::GetMachineCode()
{
	std::string ret;

	// ��ȡCPU��Ϣ

	// ��ȡӲ����Ϣ��������ֿɲ���豸��ֱ�Ӳ�����ʹ�ã�

	// ��ȡ������Ϣ

	// SHA-256ɢ��

	// Base64�ַ���

	return ret;
}

std::string bgAuthentication::GetAuthenticateInfo()
{
	std::string ret;

	// �����ݿ��ȡ����

	return ret;
}

bool bgAuthentication::SetAuthenticateInfo(std::string authen_code)
{
	bool ret = false;

	return ret;
}