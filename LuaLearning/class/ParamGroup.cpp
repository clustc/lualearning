#include "ParamGroup.h"


CParamGroup::CParamGroup(void)
{
}


CParamGroup::~CParamGroup(void)
{
}


void CParamGroup::Init()  
{  
	m_vecParamData.clear();  
};  

void CParamGroup::Close()  
{  
	for(int i = 0; i < (int)m_vecParamData.size(); i++)  
	{  
		_ParamData* pParamData = m_vecParamData[i];  
		delete pParamData;  
		pParamData = NULL;  
	}  
	m_vecParamData.clear();  
};  



void CParamGroup::Push(_ParamData* pParam)  
{  
	if(pParam != NULL)  
	{  
		m_vecParamData.push_back(pParam);  
	}  
};  



_ParamData* CParamGroup::GetParam(int nIndex)  
{  
	if(nIndex < (int)m_vecParamData.size())  
	{  
		return m_vecParamData[nIndex];  
	}  
	else  
	{  
		return NULL;  
	}  
};  

int CParamGroup::GetCount()  
{  
	return (int)m_vecParamData.size();  
}  