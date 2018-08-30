#include "bgFrameworkSrv.h"
#include "bgBase.h"

bgFrameworkSrv::bgFrameworkSrv(LPCTSTR ServiceName, LPCTSTR DisplayName /* = 0 */)
: CNTService(ServiceName, DisplayName)
{

}

bgFrameworkSrv::~bgFrameworkSrv()
{

}

void bgFrameworkSrv::Run(DWORD argc, LPTSTR * argv)
{
	
	while (true)
	{
		Sleep(1000);
		bgBase::DebugStringOutput("bgFrameworkSrv::Run()");
	}

	return ;
}

void bgFrameworkSrv::Stop()
{
	return ;
}