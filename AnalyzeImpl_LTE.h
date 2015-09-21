#pragma once
#include "AnalyzeImplBase.h"
#include "LogInfo_LTE_PS.h"
#include"LTEIEDef.h"
#include"EventSettingCollection.h"
enum E_LTE_RAT
{
	RAT_LTE,
	RAT_TD_HSPA,
	RAT_GSM,
	RAT_TD_R4,
	RAT_NULL = 0xff
};

enum enLTE_TM_Type //����ģʽʱ��ռ�� IE_LTE_TM
{
	LTE_TM_1 = 1,	  //TM1ʱ��
	LTE_TM_2,	  //TM2ʱ��
	LTE_TM_3,	  //TM3ʱ��
	LTE_TM_4,	  //TM4ʱ��
	LTE_TM_5,	  //TM5ʱ��
	LTE_TM_6,	  //TM6ʱ��
	LTE_TM_7,	  //TM7ʱ��
	LTE_TM_8	  //TM8ʱ��
};

enum enLTE_BAND_Type //LTE ��Ƶ��ռ��ʱ���ֲ�ͳ�� IE_LTE_BAND
{
	LTE_BAND_D = 38,	  //DƵ��
	LTE_BAND_F,	  //FƵ��
	LTE_BAND_E	  //EƵ��
};

class CAnalyzeImpl_LTE :
	public CAnalyzeImplBase
{
public:
	CAnalyzeImpl_LTE(void);
	~CAnalyzeImpl_LTE(void);

	virtual void Init(CLogInfoBase* pLogInfoBase, CLogInfo_LTE_PS* pLogInfoLTEPS);

	virtual int DoAnalyzeOneData(DTANASTATDATAITEM& dtitem) = 0;

	virtual int DoConclusion() = 0;

	virtual void AnaUpdateTime(DTANASTATDATAITEM& dtitem, int nCsOrPs);
	BOOL GetItem(char *inbuffer, unsigned int itemnum, char *outbuffer, const char *separator);

	//����ҿ�,��nMin<= x <nMax;
	double CalcCdf(std::vector<double>& vSamplingPoint, int nMax, int nMin = 0, int nInterval = 100, double dbRatio = 0.05);
	//double CalcCdfForPdcp(vector<double>& vSamplingPoint, bool bIsDlorUl, int nMax, int nMin = 0, double dbRatio = 0.05);

	double CalcDistanceLTE(double dbLont1,double dbLati1, double dbLont2, double dbLati2);

public:
	CLogInfo_LTE_PS* m_pLogInfoLTEPS;
};