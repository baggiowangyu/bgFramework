// bgKeepRecorder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>


typedef struct _KEEP_INFO_
{
	int index_;
	std::string app_name_;
	std::string app_code_;
	std::string room_name_;
	std::string last_url_;
} KEEP_INFO;

const KEEP_INFO *keep_info[] = {
	{ 0, "�ȱ���", "", "������", "" },
	{ -1, "��С��", "", "" }
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ����򵥶��弸��ҵ��
	return 0;
}

