// LuaLearning.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LuaFn.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CLuaFn LuaFn;
	LuaFn.LoadLuaFile("src/sample.lua");
	LuaFn.CallFileFn("func_Add", 132, 412);

	getchar();

	return 0;
}

