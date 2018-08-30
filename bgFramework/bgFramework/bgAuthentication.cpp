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

	// 首先获取本机的机器码
	std::string machine_code = GetMachineCode();

	// 从数据库取出验证码
	std::string authen_info = GetAuthenticateInfo();

	// 先用base64还原为“加密验证码”
	int cipher_authen_code_len = 1024;
	char *cipher_authen_code = new char[cipher_authen_code_len];
	int errCode = bgBase::Base64Decode(authen_info, cipher_authen_code, cipher_authen_code_len);
	if (errCode == -1)
	{
	}

	// 然后将“加密验证码”解密

	// 比对机器码，验证授权码是否合法，是否在同一台机器上

	// 验证授权期限

	// 内存缓存授权功能

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

	// 获取CPU信息

	// 获取硬盘信息（如果发现可插拔设备，直接不允许使用）

	// 获取网卡信息

	// SHA-256散列

	// Base64字符化

	return ret;
}

std::string bgAuthentication::GetAuthenticateInfo()
{
	std::string ret;

	// 从数据库读取数据

	return ret;
}

bool bgAuthentication::SetAuthenticateInfo(std::string authen_code)
{
	bool ret = false;

	return ret;
}