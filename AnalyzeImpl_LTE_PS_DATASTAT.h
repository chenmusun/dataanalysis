#pragma once
#include "AnalyzeImpl_LTE.h"
#include "LTE_PS_DataStat.h"
#include "LogInfo_LTE_PS.h"

#include <map>
using namespace std;

enum enLTE_Subframe_Assignment_Type //LTE��֡����  IE_LTE_SUBFRAME_ASSIGNMENT
{
	LTE_Subframe_Assignment_Format0, //��ʽ0
	LTE_Subframe_Assignment_Format1, //��ʽ1(1:1)
	LTE_Subframe_Assignment_Format2, //��ʽ2(3:1)
	LTE_Subframe_Assignment_Format3, //��ʽ3
	LTE_Subframe_Assignment_Format4, //��ʽ4
	LTE_Subframe_Assignment_Format5, //��ʽ5
	LTE_Subframe_Assignment_Format6 //��ʽ6
};

enum enLTE_Special_Subframe_Patterns_Type //LTE����ʱ϶���� IE_LTE_SPECIAL_SUBFRAME_PATTERNS
{
	LTE_Special_Subframe_Patterns_0, //0
	LTE_Special_Subframe_Patterns_1, //1
	LTE_Special_Subframe_Patterns_2, //2
	LTE_Special_Subframe_Patterns_3, //3
	LTE_Special_Subframe_Patterns_4, //4
	LTE_Special_Subframe_Patterns_392, //5
	LTE_Special_Subframe_Patterns_6, //6
	LTE_Special_Subframe_Patterns_1022, //7
	LTE_Special_Subframe_Patterns_8 //8
};

enum enLTE_UL_CP_Type //LTECP����ʱ���ֲ�ͳ��  IE_LTE_UL_CP_TYPE
{
	LTE_UL_CP_Normal = 0, //Normal CP
	LTE_UL_CP_Extended //Extended CP
};

enum enLTE_ENB_TX_ANTENNA_Type //LTE ���߶˿�����ʱ���ֲ�ͳ�� IE_LTE_ENB_TX_ANTENNA_NUM
{
	LTE_ENB_TX_ANTENNA_an1 = 1, //an1
	LTE_ENB_TX_ANTENNA_an2, //an2
	LTE_ENB_TX_ANTENNA_an4 = 4 //an4
};

//enum enLTE_BAND_Type //LTE ��Ƶ��ռ��ʱ���ֲ�ͳ�� IE_LTE_BAND
//{
//	LTE_BAND_D = 38,	  //DƵ��
//	LTE_BAND_F,	  //FƵ��
//	LTE_BAND_E	  //EƵ��
//};

//enum enLTE_TM_Type //����ģʽʱ��ռ�� IE_LTE_TM
//{
//	LTE_TM_1 = 1,	  //TM1ʱ��
//	LTE_TM_2,	  //TM2ʱ��
//	LTE_TM_3,	  //TM3ʱ��
//	LTE_TM_4,	  //TM4ʱ��
//	LTE_TM_5,	  //TM5ʱ��
//	LTE_TM_6,	  //TM6ʱ��
//	LTE_TM_7,	  //TM7ʱ��
//	LTE_TM_8	  //TM8ʱ��
//};

class CPSDataStatBase_LTE;

class CAnalyzeImpl_LTE_PS_DATASTAT :
	public CAnalyzeImpl_LTE
{
public:
	CAnalyzeImpl_LTE_PS_DATASTAT(void);
	~CAnalyzeImpl_LTE_PS_DATASTAT(void);

	int DoAnalyzeImpl(DTANASTATDATAITEM& dtitem, int nCsOrPs = 3);

	virtual void Init(CLogInfoBase* pLogInfoBase, CLogInfo_LTE_PS* pLogInfoLTEPS);

	virtual int DoAnalyzeOneData(DTANASTATDATAITEM& dtitem);

	virtual int DoConclusion();


private:
	void AnalysisDataItem(int nType, DTANASTATDATAITEM& dtitem);

	void GetMCSCondition(std::vector<int>& vecIEValue);

	void GetRSRPCondition(std::vector<CIEStatArea>& vecIEAreaItem);
	void GetSINRCondition(std::vector<CIEStatArea>& vecIEAreaItem);
	void GetRSRQCondition(std::vector<CIEStatArea>& vecIEAreaItem);
	
	void GetCQICondition(std::vector<int>& vecIEValue);//��ȡCQI��ϸ�ֲ�ͳ������
	void GetCQICode0Info(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS);//��ȡCode0 CQI��ϸ�ֲ�ͳ������ֶ�
	void GetCQICode1Info(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS);//��ȡCode1 CQI��ϸ�ֲ�ͳ������ֶ�

	void GetRankCondition(std::vector<int>& vecIEValue);//��ȡRankͳ������
	void GetRankInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS);//��ȡRankͳ������ֶ�


	void GetSubframe_AssignmentCondition(std::vector<int>& vecIEValue);//��ȡLTE��֡����ͳ������
	void GetSubframe_AssignmentInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS); //��ȡLTE��֡��������ֶ�

	void GetSpecial_Subframe_PatternsCondition(std::vector<int>& vecIEValue);//��ȡLTE����ʱ϶����ͳ������
	void GetSpecial_Subframe_PatternsInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS); //��ȡLTE����ʱ϶��������ֶ�

	void GetUL_CPCondition(std::vector<int>& vecIEValue);//��ȡLTECP����ʱ��ͳ������
	void GetUL_CPInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS); //��ȡLTECP����ʱ������ֶ�

	void GetENB_TX_ANTENNACondition(std::vector<int>& vecIEValue);//��ȡLTE���߶˿�����ʱ��ͳ������
	void GetENB_TX_ANTENNAInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS); //��ȡLTE���߶˿�����ʱ������ֶ�

	void GetBANDCondition(std::vector<int>& vecIEValue);//��ȡLTE��Ƶ��ռ��ʱ��ͳ������
	void GetBANDInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS); //��ȡLTE��Ƶ��ռ��ʱ������ֶ�

	void GetTMCondition(std::vector<int>& vecIEValue);//��ȡ����ģʽʱ��ͳ������
	void GetTMInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS); //��ȡ����ģʽʱ������ֶ�

	void AnalysisOther(DTANASTATDATAITEM& dtitem);
	void AnalysisDbmParaAvg(DTANASTATDATAITEM& dtitem);
	void AnalysisSingleorDoubleFlow(DTANASTATDATAITEM& dtitem);

private:
	map<int,CPSDataStatBase_LTE*> m_MapPSDataStat; //����ʵ����

	//��������ԵSINR(dB)
	std::vector<double> m_vSINREdgeAll;
	//��������ԵRSRP(dBm)
	std::vector<double> m_vRSRPEdgeAll;

	//��������ص����Ƕ�
	std::vector<int> m_vRSRPNeighborPara;
	int m_nLastRSRP;

	//�������LTE�����������
	double m_dbCurSINR; 

	//��������ص����Ƕ����
	double m_dLongitude;
	double m_dLatitude;

	/*
	����ռ��ʱ����ΪCodeWord Num == 1��ʱ����˫��ռ��ʱ��ΪCodeWord Num == 2��ʱ��
	��������ΪCodeWord Num == 1ʱ����TbsizeCW0֮��
	˫������ΪCodeWord Num == 2ʱ����TbsizeCW0��TbsizeCW1֮��
	*/
	int m_lOldCodeWordNum; //�����жϵ�˫��
	double m_dbStartCodeWordTime;
};