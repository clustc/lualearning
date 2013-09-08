#include "LuaFn.h"


CLuaFn::CLuaFn(void): m_pState(NULL)
{
	Init();
}


CLuaFn::~CLuaFn(void)
{
}

void CLuaFn::Init()
{
	if(NULL == m_pState)  
	{  
		m_pState = lua_open();  
		luaL_openlibs(m_pState);  
	}  
}

void CLuaFn::Close()
{
	if(NULL != m_pState)  
	{  
		lua_close(m_pState);  
		m_pState = NULL;  
	}  
}

bool CLuaFn::LoadLuaFile( const char* pFileName )
{
	int nRet = 0;  

	if(NULL == m_pState)  

	{  

		printf("[CLuaFn:: LoadLuaFile]m_pState is NULL.\n");  

		return false;  

	}  
	nRet = luaL_dofile(m_pState, pFileName);  

	if (nRet != 0)  

	{
		printf("[CLuaFn:: LoadLuaFile]luaL_loadfile(%s) is file(%d)(%s).\n", pFileName, nRet, lua_tostring(m_pState, -1));  
		return false;  
	}  

	return true;  
}

bool CLuaFn::CallFileFn( const char* pFunctionName, int nParam1, int nParam2 )
{
	int nRet = 0;  

	if(NULL == m_pState)  

	{  

		printf("[CLuaFn::CallFileFn]m_pState is NULL.\n");  

		return false;  

	}  



	lua_getglobal(m_pState, pFunctionName);  



	lua_pushnumber(m_pState, nParam1);  

	lua_pushnumber(m_pState, nParam2);  



	nRet = lua_pcall(m_pState, 2, 1, 0);  

	if (nRet != 0)  

	{  

		printf("[CLuaFn::CallFileFn]call function(%s) error(%d).\n", pFunctionName, nRet);  

		return false;  

	}  



	if (lua_isnumber(m_pState, -1) == 1)  

	{  

		int nSum = lua_tonumber(m_pState, -1);  

		printf("[CLuaFn::CallFileFn]Sum = %d.\n", nSum);  

	}  



	return true;  
}
