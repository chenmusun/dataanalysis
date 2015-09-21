#pragma once

#include "LogInfo_LTE_PS.h"
#include "LogInfo_LTE_CS_CSFB.h"
#include "LogInfo_LTE_Attach.h"
#include"DataSource.h"
#include"EventSettingCollection.h"

#include <list>
#include <map>
#include<vector>
using namespace std;

enum enLTE_PSStat_Count_Type
{
	LTE_PSStat_Total_Count,  //�ϱ������ۼ�
	LTE_PSStat_Total_Value,  //�ϱ�ֵ�ۼ�
	LTE_PSStat_Total_All     //����ֵ���ۼ�
};

enum enLTE_PSStat_Value_Type
{
	LTE_PSStat_Value_Int,  //����ValueֵΪint��
	LTE_PSStat_Value_Double  //����ValueֵΪdouble��
};
//LTE PSҵ������ָ��ͳ�ƻ���
class CPSDataStatBase_LTE
{
public:
	CPSDataStatBase_LTE(int nItemType, void* pItemCount, void* pItemValue=NULL, enLTE_PSStat_Count_Type nType=LTE_PSStat_Total_Count,enLTE_PSStat_Value_Type nValueType=LTE_PSStat_Value_Int); //(IE type,ͳ�Ʊ�����Ӧ�ֶδ���ֵ,ͳ�Ʒ�ʽ)
	virtual ~CPSDataStatBase_LTE(void);

public:
	virtual int AnalysisData(DTANASTATDATAITEM& dtitem);
	virtual int DoConclusion();

	//����ͳ����䷶Χ
	//virtual void AddStatCondition();
protected:
	virtual	int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ


protected:
	int m_nItemType; //IE���¼�����
	enLTE_PSStat_Count_Type m_nCountType;  //ͳ������
	enLTE_PSStat_Value_Type m_nValueType;  //����ֶ�����

	void* m_pItemCount; //��Ӧ��ͳ�Ʊ�����ֶΣ������ۼ�

	void* m_pItemValue; //��Ӧ��ͳ�Ʊ�����ֶΣ�ֵ�ۼ�

	int m_nTotalCount; //ָ���ϱ������ۼӣ�ÿ�μ�1
	//int m_nTotalValue; //ָ��ֵ�ۼ�
	INT64 m_nTotalValue; //ָ��ֵ�ۼ�

	//int m_nCurItemValue;  //��ǰ�ϱ�ֵ
	INT64 m_nCurItemValue;  //��ǰ�ϱ�ֵ
};

class CIEStatSingle
{
public:
	CIEStatSingle(){};

	CIEStatSingle(int nIEValue)
	{
		m_nIEValue=nIEValue;
		m_nCount=0;
	};

	~CIEStatSingle(){};

	int m_nIEValue; //IEȡֵ
	double m_nCount;  //�ϱ�����/��ָ��ֲ�ʱ����ʱ��ͳ��


};
//IE ��ȡֵ�ۼ�ͳ��
class CPSDataStat_LTE_IESingle:
	public CPSDataStatBase_LTE
{
public:
	CPSDataStat_LTE_IESingle(int nItemType, std::vector<void*>* vecStatInfo);
	virtual ~CPSDataStat_LTE_IESingle(void);

public:
	virtual int DoConclusion();

	//����ͳ����䷶Χ
	void AddStatCondition(std::vector<int>& vecIEValue);
protected:
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ


protected:
	map<int,CIEStatSingle> m_mapIESingleItem;
	std::vector<void*> m_vecStatInfo;  //��ͳ�Ʊ��ֶΰ�˳���ʼ��
};

enum enLTE_PSStat_MCS_Type
{
	DL_Code0_MCS,
	DL_Code1_MCS,
	UL_MCS
};

//MCS  IE �����ۼ�ͳ��
class CPSDataStat_LTE_IE_MCS:
	public CPSDataStat_LTE_IESingle
{
public:
	CPSDataStat_LTE_IE_MCS(int nItemType, CLogInfo_LTE_PS* pLogInfoLTEPS,enLTE_PSStat_MCS_Type nMCSType);  //(IE type,ͳ�Ʊ�����Ӧ�ֶ�)
	virtual ~CPSDataStat_LTE_IE_MCS(void);

public:
	virtual int DoConclusion();
protected:
	virtual int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ

private:
	void GetMCSValue(std::vector<int>& vecData, const string& str);

private:
	enLTE_PSStat_MCS_Type m_nMCSType;
	std::vector<int> m_vecMCSValue; //0-31��ֵ��˳��洢
	CLogInfo_LTE_PS* m_pLogInfo_LTE_PS;
};


//IEʱ��ռ���ۼ�ͳ��
class CPSDataStat_LTE_IE_UseTime:
	public CPSDataStat_LTE_IESingle
{
public:
	CPSDataStat_LTE_IE_UseTime(int nItemType, std::vector<void*>* vecStatInfo,double* pTime_new);  //(IE type,ͳ�Ʊ�����Ӧ�ֶ�,��ǰʱ��)
	virtual ~CPSDataStat_LTE_IE_UseTime(void);

public:
	virtual int DoConclusion();
protected:
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ

private:
	int m_nLastValue;  //��һ���ϱ���ֵ�������뱾���ϱ�ֵ��Ƚϣ��ж��Ƿ�ı�
	
	double* m_pTime_new; //��ǰʱ��
	double m_dbLastTime;  //��һ���ϱ���ʱ��
};


//���ֵͳ��
class CIEStatArea
{
public:

	CIEStatArea();
	CIEStatArea(float fMinIEValue,float fMaxIEValue)
	{
		m_fMinIEValue=fMinIEValue;
		m_fMaxIEValue=fMaxIEValue;
		m_nCount=0;
	}
	~CIEStatArea(){};

	float m_fMinIEValue; //IE����ȡֵ
	float m_fMaxIEValue; //IE����ȡֵ
	int m_nCount;  //�ϱ�����


};

enum enLTE_PSStat_Area_IEType
{
	LTE_PSStat_Area_RSRP,
	LTE_PSStat_Area_SINR,
	LTE_PSStat_Area_RSRQ
};

//IE �����ۼ�ͳ��
class CPSDataStat_LTE_IEArea:
	public CPSDataStatBase_LTE
{
public:
	CPSDataStat_LTE_IEArea(int nItemType, CLogInfo_LTE_PS* pLogInfoLTEPS,enLTE_PSStat_Area_IEType nIEType);
	virtual ~CPSDataStat_LTE_IEArea(void);

public:
	virtual int DoConclusion();

	//����ͳ����䷶Χ
	void AddStatCondition(std::vector<CIEStatArea>& vecIEArea);
protected:
	virtual int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ


protected:
	std::vector<CIEStatArea> m_vecIEAreaItem;
	enLTE_PSStat_Area_IEType m_nIEType;
	CLogInfo_LTE_PS* m_pLogInfo_LTE_PS;

	float m_fCurItemValue;
};

enum enLTE_PSStat_Event_Type
{
	LTE_PSStat_Event_Normal, //һ���¼�������Ҫ����ʱ��
	LTE_PSStat_Event_Start,  //��ʼ�¼�
	LTE_PSStat_Event_End     //�����¼�
};

//PS Event��ʱ��ͳ��
class CPSDataStat_LTE_Event:
	public CPSDataStatBase_LTE
{
public:
	CPSDataStat_LTE_Event(int nItemType, CLogInfo_LTE_PS* pLogInfoLTEPS,enLTE_PSStat_Event_Type nEventType,double* pTime_new=NULL, CPSDataStat_LTE_Event* pStartStat=NULL);
	virtual ~CPSDataStat_LTE_Event(void);

public:
	virtual int DoConclusion();
	double GetStartTime();
	void SetStartTime(double dbTime);

protected:
	//virtual int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ


protected:
	enLTE_PSStat_Event_Type m_nEventType;
	CLogInfo_LTE_PS* m_pLogInfo_LTE_PS;
	CPSDataStat_LTE_Event* m_pStartStat; //��ʼ�¼�ͳ��ʵ������¼���Ҫ��ȡ��ʼ�¼���ʱ�����ʱ��
	double* m_pTime_new; //��ǰʱ��
	double m_dbCurTime;  //��ǰʱ��

	double m_dbTotal_Delay;//ʱ�Ӻ�

};

//--------------------CSFB ------------------------------------------------------
//CSFB Event��ʱ��ͳ��
class CDataStat_LTE_Event_CSFB:
	public CPSDataStat_LTE_Event
{
public:
	CDataStat_LTE_Event_CSFB(int nItemType, CLogInfo_LTE_CS_CSFB* pLogInfoLTECSFB,enLTE_PSStat_Event_Type nEventType,double* pTime_new=NULL, CPSDataStat_LTE_Event* pStartStat=NULL);
	virtual ~CDataStat_LTE_Event_CSFB(void);

public:
	virtual int DoConclusion();

private:
	CLogInfo_LTE_CS_CSFB* m_pLogInfo_LTE_CS_CSFB;
};


//CSFB MOS����ͳ��
class CDataStat_LTE_IEArea_CSFB:
	public CPSDataStat_LTE_IEArea
{
public:
	CDataStat_LTE_IEArea_CSFB(int nItemType, CLogInfo_LTE_CS_CSFB* pLogInfoLTECSFB);
	virtual ~CDataStat_LTE_IEArea_CSFB(void);

public:
	virtual int DoConclusion();
	
protected:
	virtual int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ

private:
	CLogInfo_LTE_CS_CSFB* m_pLogInfo_LTE_CS_CSFB;
};

// Attachͳ�� [4/30/2015 liangdongxu]
class CDataStat_LTE_EventAttach:
	public CPSDataStat_LTE_Event
{
public:
	CDataStat_LTE_EventAttach(int nItemType, CLogInfo_LTE_Attach* pLogInfo_LTE_Attach, enLTE_PSStat_Event_Type nEventType, double* pTime_new = NULL, CPSDataStat_LTE_Event* pStartStat=NULL);
	virtual ~CDataStat_LTE_EventAttach(void);

	virtual int DoConclusion();

private:
	CLogInfo_LTE_Attach* m_pLogInfo_LTE_Attach;
};

// MCS  IE �����ۼ�ͳ�� [5/13/2015 liangdongxu]
class CPSDataStat_LTE_IE_MCS_V2:
	public CPSDataStat_LTE_IESingle
{
public:
	CPSDataStat_LTE_IE_MCS_V2(int nItemType, CLogInfo_LTE_Attach* pLogInfo_LTE_Attach,enLTE_PSStat_MCS_Type nMCSType);  //(IE type,ͳ�Ʊ�����Ӧ�ֶ�)
	virtual ~CPSDataStat_LTE_IE_MCS_V2(void);

public:
	virtual int DoConclusion();
protected:
	virtual int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ

private:
	void GetMCSValue(std::vector<int>& vecData, const string& str);

private:
	enLTE_PSStat_MCS_Type m_nMCSType;
	std::vector<int> m_vecMCSValue; //0-31��ֵ��˳��洢
	CLogInfo_LTE_Attach* m_pLogInfo_LTE_Attach;
};

//IE �����ۼ�ͳ��
class CPSDataStat_LTE_IEArea_V2:
	public CPSDataStatBase_LTE
{
public:
	CPSDataStat_LTE_IEArea_V2(int nItemType, CLogInfo_LTE_Attach* pLogInfoLTEPS,enLTE_PSStat_Area_IEType nIEType);
	virtual ~CPSDataStat_LTE_IEArea_V2(void);

public:
	virtual int DoConclusion();

	//����ͳ����䷶Χ
	void AddStatCondition(std::vector<CIEStatArea>& vecIEArea);
protected:
	virtual int GetCurItemValue(DTANASTATDATAITEM& dtitem); //��ȡֵ
	virtual void  CalcCurValue(DTANASTATDATAITEM& dtitem);   //����ͳ��ֵ


protected:
	std::vector<CIEStatArea> m_vecIEAreaItem;
	enLTE_PSStat_Area_IEType m_nIEType;
	CLogInfo_LTE_Attach* m_pLogInfo_LTE_PS;

	float m_fCurItemValue;
};