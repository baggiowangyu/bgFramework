#ifndef _bgFrameworkSrv_H_
#define _bgFrameworkSrv_H_

#include <tchar.h>
#include "NTService.h"

class bgFrameworkSrv : public CNTService
{
public:
	bgFrameworkSrv(LPCTSTR ServiceName, LPCTSTR DisplayName = 0);
	~bgFrameworkSrv();

public:
	virtual void	Run(DWORD argc, LPTSTR * argv);
	virtual void	Stop();
};

#endif//_bgFrameworkSrv_H_
