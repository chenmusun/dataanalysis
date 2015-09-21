#pragma once
#include "AnalyzeImpl_LTE.h"

//enum E_LTE_RAT
//{
//	RAT_LTE,
//	RAT_TD_HSPA,
//	RAT_GSM,
//	RAT_TD_R4,
//	RAT_NULL = 0xff
//};

class CAnalyzeImpl_LTE_PS_APPSTAT :
	public CAnalyzeImpl_LTE
{
public:
	CAnalyzeImpl_LTE_PS_APPSTAT(void);
	~CAnalyzeImpl_LTE_PS_APPSTAT(void);

	int DoAnalyzeImpl(DTANASTATDATAITEM& dtitem, int nCsOrPs = 3);

	virtual int DoAnalyzeOneData(DTANASTATDATAITEM& dtitem);

	virtual int DoConclusion();

private:

	//������ʽ
	UINT8 m_ucRAT;
	UINT8 m_ucOldRAT;

	//����������
	double m_dLongitude;
	double m_dLatitude;

	//���浱ǰftp״̬��0δ��ҵ��1�����У�2�ϴ���
	UINT8 m_ucFtpState;

	//�����������ʱ��
	double m_dbFTP_DL_StartTime;
	double m_dbFTP_DL_RatSwitchStartTime;
	double m_dbFTP_DL_LastTime_LTE;
	double m_dbFTP_DL_LastTime_HSPA;
	double m_dbFTP_DL_LastTime_R4;

	//��������ϴ�ʱ��
	double m_dbFTP_UL_StartTime;
	double m_dbFTP_UL_RatSwitchStartTime;
	double m_dbFTP_UL_LastTime_LTE;
	double m_dbFTP_UL_LastTime_HSPA;
	double m_dbFTP_UL_LastTime_R4;

	//�������������
	double m_dbDownLoadData_All;
	double m_dbDownLoadData_LTE;
	double m_dbDownLoadData_HSPA;
	double m_dbDownLoadData_R4;
	bool   m_bIsDownSuccessForStatisticsDownLoadData;
	bool   m_bIsDownSuccessForLTEHSPAR4;

	//��������ϴ���
	double m_dbUpLoadData_All;
	double m_dbUpLoadData_LTE;
	double m_dbUpLoadData_HSPA;
	double m_dbUpLoadData_R4;

	//���������ȵ�PRB��
	UINT64 m_ullFTP_DL_PRB_Num;
	UINT64 m_ullFTP_UL_PRB_Num;

	//�������Ӧ�ò���������(��������)
	UINT32 m_ulFtp_DL_Speed_0_0M_Num;	//����0
	UINT32 m_ulFtp_DL_Speed_0_1M_Num;	//(0,1M)
	UINT32 m_ulFtp_DL_Speed_1_2M_Num;	//[1,2M)
	UINT32 m_ulFtp_DL_Speed_2_3M_Num;	//[2,3M)
	UINT32 m_ulFtp_DL_Speed_3_4M_Num;	//[3,4M)
	UINT32 m_ulFtp_DL_Speed_4_5M_Num;	//[4,5M)
	UINT32 m_ulFtp_DL_Speed_5_10M_Num;	//[5,10M)
	UINT32 m_ulFtp_DL_Speed_10_15M_Num;	//[10,15M)
	UINT32 m_ulFtp_DL_Speed_15_20M_Num;	//[15,20M)
	UINT32 m_ulFtp_DL_Speed_20_30M_Num;	//[20,30M)
	UINT32 m_ulFtp_DL_Speed_30_50M_Num;	//[30,50M)
	UINT32 m_ulFtp_DL_Speed_50_NM_Num;	//���ڵ���50M

	//�������Ӧ�ò��ϴ�����(��������)
	UINT32 m_ulFtp_UL_Speed_0_0K_Num;		//����0
	UINT32 m_ulFtp_UL_Speed_0_256K_Num;		//(0,256K)
	UINT32 m_ulFtp_UL_Speed_256K_512K_Num;	//[256K,512K)
	UINT32 m_ulFtp_UL_Speed_512K_1M_Num;	//[512K,1M)
	UINT32 m_ulFtp_UL_Speed_1_2M_Num;		//[1,2M)
	UINT32 m_ulFtp_UL_Speed_2_3M_Num;		//[2,3M)
	UINT32 m_ulFtp_UL_Speed_3_4M_Num;		//[3,4M)
	UINT32 m_ulFtp_UL_Speed_4_5M_Num;		//[4,5M)
	UINT32 m_ulFtp_UL_Speed_5_10M_Num;		//[5,10M)
	UINT32 m_ulFtp_UL_Speed_10_15M_Num;		//[10,15M)
	UINT32 m_ulFtp_UL_Speed_15_20M_Num;		//[15,20M)
	UINT32 m_ulFtp_UL_Speed_20_30M_Num;		//[20,30M)
	UINT32 m_ulFtp_UL_Speed_30_50M_Num;		//[30,50M)

	//�������pdcp���������
	double m_dbPDCP_DL_Longitude;
	double m_dbPDCP_DL_Latitude;
	std::vector<double> m_vIR_DL_PDCP_Vetcor; //intermediate result
	std::vector<double> m_vDL_PDCP_Vetcor_NID;
	std::vector<double> m_vDL_PDCP_Vetcor_ID;
	double m_dbPDCP_UL_Longitude;
	double m_dbPDCP_UL_Latitude;
	std::vector<double> m_vIR_UL_PDCP_Vetcor; //intermediate result
	std::vector<double> m_vUL_PDCP_Vetcor_NID;
	std::vector<double> m_vUL_PDCP_Vetcor_ID;
};