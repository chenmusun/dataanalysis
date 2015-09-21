//#include "StdAfx.h"
#include "LTE_PS_DataStat.h"
#include <string>
#define INVALIDVALUE_FLOAT	FLT_MAX

CPSDataStatBase_LTE::CPSDataStatBase_LTE(int nItemType, void* pItemCount, void* pItemValue,enLTE_PSStat_Count_Type nType, enLTE_PSStat_Value_Type nValueType)
{
	m_nItemType=nItemType; //IE���¼�����
	m_nCountType=nType;//ͳ������
	m_nValueType=nValueType;//����ֶ�����

	m_pItemCount=pItemCount; //��Ӧ��ͳ�Ʊ�����ֶΣ������ۼ�

	m_pItemValue=pItemValue; //��Ӧ��ͳ�Ʊ�����ֶΣ�ֵ�ۼ�

	m_nTotalCount=0;
	m_nTotalValue=0;

	m_nCurItemValue=-1;

}

CPSDataStatBase_LTE::~CPSDataStatBase_LTE(void)
{
    
}


int CPSDataStatBase_LTE::AnalysisData(DTANASTATDATAITEM& dtitem)
{
	int nResult = 0;
	GetCurItemValue(dtitem);		
	CalcCurValue(dtitem);
			

	return nResult;
}

int CPSDataStatBase_LTE::GetCurItemValue(DTANASTATDATAITEM& dtitem)
{
	m_nCurItemValue=-1;
	if (dtitem.uiIENumber!=INVALIDVALUE_UINT32)
	{
		m_nCurItemValue=dtitem.llIEValue2;
	}

	return m_nCurItemValue;
	
}

void CPSDataStatBase_LTE::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	m_nTotalCount++;

	if (m_nCurItemValue ==-1)
		return;
	m_nTotalValue+=m_nCurItemValue;
	//TRACE("total=%I64d,cur=%d\r\n",m_nTotalValue,m_nCurItemValue);
}

int CPSDataStatBase_LTE::DoConclusion()
{
	int nResult = 0;
	if (m_nCountType==LTE_PSStat_Total_Count)
	{
		if (m_pItemCount!=NULL)
			*((int*)m_pItemCount)=m_nTotalCount;
	}
	else if (m_nCountType==LTE_PSStat_Total_Value)
	{
		if (m_pItemValue!=NULL)
		{
			if (m_nValueType==LTE_PSStat_Value_Int)
				*((int*)m_pItemValue)=(int)m_nTotalValue;
			else if (m_nValueType==LTE_PSStat_Value_Double)
				*((double*)m_pItemValue)=m_nTotalValue/1000.0;
		}
	}
	else if (m_nCountType==LTE_PSStat_Total_All)
	{
		if (m_pItemCount!=NULL)
			*((int*)m_pItemCount)=m_nTotalCount;

		if (m_pItemValue!=NULL)
		{
			if (m_nValueType==LTE_PSStat_Value_Int)
				*((int*)m_pItemValue)=(int)m_nTotalValue;
			else if (m_nValueType==LTE_PSStat_Value_Double)
				*((double*)m_pItemValue)=m_nTotalValue/1000.0;
		}
	}

	return nResult;
}

//-----------------------CPSDataStat_LTE_IESingle-------------------------------------
CPSDataStat_LTE_IESingle::CPSDataStat_LTE_IESingle(int nItemType, vector<void*>* vecStatInfo)
:CPSDataStatBase_LTE(nItemType, NULL, NULL, LTE_PSStat_Total_Value)
{
	if (vecStatInfo!=NULL)
	{
		m_vecStatInfo = *vecStatInfo;
	}
}

CPSDataStat_LTE_IESingle::~CPSDataStat_LTE_IESingle(void)
{
	
}

void CPSDataStat_LTE_IESingle::AddStatCondition(vector<int>& vecIEValue)
{
	for(vector<int>::iterator it = vecIEValue.begin(); it != vecIEValue.end(); it++)
	{
		CIEStatSingle IEStat(*it);
		m_mapIESingleItem[*it]=IEStat;
	}

}

 //count++
void CPSDataStat_LTE_IESingle::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	if (m_nCurItemValue ==-1)
		return;

	map<int,CIEStatSingle>::iterator itFind=m_mapIESingleItem.find(m_nCurItemValue);
	if (itFind != m_mapIESingleItem.end())
	{
		itFind->second.m_nCount += 1;
	}
}

//Ĭ��m_nCount��int������
int CPSDataStat_LTE_IESingle::DoConclusion()
{
	int nResult = 0;

	if (m_vecStatInfo.size()==0)
		return nResult;

	int i=0;
	for(map<int,CIEStatSingle>::iterator it = m_mapIESingleItem.begin(); it != m_mapIESingleItem.end(); it++)
	{
		*((int*)m_vecStatInfo[i])=(int)(it->second.m_nCount);
		i++;
	}
	return nResult;
}

//-----------------------CPSDataStat_LTE_IE_UseTime-------------------------------------
CPSDataStat_LTE_IE_UseTime::CPSDataStat_LTE_IE_UseTime(int nItemType, vector<void*>* vecStatInfo,double* pTime_new)
:CPSDataStat_LTE_IESingle(nItemType, vecStatInfo)
{
	m_pTime_new=pTime_new; //��ǰʱ��
	m_nLastValue=-1;
	m_dbLastTime=-1;  //��һ���ϱ���ʱ��
}

CPSDataStat_LTE_IE_UseTime::~CPSDataStat_LTE_IE_UseTime(void)
{

}

//ʱ���ۼ�
void CPSDataStat_LTE_IE_UseTime::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	if (m_nCurItemValue ==-1 || m_nCurItemValue==m_nLastValue)  //��ǰ�ϱ�ֵû�б仯���򲻴���
		return;

	double dbCurTime=*m_pTime_new;
	if (m_nLastValue==-1 && m_dbLastTime<0) //��һ���ϱ��Ĵ���
	{
		m_nLastValue=m_nCurItemValue;
		m_dbLastTime=dbCurTime; 
		return;
	}

	map<int,CIEStatSingle>::iterator itFind=m_mapIESingleItem.find(m_nLastValue); //�ϱ�ֵ�仯��ʱ���ۼƵ���һ����ռ��ʱ��
	if (itFind != m_mapIESingleItem.end())
	{
		itFind->second.m_nCount += dbCurTime-m_dbLastTime;  //ʱ���ۼ�
	}

	m_nLastValue=m_nCurItemValue;
	m_dbLastTime=dbCurTime; 
}

//Ĭ��m_nCount��int������
int CPSDataStat_LTE_IE_UseTime::DoConclusion()
{
	int nResult = 0;
	//������ʱ���ۼ�
	double dbCurTime=*m_pTime_new;

	if (m_nLastValue!=-1 && dbCurTime>m_dbLastTime)
	{
		map<int,CIEStatSingle>::iterator itFind=m_mapIESingleItem.find(m_nLastValue); //ʱ���ۼƵ���һ����ռ��ʱ��
		if (itFind != m_mapIESingleItem.end())
		{
			itFind->second.m_nCount += dbCurTime-m_dbLastTime;  //ʱ���ۼ�
		}
	}

	//��ֵ
	int i=0;
	for(map<int,CIEStatSingle>::iterator it = m_mapIESingleItem.begin(); it != m_mapIESingleItem.end(); it++)
	{
		*((double*)m_vecStatInfo[i])=it->second.m_nCount;
		i++;
	}
	return nResult;
}

//---------------------------CPSDataStat_LTE_IE_MCS-----------------------------------------------------
CPSDataStat_LTE_IE_MCS::CPSDataStat_LTE_IE_MCS(int nItemType, CLogInfo_LTE_PS* pLogInfoLTEPS,enLTE_PSStat_MCS_Type nMCSType)
:CPSDataStat_LTE_IESingle(nItemType,NULL)
{
	m_nMCSType=nMCSType;
	m_pLogInfo_LTE_PS=pLogInfoLTEPS;
}

CPSDataStat_LTE_IE_MCS::~CPSDataStat_LTE_IE_MCS(void)
{

}

void CPSDataStat_LTE_IE_MCS::GetMCSValue(vector<int>& vecData, const string& str)
{
	string::size_type bPos = 0;
	string::size_type ePos = 0;
	while((ePos = str.find(';',bPos)) != -1)
	{
		vecData.push_back(atoi((str.substr(bPos, ePos - bPos)).c_str()));
		bPos = ePos + 1;
	}
}

int CPSDataStat_LTE_IE_MCS::GetCurItemValue(DTANASTATDATAITEM& dtitem)
{
	string strValue="";
	m_vecMCSValue.clear();
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		if (!dtitem.strDLMCS0.empty())
		{
			strValue=dtitem.strDLMCS0;
		}
		break;
	case DL_Code1_MCS:
		if (!dtitem.strDLMCS1.empty())
		{
			strValue=dtitem.strDLMCS1;
		}
		break;
	case UL_MCS:
		if (!dtitem.strULMCS.empty())
		{
			strValue=dtitem.strULMCS;
		}
		break;
	default:
		return -1;
	}
	if (!strValue.empty())
	{
		GetMCSValue(m_vecMCSValue,strValue);
	}

	return -1;
}


//Count += CurValue
void CPSDataStat_LTE_IE_MCS::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	if(m_vecMCSValue.size() != 32)
		return;

	CIEStatSingle* pIEStat=NULL;
	for(int i=0; i<32; i++)
	{
		pIEStat=&(m_mapIESingleItem[i]);
		int nValue=m_vecMCSValue[i];
		if (pIEStat!=NULL && nValue!=0)
		{
			pIEStat->m_nCount+=nValue;  //ֵ�ۼ�
 		}
	}
}


int CPSDataStat_LTE_IE_MCS::DoConclusion()
{
	int nResult = 0;

	int nIndex=0;
	CIEStatSingle* pIEStat=NULL;

	pIEStat=&(m_mapIESingleItem[nIndex]);  //0
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS0_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS0_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS0_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //1
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS1_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS1_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS1_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //2
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS2_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS2_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS2_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //3
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS3_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS3_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS3_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //4
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS4_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS4_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS4_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //5
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS5_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS5_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS5_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //6
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS6_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS6_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS6_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //7
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS7_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS7_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS7_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //8
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS8_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS8_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS8_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //9
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS9_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS9_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS9_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //10
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS10_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS10_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS10_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //11
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS11_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS11_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS11_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //12
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS12_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS12_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS12_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //13
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS13_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS13_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS13_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //14
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS14_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS14_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS14_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //15
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS15_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS15_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS15_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //16
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS16_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS16_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS16_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //17
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS17_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS17_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS17_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //18
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS18_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS18_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS18_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //19
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS19_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS19_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS19_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //20
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS20_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS20_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS20_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //21
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS21_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS21_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS21_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //22
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS22_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS22_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS22_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //23
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS23_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS23_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS23_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //24
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS24_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS24_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS24_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //25
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS25_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS25_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS25_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //26
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS26_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS26_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS26_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //27
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS27_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS27_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS27_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //28
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS28_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS28_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS28_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //29
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS29_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS29_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS29_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //30
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS30_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS30_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS30_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //31
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code0_MCS31_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_PS->m_ulDL_Code1_MCS31_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_PS->m_ulUL_MCS31_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}	
	
	return nResult;
}


//---------------------------CPSDataStat_LTE_IEArea-----------------------------------------------------
CPSDataStat_LTE_IEArea::CPSDataStat_LTE_IEArea(int nItemType, CLogInfo_LTE_PS* pLogInfoLTEPS,enLTE_PSStat_Area_IEType nIEType)
:CPSDataStatBase_LTE(nItemType,NULL,NULL)
{
	m_nIEType=nIEType;
	m_pLogInfo_LTE_PS=pLogInfoLTEPS;
}

CPSDataStat_LTE_IEArea::~CPSDataStat_LTE_IEArea(void)
{

}


void CPSDataStat_LTE_IEArea::AddStatCondition(vector<CIEStatArea>& vecIEArea)
{
	m_vecIEAreaItem=vecIEArea;
}

int CPSDataStat_LTE_IEArea::GetCurItemValue(DTANASTATDATAITEM& dtitem)
{
	m_fCurItemValue=INVALIDVALUE_FLOAT;
	switch (m_nIEType)
	{
	case LTE_PSStat_Area_RSRP:
		if (dtitem.ulEastShift != INVALIDVALUE_INT32)
		{
			m_fCurItemValue=((int)dtitem.ulEastShift)/1000.0;
		}
		break;
	case LTE_PSStat_Area_SINR:
		if (dtitem.ulHeightShift != INVALIDVALUE_INT32)
		{
			m_fCurItemValue=((int)dtitem.ulHeightShift)/1000.0;
		}
		break;
	case LTE_PSStat_Area_RSRQ:
		if (dtitem.ulFloor != INVALIDVALUE_INT32)
		{
			m_fCurItemValue=((int)dtitem.ulFloor)/1000.0;
		}
		break;
	default:
		break;
	}

	return m_fCurItemValue;
}


//����䷶Χ�ڣ�Count++
void CPSDataStat_LTE_IEArea::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	if (m_fCurItemValue==INVALIDVALUE_FLOAT)
		return;

	for(vector<CIEStatArea>::iterator it = m_vecIEAreaItem.begin(); it != m_vecIEAreaItem.end(); it++)
	{
		if (m_fCurItemValue >= it->m_fMinIEValue && m_fCurItemValue < it->m_fMaxIEValue)  //����ҿ�
		{
			it->m_nCount++;  //����
			break;
		}
	}
}


int CPSDataStat_LTE_IEArea::DoConclusion()
{
	int nResult = 0;
	int nIndex=0;
	if (m_nIEType==LTE_PSStat_Area_RSRP)
	{
		m_pLogInfo_LTE_PS->m_ulRSRP_60_44_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_65_60_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_70_65_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_75_70_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_80_75_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_85_80_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_90_85_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_95_90_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_100_95_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_105_100_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_110_105_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_141_110_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	}

	nIndex=0;
	if (m_nIEType==LTE_PSStat_Area_SINR)//SINR���ֲ�ͳ��
	{
		m_pLogInfo_LTE_PS->m_ulSINR_25_50_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_20_25_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_15_20_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_10_15_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_6_10_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_3_6_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_0_3_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_3_0_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_6_3_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_10_6_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_50_10_Num=m_vecIEAreaItem[nIndex++].m_nCount;

	}

	nIndex=0;
	if (m_nIEType==LTE_PSStat_Area_RSRQ)//RSRQ���ֲ�ͳ��
	{
		m_pLogInfo_LTE_PS->m_ulRSRQ_35_30_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_55_35_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_75_55_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_95_75_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_115_95_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_135_115_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_155_135_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_175_155_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_196_175_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	}

	return nResult;
}


//---------------------------CPSDataStat_LTE_Event-----------------------------------------------------
CPSDataStat_LTE_Event::CPSDataStat_LTE_Event(int nItemType, CLogInfo_LTE_PS* pLogInfoLTEPS,enLTE_PSStat_Event_Type nEventType,double* pTime_new, CPSDataStat_LTE_Event* pStartStat)
:CPSDataStatBase_LTE(nItemType,NULL,NULL,LTE_PSStat_Total_Count)
{
	m_nEventType=nEventType;
	m_pLogInfo_LTE_PS=pLogInfoLTEPS;
	m_pStartStat=pStartStat; //��ʼ�¼�ͳ��ʵ������¼���Ҫ��ȡ��ʼ�¼���ʱ�����ʱ��
	m_pTime_new=pTime_new; //��ǰʱ��
	
	m_dbCurTime=-1;  //��ǰʱ��

	m_dbTotal_Delay=0;//ʱ�Ӻ�
}

CPSDataStat_LTE_Event::~CPSDataStat_LTE_Event(void)
{

}

double CPSDataStat_LTE_Event::GetStartTime()
{
	return m_dbCurTime;
}

void CPSDataStat_LTE_Event::SetStartTime(double dbTime)
{
	m_dbCurTime=dbTime;
}

void CPSDataStat_LTE_Event::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	
	if (m_nEventType==LTE_PSStat_Event_Start)  //��ʼ�¼�
	{
		CPSDataStatBase_LTE::CalcCurValue(dtitem); //Count++
		m_dbCurTime=*m_pTime_new;  //��ʼʱ�����
	}
	else if (m_nEventType==LTE_PSStat_Event_End)  //�����¼�
	{
		//�ж��п�ʼ�¼��ϱ����Ž���ͳ�ƣ����Ե���ƥ����¼�
		if (m_pStartStat!=NULL && m_pStartStat->GetStartTime() > 0 )
		{
			CPSDataStatBase_LTE::CalcCurValue(dtitem); //Count++
			m_dbTotal_Delay += (*m_pTime_new) - m_pStartStat->GetStartTime();  //ʱ���ۼ�
			m_pStartStat->SetStartTime(-1); //����ʼ�¼�ʱ�临λΪ�Ƿ�ֵ
		}

	}
	else //normal�¼�
	{
		CPSDataStatBase_LTE::CalcCurValue(dtitem); //Count++
	}
	
}

int CPSDataStat_LTE_Event::DoConclusion()
{
	int nResult = 0;
	if (m_nEventType==LTE_PSStat_Event_Start)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_HANDOVER_ATTEMP:  //�����л����Դ���:Handover Start�¼��ϱ�����    
			m_pLogInfo_LTE_PS->m_ulLTE_LTE_Handover_Start_NUM=m_nTotalCount;
			break;
		case PREDEFINE_LTE_HANDOVER_TO_TD_ATTEMP:  ////LTE-TD�л����Դ���:TDSCDMA from LTE Handover Start�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulLTE_TD_Handover_Start_NUM=m_nTotalCount;
			break;
		case PREDEFINE_LTE_HANDOVER_FROM_TD_ATTEMP: //TD-LTE�л����Դ���:TDSCDMA to LTE Handover Start�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulTD_LTE_Handover_Start_NUM=m_nTotalCount;
			break;
		case PREDEFINE_CELLRESEL_ATTEMP_L2T: //LTE-TD��ѡ����:TDSCDMA from LTE Resel Start�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulLTE_TD_Resel_Start_NUM=m_nTotalCount;
			break;
		case PREDEFINE_CELLRESEL_ATTEMP_T2L: //TD-LTE��ѡ����:TDSCDMA to LTE Resel Start�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulTD_LTE_Resel_Start_NUM=m_nTotalCount;

		case PREDEFINE_LTE_ATTACH_ATTEMP: //Attch���Դ���:EPS Attach Request�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulEPS_Attach_Request_NUM=m_nTotalCount;
			break;
		case PREDEFINE_LTE_SERVICE_ATTEMP: //Service�������:SERVICE REQUEST�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulSERVICE_Request_NUM=m_nTotalCount;
			break;
		case PREDEFINE_LTE_TAU_ATTEMP: //TA���³��Դ���:TAU Request�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulTAU_Request_NUM=m_nTotalCount;
			break;
		default:
			return nResult;
		}
	}
	else if (m_nEventType==LTE_PSStat_Event_End)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_HANDOVER_SUCCESS:  //�����л��ɹ�����:Handover Success�¼��ϱ�����    
			m_pLogInfo_LTE_PS->m_ulLTE_LTE_Handover_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbLTE_LTE_Handover_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_HANDOVER_TO_TD_SUCCESS:  //LTE-TD�л��ɹ�����:TDSCDMA from LTE Handover Success�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulLTE_TD_Handover_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbLTE_TD_Handover_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_HANDOVER_FROM_TD_SUCCESS: //TD-LTE�л��ɹ�����:TDSCDMA to LTE Handover Success�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulTD_LTE_Handover_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbTD_LTE_Handover_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_CELLRESEL_SUCCESS_L2T: //LTE-TD��ѡ�ɹ�����:TDSCDMA from LTE Resel Success�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulLTE_TD_Resel_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbLTE_TD_Resel_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_CELLRESEL_SUCCESS_T2L: //TD-LTE��ѡ�ɹ�����:TDSCDMA to LTE Resel Success�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulTD_LTE_Resel_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbTD_LTE_Resel_Total_Delay=m_dbTotal_Delay;
		case PREDEFINE_LTE_ATTACH_SUCCESS: //Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulEPS_Attach_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbEPS_Attach_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_SERVICE_SUCCESS: //Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulSERVICE_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbSERVICE_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_TAU_SUCCESS: //TA���³ɹ�����:TAU Success�¼��ϱ�����
			m_pLogInfo_LTE_PS->m_ulTAU_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_PS->m_dbTAU_Total_Delay=m_dbTotal_Delay;
			break;
		default:
			return nResult;
		}
	}
	else if (m_nEventType==LTE_PSStat_Event_Normal)
	{
		
	}
	

	return nResult;
}



//---------------------------CDataStat_LTE_Event_CSFB-----------------------------------------------------
CDataStat_LTE_Event_CSFB::CDataStat_LTE_Event_CSFB(int nItemType, CLogInfo_LTE_CS_CSFB* pLogInfoLTECSFB,enLTE_PSStat_Event_Type nEventType,double* pTime_new, CPSDataStat_LTE_Event* pStartStat)
:CPSDataStat_LTE_Event(nItemType,NULL,nEventType,pTime_new,pStartStat)
{
	m_pLogInfo_LTE_CS_CSFB=pLogInfoLTECSFB;
}

CDataStat_LTE_Event_CSFB::~CDataStat_LTE_Event_CSFB(void)
{

}

int CDataStat_LTE_Event_CSFB::DoConclusion()
{
	int nResult = 0;
	if (m_nEventType==LTE_PSStat_Event_Start)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_CSFB_START_MO:  //CSFB�Ժ��������У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Start_NUM_MO=m_nTotalCount;
			break;
		case PREDEFINE_LTE_CSFB_RETURN_START_MO:  //GSM-LTE���Դ������У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Return_Start_NUM_MO=m_nTotalCount;
			break;
		case PREDEFINE_LTE_CSFB_START_MT:  //CSFB�Ժ�����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Start_NUM_MT=m_nTotalCount;
			break;
		case PREDEFINE_LTE_CSFB_RETURN_START_MT:  //GSM-LTE���Դ���У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Return_Start_NUM_MT=m_nTotalCount;
			break;
		default:
			return nResult;
		}
	}
	else if (m_nEventType==LTE_PSStat_Event_End)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_CSFB_SUCCESS_MO:  //CSFB LTE2GSM�ɹ��������У���LTE2GSM��ѡʱ�Ӻ�(s)�����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Success_NUM_MO=m_nTotalCount;
			m_pLogInfo_LTE_CS_CSFB->m_dbL2G_Resel_Total_Delay_MO=m_dbTotal_Delay;  
			break;
		case PREDEFINE_LTE_CSFB_ALERTING_MO:  //CSFB����������У���CSFB���н���ʱ�Ӻ�(s) �����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Alerting_NUM_MO=m_nTotalCount;
			m_pLogInfo_LTE_CS_CSFB->m_dbCSFB_Call_Start_Total_Delay_MO=m_dbTotal_Delay; 
			break;
		case PREDEFINE_LTE_CSFB_RETURN_END_MO:  //GSM-LTE�ɹ��������У���GSM2LTE��ѡʱ�Ӻ�(s)�����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Return_End_NUM_MO=m_nTotalCount;
			m_pLogInfo_LTE_CS_CSFB->m_dbG2L_Resel_Total_Delay_MO=m_dbTotal_Delay; 
			break;
		case PREDEFINE_LTE_CSFB_SUCCESS_MT:  //CSFB LTE2GSM�ɹ�����У���LTE2GSM��ѡʱ�Ӻ�(s)�����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Success_NUM_MT=m_nTotalCount;
			m_pLogInfo_LTE_CS_CSFB->m_dbL2G_Resel_Total_Delay_MT=m_dbTotal_Delay; 
			break;
		case PREDEFINE_LTE_CSFB_CONNECT_MT:  //CSFB��ͨ����У���CSFB���н���ʱ�Ӻ�(s) �����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Connect_NUM_MT=m_nTotalCount;
			m_pLogInfo_LTE_CS_CSFB->m_dbCSFB_Call_Start_Total_Delay_MT=m_dbTotal_Delay; 
		case PREDEFINE_LTE_CSFB_RETURN_END_MT:  //GSM-LTE�ɹ�����У���GSM2LTE��ѡʱ�Ӻ�(s)�����У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Return_End_NUM_MT=m_nTotalCount;
			m_pLogInfo_LTE_CS_CSFB->m_dbG2L_Resel_Total_Delay_MT=m_dbTotal_Delay; 

			break;
		default:
			return nResult;
		}
	}
	else if (m_nEventType==LTE_PSStat_Event_Normal)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_CSFB_CONNECT_MO:  //CSFB��ͨ�������У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Connect_NUM_MO=m_nTotalCount;
			break;
		case PREDEFINE_LTE_CSFB_DROP_MO:  //CSFB���ߴ������У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Drop_NUM_MO=m_nTotalCount;
			break;
		case PREDEFINE_LTE_CSFB_DROP_MT:  //GSM-LTE���Դ���У�
			m_pLogInfo_LTE_CS_CSFB->m_ulCSFB_Drop_NUM_MT=m_nTotalCount;
			break;
		default:
			return nResult;
		}
	}

	return nResult;
}

//---------------------------CPSDataStat_LTE_IEArea-----------------------------------------------------
CDataStat_LTE_IEArea_CSFB::CDataStat_LTE_IEArea_CSFB(int nItemType, CLogInfo_LTE_CS_CSFB* pLogInfoLTECSFB)
:CPSDataStat_LTE_IEArea(nItemType,NULL,LTE_PSStat_Area_RSRP)
{
	m_pLogInfo_LTE_CS_CSFB=pLogInfoLTECSFB;
}

CDataStat_LTE_IEArea_CSFB::~CDataStat_LTE_IEArea_CSFB(void)
{

}


int CDataStat_LTE_IEArea_CSFB::GetCurItemValue(DTANASTATDATAITEM& dtitem)
{
	m_fCurItemValue=INVALIDVALUE_FLOAT;
	
	
	if (dtitem.usMOSScore !=INVALIDVALUE_UINT16)  
	{
		m_fCurItemValue=dtitem.usMOSScore/100.0;
	}

	return m_fCurItemValue;
}

int CDataStat_LTE_IEArea_CSFB::DoConclusion()
{
	int nResult = 0;
	int nIndex=0;
	
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_0_2_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_2_22_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_22_24_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_24_26_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_26_28_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_28_30_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_30_32_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_32_34_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_34_36_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_36_38_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_38_40_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	m_pLogInfo_LTE_CS_CSFB->m_ulMOS_40_50_Num=m_vecIEAreaItem[nIndex++].m_nCount;

	return nResult;
}

// CDataStat_LTE_EventAttachʵ�� [4/30/2015 liangdongxu]
CDataStat_LTE_EventAttach::CDataStat_LTE_EventAttach(int nItemType, CLogInfo_LTE_Attach* pLogInfo_LTE_Attach, enLTE_PSStat_Event_Type nEventType, double* pTime_new /* = NULL */, CPSDataStat_LTE_Event* pStartStat/* =NULL */)
:CPSDataStat_LTE_Event(nItemType,NULL,nEventType,pTime_new,pStartStat)
{
	m_pLogInfo_LTE_Attach = pLogInfo_LTE_Attach;
}


CDataStat_LTE_EventAttach::~CDataStat_LTE_EventAttach(void)
{

}

int CDataStat_LTE_EventAttach::DoConclusion()
{
	int nResult = 0;
	if (m_nEventType==LTE_PSStat_Event_Start)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_ATTACH_ATTEMP: //Attch���Դ���:EPS Attach Request�¼��ϱ�����
			m_pLogInfo_LTE_Attach->m_ulEPS_Attach_Request_NUM=m_nTotalCount;
			break;
		case PREDEFINE_LTE_SERVICE_ATTEMP: //Service�������:SERVICE REQUEST�¼��ϱ�����
			m_pLogInfo_LTE_Attach->m_ulSERVICE_Request_NUM=m_nTotalCount;
			break;
		//�ƶ���
		case PREDEFINE_LTE_HANDOVER_ATTEMP:
			m_pLogInfo_LTE_Attach->m_ulLTE_LTE_Handover_Start_NUM = m_nTotalCount;
			break;
		case PREDEFINE_LTE_INTRAHO_ATTEMP:
			m_pLogInfo_LTE_Attach->m_ulLTE_intraHandover_Start_NUM = m_nTotalCount;	//LTEƵ���л�
			break;
		case PREDEFINE_LTE_INTERHO_ATTEMP:
			m_pLogInfo_LTE_Attach->m_ulLTE_interHandover_Start_NUM = m_nTotalCount;	//LTEƵ���л�
			break;
		case PREDEFINE_CELLRESEL_ATTEMP_L2T:
			m_pLogInfo_LTE_Attach->m_ulLTE_TD_Resel_Start_NUM = m_nTotalCount;	//LTE-TD��ѡ����
			break;
		case PREDEFINE_CELLRESEL_ATTEMP_T2L:
			m_pLogInfo_LTE_Attach->m_ulTD_LTE_Resel_Start_NUM = m_nTotalCount;	//TD-LTE��ѡ����
			break;
		case PREDEFINE_RD_ATTEMP_L2T:
			m_pLogInfo_LTE_Attach->m_ulLTE_TD_RD_Start_NUM = m_nTotalCount;	//TDL-TDS�ض����Դ���
			break;
		case PREDEFINE_LTE_TAU_ATTEMP:
			m_pLogInfo_LTE_Attach->m_ulTAU_Request_NUM = m_nTotalCount;	//TA���³��Դ���
			break;

		default:
			return nResult;
		}
	}
	else if (m_nEventType==LTE_PSStat_Event_End)
	{
		switch (m_nItemType)
		{
		case PREDEFINE_LTE_ATTACH_SUCCESS: //Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
			m_pLogInfo_LTE_Attach->m_ulEPS_Attach_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_dbEPS_Attach_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_SERVICE_SUCCESS: //Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
			m_pLogInfo_LTE_Attach->m_ulSERVICE_Success_NUM=m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_dbSERVICE_Total_Delay=m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_HANDOVER_SUCCESS:	//LTE�����л�
			m_pLogInfo_LTE_Attach->m_ulLTE_LTE_Handover_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_dbLTE_LTE_Handover_Total_Delay = m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_INTRAHO_SUCCESS:	//LTEͬƵ�л�
			m_pLogInfo_LTE_Attach->m_ulLTE_intraHandover_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_abLTE_intraHandover_Total_Delay = m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_INTERHO_SUCCESS:	//LTE��Ƶ�л�
			m_pLogInfo_LTE_Attach->m_ulLTE_interHandover_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_abLTE_interHandover_Total_Delay = m_dbTotal_Delay;
			break;
		case PREDEFINE_CELLRESEL_SUCCESS_L2T:	//LTE-TDSCDMA��ѡ
			m_pLogInfo_LTE_Attach->m_ulLTE_TD_Resel_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_dbLTE_TD_Resel_Total_Delay = m_dbTotal_Delay;
			break;
		case PREDEFINE_CELLRESEL_SUCCESS_T2L:	//TDSCDMA-LTE��ѡ
			m_pLogInfo_LTE_Attach->m_ulTD_LTE_Resel_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_dbTD_LTE_Resel_Total_Delay = m_dbTotal_Delay;
			break;
		case PREDEFINE_RD_SUCCESS_L2T:	//TDL-TDS�ض���
			m_pLogInfo_LTE_Attach->m_ulLTE_TD_RD_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_abLTE_TD_RD_Total_Delay = m_dbTotal_Delay;
			break;
		case PREDEFINE_LTE_TAU_SUCCESS:	//TA���³���
			m_pLogInfo_LTE_Attach->m_ulTAU_Success_NUM = m_nTotalCount;
			m_pLogInfo_LTE_Attach->m_dbTAU_Total_Delay = m_dbTotal_Delay;
			break;
		default:
			return nResult;
		}
	}
	else if (m_nEventType==LTE_PSStat_Event_Normal)
	{
	}

	return nResult;
}

//////////////////////////////////////////////////////////////////////////
// ������ [5/13/2015 liangdongxu]
//---------------------------CPSDataStat_LTE_IE_MCS_V2-----------------------------------------------------
CPSDataStat_LTE_IE_MCS_V2::CPSDataStat_LTE_IE_MCS_V2(int nItemType, CLogInfo_LTE_Attach* pLogInfoLTEPS,enLTE_PSStat_MCS_Type nMCSType)
:CPSDataStat_LTE_IESingle(nItemType,NULL)
{
	m_nMCSType=nMCSType;
	m_pLogInfo_LTE_Attach=pLogInfoLTEPS;
}

CPSDataStat_LTE_IE_MCS_V2::~CPSDataStat_LTE_IE_MCS_V2(void)
{

}

void CPSDataStat_LTE_IE_MCS_V2::GetMCSValue(vector<int>& vecData, const string& str)
{
	string::size_type bPos = 0;
	string::size_type ePos = 0;
	while((ePos = str.find(';',bPos)) != -1)
	{
		vecData.push_back(atoi((str.substr(bPos, ePos - bPos)).c_str()));
		bPos = ePos + 1;
	}
}

int CPSDataStat_LTE_IE_MCS_V2::GetCurItemValue(DTANASTATDATAITEM& dtitem)
{
	string strValue="";
	m_vecMCSValue.clear();
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		if (!dtitem.strDLMCS0.empty())
		{
			strValue=dtitem.strDLMCS0;
		}
		break;
	case DL_Code1_MCS:
		if (!dtitem.strDLMCS1.empty())
		{
			strValue=dtitem.strDLMCS1;
		}
		break;
	case UL_MCS:
		if (!dtitem.strULMCS.empty())
		{
			strValue=dtitem.strULMCS;
		}
		break;
	default:
		return -1;
	}
	if (!strValue.empty())
	{
		GetMCSValue(m_vecMCSValue,strValue);
	}

	return -1;
}


//Count += CurValue
void CPSDataStat_LTE_IE_MCS_V2::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	if(m_vecMCSValue.size() != 32)
		return;

	CIEStatSingle* pIEStat=NULL;
	for(int i=0; i<32; i++)
	{
		pIEStat=&(m_mapIESingleItem[i]);
		int nValue=m_vecMCSValue[i];
		if (pIEStat!=NULL && nValue!=0)
		{
			pIEStat->m_nCount+=nValue;  //ֵ�ۼ�
		}
	}
}


int CPSDataStat_LTE_IE_MCS_V2::DoConclusion()
{
	int nResult = 0;

	int nIndex=0;
	CIEStatSingle* pIEStat=NULL;

	pIEStat=&(m_mapIESingleItem[nIndex]);  //0
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS0_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS0_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS0_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //1
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS1_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS1_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS1_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //2
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS2_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS2_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS2_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //3
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS3_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS3_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS3_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //4
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS4_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS4_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS4_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //5
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS5_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS5_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS5_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //6
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS6_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS6_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS6_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //7
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS7_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS7_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS7_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //8
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS8_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS8_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS8_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //9
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS9_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS9_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS9_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //10
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS10_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS10_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS10_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //11
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS11_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS11_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS11_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //12
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS12_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS12_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS12_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //13
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS13_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS13_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS13_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //14
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS14_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS14_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS14_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //15
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS15_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS15_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS15_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //16
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS16_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS16_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS16_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //17
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS17_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS17_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS17_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //18
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS18_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS18_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS18_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //19
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS19_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS19_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS19_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //20
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS20_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS20_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS20_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}


	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //21
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS21_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS21_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS21_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //22
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS22_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS22_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS22_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //23
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS23_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS23_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS23_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}

	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //24
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS24_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS24_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS24_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //25
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS25_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS25_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS25_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //26
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS26_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS26_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS26_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //27
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS27_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS27_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS27_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //28
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS28_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS28_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS28_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //29
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS29_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS29_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS29_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //30
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS30_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS30_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS30_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}
	nIndex++;
	pIEStat=&(m_mapIESingleItem[nIndex]);  //31
	switch (m_nMCSType)
	{
	case DL_Code0_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code0_MCS31_Num=pIEStat->m_nCount;
		break;
	case DL_Code1_MCS:
		m_pLogInfo_LTE_Attach->m_ulDL_Code1_MCS31_Num=pIEStat->m_nCount;
		break;
	case UL_MCS:
		m_pLogInfo_LTE_Attach->m_ulUL_MCS31_Num=pIEStat->m_nCount;
		break;
	default:
		break;
	}	

	return nResult;
}
//////////////////////////////////////////////////////////////////////////
// ���縲����ֶ�ռ��ͳ�� [5/14/2015 liangdongxu]
//---------------------------CPSDataStat_LTE_IEArea_V2-----------------------------------------------------
CPSDataStat_LTE_IEArea_V2::CPSDataStat_LTE_IEArea_V2(int nItemType, CLogInfo_LTE_Attach* pLogInfoLTEPS,enLTE_PSStat_Area_IEType nIEType)
:CPSDataStatBase_LTE(nItemType,NULL,NULL)
{
	m_nIEType=nIEType;
	m_pLogInfo_LTE_PS=pLogInfoLTEPS;
}

CPSDataStat_LTE_IEArea_V2::~CPSDataStat_LTE_IEArea_V2(void)
{

}


void CPSDataStat_LTE_IEArea_V2::AddStatCondition(vector<CIEStatArea>& vecIEArea)
{
	m_vecIEAreaItem=vecIEArea;
}

int CPSDataStat_LTE_IEArea_V2::GetCurItemValue(DTANASTATDATAITEM& dtitem)
{
	m_fCurItemValue=INVALIDVALUE_FLOAT;
	switch (m_nIEType)
	{
	case LTE_PSStat_Area_RSRP:
		if (dtitem.ulEastShift != INVALIDVALUE_INT32)
		{
			m_fCurItemValue=((int)dtitem.ulEastShift)/1000.0;
		}
		break;
	case LTE_PSStat_Area_SINR:
		if (dtitem.ulHeightShift != INVALIDVALUE_INT32)
		{
			m_fCurItemValue=((int)dtitem.ulHeightShift)/1000.0;
		}
		break;
	case LTE_PSStat_Area_RSRQ:
		if (dtitem.ulFloor != INVALIDVALUE_INT32)
		{
			m_fCurItemValue=((int)dtitem.ulFloor)/1000.0;
		}
		break;
	default:
		break;
	}

	return m_fCurItemValue;
}


//����䷶Χ�ڣ�Count++
void CPSDataStat_LTE_IEArea_V2::CalcCurValue(DTANASTATDATAITEM& dtitem)
{
	if (m_fCurItemValue==INVALIDVALUE_FLOAT)
		return;

	for(vector<CIEStatArea>::iterator it = m_vecIEAreaItem.begin(); it != m_vecIEAreaItem.end(); it++)
	{
		if (m_fCurItemValue >= it->m_fMinIEValue && m_fCurItemValue < it->m_fMaxIEValue)  //����ҿ�
		{
			it->m_nCount++;  //����
			break;
		}
	}
}


int CPSDataStat_LTE_IEArea_V2::DoConclusion()
{
	int nResult = 0;
	int nIndex=0;
	if (m_nIEType==LTE_PSStat_Area_RSRP)
	{
		m_pLogInfo_LTE_PS->m_ulRSRP_75_40_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_85_75_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_95_85_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_100_95_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_105_100_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_110_105_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRP_141_110_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	}

	nIndex=0;
	if (m_nIEType==LTE_PSStat_Area_SINR)//SINR���ֲ�ͳ��
	{
		m_pLogInfo_LTE_PS->m_ulSINR_15_50_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_9_15_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_6_9_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_3_6_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_0_3_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_3_0_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulSINR_50_3_Num=m_vecIEAreaItem[nIndex++].m_nCount;

		//m_pLogInfo_LTE_PS->m_ulSINR_3_3_Num = m_pLogInfo_LTE_PS->m_ulSINR_3_0_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_0_3_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_3_6_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_6_9_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_9_15_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_15_50_Num;
		//m_pLogInfo_LTE_PS->m_ulSINR_0_0_Num = m_pLogInfo_LTE_PS->m_ulSINR_0_3_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_3_6_Num 
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_6_9_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_9_15_Num
		//	+ m_pLogInfo_LTE_PS->m_ulSINR_15_50_Num;
	}

	nIndex=0;
	if (m_nIEType==LTE_PSStat_Area_RSRQ)//RSRQ���ֲ�ͳ��
	{
		m_pLogInfo_LTE_PS->m_ulRSRQ_35_30_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_55_35_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_75_55_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_95_75_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_115_95_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_135_115_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_155_135_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_175_155_Num=m_vecIEAreaItem[nIndex++].m_nCount;
		m_pLogInfo_LTE_PS->m_ulRSRQ_196_175_Num=m_vecIEAreaItem[nIndex++].m_nCount;
	}

	return nResult;
}

