#pragma once
#include "LogInfoBase.h"

class CLogInfo_LTE_CS_CSFB:
	public CLogInfoBase
{
public:
	CLogInfo_LTE_CS_CSFB(void);
	~CLogInfo_LTE_CS_CSFB(void);

//	virtual CString GetInsertSQL();

	void InitPara();
	
public:
	UINT64  RecSeqNo;    //��¼���к�, ȫ��ֵΨһ,����

	//--------------����----------------------------------------------
	UINT32 m_ulCSFB_Start_NUM_MO;		//CSFB�Ժ��������У�
	UINT32 m_ulCSFB_Success_NUM_MO;		//CSFB LTE2GSM�ɹ��������У�
	UINT32 m_ulCSFB_Alerting_NUM_MO;		//CSFB����������У�
	UINT32 m_ulCSFB_Connect_NUM_MO;		//CSFB��ͨ�������У�

	UINT32 m_ulCSFB_Return_Start_NUM_MO;	//GSM-LTE���Դ������У�
	UINT32 m_ulCSFB_Return_End_NUM_MO;		//GSM-LTE�ɹ��������У�

	UINT32 m_ulCSFB_Drop_NUM_MO;		//CSFB���ߴ������У�

	//--------------����----------------------------------------------
	UINT32 m_ulCSFB_Start_NUM_MT;		//CSFB�Ժ�����У�
	UINT32 m_ulCSFB_Success_NUM_MT;		//CSFB LTE2GSM�ɹ�����У�
	UINT32 m_ulCSFB_Alerting_NUM_MT;		//CSFB�������У�
	UINT32 m_ulCSFB_Connect_NUM_MT;		//CSFB��ͨ����У�

	UINT32 m_ulCSFB_Return_Start_NUM_MT;	//GSM-LTE���Դ���У�
	UINT32 m_ulCSFB_Return_End_NUM_MT;		//GSM-LTE�ɹ�����У�

	UINT32 m_ulCSFB_Drop_NUM_MT;		//CSFB���ߴ���У�

	//----------------ʱ��----------------------------------------------------
	double m_dbCSFB_Call_Start_Total_Delay_MO;       //CSFB���н���ʱ�Ӻ�(s) �����У�
	double m_dbCSFB_Call_Start_Total_Delay_MT;       //CSFB���н���ʱ�Ӻ�(s) �����У�

	double m_dbL2G_Resel_Total_Delay_MO;                //LTE2GSM��ѡʱ�Ӻ�(s)�����У�
	double m_dbL2G_Resel_Total_Delay_MT;                //LTE2GSM��ѡʱ�Ӻ�(s)�����У�

	double m_dbG2L_Resel_Total_Delay_MO;                //GSM2LTE��ѡʱ�Ӻ�(s)�����У�
	double m_dbG2L_Resel_Total_Delay_MT;                //GSM2LTE��ѡʱ�Ӻ�(s)�����У�

	
	//MOSռ��
	UINT32 m_ulMOS_0_2_Num;		//[0,2)
	UINT32 m_ulMOS_2_22_Num;		//[2,2.2)
	UINT32 m_ulMOS_22_24_Num;		//[2.2,2.4)
	UINT32 m_ulMOS_24_26_Num;		//[2.4,2.6)
	UINT32 m_ulMOS_26_28_Num;		//[2.6,2.8)
	UINT32 m_ulMOS_28_30_Num;		//[2.8,3.0)
	UINT32 m_ulMOS_30_32_Num;		//[3.0,3.2)
	UINT32 m_ulMOS_32_34_Num;		//[3.2,3.4)
	UINT32 m_ulMOS_34_36_Num;		//[3.4,3.6)
	UINT32 m_ulMOS_36_38_Num;		//[3.6,3.8)
	UINT32 m_ulMOS_38_40_Num;		//[3.8,4.0)
	UINT32 m_ulMOS_40_50_Num;		//[4.0,5.0]   ---�������ֵ[4,5.1)���Ժ���5.0
    
};