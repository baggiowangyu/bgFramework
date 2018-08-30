// bgFramework.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <tchar.h>
#include "bgFrameworkSrv.h"


int _tmain(int argc, _TCHAR* argv[])
{
	bgFrameworkSrv svr(_T("bgFramework"), _T("bgFramework"));

	BOOL bret = FALSE;
#ifdef _DEBUG
	bret = svr.DebugService(argc, argv);
#else
	// 如果有参数就按照参数执行，例如安装，卸载
	// 如果没有参数，则由系统服务管理器启动服务
	bret = svr.RegisterService(argc, argv);
#endif

	return 0;
}

