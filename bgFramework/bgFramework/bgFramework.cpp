// bgFramework.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ����в����Ͱ��ղ���ִ�У����簲װ��ж��
	// ���û�в���������ϵͳ�����������������
	bret = svr.RegisterService(argc, argv);
#endif

	return 0;
}

