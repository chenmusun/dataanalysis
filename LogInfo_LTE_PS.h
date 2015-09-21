#pragma once
#include "LogInfoBase.h"

class CLogInfo_LTE_PS:
	public CLogInfoBase
{
public:
	CLogInfo_LTE_PS(void);
	~CLogInfo_LTE_PS(void);

	//virtual std::string GetInsertSQL();

	void InitPara();

public:
	UINT64  RecSeqNo;    //��¼���к�, ȫ��ֵΨһ,����

	//ҵ�񲿷�

	//����ʱ��(�ļ�����ʱ��-�ļ���ʼʱ��)�Ͳ��������ǰ̨����

	//NID��ʾ��������,ID��ʾ������

	double m_dbFTP_DL_TotalData_NID;		//FTP����ִ��ʱ�����ܵ����������(��������)
	double m_dbFTP_DL_TotalData_LTE_NID;    //FTP����ִ��ʱ����,ռ��LTE������������(��������)
	double m_dbFTP_DL_TotalData_HSPA_NID;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ�����������(��������),��ҪTD����
	double m_dbFTP_DL_TotalData_R4_NID;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ�����������(��������),��ҪTD����
	double m_dbFTP_DL_TotalData_ID;			//FTP����ִ��ʱ�����ܵ����������(������)
	double m_dbFTP_DL_TotalData_LTE_ID;		//FTP����ִ��ʱ����,ռ��LTE������������(������)
	double m_dbFTP_DL_TotalData_HSPA_ID;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ�����������(������),��ҪTD����
	double m_dbFTP_DL_TotalData_R4_ID;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ�����������(������),��ҪTD����

	double m_dbFTP_DL_TotalTime_NID;		//FTP������ʱ��(��������)
	double m_dbFTP_DL_TotalTime_LTE_NID;	//FTP����ִ��ʱ����,ռ��LTE���ʱ��(��������)
	double m_dbFTP_DL_TotalTime_HSPA_NID;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(��������)
	double m_dbFTP_DL_TotalTime_R4_NID;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(��������)
	double m_dbFTP_DL_TotalTime_ID;			//FTP������ʱ��(������)
	double m_dbFTP_DL_TotalTime_LTE_ID;		//FTP����ִ��ʱ����,ռ��LTE���ʱ��(������)
	double m_dbFTP_DL_TotalTime_HSPA_ID;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(������)
	double m_dbFTP_DL_TotalTime_R4_ID;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(������)

	UINT64 m_ullFTP_DL_PRB_NID;	//ÿRBƽ��������(��������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(��������)
	UINT64 m_ullFTP_DL_PRB_ID;	//ÿRBƽ��������(������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(������)

	UINT32 m_ulFtp_DL_Attempt_Num;		//FTP Download Attempt�ϱ�����
	UINT32 m_ulFtp_DL_Success_Num;		//FTP Download Success�ϱ�����
	UINT32 m_ulFtp_DL_Drop_LTE_Num;		//LTE��ʽ��,FTP Download Drop�ϱ�����
	UINT32 m_ulFtp_DL_Drop_HSPA_Num;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Download Drop�ϱ�����
	UINT32 m_ulFtp_DL_Drop_R4_Num;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Download Drop�ϱ�����
	UINT32 m_ulFtp_DL_Fail_LTE_Num;		//LTE��ʽ��,FTP Download Fail�ϱ�����
	UINT32 m_ulFtp_DL_Fail_HSPA_Num;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Download Fail�ϱ�����
	UINT32 m_ulFtp_DL_Fail_R4_Num;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Download Fail�ϱ�����

	double m_dbFtp_DL_RLCThroughputDL_Sum;	//��·��ƽ��������(Kbps):FTP����ִ��ʱ����,RLC Throughput DL���ܺ�
	UINT32 m_ulFtp_DL_RLCThroughputDL_Num;	//��·��ƽ��������(Kbps):FTP����ִ��ʱ����,RLC Throughput DL�ĸ���
	UINT32 m_ulFtp_DL_TotalTB;				//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��
	UINT32 m_ulFtp_DL_TotalErrorTB;			//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��

	double m_dbFtp_DL_LowThroughtDistance;	//������������������(km):ҵ������ʱ����,�������������·��,����������������1Mbps
	double m_dbFtp_DL_PDCPThroughtDistance;	//ҵ������ʱ����,PDCP�������ܲ����·�� "�淶Ҫ����pdcp��������"
	double m_dbFtp_DL_Edge_Throught_NID;	//��Ե����������(��������)(Kbps)
	double m_dbFtp_DL_Edge_Throught_ID;		//��Ե����������(������)(Kbps)

	//Ӧ�ò��������ʷֶ�ռ��:Ӧ�ò���������(��������)
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

	double m_dbFTP_UL_TotalData_NID;		//FTP�ϴ�ִ��ʱ�����ܵ��ϴ������(��������)
	double m_dbFTP_UL_TotalData_LTE_NID;	//FTP�ϴ�ִ��ʱ����,ռ��LTE����ϴ������(��������)
	double m_dbFTP_UL_TotalData_HSPA_NID;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ���ϴ������(��������),��ҪTD����
	double m_dbFTP_UL_TotalData_R4_NID;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ���ϴ����������������),��ҪTD����
	double m_dbFTP_UL_TotalData_ID;			//FTP�ϴ�ִ��ʱ�����ܵ��ϴ������(������)
	double m_dbFTP_UL_TotalData_LTE_ID;		//FTP�ϴ�ִ��ʱ����,ռ��LTE����ϴ������(������)
	double m_dbFTP_UL_TotalData_HSPA_ID;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ���ϴ������(������),��ҪTD����
	double m_dbFTP_UL_TotalData_R4_ID;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ���ϴ��������������),��ҪTD����

	double m_dbFTP_UL_TotalTime_NID;		//FTP�ϴ���ʱ��(��������)
	double m_dbFTP_UL_TotalTime_LTE_NID;	//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)
	double m_dbFTP_UL_TotalTime_HSPA_NID;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(��������)
	double m_dbFTP_UL_TotalTime_R4_NID;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(��������)
	double m_dbFTP_UL_TotalTime_ID;			//FTP�ϴ���ʱ��(������)
	double m_dbFTP_UL_TotalTime_LTE_ID;		//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)
	double m_dbFTP_UL_TotalTime_HSPA_ID;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(������)
	double m_dbFTP_UL_TotalTime_R4_ID;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(������)

	UINT64 m_ullFTP_UL_PRB_NID;			//ÿRBƽ���ϴ���(��������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(��������)
	UINT64 m_ullFTP_UL_PRB_ID;			//ÿRBƽ���ϴ���(������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(������)

	UINT32 m_ulFtp_UL_Attempt_Num;		//FTP Upload Attempt�ϱ�����
	UINT32 m_ulFtp_UL_Success_Num;		//FTP Upload Success�ϱ�����
	UINT32 m_ulFtp_UL_Drop_LTE_Num;		//LTE��ʽ��,FTP Upload Drop�ϱ�����
	UINT32 m_ulFtp_UL_Drop_HSPA_Num;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Upload Drop�ϱ�����
	UINT32 m_ulFtp_UL_Drop_R4_Num;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Upload Drop�ϱ�����
	UINT32 m_ulFtp_UL_Fail_LTE_Num;		//LTE��ʽ��,FTP Upload Fail�ϱ�����
	UINT32 m_ulFtp_UL_Fail_HSPA_Num;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Upload Fail�ϱ�����
	UINT32 m_ulFtp_UL_Fail_R4_Num;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Upload Fail�ϱ�����

	double m_dbFtp_UL_RLCThroughputUL_Sum;	//��·��ƽ��������(Kbps):FTP�ϴ�ִ��ʱ����,RLC Throughput UL���ܺ�
	UINT32 m_ulFtp_UL_RLCThroughputUL_Num;	//��·��ƽ��������(Kbps):FTP�ϴ�ִ��ʱ����,RLC Throughput UL�ĸ���

	double m_dbFtp_UL_LowThroughtDistance;	//������������������(km):ҵ���ϴ�ʱ����,�������������·��,�������������ϴ�256Kbps
	double m_dbFtp_UL_PDCPThroughtDistance;	//ҵ���ϴ�ʱ����,PDCP�������ܲ����·��
	double m_dbFtp_UL_Edge_Throught_NID;	//��Ե����������(��������)(Kbps)
	double m_dbFtp_UL_Edge_Throught_ID;		//��Ե����������(������)(Kbps)

	//Ӧ�ò��ϴ����ʷֶ�ռ��:Ӧ�ò��ϴ�����(��������)
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

	//���ܲ���

	//LTE�����л�
	UINT32 m_ulLTE_LTE_Handover_Start_NUM;	//�����л����Դ���:Handover Start�¼��ϱ�����
	UINT32 m_ulLTE_LTE_Handover_Success_NUM;//�����л��ɹ�����:Handover Success�¼��ϱ�����
	double m_dbLTE_LTE_Handover_Total_Delay;//�����л�ʱ�Ӻ�(s):Handover Start�¼���Handover Success�¼���ʱ���ܺ�

	//LTE-TDSCDMA�л�
	UINT32 m_ulLTE_TD_Handover_Start_NUM;	//LTE-TD�л����Դ���:TDSCDMA from LTE Handover Start�¼��ϱ�����
	UINT32 m_ulLTE_TD_Handover_Success_NUM;	//LTE-TD�л��ɹ�����:TDSCDMA from LTE Handover Success�¼��ϱ�����
	double m_dbLTE_TD_Handover_Total_Delay;	//LTE-TD�л�ʱ�Ӻ�(s):TDSCDMA from LTE Handover Start�¼���TDSCDMA from LTE Handover Success�¼���ʱ���ܺ�
	double m_dbLTE_TD_RSRP_Sum_Before_Handover_Start_5Second;	//LTE-TD�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Start�¼�ǰ5������RSRP�ܺ�
	UINT32 m_ulLTE_TD_RSRP_Num_Before_Handover_Start_5Second;	//LTE-TD�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Start�¼�ǰ5������RSRP����
	double m_dbLTE_TD_RSRP_Sum_After_Handover_Success_5Second;	//LTE-TD�л����ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Success�¼���5������RSRP�ܺ�
	UINT32 m_ulLTE_TD_RSRP_Num_After_Handover_Success_5Second;	//LTE-TD�л����ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Success�¼���5������RSRP����

	//TDSCDMA-LTE�л�
	UINT32 m_ulTD_LTE_Handover_Start_NUM;	//TD-LTE�л����Դ���:TDSCDMA to LTE Handover Start�¼��ϱ�����
	UINT32 m_ulTD_LTE_Handover_Success_NUM;	//TD-LTE�л��ɹ�����:TDSCDMA to LTE Handover Success�¼��ϱ�����
	double m_dbTD_LTE_Handover_Total_Delay;	//TD-LTE�л�ʱ�Ӻ�(s):TDSCDMA to LTE Handover Start�¼���TDSCDMA to LTE Handover Success�¼���ʱ���ܺ�
	double m_dbTD_LTE_RSRP_Sum_Before_Handover_Start_5Second;	//TD-LTE�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Start�¼�ǰ5������RSRP�ܺ�
	UINT32 m_ulTD_LTE_RSRP_Num_Before_Handover_Start_5Second;	//TD-LTE�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Start�¼�ǰ5������RSRP����
	double m_dbTD_LTE_RSRP_Sum_After_Handover_Success_5Second;	//TD-LTE�л����ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Success�¼���5������RSRP�ܺ�
	UINT32 m_ulTD_LTE_RSRP_Num_After_Handover_Success_5Second;	//TD-LTE�л����ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Success�¼���5������RSRP����

	//LTE-TDSCDMA��ѡ
	UINT32 m_ulLTE_TD_Resel_Start_NUM;	//LTE-TD��ѡ����:TDSCDMA from LTE Resel Start�¼��ϱ�����
	UINT32 m_ulLTE_TD_Resel_Success_NUM;//LTE-TD��ѡ�ɹ�����:TDSCDMA from LTE Resel Success�¼��ϱ�����
	double m_dbLTE_TD_Resel_Total_Delay;//LTE-TD��ѡʱ�Ӻ�(s):TDSCDMA from LTE Resel Start�¼���TDSCDMA from LTE Resel Success�¼���ʱ���ܺ�
	double m_dbLTE_TD_RSRP_Sum_Before_Resel_Start_5Second;	//LTE-TD��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Start�¼�ǰ5������RSRP�ܺ�
	UINT32 m_ulLTE_TD_RSRP_Num_Before_Resel_Start_5Second;	//LTE-TD��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Start�¼�ǰ5������RSRP����
	double m_dbLTE_TD_RSRP_Sum_After_Resel_Success_5Second;	//LTE-TD��ѡ���ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Success�¼���5������RSRP�ܺ�
	UINT32 m_ulLTE_TD_RSRP_Num_After_Resel_Success_5Second;	//LTE-TD��ѡ���ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Success�¼���5������RSRP����

	//TDSCDMA-LTE��ѡ
	UINT32 m_ulTD_LTE_Resel_Start_NUM;	//TD-LTE��ѡ����:TDSCDMA to LTE Resel Start�¼��ϱ�����
	UINT32 m_ulTD_LTE_Resel_Success_NUM;//TD-LTE��ѡ�ɹ�����:TDSCDMA to LTE Resel Success�¼��ϱ�����
	double m_dbTD_LTE_Resel_Total_Delay;//TD-LTE��ѡʱ�Ӻ�(s):TDSCDMA to LTE Resel Start�¼���TDSCDMA to LTE Resel Success�¼���ʱ���ܺ�
	double m_dbTD_LTE_RSRP_Sum_Before_Resel_Start_5Second;	//TD-LTE��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Start�¼�ǰ5������RSRP�ܺ�
	UINT32 m_ulTD_LTE_RSRP_Num_Before_Resel_Start_5Second;	//TD-LTE��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Start�¼�ǰ5������RSRP����
	double m_dbTD_LTE_RSRP_Sum_After_Resel_Success_5Second;	//TD-LTE��ѡ���ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Success�¼���5������RSRP�ܺ�
	UINT32 m_ulTD_LTE_RSRP_Num_After_Resel_Success_5Second;	//TD-LTE��ѡ���ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Success�¼���5������RSRP����

	//Attachͳ��
	UINT32 m_ulEPS_Attach_Request_NUM;	//Attch���Դ���:EPS Attach Request�¼��ϱ�����
	UINT32 m_ulEPS_Attach_Success_NUM;	//Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
	double m_dbEPS_Attach_Total_Delay;	//Attachʱ�Ӻ�(s):EPS Attach Request�¼���EPS Attach Success�¼���ʱ���ܺ�

	//Serviceͳ��
	UINT32 m_ulSERVICE_Request_NUM;	//Service�������:SERVICE REQUEST�¼��ϱ�����
	UINT32 m_ulSERVICE_Success_NUM;	//Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
	double m_dbSERVICE_Total_Delay;	//Service����ʱ�Ӻ�(s):SERVICE REQUEST�¼���SERVICE SUCCESS�¼���ʱ���ܺ�

	//LTE���������ͳ��
	UINT32 m_ulTAU_Request_NUM;	//TA���³��Դ���:TAU Request�¼��ϱ�����
	UINT32 m_ulTAU_Success_NUM;	//TA���³ɹ�����:TAU Success�¼��ϱ�����
	double m_dbTAU_Total_Delay;	//TA����ʱ�Ӻ�(s):(TAU Success-TAU Request)��ʱ���ܺ�

	//������ͳ��
	double m_dbPDCP_DL_Throughput_Sum_ID;	//PDCP����ƽ��������Kbps(������):PDCP Throughput DL�ܺ�
	UINT32 m_ulPDCP_DL_Throughput_Num_ID;	//PDCP����ƽ��������Kbps(������):PDCP Throughput DL����
	double m_dbPDCP_UL_Throughput_Sum_ID;	//PDCP����ƽ��������Kbps(������):PDCP Throughput UL�ܺ�
	UINT32 m_ulPDCP_UL_Throughput_Num_ID;	//PDCP����ƽ��������Kbps(������):PDCP Throughput UL����
	//double m_dbRLC_DL_Throughput_Sum_ID;	//RLC����ƽ��������Kbps(������):RLC Throughput DL�ܺ�
	//UINT32 m_ulRLC_DL_Throughput_Num_ID;	//RLC����ƽ��������Kbps(������):RLC Throughput DL����
	//double m_dbRLC_UL_Throughput_Sum_ID;	//RLC����ƽ��������Kbps(������):RLC Throughput UL�ܺ�
	//UINT32 m_ulRLC_UL_Throughput_Num_ID;	//RLC����ƽ��������Kbps(������):RLC Throughput UL����
	double m_dbMAC_DL_Throughput_Sum_ID;	//MAC����ƽ��������Kbps(������):MAC Throughput DL�ܺ�
	UINT32 m_ulMAC_DL_Throughput_Num_ID;	//MAC����ƽ��������Kbps(������):MAC Throughput DL����
	double m_dbMAC_UL_Throughput_Sum_ID;	//MAC����ƽ��������Kbps(������):MAC Throughput UL�ܺ�
	UINT32 m_ulMAC_UL_Throughput_Num_ID;	//MAC����ƽ��������Kbps(������):MAC Throughput UL����

	//PDSCH�ش�ͳ��
	UINT32 m_ulPDSCH_first_rx_success_cnt;	//���ν��ճɹ�����:pdsch_first_rx_success_cnt
	UINT32 m_ulPDSCH_multi_retrans_success_cnt;	//����ش��ɹ�����:pdsch_multi_retrans_success_cnt

	//PUSCH�ش�ͳ��
	UINT32 m_ulHARQ_UL_1st_Tx_Succ_Num;		//�����ɹ�����:HARQ UL 1st Tx Succ Num
	UINT32 m_ulHARQ_UL_1st_ReTx_Succ_Num;	//1���ش��ɹ�����:HARQ UL 1st ReTx Succ Num
	UINT32 m_ulHARQ_UL_2nd_ReTx_Succ_Num;	//2���ش��ɹ�����:HARQ UL 2nd ReTx Succ Num
	UINT32 m_ulHARQ_UL_3rd_ReTx_Succ_Num;	//3���ش��ɹ�����:HARQ UL 3rd ReTx Succ Num
	UINT32 m_ulHARQ_UL_4th_ReTx_Succ_Num;	//4���ش��ɹ�����:HARQ UL 4th ReTx Succ Num
	UINT32 m_ulHARQ_UL_mutil_ReTx_Succ_Num;	//����ش��ɹ�����:HARQ UL mutil ReTx Succ Num
	UINT32 m_ulHARQ_DL_ReTx_Failed_cnt;		//�ش�ʧ�ܴ���:HARQ DL ReTx Failed Num;
	UINT32 m_ulHARQ_UL_ReTx_Failed_cnt;		//�ش�ʧ�ܴ���:HARQ UL ReTx Failed Num;

	//����0����ACK/NACKͳ��
	UINT32 m_ulHARQ_DL_C0_ACK_Count;	//ACK Count:HARQ DL C0 ACK Count
	UINT32 m_ulHARQ_DL_C0_NACK_Count;	//NACK Count:HARQ DL C0 NACK Count
	//����1����ACK/NACKͳ��
	UINT32 m_ulHARQ_DL_C1_ACK_Count;	//ACK Count:HARQ DL C1 ACK Count
	UINT32 m_ulHARQ_DL_C1_NACK_Count;	//NACK Count:HARQ DL C1 NACK Count
	//����ACK/NACKͳ��
	UINT32 m_ulHARQ_UL_Ack_Count;	//ACK Count:HARQ UL ACK Count
	UINT32 m_ulHARQ_UL_NAck_Count;	//NACK Count:HARQ UL NACK Count

	//����BLER
	double m_dbDL_Code0_BLER_Sum;		//��������0Bler(%):DL Code0 BLER�ܺ�
	UINT32 m_ulDL_Code0_BLER_Num;		//��������0Bler(%):DL Code0 BLER����
	double m_dbDL_Code1_BLER_Sum;		//��������1Bler(%):DL Code1 BLER�ܺ�
	UINT32 m_ulDL_Code1_BLER_Num;		//��������1Bler(%):DL Code1 BLER����
	double m_dbDL_Code0_I_BLER_Sum;		//��������0��ʼBler(%):DL Code0 IBLER�ܺ�
	UINT32 m_ulDL_Code0_I_BLER_Num;		//��������0��ʼBler(%):DL Code0 IBLER����
	double m_dbDL_Code0_R_BLER_Sum;		//��������0����Bler(%):DL Code0 RBLER�ܺ�
	UINT32 m_ulDL_Code0_R_BLER_Num;		//��������0����Bler(%):DL Code0 RBLER����
	double m_dbDL_Code1_I_BLER_Sum;		//��������1��ʼBler(%):DL Code1 IBLER�ܺ�
	UINT32 m_ulDL_Code1_I_BLER_Num;		//��������1��ʼBler(%):DL Code1 IBLER����
	double m_dbDL_Code2_R_BLER_Sum;		//��������1����Bler(%):DL Code1 RBLER�ܺ�
	UINT32 m_ulDL_Code2_R_BLER_Num;		//��������1����Bler(%):DL Code1 RBLER����

	//����BLER
	double m_dbUL_BLER_Sum;				//����Bler(%):UL BLER�ܺ�
	UINT32 m_ulUL_BLER_Num;				//����Bler(%):UL BLER����
	double m_dbUL_I_BLER_Sum;			//���г�ʼBler(%):UL IBLER�ܺ�
	UINT32 m_ulUL_I_BLER_Num;			//���г�ʼBler(%):UL IBLER����
	double m_dbUL_R_BLER_Sum;			//���в���Bler(%):UL RBLER�ܺ�
	UINT32 m_ulUL_R_BLER_Num;			//���в���Bler(%):UL RBLER����

	double m_dbRSRP_Sum;		//ƽ��RSRP(dBm):RSRP�ܺ�
	double m_dbRSRP_Edge;		//��ԵRSRP(dBm):RSRP�����CDF(�ۻ���ʷֲ�)5%��Ӧ��ֵ
	UINT32 m_ulRSRP_MeetNum;	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR >= 0dB

	double m_dbLTETotalDistance;		//LTE�������:LTE��ʽ�µ�����ܺ�
	double m_dbLTEWeakCoverDistance;	//LTE�������������:����10��70%�Ĳ����·������RSRP<-105dBm,��CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
	double m_dbLTENoneCoverDistance;	//LTE�����޸������:����10��70%�Ĳ����·������RSRP<-115dBm,CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
	double m_dbLTEHighTxpowerDistance;	//UE�߹��ʷ������:UE��PUSCH�ŵ����书�ʳ���10��70%�����>16dBm������·��

	double m_dbPRACH_Power_Sum;	//PRACHƽ����(dBm):PRACH_Power�ܺ�
	UINT32 m_ulPRACH_Power_Num;	//PRACHƽ����(dBm):PRACH_Power����
	double m_dbPUSCH_Power_Sum;	//PUSCHƽ����(dBm):PUSCH_Power�ܺ�
	UINT32 m_ulPUSCH_Power_Num;	//PUSCHƽ����(dBm):PUSCH_Power����
	double m_dbPUCCH_Power_Sum;	//PUCCHƽ����(dBm):PUCCH_Power�ܺ�
	UINT32 m_ulPUCCH_Power_Num;	//PUCCHƽ����(dBm):PUCCH_Power����
	double m_dbSRS_Power_Sum;	//SRSƽ����(dBm):SRS_Power�ܺ�
	UINT32 m_ulSRS_Power_Num;	//SRSƽ����(dBm):SRS_Power����

	double m_dbSINR_Sum;		//SINR(dB)�ܺ�
	double m_dbSINR_Edge;		//��ԵSINR(dB):SINR�����CDF(�ۼƸ��ʷֲ�)5%��Ӧ��ֵ
	double m_dbRSRQ_Sum;		//RSRQ(dB)�ܺ�
	double m_dbRank1_Wideband_Code0_SINR_Sum;	//Rank1 SINR(dBm):RI=1��Wideband Code0 SINR�ܺ�
	UINT32 m_ulRank1_Wideband_Code0_SINR_Num;	//Rank1 SINR(dBm):RI=1��Wideband Code0 SINR����
	double m_dbRank2_Wideband_Code0_SINR_Sum;	//Rank2 SINR1(dBm):RI=2��Wideband Code0 SINR�ܺ�
	UINT32 m_ulRank2_Wideband_Code0_SINR_Num;	//Rank2 SINR1(dBm):RI=2��Wideband Code0 SINR����
	double m_dbRank2_Wideband_Code1_SINR_Sum;	//Rank2 SINR2(dBm):RI=2��Wideband Code1 SINR�ܺ�
	UINT32 m_ulRank2_Wideband_Code1_SINR_Num;	//Rank2 SINR2(dBm):RI=2��Wideband Code1 SINR����

	double m_dbLowSINRDistance;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-1dB������·��
	UINT32 m_ulOverCoverMeetNum;//�ص����Ƕ�>=3�Ĳ������:�ص����Ƕ�:·��������ǿС��RSRP�Ĳ�ֵ����-6dB�ĵ�ƽ������ ͬʱ��ǿС��RSRP>=-105dB
	double m_dbOverCoverDistance;//�����ص����Ƕ�>=3�����

	//RSRP���ֲ�ͳ��
	UINT32 m_ulRSRP_141_110_Num;	//RSRP[-141,-110)
	UINT32 m_ulRSRP_110_105_Num;	//RSRP[-110,-105)
	UINT32 m_ulRSRP_105_100_Num;	//RSRP[-105,-100)
	UINT32 m_ulRSRP_100_95_Num;		//RSRP[-100,-95)
	UINT32 m_ulRSRP_95_90_Num;		//RSRP[-95,-90)
	UINT32 m_ulRSRP_90_85_Num;		//RSRP[-90,-85)
	UINT32 m_ulRSRP_85_80_Num;		//RSRP[-85,-80)
	UINT32 m_ulRSRP_80_75_Num;		//RSRP[-80,-75)
	UINT32 m_ulRSRP_75_70_Num;		//RSRP[-75,-70)
	UINT32 m_ulRSRP_70_65_Num;		//RSRP[-70,-65)
	UINT32 m_ulRSRP_65_60_Num;		//RSRP[-65,-60)
	UINT32 m_ulRSRP_60_44_Num;		//RSRP[-60,-44]

	//SINR���ֲ�ͳ��
	UINT32 m_ulSINR_50_10_Num;	//SINR[-50,-10)
	UINT32 m_ulSINR_10_6_Num;	//SINR[-10,-6)
	UINT32 m_ulSINR_6_3_Num;	//SINR[-6,-3)
	UINT32 m_ulSINR_3_0_Num;	//SINR[-3,0)
	UINT32 m_ulSINR_0_3_Num;	//SINR[0,3)
	UINT32 m_ulSINR_3_6_Num;	//SINR[3,6)
	UINT32 m_ulSINR_6_10_Num;	//SINR[6,10)
	UINT32 m_ulSINR_10_15_Num;	//SINR[10,15)
	UINT32 m_ulSINR_15_20_Num;	//SINR[15,20)
	UINT32 m_ulSINR_20_25_Num;	//SINR[20,25)
	UINT32 m_ulSINR_25_50_Num;	//SINR[25,50]

	//RSRQ���ֲ�ͳ��
	UINT32 m_ulRSRQ_196_175_Num;	//RSRQ[-19.6,-17.5)
	UINT32 m_ulRSRQ_175_155_Num;	//RSRQ[-17.5,-15.5)
	UINT32 m_ulRSRQ_155_135_Num;	//RSRQ[-15.5,-13.5)
	UINT32 m_ulRSRQ_135_115_Num;	//RSRQ[-13.5,-11.5)
	UINT32 m_ulRSRQ_115_95_Num;		//RSRQ[-11.5,-9.5)
	UINT32 m_ulRSRQ_95_75_Num;		//RSRQ[-9.5,-7.5)
	UINT32 m_ulRSRQ_75_55_Num;		//RSRQ[-7.5,-5.5)
	UINT32 m_ulRSRQ_55_35_Num;		//RSRQ[-5.5,-3.5)
	UINT32 m_ulRSRQ_35_30_Num;		//RSRQ[-3.5,-3]

	//�ص����Ƕ����ֲ�ͳ��
	UINT32 m_ulOverCoverDegree_0_Num;		//0
	UINT32 m_ulOverCoverDegree_1_Num;		//1
	UINT32 m_ulOverCoverDegree_2_Num;		//2
	UINT32 m_ulOverCoverDegree_3_Num;		//3
	UINT32 m_ulOverCoverDegree_4_Num;		//4
	UINT32 m_ulOverCoverDegree_5_Num;		//5
	UINT32 m_ulOverCoverDegree_5_10_Num;	//(5,10]
	UINT32 m_ulOverCoverDegree_10_N_Num;	// >10

	//PHY������
	double m_dbPHY_Throughput_DL_Sum;		//PHY����ƽ��������:PHY Throughput DL�ܺ�
	UINT32 m_ulPHY_Throughput_DL_Num;		//PHY����ƽ��������:PHY Throughput DL����
	double m_dbPHY_Cw0_Throughput_DL_Sum;	//����0ƽ��������(Kbps):PHY Cw0 Throughput DL�ܺ�
	UINT32 m_ulPHY_Cw0_Throughput_DL_Num;	//����0ƽ��������(Kbps):PHY Cw0 Throughput DL����
	double m_dbPHY_Cw1_Throughput_DL_Sum;	//����1ƽ��������(Kbps):PHY Cw1 Throughput DL�ܺ�
	UINT32 m_ulPHY_Cw1_Throughput_DL_Num;	//����1ƽ��������(Kbps):PHY Cw1 Throughput DL����
	double m_dbPHY_Throughput_UL_Sum;		//PHY����ƽ��������:PHY Throughput UL�ܺ�
	UINT32 m_ulPHY_Throughput_UL_Num;		//PHY����ƽ��������:PHY Throughput UL����

	//��֡����
	UINT32 m_ulSubFrame_DL_TotalNum;	//���ȸ�UE��������֡���ܺ�
	UINT32 m_ulSubFrame_UL_TotalNum;	//���ȸ�UE��������֡���ܺ�

	//MCSͳ��, ͨ����ϸ�ֲ�ͳ���Լ�����
	//CQIͳ��, ͨ����ϸ�ֲ�ͳ���Լ�����

	//Rankͳ��,ֻ����DL Code0 MCSΪ����,ͬʱ����DL Code0 MCS��DL Code1 MCSΪ˫��
	UINT32 m_ulRank1_ReportNum;	//RI=1�ϱ�����
	UINT32 m_ulRank2_ReportNum;	//RI=2�ϱ�����
	double m_dbSingleFlowTime;	//����ʱ��
	double m_dbDoubleFlowTime;	//˫��ʱ��
	double m_dbSingleFlowData;	//���������
	double m_dbDoubleFlowData;	//˫�������

	//����ģʽʱ��ռ��(%)
	double m_dbTM1ModeTime;	//TM1ʱ��
	double m_dbTM2ModeTime;	//TM2ʱ��
	double m_dbTM3ModeTime;	//TM3ʱ��
	double m_dbTM4ModeTime;	//TM4ʱ��
	double m_dbTM5ModeTime;	//TM5ʱ��
	double m_dbTM6ModeTime;	//TM6ʱ��
	double m_dbTM7ModeTime;	//TM7ʱ��
	double m_dbTM8ModeTime;	//TM8ʱ��

	//���Ʒ�ʽ�ֲ�ͳ��
	UINT32 m_ulDL_Code0_QPSK_Num;	//��������0���Ʒ�ʽQPSK
	UINT32 m_ulDL_Code0_16QAM_Num;	//��������0���Ʒ�ʽ16QAM
	UINT32 m_ulDL_Code0_64QAM_Num;	//��������0���Ʒ�ʽ64QAM
	UINT32 m_ulDL_Code1_QPSK_Num;	//��������1���Ʒ�ʽQPSK
	UINT32 m_ulDL_Code1_16QAM_Num;	//��������1���Ʒ�ʽ16QAM
	UINT32 m_ulDL_Code1_64QAM_Num;	//��������1���Ʒ�ʽ64QAM
	UINT32 m_ulUL_QPSK_Num;			//���е��Ʒ�ʽQPSK
	UINT32 m_ulUL_16QAM_Num;		//���е��Ʒ�ʽ16QAM
	UINT32 m_ulUL_64QAM_Num;		//���е��Ʒ�ʽ64QAM

	//����MCS����0��ϸ�ֲ����(%)
	UINT32 m_ulDL_Code0_MCS0_Num;	//DL Code0 MCS == 0 �ĸ���
	UINT32 m_ulDL_Code0_MCS1_Num;
	UINT32 m_ulDL_Code0_MCS2_Num;
	UINT32 m_ulDL_Code0_MCS3_Num;
	UINT32 m_ulDL_Code0_MCS4_Num;
	UINT32 m_ulDL_Code0_MCS5_Num;
	UINT32 m_ulDL_Code0_MCS6_Num;
	UINT32 m_ulDL_Code0_MCS7_Num;
	UINT32 m_ulDL_Code0_MCS8_Num;
	UINT32 m_ulDL_Code0_MCS9_Num;
	UINT32 m_ulDL_Code0_MCS10_Num;
	UINT32 m_ulDL_Code0_MCS11_Num;
	UINT32 m_ulDL_Code0_MCS12_Num;
	UINT32 m_ulDL_Code0_MCS13_Num;
	UINT32 m_ulDL_Code0_MCS14_Num;
	UINT32 m_ulDL_Code0_MCS15_Num;
	UINT32 m_ulDL_Code0_MCS16_Num;
	UINT32 m_ulDL_Code0_MCS17_Num;
	UINT32 m_ulDL_Code0_MCS18_Num;
	UINT32 m_ulDL_Code0_MCS19_Num;
	UINT32 m_ulDL_Code0_MCS20_Num;
	UINT32 m_ulDL_Code0_MCS21_Num;
	UINT32 m_ulDL_Code0_MCS22_Num;
	UINT32 m_ulDL_Code0_MCS23_Num;
	UINT32 m_ulDL_Code0_MCS24_Num;
	UINT32 m_ulDL_Code0_MCS25_Num;
	UINT32 m_ulDL_Code0_MCS26_Num;
	UINT32 m_ulDL_Code0_MCS27_Num;
	UINT32 m_ulDL_Code0_MCS28_Num;
	UINT32 m_ulDL_Code0_MCS29_Num;
	UINT32 m_ulDL_Code0_MCS30_Num;
	UINT32 m_ulDL_Code0_MCS31_Num;

	//����MCS����1��ϸ�ֲ����(%)
	UINT32 m_ulDL_Code1_MCS0_Num;	//DL Code1 MCS == 0 �ĸ���
	UINT32 m_ulDL_Code1_MCS1_Num;
	UINT32 m_ulDL_Code1_MCS2_Num;
	UINT32 m_ulDL_Code1_MCS3_Num;
	UINT32 m_ulDL_Code1_MCS4_Num;
	UINT32 m_ulDL_Code1_MCS5_Num;
	UINT32 m_ulDL_Code1_MCS6_Num;
	UINT32 m_ulDL_Code1_MCS7_Num;
	UINT32 m_ulDL_Code1_MCS8_Num;
	UINT32 m_ulDL_Code1_MCS9_Num;
	UINT32 m_ulDL_Code1_MCS10_Num;
	UINT32 m_ulDL_Code1_MCS11_Num;
	UINT32 m_ulDL_Code1_MCS12_Num;
	UINT32 m_ulDL_Code1_MCS13_Num;
	UINT32 m_ulDL_Code1_MCS14_Num;
	UINT32 m_ulDL_Code1_MCS15_Num;
	UINT32 m_ulDL_Code1_MCS16_Num;
	UINT32 m_ulDL_Code1_MCS17_Num;
	UINT32 m_ulDL_Code1_MCS18_Num;
	UINT32 m_ulDL_Code1_MCS19_Num;
	UINT32 m_ulDL_Code1_MCS20_Num;
	UINT32 m_ulDL_Code1_MCS21_Num;
	UINT32 m_ulDL_Code1_MCS22_Num;
	UINT32 m_ulDL_Code1_MCS23_Num;
	UINT32 m_ulDL_Code1_MCS24_Num;
	UINT32 m_ulDL_Code1_MCS25_Num;
	UINT32 m_ulDL_Code1_MCS26_Num;
	UINT32 m_ulDL_Code1_MCS27_Num;
	UINT32 m_ulDL_Code1_MCS28_Num;
	UINT32 m_ulDL_Code1_MCS29_Num;
	UINT32 m_ulDL_Code1_MCS30_Num;
	UINT32 m_ulDL_Code1_MCS31_Num;

	//����MCS ��ϸ�ֲ����(%)
	UINT32 m_ulUL_MCS0_Num;	//UL MCS == 0 �ĸ���
	UINT32 m_ulUL_MCS1_Num;
	UINT32 m_ulUL_MCS2_Num;
	UINT32 m_ulUL_MCS3_Num;
	UINT32 m_ulUL_MCS4_Num;
	UINT32 m_ulUL_MCS5_Num;
	UINT32 m_ulUL_MCS6_Num;
	UINT32 m_ulUL_MCS7_Num;
	UINT32 m_ulUL_MCS8_Num;
	UINT32 m_ulUL_MCS9_Num;
	UINT32 m_ulUL_MCS10_Num;
	UINT32 m_ulUL_MCS11_Num;
	UINT32 m_ulUL_MCS12_Num;
	UINT32 m_ulUL_MCS13_Num;
	UINT32 m_ulUL_MCS14_Num;
	UINT32 m_ulUL_MCS15_Num;
	UINT32 m_ulUL_MCS16_Num;
	UINT32 m_ulUL_MCS17_Num;
	UINT32 m_ulUL_MCS18_Num;
	UINT32 m_ulUL_MCS19_Num;
	UINT32 m_ulUL_MCS20_Num;
	UINT32 m_ulUL_MCS21_Num;
	UINT32 m_ulUL_MCS22_Num;
	UINT32 m_ulUL_MCS23_Num;
	UINT32 m_ulUL_MCS24_Num;
	UINT32 m_ulUL_MCS25_Num;
	UINT32 m_ulUL_MCS26_Num;
	UINT32 m_ulUL_MCS27_Num;
	UINT32 m_ulUL_MCS28_Num;
	UINT32 m_ulUL_MCS29_Num;
	UINT32 m_ulUL_MCS30_Num;
	UINT32 m_ulUL_MCS31_Num;

	//����0��CQI��ϸ�ֲ����(%)
	UINT32 m_ulWideband_Code0_CQI0_Num;	//Wideband Code0 CQI == 0 �ĸ���
	UINT32 m_ulWideband_Code0_CQI1_Num;
	UINT32 m_ulWideband_Code0_CQI2_Num;
	UINT32 m_ulWideband_Code0_CQI3_Num;
	UINT32 m_ulWideband_Code0_CQI4_Num;
	UINT32 m_ulWideband_Code0_CQI5_Num;
	UINT32 m_ulWideband_Code0_CQI6_Num;
	UINT32 m_ulWideband_Code0_CQI7_Num;
	UINT32 m_ulWideband_Code0_CQI8_Num;
	UINT32 m_ulWideband_Code0_CQI9_Num;
	UINT32 m_ulWideband_Code0_CQI10_Num;
	UINT32 m_ulWideband_Code0_CQI11_Num;
	UINT32 m_ulWideband_Code0_CQI12_Num;
	UINT32 m_ulWideband_Code0_CQI13_Num;
	UINT32 m_ulWideband_Code0_CQI14_Num;
	UINT32 m_ulWideband_Code0_CQI15_Num;

	//����1��CQI��ϸ�ֲ����(%)
	UINT32 m_ulWideband_Code1_CQI0_Num;	//Wideband Code1 CQI == 0 �ĸ���
	UINT32 m_ulWideband_Code1_CQI1_Num;
	UINT32 m_ulWideband_Code1_CQI2_Num;
	UINT32 m_ulWideband_Code1_CQI3_Num;
	UINT32 m_ulWideband_Code1_CQI4_Num;
	UINT32 m_ulWideband_Code1_CQI5_Num;
	UINT32 m_ulWideband_Code1_CQI6_Num;
	UINT32 m_ulWideband_Code1_CQI7_Num;
	UINT32 m_ulWideband_Code1_CQI8_Num;
	UINT32 m_ulWideband_Code1_CQI9_Num;
	UINT32 m_ulWideband_Code1_CQI10_Num;
	UINT32 m_ulWideband_Code1_CQI11_Num;
	UINT32 m_ulWideband_Code1_CQI12_Num;
	UINT32 m_ulWideband_Code1_CQI13_Num;
	UINT32 m_ulWideband_Code1_CQI14_Num;
	UINT32 m_ulWideband_Code1_CQI15_Num;

	//PDCCH CFI�ֲ�ͳ��(%)
	UINT32 m_ulPDCCH_CFI1_Num; //CFI1 Count == 1 �ĸ���
	UINT32 m_ulPDCCH_CFI2_Num;
	UINT32 m_ulPDCCH_CFI3_Num;
	UINT32 m_ulPDCCH_CFI4_Num;

	//LTE��֡����ʱ���ֲ�ͳ��(%):subframe_Assignment
	double m_dbSubFrameAssign_Format0_Time;	//��ʽ0
	double m_dbSubFrameAssign_Format1_Time;	//��ʽ1(1:1)
	double m_dbSubFrameAssign_Format2_Time;	//��ʽ2(3:1)
	double m_dbSubFrameAssign_Format3_Time;	//��ʽ3
	double m_dbSubFrameAssign_Format4_Time;	//��ʽ4
	double m_dbSubFrameAssign_Format5_Time;	//��ʽ5
	double m_dbSubFrameAssign_Format6_Time;	//��ʽ6

	//LTE����ʱ϶����ʱ���ֲ�ͳ��(%):special_Subframe_Patterns
	double m_dbSpecialSubframePatterns_0_Time;	//0
	double m_dbSpecialSubframePatterns_1_Time;	//1
	double m_dbSpecialSubframePatterns_2_Time;	//2
	double m_dbSpecialSubframePatterns_3_Time;	//3
	double m_dbSpecialSubframePatterns_4_Time;	//4
	double m_dbSpecialSubframePatterns_3_9_2_Time;	//5
	double m_dbSpecialSubframePatterns_6_Time;	//6
	double m_dbSpecialSubframePatterns_10_2_2_Time;	//7
	double m_dbSpecialSubframePatterns_8_Time;	//8
	double m_dbSpecialSubframePatterns_Other_Time;	//����

	//LTE CP����ʱ���ֲ�ͳ��(%):UL_CP_Type
	double m_dbLTE_Normal_CP_Time;	//Normal CP
	double m_dbLTE_Extended_CP_Time;//Extended CP

	//LTE ���߶˿�����ʱ���ֲ�ͳ��(%):eNB_Tx_Antenna_Num
	double m_dbLTE_AN_1_Time;	//an1
	double m_dbLTE_AN_2_Time;	//an2
	double m_dbLTE_AN_4_Time;	//an4

	//LTE ��Ƶ��ռ��ʱ���ֲ�ͳ��(%):Band
	double m_dbLTE_Band_D_Time;	//DƵ��
	double m_dbLTE_Band_E_Time;	//EƵ��
	double m_dbLTE_Band_F_Time;	//FƵ��

	//��֡����
	UINT32 m_ulSubFrame_DL_Count;	//���ȸ�UE��������֡���ܸ���
	UINT32 m_ulSubFrame_UL_Count;	//���ȸ�UE��������֡���ܸ���

	UINT64 m_ullFTP_DL_PRB_Sum;
	UINT64 m_ullFTP_DL_PRB_Count;
	UINT64 m_ullFTP_UL_PRB_Sum;
	UINT64 m_ullFTP_UL_PRB_Count;
};