#ifndef _CLUAFN_H_
#define _CLUAFN_H_

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua++.h"
}

class CLuaFn
{
public:
	CLuaFn(void);
	virtual ~CLuaFn(void);

	void Init();            //��ʼ��Lua����ָ�����  
	void Close();         //�ر�Lua����ָ��  

	bool LoadLuaFile(const char* pFileName);                              //����ָ����Lua�ļ�  
	bool CallFileFn(const char* pFunctionName, int nParam1, int nParam2);        //ִ��ָ��Lua�ļ��еĺ���  

private:  
	lua_State* m_pState;   //�����Lua��State����ָ�룬�����һ��lua�ļ���Ӧһ����  
};

#endif
