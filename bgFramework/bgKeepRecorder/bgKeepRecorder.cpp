// bgKeepRecorder.cpp : 定义控制台应用程序的入口点。
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
	{ 0, "萌宝宝", "", "涵宝儿", "" },
	{ -1, "大小姐", "", "" }
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 这里简单定义几个业务
	return 0;
}

