#ifndef _PARAMDATA_H  
#define _PARAMDATA_H  

#include <vector>  
using namespace std;

#define MAX_PARAM_200 200 

typedef struct _ParamData  
{  
public:  
	void* m_pParam;  
	char  m_szType[MAX_PARAM_200];  
	int   m_TypeLen;  
public:  
	_ParamData()  
	{  
		m_pParam    = NULL;  
		m_szType[0] = '\0';  
		m_TypeLen   = 0;  
	};  

	_ParamData(void* pParam, const char* szType, int nTypeLen)  
	{  
		SetParam(pParam, szType, nTypeLen);  
	}  

	~_ParamData() {};  

	void SetParam(void* pParam, const char* szType, int nTypeLen)  
	{  
		m_pParam = pParam;  
		sprintf_s(m_szType, "%s", szType);  
		m_TypeLen = nTypeLen;  
	};  

	bool SetData(void* pParam, int nLen)  
	{  
		if(m_TypeLen < nLen)  
		{  
			return false;  
		}  
		if(nLen > 0)  
		{  
			memcpy(m_pParam, pParam, nLen);  
		}  
		else  
		{  
			memcpy(m_pParam, pParam, m_TypeLen);  
		}  
		return true;  
	}  

	void* GetParam()  
	{  
		return m_pParam;  
	}  

	const char* GetType()  
	{  
		return m_szType;  
	}  

	bool CompareType(const char* pType)  
	{  
		if(0 == strcmp(m_szType, pType))  
		{  
			return true;  
		}  
		else  
		{  
			return false;  
		}  
	}  
} _ParamData;  

class CParamGroup
{
public:
	CParamGroup(void);
	virtual ~CParamGroup(void);

	void Init();

	void Close();

	void Push(_ParamData* pParam) ;

	_ParamData* GetParam(int nIndex) ; 

	int GetCount() ;


private:  
	typedef vector<_ParamData*> vecParamData;

	vecParamData m_vecParamData; 

	//vector<_ParamData*> m_vecParamData;
};

#endif

