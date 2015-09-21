//#include "StdAfx.h"
#include "LogInfo_LTE_PS.h"

CLogInfo_LTE_PS::CLogInfo_LTE_PS(void)
{
	InitPara();
}


CLogInfo_LTE_PS::~CLogInfo_LTE_PS(void)
{

}

//CString CLogInfo_LTE_PS::GetInsertSQL()
//{
//	CString strSQL = _T("");
//
//	strSQL.Format(_T("insert into %s values ( "), m_strTableName);
//
//	SQL_AppendULONGLONG(strSQL, RecSeqNo);    //��¼���к�, ȫ��ֵΨһ,����
//	//ҵ�񲿷�
//
//	//����ʱ��(�ļ�����ʱ��-�ļ���ʼʱ��)�Ͳ��������ǰ̨����
//
//	//NID��ʾ��������,ID��ʾ������
//
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_NID);		//FTP����ִ��ʱ�����ܵ����������(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_LTE_NID);    //FTP����ִ��ʱ����,ռ��LTE������������(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_HSPA_NID);	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ�����������(��������),��ҪTD����
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_R4_NID);		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ�����������(��������),��ҪTD����
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_ID);			//FTP����ִ��ʱ�����ܵ����������(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_LTE_ID);		//FTP����ִ��ʱ����,ռ��LTE������������(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_HSPA_ID);	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ�����������(������),��ҪTD����
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalData_R4_ID);		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ�����������(������),��ҪTD����
//
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_NID);		//FTP������ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_LTE_NID);	//FTP����ִ��ʱ����,ռ��LTE���ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_HSPA_NID);	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_R4_NID);		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_ID);			//FTP������ʱ��(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_LTE_ID);		//FTP����ִ��ʱ����,ռ��LTE���ʱ��(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_HSPA_ID);	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_R4_ID);		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(������)
//
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_DL_PRB_NID);	//ÿRBƽ��������(��������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(��������)
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_DL_PRB_ID);	//ÿRBƽ��������(������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(������)==����ҵ�����PRB�����ܺͣ�
//
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Attempt_Num);		//FTP Download Attempt�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Success_Num);		//FTP Download Success�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Drop_LTE_Num);		//LTE��ʽ��,FTP Download Drop�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Drop_HSPA_Num);	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Download Drop�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Drop_R4_Num);		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Download Drop�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Fail_LTE_Num);		//LTE��ʽ��,FTP Download Fail�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Fail_HSPA_Num);	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Download Fail�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Fail_R4_Num);		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Download Fail�ϱ�����
//
//	SQL_AppendFlt(strSQL, m_dbFtp_DL_RLCThroughputDL_Sum);	//��·��ƽ��������(Kbps):FTP����ִ��ʱ����,RLC Throughput DL���ܺ�
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_RLCThroughputDL_Num);	//��·��ƽ��������(Kbps):FTP����ִ��ʱ����,RLC Throughput DL�ĸ���
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TotalTB);				//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TotalErrorTB);			//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��
//
//	SQL_AppendFlt(strSQL, m_dbFtp_DL_LowThroughtDistance);	//������������������(km):ҵ������ʱ����,�������������·��,����������������1Mbps
//	SQL_AppendFlt(strSQL, m_dbFtp_DL_PDCPThroughtDistance);	//ҵ������ʱ����,PDCP�������ܲ����·�� "�淶Ҫ����pdcp��������"
//	SQL_AppendFlt(strSQL, m_dbFtp_DL_Edge_Throught_NID);	//��Ե����������(��������)(Kbps)
//	SQL_AppendFlt(strSQL, m_dbFtp_DL_Edge_Throught_ID);		//��Ե����������(������)(Kbps)
//
//	//Ӧ�ò��������ʷֶ�ռ��:Ӧ�ò���������(��������)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_0_0M_Num);	//����0
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_0_1M_Num);	//(0,1M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_1_2M_Num);	//[1,2M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_2_3M_Num);	//[2,3M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_3_4M_Num);	//[3,4M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_4_5M_Num);	//[4,5M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_5_10M_Num);	//[5,10M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_10_15M_Num);	//[10,15M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_15_20M_Num);	//[15,20M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_20_30M_Num);	//[20,30M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_30_50M_Num);	//[30,50M)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_50_NM_Num);	//���ڵ���50M
//
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_NID);		//FTP�ϴ�ִ��ʱ�����ܵ��ϴ������(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_LTE_NID);	//FTP�ϴ�ִ��ʱ����,ռ��LTE����ϴ������(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_HSPA_NID);	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ���ϴ������(��������),��ҪTD����
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_R4_NID);		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ���ϴ����������������),��ҪTD����
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_ID);			//FTP�ϴ�ִ��ʱ�����ܵ��ϴ������(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_LTE_ID);		//FTP�ϴ�ִ��ʱ����,ռ��LTE����ϴ������(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_HSPA_ID);	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ���ϴ������(������),��ҪTD����
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_R4_ID);		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ���ϴ��������������),��ҪTD����
//
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_NID);		//FTP�ϴ���ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_LTE_NID);	//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_HSPA_NID);	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_R4_NID);		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(��������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_ID);			//FTP�ϴ���ʱ��(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_LTE_ID);		//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_HSPA_ID);	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(������)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_R4_ID);		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(������)
//
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_UL_PRB_NID);			//ÿRBƽ���ϴ���(��������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(��������)
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_UL_PRB_ID);			//ÿRBƽ���ϴ���(������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(������)
//
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Attempt_Num);		//FTP Upload Attempt�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Success_Num);		//FTP Upload Success�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Drop_LTE_Num);		//LTE��ʽ��,FTP Upload Drop�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Drop_HSPA_Num);	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Upload Drop�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Drop_R4_Num);		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Upload Drop�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Fail_LTE_Num);		//LTE��ʽ��,FTP Upload Fail�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Fail_HSPA_Num);	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Upload Fail�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Fail_R4_Num);		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Upload Fail�ϱ�����
//
//	SQL_AppendFlt(strSQL, m_dbFtp_UL_RLCThroughputUL_Sum);	//��·��ƽ��������(Kbps):FTP�ϴ�ִ��ʱ����,RLC Throughput UL���ܺ�
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_RLCThroughputUL_Num);	//��·��ƽ��������(Kbps):FTP�ϴ�ִ��ʱ����,RLC Throughput UL�ĸ���
//
//	SQL_AppendFlt(strSQL, m_dbFtp_UL_LowThroughtDistance);	//������������������(km):ҵ���ϴ�ʱ����,�������������·��,�������������ϴ�256Kbps
//	SQL_AppendFlt(strSQL, m_dbFtp_UL_PDCPThroughtDistance);	//ҵ���ϴ�ʱ����,PDCP�������ܲ����·��
//	SQL_AppendFlt(strSQL, m_dbFtp_UL_Edge_Throught_NID);	//��Ե����������(��������)(Kbps)
//	SQL_AppendFlt(strSQL, m_dbFtp_UL_Edge_Throught_ID);		//��Ե����������(������)(Kbps)
//
//	//Ӧ�ò��ϴ����ʷֶ�ռ��:Ӧ�ò��ϴ�����(��������)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_0_0K_Num);		//����0
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_0_256K_Num);		//(0,256K)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_256K_512K_Num);	//[256K,512K)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_512K_1M_Num);	//[512K,1M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_1_2M_Num);		//[1,2M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_2_3M_Num);		//[2,3M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_3_4M_Num);		//[3,4M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_4_5M_Num);		//[4,5M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_5_10M_Num);		//[5,10M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_10_15M_Num);		//[10,15M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_15_20M_Num);		//[15,20M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_20_30M_Num);		//[20,30M)
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_30_50M_Num);		//[30,50M)
//
//	//���ܲ���
//
//	//LTE�����л�
//	SQL_AppendUInt(strSQL, m_ulLTE_LTE_Handover_Start_NUM);		//�����л����Դ���:Handover Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulLTE_LTE_Handover_Success_NUM);	//�����л��ɹ�����:Handover Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbLTE_LTE_Handover_Total_Delay);	//�����л�ʱ�Ӻ�(s):Handover Start�¼���Handover Success�¼���ʱ���ܺ�
//
//	//LTE-TDSCDMA�л�
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_Handover_Start_NUM);		//LTE-TD�л����Դ���:TDSCDMA from LTE Handover Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_Handover_Success_NUM);		//LTE-TD�л��ɹ�����:TDSCDMA from LTE Handover Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_Handover_Total_Delay);		//LTE-TD�л�ʱ�Ӻ�(s):TDSCDMA from LTE Handover Start�¼���TDSCDMA from LTE Handover Success�¼���ʱ���ܺ�
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_RSRP_Sum_Before_Handover_Start_5Second);	//LTE-TD�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Start�¼�ǰ5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_RSRP_Num_Before_Handover_Start_5Second);	//LTE-TD�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Start�¼�ǰ5������RSRP����
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_RSRP_Sum_After_Handover_Success_5Second);	//LTE-TD�л����ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Success�¼���5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_RSRP_Num_After_Handover_Success_5Second);	//LTE-TD�л����ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Success�¼���5������RSRP����
//
//	//TDSCDMA-LTE�л�
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_Handover_Start_NUM);		//TD-LTE�л����Դ���:TDSCDMA to LTE Handover Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_Handover_Success_NUM);		//TD-LTE�л��ɹ�����:TDSCDMA to LTE Handover Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_Handover_Total_Delay);		//TD-LTE�л�ʱ�Ӻ�(s):TDSCDMA to LTE Handover Start�¼���TDSCDMA to LTE Handover Success�¼���ʱ���ܺ�
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_RSRP_Sum_Before_Handover_Start_5Second);	//TD-LTE�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Start�¼�ǰ5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_RSRP_Num_Before_Handover_Start_5Second);	//TD-LTE�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Start�¼�ǰ5������RSRP����
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_RSRP_Sum_After_Handover_Success_5Second);	//TD-LTE�л����ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Success�¼���5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_RSRP_Num_After_Handover_Success_5Second);	//TD-LTE�л����ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Success�¼���5������RSRP����
//
//	//LTE-TDSCDMA��ѡ
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_Resel_Start_NUM);		//LTE-TD��ѡ����:TDSCDMA from LTE Resel Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_Resel_Success_NUM);	//LTE-TD��ѡ�ɹ�����:TDSCDMA from LTE Resel Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_Resel_Total_Delay);	//LTE-TD��ѡʱ�Ӻ�(s):TDSCDMA from LTE Resel Start�¼���TDSCDMA from LTE Resel Success�¼���ʱ���ܺ�
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_RSRP_Sum_Before_Resel_Start_5Second);	//LTE-TD��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Start�¼�ǰ5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_RSRP_Num_Before_Resel_Start_5Second);	//LTE-TD��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Start�¼�ǰ5������RSRP����
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_RSRP_Sum_After_Resel_Success_5Second);//LTE-TD��ѡ���ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Success�¼���5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_RSRP_Num_After_Resel_Success_5Second);//LTE-TD��ѡ���ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Success�¼���5������RSRP����
//
//	//TDSCDMA-LTE��ѡ
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_Resel_Start_NUM);		//TD-LTE��ѡ����:TDSCDMA to LTE Resel Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_Resel_Success_NUM);	//TD-LTE��ѡ�ɹ�����:TDSCDMA to LTE Resel Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_Resel_Total_Delay);	//TD-LTE��ѡʱ�Ӻ�(s):TDSCDMA to LTE Resel Start�¼���TDSCDMA to LTE Resel Success�¼���ʱ���ܺ�
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_RSRP_Sum_Before_Resel_Start_5Second);	//TD-LTE��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Start�¼�ǰ5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_RSRP_Num_Before_Resel_Start_5Second);	//TD-LTE��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Start�¼�ǰ5������RSRP����
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_RSRP_Sum_After_Resel_Success_5Second);//TD-LTE��ѡ���ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Success�¼���5������RSRP�ܺ�
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_RSRP_Num_After_Resel_Success_5Second);//TD-LTE��ѡ���ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Success�¼���5������RSRP����
//
//	//Attachͳ��
//	SQL_AppendUInt(strSQL, m_ulEPS_Attach_Request_NUM);	//Attch���Դ���:EPS Attach Request�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulEPS_Attach_Success_NUM);	//Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbEPS_Attach_Total_Delay);	//Attachʱ�Ӻ�(s):EPS Attach Request�¼���EPS Attach Success�¼���ʱ���ܺ�
//
//	//Serviceͳ��
//	SQL_AppendUInt(strSQL, m_ulSERVICE_Request_NUM);	//Service�������:SERVICE REQUEST�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulSERVICE_Success_NUM);	//Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbSERVICE_Total_Delay);	//Service����ʱ�Ӻ�(s):SERVICE REQUEST�¼���SERVICE SUCCESS�¼���ʱ���ܺ�
//
//	//LTE���������ͳ��
//	SQL_AppendUInt(strSQL, m_ulTAU_Request_NUM);	//TA���³��Դ���:TAU Request�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulTAU_Success_NUM);	//TA���³ɹ�����:TAU Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbTAU_Total_Delay);	//TA����ʱ�Ӻ�(s):(TAU Success-TAU Request)��ʱ���ܺ�
//
//	//������ͳ��
//	SQL_AppendFlt(strSQL, m_dbPDCP_DL_Throughput_Sum_ID);	//PDCP����ƽ��������Kbps(������):PDCP Throughput DL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPDCP_DL_Throughput_Num_ID);	//PDCP����ƽ��������Kbps(������):PDCP Throughput DL����
//	SQL_AppendFlt(strSQL, m_dbPDCP_UL_Throughput_Sum_ID);	//PDCP����ƽ��������Kbps(������):PDCP Throughput UL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPDCP_UL_Throughput_Num_ID);	//PDCP����ƽ��������Kbps(������):PDCP Throughput UL����
//	//SQL_AppendFlt(strSQL, m_dbRLC_DL_Throughput_Sum_ID);	//RLC����ƽ��������Kbps(������):RLC Throughput DL�ܺ�
//	//SQL_AppendUInt(strSQL, m_ulRLC_DL_Throughput_Num_ID);	//RLC����ƽ��������Kbps(������):RLC Throughput DL����
//	//SQL_AppendFlt(strSQL, m_dbRLC_UL_Throughput_Sum_ID);	//RLC����ƽ��������Kbps(������):RLC Throughput UL�ܺ�
//	//SQL_AppendUInt(strSQL, m_ulRLC_UL_Throughput_Num_ID);	//RLC����ƽ��������Kbps(������):RLC Throughput UL����
//	SQL_AppendFlt(strSQL, m_dbMAC_DL_Throughput_Sum_ID);	//MAC����ƽ��������Kbps(������):MAC Throughput DL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulMAC_DL_Throughput_Num_ID);	//MAC����ƽ��������Kbps(������):MAC Throughput DL����
//	SQL_AppendFlt(strSQL, m_dbMAC_UL_Throughput_Sum_ID);	//MAC����ƽ��������Kbps(������):MAC Throughput UL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulMAC_UL_Throughput_Num_ID);	//MAC����ƽ��������Kbps(������):MAC Throughput UL����
//
//	//PDSCH�ش�ͳ��
//	SQL_AppendUInt(strSQL, m_ulPDSCH_first_rx_success_cnt);		//���ν��ճɹ�����:pdsch_first_rx_success_cnt
//	SQL_AppendUInt(strSQL, m_ulPDSCH_multi_retrans_success_cnt);//����ش��ɹ�����:pdsch_multi_retrans_success_cnt
//
//	//PUSCH�ش�ͳ��
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_1st_Tx_Succ_Num);		//�����ɹ�����:HARQ UL 1st Tx Succ Num
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_1st_ReTx_Succ_Num);	//1���ش��ɹ�����:HARQ UL 1st ReTx Succ Num
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_2nd_ReTx_Succ_Num);	//2���ش��ɹ�����:HARQ UL 2nd ReTx Succ Num
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_3rd_ReTx_Succ_Num);	//3���ش��ɹ�����:HARQ UL 3rd ReTx Succ Num
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_4th_ReTx_Succ_Num);	//4���ش��ɹ�����:HARQ UL 4th ReTx Succ Num
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_mutil_ReTx_Succ_Num);	//����ش��ɹ�����:HARQ UL mutil ReTx Succ Num
//	SQL_AppendUInt(strSQL, m_ulHARQ_DL_ReTx_Failed_cnt);		//�ش�ʧ�ܴ���:HARQ DL ReTx Failed Num;
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_ReTx_Failed_cnt);		//�ش�ʧ�ܴ���:HARQ UL ReTx Failed Num;
//
//	//����0����ACK/NACKͳ��
//	SQL_AppendUInt(strSQL, m_ulHARQ_DL_C0_ACK_Count);	//ACK Count:HARQ DL C0 ACK Count
//	SQL_AppendUInt(strSQL, m_ulHARQ_DL_C0_NACK_Count);	//NACK Count:HARQ DL C0 NACK Count
//	//����1����ACK/NACKͳ��
//	SQL_AppendUInt(strSQL, m_ulHARQ_DL_C1_ACK_Count);	//ACK Count:HARQ DL C1 ACK Count
//	SQL_AppendUInt(strSQL, m_ulHARQ_DL_C1_NACK_Count);	//NACK Count:HARQ DL C1 NACK Count
//	//����ACK/NACKͳ��
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_Ack_Count);	//ACK Count:HARQ UL ACK Count
//	SQL_AppendUInt(strSQL, m_ulHARQ_UL_NAck_Count);	//NACK Count:HARQ UL NACK Count
//
//	//����BLER
//	SQL_AppendFlt(strSQL, m_dbDL_Code0_BLER_Sum);	//��������0Bler(%):DL Code0 BLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_BLER_Num);	//��������0Bler(%):DL Code0 BLER����
//	SQL_AppendFlt(strSQL, m_dbDL_Code1_BLER_Sum);	//��������1Bler(%):DL Code1 BLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_BLER_Num);	//��������1Bler(%):DL Code1 BLER����
//	SQL_AppendFlt(strSQL, m_dbDL_Code0_I_BLER_Sum);	//��������0��ʼBler(%):DL Code0 IBLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_I_BLER_Num);	//��������0��ʼBler(%):DL Code0 IBLER����
//	SQL_AppendFlt(strSQL, m_dbDL_Code0_R_BLER_Sum);	//��������0����Bler(%):DL Code0 RBLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_R_BLER_Num);	//��������0����Bler(%):DL Code0 RBLER����
//	SQL_AppendFlt(strSQL, m_dbDL_Code1_I_BLER_Sum);	//��������1��ʼBler(%):DL Code1 IBLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_I_BLER_Num);	//��������1��ʼBler(%):DL Code1 IBLER����
//	SQL_AppendFlt(strSQL, m_dbDL_Code2_R_BLER_Sum);	//��������1����Bler(%):DL Code1 RBLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulDL_Code2_R_BLER_Num);	//��������1����Bler(%):DL Code1 RBLER����
//
//	//����BLER
//	SQL_AppendFlt(strSQL, m_dbUL_BLER_Sum);			//����Bler(%):UL BLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulUL_BLER_Num);			//����Bler(%):UL BLER����
//	SQL_AppendFlt(strSQL, m_dbUL_I_BLER_Sum);		//���г�ʼBler(%):UL IBLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulUL_I_BLER_Num);		//���г�ʼBler(%):UL IBLER����
//	SQL_AppendFlt(strSQL, m_dbUL_R_BLER_Sum);		//���в���Bler(%):UL RBLER�ܺ�
//	SQL_AppendUInt(strSQL, m_ulUL_R_BLER_Num);		//���в���Bler(%):UL RBLER����
//
//	SQL_AppendFlt(strSQL, m_dbRSRP_Sum);		//ƽ��RSRP(dBm):RSRP�ܺ�
//	SQL_AppendFlt(strSQL, m_dbRSRP_Edge);		//��ԵRSRP(dBm):RSRP�����CDF(�ۻ���ʷֲ�)5%��Ӧ��ֵ
//	SQL_AppendUInt(strSQL, m_ulRSRP_MeetNum);	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR >= 0dB
//
//	SQL_AppendFlt(strSQL, m_dbLTETotalDistance);		//LTE�������:LTE��ʽ�µ�����ܺ�
//	SQL_AppendFlt(strSQL, m_dbLTEWeakCoverDistance);	//LTE�������������:����10��70%�Ĳ����·������RSRP<-105dBm,��CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
//	SQL_AppendFlt(strSQL, m_dbLTENoneCoverDistance);	//LTE�����޸������:����10��70%�Ĳ����·������RSRP<-115dBm,CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
//	SQL_AppendFlt(strSQL, m_dbLTEHighTxpowerDistance);	//UE�߹��ʷ������:UE��PUSCH�ŵ����书�ʳ���10��70%�����>16dBm������·��
//
//	SQL_AppendFlt(strSQL, m_dbPRACH_Power_Sum);	//PRACHƽ����(dBm):PRACH_Power�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPRACH_Power_Num);	//PRACHƽ����(dBm):PRACH_Power����
//	SQL_AppendFlt(strSQL, m_dbPUSCH_Power_Sum);	//PUSCHƽ����(dBm):PUSCH_Power�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPUSCH_Power_Num);	//PUSCHƽ����(dBm):PUSCH_Power����
//	SQL_AppendFlt(strSQL, m_dbPUCCH_Power_Sum);	//PUCCHƽ����(dBm):PUCCH_Power�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPUCCH_Power_Num);	//PUCCHƽ����(dBm):PUCCH_Power����
//	SQL_AppendFlt(strSQL, m_dbSRS_Power_Sum);	//SRSƽ����(dBm):SRS_Power�ܺ�
//	SQL_AppendUInt(strSQL, m_ulSRS_Power_Num);	//SRSƽ����(dBm):SRS_Power����
//
//	SQL_AppendFlt(strSQL, m_dbSINR_Sum);		//SINR(dB)�ܺ�
//	SQL_AppendFlt(strSQL, m_dbSINR_Edge);		//��ԵSINR(dB):SINR�����CDF(�ۼƸ��ʷֲ�)5%��Ӧ��ֵ
//	SQL_AppendFlt(strSQL, m_dbRSRQ_Sum);		//RSRQ(dB)�ܺ�
//	SQL_AppendFlt(strSQL, m_dbRank1_Wideband_Code0_SINR_Sum);	//Rank1 SINR(dBm):RI=1��Wideband Code0 SINR�ܺ�
//	SQL_AppendUInt(strSQL, m_ulRank1_Wideband_Code0_SINR_Num);	//Rank1 SINR(dBm):RI=1��Wideband Code0 SINR����
//	SQL_AppendFlt(strSQL, m_dbRank2_Wideband_Code0_SINR_Sum);	//Rank2 SINR1(dBm):RI=2��Wideband Code0 SINR�ܺ�
//	SQL_AppendUInt(strSQL, m_ulRank2_Wideband_Code0_SINR_Num);	//Rank2 SINR1(dBm):RI=2��Wideband Code0 SINR����
//	SQL_AppendFlt(strSQL, m_dbRank2_Wideband_Code1_SINR_Sum);	//Rank2 SINR2(dBm):RI=2��Wideband Code1 SINR�ܺ�
//	SQL_AppendUInt(strSQL, m_ulRank2_Wideband_Code1_SINR_Num);	//Rank2 SINR2(dBm):RI=2��Wideband Code1 SINR����
//
//	SQL_AppendFlt(strSQL, m_dbLowSINRDistance);	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-1dB������·��
//	SQL_AppendUInt(strSQL, m_ulOverCoverMeetNum);	//�ص����Ƕ�>=3�Ĳ������:�ص����Ƕ�:·��������ǿС��RSRP�Ĳ�ֵ����-6dB�ĵ�ƽ������ ͬʱ��ǿС��RSRP>=-105dB
//	SQL_AppendFlt(strSQL, m_dbOverCoverDistance);	//�����ص����Ƕ�>=3�����
//
//	//RSRP���ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulRSRP_141_110_Num);	//RSRP[-141,-110)
//	SQL_AppendUInt(strSQL, m_ulRSRP_110_105_Num);	//RSRP[-110,-105)
//	SQL_AppendUInt(strSQL, m_ulRSRP_105_100_Num);	//RSRP[-105,-100)
//	SQL_AppendUInt(strSQL, m_ulRSRP_100_95_Num);		//RSRP[-100,-95)
//	SQL_AppendUInt(strSQL, m_ulRSRP_95_90_Num);		//RSRP[-95,-90)
//	SQL_AppendUInt(strSQL, m_ulRSRP_90_85_Num);		//RSRP[-90,-85)
//	SQL_AppendUInt(strSQL, m_ulRSRP_85_80_Num);		//RSRP[-85,-80)
//	SQL_AppendUInt(strSQL, m_ulRSRP_80_75_Num);		//RSRP[-80,-75)
//	SQL_AppendUInt(strSQL, m_ulRSRP_75_70_Num);		//RSRP[-75,-70)
//	SQL_AppendUInt(strSQL, m_ulRSRP_70_65_Num);		//RSRP[-70,-65)
//	SQL_AppendUInt(strSQL, m_ulRSRP_65_60_Num);		//RSRP[-65,-60)
//	SQL_AppendUInt(strSQL, m_ulRSRP_60_44_Num);		//RSRP[-60,-44]
//
//	//SINR���ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulSINR_50_10_Num);	//SINR[-50,-10)
//	SQL_AppendUInt(strSQL, m_ulSINR_10_6_Num);	//SINR[-10,-6)
//	SQL_AppendUInt(strSQL, m_ulSINR_6_3_Num);	//SINR[-6,-3)
//	SQL_AppendUInt(strSQL, m_ulSINR_3_0_Num);	//SINR[-3,0)
//	SQL_AppendUInt(strSQL, m_ulSINR_0_3_Num);	//SINR[0,3)
//	SQL_AppendUInt(strSQL, m_ulSINR_3_6_Num);	//SINR[3,6)
//	SQL_AppendUInt(strSQL, m_ulSINR_6_10_Num);	//SINR[6,10)
//	SQL_AppendUInt(strSQL, m_ulSINR_10_15_Num);	//SINR[10,15)
//	SQL_AppendUInt(strSQL, m_ulSINR_15_20_Num);	//SINR[15,20)
//	SQL_AppendUInt(strSQL, m_ulSINR_20_25_Num);	//SINR[20,25)
//	SQL_AppendUInt(strSQL, m_ulSINR_25_50_Num);	//SINR[25,50]
//
//	//RSRQ���ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulRSRQ_196_175_Num);	//RSRQ[-19.6,-17.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_175_155_Num);	//RSRQ[-17.5,-15.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_155_135_Num);	//RSRQ[-15.5,-13.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_135_115_Num);	//RSRQ[-13.5,-11.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_115_95_Num);		//RSRQ[-11.5,-9.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_95_75_Num);		//RSRQ[-9.5,-7.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_75_55_Num);		//RSRQ[-7.5,-5.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_55_35_Num);		//RSRQ[-5.5,-3.5)
//	SQL_AppendUInt(strSQL, m_ulRSRQ_35_30_Num);		//RSRQ[-3.5,-3]
//
//	//�ص����Ƕ����ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_0_Num);		//0
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_1_Num);		//1
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_2_Num);		//2
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_3_Num);		//3
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_4_Num);		//4
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_5_Num);		//5
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_5_10_Num);	//(5,10]
//	SQL_AppendUInt(strSQL, m_ulOverCoverDegree_10_N_Num);	// >10
//
//	//PHY������
//	SQL_AppendFlt(strSQL, m_dbPHY_Throughput_DL_Sum);		//PHY����ƽ��������:PHY Throughput DL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPHY_Throughput_DL_Num);		//PHY����ƽ��������:PHY Throughput DL����
//	SQL_AppendFlt(strSQL, m_dbPHY_Cw0_Throughput_DL_Sum);	//����0ƽ��������(Kbps):PHY Cw0 Throughput DL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPHY_Cw0_Throughput_DL_Num);	//����0ƽ��������(Kbps):PHY Cw0 Throughput DL����
//	SQL_AppendFlt(strSQL, m_dbPHY_Cw1_Throughput_DL_Sum);	//����1ƽ��������(Kbps):PHY Cw1 Throughput DL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPHY_Cw1_Throughput_DL_Num);	//����1ƽ��������(Kbps):PHY Cw1 Throughput DL����
//	SQL_AppendFlt(strSQL, m_dbPHY_Throughput_UL_Sum);		//PHY����ƽ��������:PHY Throughput UL�ܺ�
//	SQL_AppendUInt(strSQL, m_ulPHY_Throughput_UL_Num);		//PHY����ƽ��������:PHY Throughput UL����
//
//	//��֡����
//	SQL_AppendUInt(strSQL, m_ulSubFrame_DL_TotalNum);	//���ȸ�UE��������֡���ܺ�
//	SQL_AppendUInt(strSQL, m_ulSubFrame_UL_TotalNum);	//���ȸ�UE��������֡���ܺ�
//
//	//MCSͳ��, ͨ����ϸ�ֲ�ͳ���Լ�����
//	//CQIͳ��, ͨ����ϸ�ֲ�ͳ���Լ�����
//
//	//Rankͳ��,ֻ����DL Code0 MCSΪ����,ͬʱ����DL Code0 MCS��DL Code1 MCSΪ˫��
//	SQL_AppendUInt(strSQL, m_ulRank1_ReportNum);	//RI=1�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulRank2_ReportNum);	//RI=2�ϱ�����
//	SQL_AppendFlt(strSQL, m_dbSingleFlowTime);	//����ʱ��
//	SQL_AppendFlt(strSQL, m_dbDoubleFlowTime);	//˫��ʱ��
//	SQL_AppendFlt(strSQL, m_dbSingleFlowData);	//���������
//	SQL_AppendFlt(strSQL, m_dbDoubleFlowData);	//˫�������
//
//	//����ģʽʱ��ռ��(%)
//	SQL_AppendFlt(strSQL, m_dbTM1ModeTime);	//TM1ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM2ModeTime);	//TM2ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM3ModeTime);	//TM3ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM4ModeTime);	//TM4ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM5ModeTime);	//TM5ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM6ModeTime);	//TM6ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM7ModeTime);	//TM7ʱ��
//	SQL_AppendFlt(strSQL, m_dbTM8ModeTime);	//TM8ʱ��
//
//	//���Ʒ�ʽ�ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_QPSK_Num);	//��������0���Ʒ�ʽQPSK
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_16QAM_Num);	//��������0���Ʒ�ʽ16QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_64QAM_Num);	//��������0���Ʒ�ʽ64QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_QPSK_Num);	//��������1���Ʒ�ʽQPSK
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_16QAM_Num);	//��������1���Ʒ�ʽ16QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_64QAM_Num);	//��������1���Ʒ�ʽ64QAM
//	SQL_AppendUInt(strSQL, m_ulUL_QPSK_Num);			//���е��Ʒ�ʽQPSK
//	SQL_AppendUInt(strSQL, m_ulUL_16QAM_Num);		//���е��Ʒ�ʽ16QAM
//	SQL_AppendUInt(strSQL, m_ulUL_64QAM_Num);		//���е��Ʒ�ʽ64QAM
//
//	//����MCS����0��ϸ�ֲ����(%)
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS0_Num);	//DL Code0 MCS == 0 �ĸ���
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS1_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS2_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS3_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS4_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS5_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS6_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS7_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS8_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS9_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS10_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS11_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS12_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS13_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS14_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS15_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS16_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS17_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS18_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS19_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS20_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS21_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS22_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS23_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS24_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS25_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS26_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS27_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS28_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS29_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS30_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_MCS31_Num);
//
//	//����MCS����1��ϸ�ֲ����(%)
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS0_Num);	//DL Code1 MCS == 0 �ĸ���
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS1_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS2_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS3_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS4_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS5_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS6_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS7_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS8_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS9_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS10_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS11_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS12_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS13_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS14_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS15_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS16_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS17_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS18_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS19_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS20_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS21_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS22_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS23_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS24_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS25_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS26_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS27_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS28_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS29_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS30_Num);
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_MCS31_Num);
//
//	//����MCS ��ϸ�ֲ����(%)
//	SQL_AppendUInt(strSQL, m_ulUL_MCS0_Num);	//UL MCS == 0 �ĸ���
//	SQL_AppendUInt(strSQL, m_ulUL_MCS1_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS2_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS3_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS4_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS5_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS6_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS7_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS8_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS9_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS10_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS11_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS12_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS13_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS14_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS15_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS16_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS17_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS18_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS19_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS20_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS21_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS22_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS23_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS24_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS25_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS26_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS27_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS28_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS29_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS30_Num);
//	SQL_AppendUInt(strSQL, m_ulUL_MCS31_Num);
//
//	//����0��CQI��ϸ�ֲ����(%)
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI0_Num);	//Wideband Code0 CQI == 0 �ĸ���
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI1_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI2_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI3_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI4_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI5_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI6_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI7_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI8_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI9_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI10_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI11_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI12_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI13_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI14_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code0_CQI15_Num);
//
//	//����1��CQI��ϸ�ֲ����(%)
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI0_Num);	//Wideband Code1 CQI == 0 �ĸ���
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI1_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI2_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI3_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI4_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI5_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI6_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI7_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI8_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI9_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI10_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI11_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI12_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI13_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI14_Num);
//	SQL_AppendUInt(strSQL, m_ulWideband_Code1_CQI15_Num);
//
//	//PDCCH CFI�ֲ�ͳ��(%)
//	SQL_AppendUInt(strSQL, m_ulPDCCH_CFI1_Num); //CFI1 Count == 1 �ĸ���
//	SQL_AppendUInt(strSQL, m_ulPDCCH_CFI2_Num);
//	SQL_AppendUInt(strSQL, m_ulPDCCH_CFI3_Num);
//	SQL_AppendUInt(strSQL, m_ulPDCCH_CFI4_Num);
//
//	//LTE��֡����ʱ���ֲ�ͳ��(%):subframe_Assignment
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format0_Time);	//��ʽ0
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format1_Time);	//��ʽ1(1:1)
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format2_Time);	//��ʽ2(3:1)
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format3_Time);	//��ʽ3
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format4_Time);	//��ʽ4
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format5_Time);	//��ʽ5
//	SQL_AppendFlt(strSQL, m_dbSubFrameAssign_Format6_Time);	//��ʽ6
//
//	//LTE����ʱ϶����ʱ���ֲ�ͳ��(%):special_Subframe_Patterns
//	SQL_AppendFlt(strSQL, m_dbSpecialSubframePatterns_3_9_2_Time);		//3:9:2
//	SQL_AppendFlt(strSQL, m_dbSpecialSubframePatterns_10_2_2_Time);	//10:2:2
//	SQL_AppendFlt(strSQL, m_dbSpecialSubframePatterns_Other_Time);		//����
//
//	//LTE CP����ʱ���ֲ�ͳ��(%):UL_CP_Type
//	SQL_AppendFlt(strSQL, m_dbLTE_Normal_CP_Time);		//Normal CP
//	SQL_AppendFlt(strSQL, m_dbLTE_Extended_CP_Time);	//Extended CP
//
//	//LTE ���߶˿�����ʱ���ֲ�ͳ��(%):eNB_Tx_Antenna_Num
//	SQL_AppendFlt(strSQL, m_dbLTE_AN_1_Time);	//an1
//	SQL_AppendFlt(strSQL, m_dbLTE_AN_2_Time);	//an2
//	SQL_AppendFlt(strSQL, m_dbLTE_AN_4_Time);	//an4
//
//	//LTE ��Ƶ��ռ��ʱ���ֲ�ͳ��(%):Band
//	SQL_AppendFlt(strSQL, m_dbLTE_Band_D_Time);	//DƵ��
//	SQL_AppendFlt(strSQL, m_dbLTE_Band_E_Time);	//EƵ��
//	SQL_AppendFlt(strSQL, m_dbLTE_Band_F_Time);	//FƵ��
//
//	SQL_AppendUInt(strSQL, m_ulSubFrame_DL_Count);	//���ȸ�UE��������֡���ܸ���
//	SQL_AppendUInt(strSQL, m_ulSubFrame_UL_Count);	//���ȸ�UE��������֡���ܸ���
//
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_DL_PRB_Sum);
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_DL_PRB_Count);
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_UL_PRB_Sum);
//	SQL_AppendULONGLONG(strSQL, m_ullFTP_UL_PRB_Count);
//
//	strSQL.TrimRight(_T(", "));
//	strSQL.AppendFormat(_T(" )"));
//
//	return strSQL;
//}

void CLogInfo_LTE_PS::InitPara()
{
	m_strTableName = "";

	RecSeqNo = -1;	    //��¼���к�, ȫ��ֵΨһ,����

	//ҵ�񲿷�

	//����ʱ��(�ļ�����ʱ��-�ļ���ʼʱ��)�Ͳ��������ǰ̨����

	//NID��ʾ��������,ID��ʾ������

	m_dbFTP_DL_TotalData_NID = 0;		//FTP����ִ��ʱ�����ܵ����������(��������)
	m_dbFTP_DL_TotalData_LTE_NID = 0;    //FTP����ִ��ʱ����,ռ��LTE������������(��������)
	m_dbFTP_DL_TotalData_HSPA_NID = 0;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ�����������(��������),��ҪTD����
	m_dbFTP_DL_TotalData_R4_NID = 0;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ�����������(��������),��ҪTD����
	m_dbFTP_DL_TotalData_ID = 0;			//FTP����ִ��ʱ�����ܵ����������(������)
	m_dbFTP_DL_TotalData_LTE_ID = 0;		//FTP����ִ��ʱ����,ռ��LTE������������(������)
	m_dbFTP_DL_TotalData_HSPA_ID = 0;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ�����������(������),��ҪTD����
	m_dbFTP_DL_TotalData_R4_ID = 0;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ�����������(������),��ҪTD����

	m_dbFTP_DL_TotalTime_NID = 0;		//FTP������ʱ��(��������)
	m_dbFTP_DL_TotalTime_LTE_NID = 0;	//FTP����ִ��ʱ����,ռ��LTE���ʱ��(��������)
	m_dbFTP_DL_TotalTime_HSPA_NID = 0;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(��������)
	m_dbFTP_DL_TotalTime_R4_NID = 0;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(��������)
	m_dbFTP_DL_TotalTime_ID = 0;			//FTP������ʱ��(������)
	m_dbFTP_DL_TotalTime_LTE_ID = 0;		//FTP����ִ��ʱ����,ռ��LTE���ʱ��(������)
	m_dbFTP_DL_TotalTime_HSPA_ID = 0;	//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(������)
	m_dbFTP_DL_TotalTime_R4_ID = 0;		//FTP����ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(������)

	m_ullFTP_DL_PRB_NID = 0;	//ÿRBƽ��������(��������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(��������)
	m_ullFTP_DL_PRB_ID = 0;	//ÿRBƽ��������(������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(������)==����ҵ�����PRB�����ܺͣ�

	m_ulFtp_DL_Attempt_Num = 0;		//FTP Download Attempt�ϱ�����
	m_ulFtp_DL_Success_Num = 0;		//FTP Download Success�ϱ�����
	m_ulFtp_DL_Drop_LTE_Num = 0;		//LTE��ʽ��,FTP Download Drop�ϱ�����
	m_ulFtp_DL_Drop_HSPA_Num = 0;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Download Drop�ϱ�����
	m_ulFtp_DL_Drop_R4_Num = 0;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Download Drop�ϱ�����
	m_ulFtp_DL_Fail_LTE_Num = 0;		//LTE��ʽ��,FTP Download Fail�ϱ�����
	m_ulFtp_DL_Fail_HSPA_Num = 0;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Download Fail�ϱ�����
	m_ulFtp_DL_Fail_R4_Num = 0;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Download Fail�ϱ�����

	m_dbFtp_DL_RLCThroughputDL_Sum = 0;	//��·��ƽ��������(Kbps):FTP����ִ��ʱ����,RLC Throughput DL���ܺ�
	m_ulFtp_DL_RLCThroughputDL_Num = 0;	//��·��ƽ��������(Kbps):FTP����ִ��ʱ����,RLC Throughput DL�ĸ���
	m_ulFtp_DL_TotalTB = 0;				//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��
	m_ulFtp_DL_TotalErrorTB = 0;			//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��

	m_dbFtp_DL_LowThroughtDistance = 0;	//������������������(km):ҵ������ʱ����,�������������·��,����������������1Mbps
	m_dbFtp_DL_PDCPThroughtDistance = 0;	//ҵ������ʱ����,PDCP�������ܲ����·�� "�淶Ҫ����pdcp��������"
	m_dbFtp_DL_Edge_Throught_NID = 0;	//��Ե����������(��������)(Kbps)
	m_dbFtp_DL_Edge_Throught_ID = 0;		//��Ե����������(������)(Kbps)

	//Ӧ�ò��������ʷֶ�ռ��:Ӧ�ò���������(��������)
	m_ulFtp_DL_Speed_0_0M_Num = 0;	//����0
	m_ulFtp_DL_Speed_0_1M_Num = 0;	//(0,1M)
	m_ulFtp_DL_Speed_1_2M_Num = 0;	//[1,2M)
	m_ulFtp_DL_Speed_2_3M_Num = 0;	//[2,3M)
	m_ulFtp_DL_Speed_3_4M_Num = 0;	//[3,4M)
	m_ulFtp_DL_Speed_4_5M_Num = 0;	//[4,5M)
	m_ulFtp_DL_Speed_5_10M_Num = 0;	//[5,10M)
	m_ulFtp_DL_Speed_10_15M_Num = 0;	//[10,15M)
	m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
	m_ulFtp_DL_Speed_20_30M_Num = 0;	//[20,30M)
	m_ulFtp_DL_Speed_30_50M_Num = 0;	//[30,50M)
	m_ulFtp_DL_Speed_50_NM_Num = 0;	//���ڵ���50M

	m_dbFTP_UL_TotalData_NID = 0;		//FTP�ϴ�ִ��ʱ�����ܵ��ϴ������(��������)
	m_dbFTP_UL_TotalData_LTE_NID = 0;	//FTP�ϴ�ִ��ʱ����,ռ��LTE����ϴ������(��������)
	m_dbFTP_UL_TotalData_HSPA_NID = 0;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ���ϴ������(��������),��ҪTD����
	m_dbFTP_UL_TotalData_R4_NID = 0;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ���ϴ����������������),��ҪTD����
	m_dbFTP_UL_TotalData_ID = 0;			//FTP�ϴ�ִ��ʱ�����ܵ��ϴ������(������)
	m_dbFTP_UL_TotalData_LTE_ID = 0;		//FTP�ϴ�ִ��ʱ����,ռ��LTE����ϴ������(������)
	m_dbFTP_UL_TotalData_HSPA_ID = 0;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ���ϴ������(������),��ҪTD����
	m_dbFTP_UL_TotalData_R4_ID = 0;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ���ϴ��������������),��ҪTD����

	m_dbFTP_UL_TotalTime_NID = 0;		//FTP�ϴ���ʱ��(��������)
	m_dbFTP_UL_TotalTime_LTE_NID = 0;	//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)
	m_dbFTP_UL_TotalTime_HSPA_NID = 0;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(��������)
	m_dbFTP_UL_TotalTime_R4_NID = 0;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(��������)
	m_dbFTP_UL_TotalTime_ID = 0;			//FTP�ϴ���ʱ��(������)
	m_dbFTP_UL_TotalTime_LTE_ID = 0;		//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)
	m_dbFTP_UL_TotalTime_HSPA_ID = 0;	//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��HSPA��Դ��ʱ��(������)
	m_dbFTP_UL_TotalTime_R4_ID = 0;		//FTP�ϴ�ִ��ʱ����,ռ��TDSCDMA��ʹ��R4��Դ��ʱ��(������)

	m_ullFTP_UL_PRB_NID = 0;			//ÿRBƽ���ϴ���(��������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(��������)
	m_ullFTP_UL_PRB_ID = 0;			//ÿRBƽ���ϴ���(������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(������)

	m_ulFtp_UL_Attempt_Num = 0;		//FTP Upload Attempt�ϱ�����
	m_ulFtp_UL_Success_Num = 0;		//FTP Upload Success�ϱ�����
	m_ulFtp_UL_Drop_LTE_Num = 0;		//LTE��ʽ��,FTP Upload Drop�ϱ�����
	m_ulFtp_UL_Drop_HSPA_Num = 0;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Upload Drop�ϱ�����
	m_ulFtp_UL_Drop_R4_Num = 0;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Upload Drop�ϱ�����
	m_ulFtp_UL_Fail_LTE_Num = 0;		//LTE��ʽ��,FTP Upload Fail�ϱ�����
	m_ulFtp_UL_Fail_HSPA_Num = 0;	//ռ��TDSCDMA��ʹ��HSPA��Դʱ,FTP Upload Fail�ϱ�����
	m_ulFtp_UL_Fail_R4_Num = 0;		//ռ��TDSCDMA��ʹ��R4��Դ��,FTP Upload Fail�ϱ�����

	m_dbFtp_UL_RLCThroughputUL_Sum = 0;	//��·��ƽ��������(Kbps):FTP�ϴ�ִ��ʱ����,RLC Throughput UL���ܺ�
	m_ulFtp_UL_RLCThroughputUL_Num = 0;	//��·��ƽ��������(Kbps):FTP�ϴ�ִ��ʱ����,RLC Throughput UL�ĸ���

	m_dbFtp_UL_LowThroughtDistance = 0;	//������������������(km):ҵ���ϴ�ʱ����,�������������·��,�������������ϴ�256Kbps
	m_dbFtp_UL_PDCPThroughtDistance = 0;	//ҵ���ϴ�ʱ����,PDCP�������ܲ����·��
	m_dbFtp_UL_Edge_Throught_NID = 0;	//��Ե����������(��������)(Kbps)
	m_dbFtp_UL_Edge_Throught_ID = 0;		//��Ե����������(������)(Kbps)

	//Ӧ�ò��ϴ����ʷֶ�ռ��:Ӧ�ò��ϴ�����(��������)
	m_ulFtp_UL_Speed_0_0K_Num = 0;		//����0
	m_ulFtp_UL_Speed_0_256K_Num = 0;		//(0,256K)
	m_ulFtp_UL_Speed_256K_512K_Num = 0;	//[256K,512K)
	m_ulFtp_UL_Speed_512K_1M_Num = 0;	//[512K,1M)
	m_ulFtp_UL_Speed_1_2M_Num = 0;		//[1,2M)
	m_ulFtp_UL_Speed_2_3M_Num = 0;		//[2,3M)
	m_ulFtp_UL_Speed_3_4M_Num = 0;		//[3,4M)
	m_ulFtp_UL_Speed_4_5M_Num = 0;		//[4,5M)
	m_ulFtp_UL_Speed_5_10M_Num = 0;		//[5,10M)
	m_ulFtp_UL_Speed_10_15M_Num = 0;		//[10,15M)
	m_ulFtp_UL_Speed_15_20M_Num = 0;		//[15,20M)
	m_ulFtp_UL_Speed_20_30M_Num = 0;		//[20,30M)
	m_ulFtp_UL_Speed_30_50M_Num = 0;		//[30,50M)

	//���ܲ���

	//LTE�����л�
	m_ulLTE_LTE_Handover_Start_NUM = 0;		//�����л����Դ���:Handover Start�¼��ϱ�����
	m_ulLTE_LTE_Handover_Success_NUM = 0;	//�����л��ɹ�����:Handover Success�¼��ϱ�����
	m_dbLTE_LTE_Handover_Total_Delay = 0;	//�����л�ʱ�Ӻ�(s):Handover Start�¼���Handover Success�¼���ʱ���ܺ�

	//LTE-TDSCDMA�л�
	m_ulLTE_TD_Handover_Start_NUM = 0;		//LTE-TD�л����Դ���:TDSCDMA from LTE Handover Start�¼��ϱ�����
	m_ulLTE_TD_Handover_Success_NUM = 0;	//LTE-TD�л��ɹ�����:TDSCDMA from LTE Handover Success�¼��ϱ�����
	m_dbLTE_TD_Handover_Total_Delay = 0;	//LTE-TD�л�ʱ�Ӻ�(s):TDSCDMA from LTE Handover Start�¼���TDSCDMA from LTE Handover Success�¼���ʱ���ܺ�
	m_dbLTE_TD_RSRP_Sum_Before_Handover_Start_5Second = 0;	//LTE-TD�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Start�¼�ǰ5������RSRP�ܺ�
	m_ulLTE_TD_RSRP_Num_Before_Handover_Start_5Second = 0;	//LTE-TD�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Start�¼�ǰ5������RSRP����
	m_dbLTE_TD_RSRP_Sum_After_Handover_Success_5Second = 0;	//LTE-TD�л����ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Success�¼���5������RSRP�ܺ�
	m_ulLTE_TD_RSRP_Num_After_Handover_Success_5Second = 0;	//LTE-TD�л����ƽƽ��ֵ(dBm):TDSCDMA from LTE Handover Success�¼���5������RSRP����

	//TDSCDMA-LTE�л�
	m_ulTD_LTE_Handover_Start_NUM = 0;		//TD-LTE�л����Դ���:TDSCDMA to LTE Handover Start�¼��ϱ�����
	m_ulTD_LTE_Handover_Success_NUM = 0;	//TD-LTE�л��ɹ�����:TDSCDMA to LTE Handover Success�¼��ϱ�����
	m_dbTD_LTE_Handover_Total_Delay = 0;	//TD-LTE�л�ʱ�Ӻ�(s):TDSCDMA to LTE Handover Start�¼���TDSCDMA to LTE Handover Success�¼���ʱ���ܺ�
	m_dbTD_LTE_RSRP_Sum_Before_Handover_Start_5Second = 0;	//TD-LTE�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Start�¼�ǰ5������RSRP�ܺ�
	m_ulTD_LTE_RSRP_Num_Before_Handover_Start_5Second = 0;	//TD-LTE�л�ǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Start�¼�ǰ5������RSRP����
	m_dbTD_LTE_RSRP_Sum_After_Handover_Success_5Second = 0;	//TD-LTE�л����ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Success�¼���5������RSRP�ܺ�
	m_ulTD_LTE_RSRP_Num_After_Handover_Success_5Second = 0;	//TD-LTE�л����ƽƽ��ֵ(dBm):TDSCDMA to LTE Handover Success�¼���5������RSRP����

	//LTE-TDSCDMA��ѡ
	m_ulLTE_TD_Resel_Start_NUM = 0;		//LTE-TD��ѡ����:TDSCDMA from LTE Resel Start�¼��ϱ�����
	m_ulLTE_TD_Resel_Success_NUM = 0;	//LTE-TD��ѡ�ɹ�����:TDSCDMA from LTE Resel Success�¼��ϱ�����
	m_dbLTE_TD_Resel_Total_Delay = 0;	//LTE-TD��ѡʱ�Ӻ�(s):TDSCDMA from LTE Resel Start�¼���TDSCDMA from LTE Resel Success�¼���ʱ���ܺ�
	m_dbLTE_TD_RSRP_Sum_Before_Resel_Start_5Second = 0;	//LTE-TD��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Start�¼�ǰ5������RSRP�ܺ�
	m_ulLTE_TD_RSRP_Num_Before_Resel_Start_5Second = 0;	//LTE-TD��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Start�¼�ǰ5������RSRP����
	m_dbLTE_TD_RSRP_Sum_After_Resel_Success_5Second = 0;//LTE-TD��ѡ���ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Success�¼���5������RSRP�ܺ�
	m_ulLTE_TD_RSRP_Num_After_Resel_Success_5Second = 0;//LTE-TD��ѡ���ƽƽ��ֵ(dBm):TDSCDMA from LTE Resel Success�¼���5������RSRP����

	//TDSCDMA-LTE��ѡ
	m_ulTD_LTE_Resel_Start_NUM = 0;		//TD-LTE��ѡ����:TDSCDMA to LTE Resel Start�¼��ϱ�����
	m_ulTD_LTE_Resel_Success_NUM = 0;	//TD-LTE��ѡ�ɹ�����:TDSCDMA to LTE Resel Success�¼��ϱ�����
	m_dbTD_LTE_Resel_Total_Delay = 0;	//TD-LTE��ѡʱ�Ӻ�(s):TDSCDMA to LTE Resel Start�¼���TDSCDMA to LTE Resel Success�¼���ʱ���ܺ�
	m_dbTD_LTE_RSRP_Sum_Before_Resel_Start_5Second = 0;	//TD-LTE��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Start�¼�ǰ5������RSRP�ܺ�
	m_ulTD_LTE_RSRP_Num_Before_Resel_Start_5Second = 0;	//TD-LTE��ѡǰ��ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Start�¼�ǰ5������RSRP����
	m_dbTD_LTE_RSRP_Sum_After_Resel_Success_5Second = 0;//TD-LTE��ѡ���ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Success�¼���5������RSRP�ܺ�
	m_ulTD_LTE_RSRP_Num_After_Resel_Success_5Second = 0;//TD-LTE��ѡ���ƽƽ��ֵ(dBm):TDSCDMA to LTE Resel Success�¼���5������RSRP����

	//Attachͳ��
	m_ulEPS_Attach_Request_NUM = 0;	//Attch���Դ���:EPS Attach Request�¼��ϱ�����
	m_ulEPS_Attach_Success_NUM = 0;	//Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
	m_dbEPS_Attach_Total_Delay = 0;	//Attachʱ�Ӻ�(s):EPS Attach Request�¼���EPS Attach Success�¼���ʱ���ܺ�

	//Serviceͳ��
	m_ulSERVICE_Request_NUM = 0;	//Service�������:SERVICE REQUEST�¼��ϱ�����
	m_ulSERVICE_Success_NUM = 0;	//Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
	m_dbSERVICE_Total_Delay = 0;	//Service����ʱ�Ӻ�(s):SERVICE REQUEST�¼���SERVICE SUCCESS�¼���ʱ���ܺ�

	//LTE���������ͳ��
	m_ulTAU_Request_NUM = 0;	//TA���³��Դ���:TAU Request�¼��ϱ�����
	m_ulTAU_Success_NUM = 0;	//TA���³ɹ�����:TAU Success�¼��ϱ�����
	m_dbTAU_Total_Delay = 0;	//TA����ʱ�Ӻ�(s):(TAU Success-TAU Request)��ʱ���ܺ�

	//������ͳ��
	m_dbPDCP_DL_Throughput_Sum_ID = 0;	//PDCP����ƽ��������Kbps(������):PDCP Throughput DL�ܺ�
	m_ulPDCP_DL_Throughput_Num_ID = 0;	//PDCP����ƽ��������Kbps(������):PDCP Throughput DL����
	m_dbPDCP_UL_Throughput_Sum_ID = 0;	//PDCP����ƽ��������Kbps(������):PDCP Throughput UL�ܺ�
	m_ulPDCP_UL_Throughput_Num_ID = 0;	//PDCP����ƽ��������Kbps(������):PDCP Throughput UL����
	//m_dbRLC_DL_Throughput_Sum_ID = 0;	//RLC����ƽ��������Kbps(������):RLC Throughput DL�ܺ�
	//m_ulRLC_DL_Throughput_Num_ID = 0;	//RLC����ƽ��������Kbps(������):RLC Throughput DL����
	//m_dbRLC_UL_Throughput_Sum_ID = 0;	//RLC����ƽ��������Kbps(������):RLC Throughput UL�ܺ�
	//m_ulRLC_UL_Throughput_Num_ID = 0;	//RLC����ƽ��������Kbps(������):RLC Throughput UL����
	m_dbMAC_DL_Throughput_Sum_ID = 0;	//MAC����ƽ��������Kbps(������):MAC Throughput DL�ܺ�
	m_ulMAC_DL_Throughput_Num_ID = 0;	//MAC����ƽ��������Kbps(������):MAC Throughput DL����
	m_dbMAC_UL_Throughput_Sum_ID = 0;	//MAC����ƽ��������Kbps(������):MAC Throughput UL�ܺ�
	m_ulMAC_UL_Throughput_Num_ID = 0;	//MAC����ƽ��������Kbps(������):MAC Throughput UL����

	//PDSCH�ش�ͳ��
	m_ulPDSCH_first_rx_success_cnt = 0;		//���ν��ճɹ�����:pdsch_first_rx_success_cnt
	m_ulPDSCH_multi_retrans_success_cnt = 0;//����ش��ɹ�����:pdsch_multi_retrans_success_cnt

	//PUSCH�ش�ͳ��
	m_ulHARQ_UL_1st_Tx_Succ_Num = 0;		//�����ɹ�����:HARQ UL 1st Tx Succ Num
	m_ulHARQ_UL_1st_ReTx_Succ_Num = 0;		//1���ش��ɹ�����:HARQ UL 1st ReTx Succ Num
	m_ulHARQ_UL_2nd_ReTx_Succ_Num = 0;		//2���ش��ɹ�����:HARQ UL 2nd ReTx Succ Num
	m_ulHARQ_UL_3rd_ReTx_Succ_Num = 0;		//3���ش��ɹ�����:HARQ UL 3rd ReTx Succ Num
	m_ulHARQ_UL_4th_ReTx_Succ_Num = 0;		//4���ش��ɹ�����:HARQ UL 4th ReTx Succ Num
	m_ulHARQ_UL_mutil_ReTx_Succ_Num = 0;	//����ش��ɹ�����:HARQ UL mutil ReTx Succ Num
	m_ulHARQ_DL_ReTx_Failed_cnt = 0;		//�ش�ʧ�ܴ���:HARQ DL ReTx Failed Num;
	m_ulHARQ_UL_ReTx_Failed_cnt = 0;		//�ش�ʧ�ܴ���:HARQ UL ReTx Failed Num;

	//����0����ACK/NACKͳ��
	m_ulHARQ_DL_C0_ACK_Count = 0;	//ACK Count:HARQ DL C0 ACK Count
	m_ulHARQ_DL_C0_NACK_Count = 0;	//NACK Count:HARQ DL C0 NACK Count
	//����1����ACK/NACKͳ��
	m_ulHARQ_DL_C1_ACK_Count = 0;	//ACK Count:HARQ DL C1 ACK Count
	m_ulHARQ_DL_C1_NACK_Count = 0;	//NACK Count:HARQ DL C1 NACK Count
	//����ACK/NACKͳ��
	m_ulHARQ_UL_Ack_Count = 0;	//ACK Count:HARQ UL ACK Count
	m_ulHARQ_UL_NAck_Count = 0;	//NACK Count:HARQ UL NACK Count

	//����BLER
	m_dbDL_Code0_BLER_Sum = 0;		//��������0Bler(%):DL Code0 BLER�ܺ�
	m_ulDL_Code0_BLER_Num = 0;		//��������0Bler(%):DL Code0 BLER����
	m_dbDL_Code1_BLER_Sum = 0;		//��������1Bler(%):DL Code1 BLER�ܺ�
	m_ulDL_Code1_BLER_Num = 0;		//��������1Bler(%):DL Code1 BLER����
	m_dbDL_Code0_I_BLER_Sum = 0;	//��������0��ʼBler(%):DL Code0 IBLER�ܺ�
	m_ulDL_Code0_I_BLER_Num = 0;	//��������0��ʼBler(%):DL Code0 IBLER����
	m_dbDL_Code0_R_BLER_Sum = 0;	//��������0����Bler(%):DL Code0 RBLER�ܺ�
	m_ulDL_Code0_R_BLER_Num = 0;	//��������0����Bler(%):DL Code0 RBLER����
	m_dbDL_Code1_I_BLER_Sum = 0;	//��������1��ʼBler(%):DL Code1 IBLER�ܺ�
	m_ulDL_Code1_I_BLER_Num = 0;	//��������1��ʼBler(%):DL Code1 IBLER����
	m_dbDL_Code2_R_BLER_Sum = 0;	//��������1����Bler(%):DL Code1 RBLER�ܺ�
	m_ulDL_Code2_R_BLER_Num = 0;	//��������1����Bler(%):DL Code1 RBLER����

	//����BLER
	m_dbUL_BLER_Sum = 0;			//����Bler(%):UL BLER�ܺ�
	m_ulUL_BLER_Num = 0;			//����Bler(%):UL BLER����
	m_dbUL_I_BLER_Sum = 0;			//���г�ʼBler(%):UL IBLER�ܺ�
	m_ulUL_I_BLER_Num = 0;			//���г�ʼBler(%):UL IBLER����
	m_dbUL_R_BLER_Sum = 0;			//���в���Bler(%):UL RBLER�ܺ�
	m_ulUL_R_BLER_Num = 0;			//���в���Bler(%):UL RBLER����

	m_dbRSRP_Sum = 0;		//ƽ��RSRP(dBm):RSRP�ܺ�
	m_dbRSRP_Edge = 0;		//��ԵRSRP(dBm):RSRP�����CDF(�ۻ���ʷֲ�)5%��Ӧ��ֵ
	m_ulRSRP_MeetNum = 0;	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR >= 0dB

	m_dbLTETotalDistance = 0;		//LTE�������:LTE��ʽ�µ�����ܺ�
	m_dbLTEWeakCoverDistance = 0;	//LTE�������������:����10��70%�Ĳ����·������RSRP<-105dBm,��CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
	m_dbLTENoneCoverDistance = 0;	//LTE�����޸������:����10��70%�Ĳ����·������RSRP<-115dBm,CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
	m_dbLTEHighTxpowerDistance = 0;	//UE�߹��ʷ������:UE��PUSCH�ŵ����书�ʳ���10��70%�����>16dBm������·��

	m_dbPRACH_Power_Sum = 0;	//PRACHƽ����(dBm):PRACH_Power�ܺ�
	m_ulPRACH_Power_Num = 0;	//PRACHƽ����(dBm):PRACH_Power����
	m_dbPUSCH_Power_Sum = 0;	//PUSCHƽ����(dBm):PUSCH_Power�ܺ�
	m_ulPUSCH_Power_Num = 0;	//PUSCHƽ����(dBm):PUSCH_Power����
	m_dbPUCCH_Power_Sum = 0;	//PUCCHƽ����(dBm):PUCCH_Power�ܺ�
	m_ulPUCCH_Power_Num = 0;	//PUCCHƽ����(dBm):PUCCH_Power����
	m_dbSRS_Power_Sum = 0;		//SRSƽ����(dBm):SRS_Power�ܺ�
	m_ulSRS_Power_Num = 0;		//SRSƽ����(dBm):SRS_Power����

	m_dbSINR_Sum = 0;		//SINR(dB)�ܺ�
	m_dbSINR_Edge = 0;		//��ԵSINR(dB):SINR�����CDF(�ۼƸ��ʷֲ�)5%��Ӧ��ֵ
	m_dbRSRQ_Sum = 0;		//RSRQ(dB)�ܺ�
	m_dbRank1_Wideband_Code0_SINR_Sum = 0;	//Rank1 SINR(dBm):RI=1��Wideband Code0 SINR�ܺ�
	m_ulRank1_Wideband_Code0_SINR_Num = 0;	//Rank1 SINR(dBm):RI=1��Wideband Code0 SINR����
	m_dbRank2_Wideband_Code0_SINR_Sum = 0;	//Rank2 SINR1(dBm):RI=2��Wideband Code0 SINR�ܺ�
	m_ulRank2_Wideband_Code0_SINR_Num = 0;	//Rank2 SINR1(dBm):RI=2��Wideband Code0 SINR����
	m_dbRank2_Wideband_Code1_SINR_Sum = 0;	//Rank2 SINR2(dBm):RI=2��Wideband Code1 SINR�ܺ�
	m_ulRank2_Wideband_Code1_SINR_Num = 0;	//Rank2 SINR2(dBm):RI=2��Wideband Code1 SINR����

	m_dbLowSINRDistance = 0;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-1dB������·��
	m_ulOverCoverMeetNum = 0;	//�ص����Ƕ�>=3�Ĳ������:�ص����Ƕ�:·��������ǿС��RSRP�Ĳ�ֵ����-6dB�ĵ�ƽ������ ͬʱ��ǿС��RSRP>=-105dB
	m_dbOverCoverDistance = 0;	//�����ص����Ƕ�>=3�����

	//RSRP���ֲ�ͳ��
	m_ulRSRP_141_110_Num = 0;	//RSRP[-141,-110)
	m_ulRSRP_110_105_Num = 0;	//RSRP[-110,-105)
	m_ulRSRP_105_100_Num = 0;	//RSRP[-105,-100)
	m_ulRSRP_100_95_Num = 0;	//RSRP[-100,-95)
	m_ulRSRP_95_90_Num = 0;		//RSRP[-95,-90)
	m_ulRSRP_90_85_Num = 0;		//RSRP[-90,-85)
	m_ulRSRP_85_80_Num = 0;		//RSRP[-85,-80)
	m_ulRSRP_80_75_Num = 0;		//RSRP[-80,-75)
	m_ulRSRP_75_70_Num = 0;		//RSRP[-75,-70)
	m_ulRSRP_70_65_Num = 0;		//RSRP[-70,-65)
	m_ulRSRP_65_60_Num = 0;		//RSRP[-65,-60)
	m_ulRSRP_60_44_Num = 0;		//RSRP[-60,-44]

	//SINR���ֲ�ͳ��
	m_ulSINR_50_10_Num = 0;	//SINR[-50,-10)
	m_ulSINR_10_6_Num = 0;	//SINR[-10,-6)
	m_ulSINR_6_3_Num = 0;	//SINR[-6,-3)
	m_ulSINR_3_0_Num = 0;	//SINR[-3,0)
	m_ulSINR_0_3_Num = 0;	//SINR[0,3)
	m_ulSINR_3_6_Num = 0;	//SINR[3,6)
	m_ulSINR_6_10_Num = 0;	//SINR[6,10)
	m_ulSINR_10_15_Num = 0;	//SINR[10,15)
	m_ulSINR_15_20_Num = 0;	//SINR[15,20)
	m_ulSINR_20_25_Num = 0;	//SINR[20,25)
	m_ulSINR_25_50_Num = 0;	//SINR[25,50]

	//RSRQ���ֲ�ͳ��
	m_ulRSRQ_196_175_Num = 0;	//RSRQ[-19.6,-17.5)
	m_ulRSRQ_175_155_Num = 0;	//RSRQ[-17.5,-15.5)
	m_ulRSRQ_155_135_Num = 0;	//RSRQ[-15.5,-13.5)
	m_ulRSRQ_135_115_Num = 0;	//RSRQ[-13.5,-11.5)
	m_ulRSRQ_115_95_Num = 0;	//RSRQ[-11.5,-9.5)
	m_ulRSRQ_95_75_Num = 0;		//RSRQ[-9.5,-7.5)
	m_ulRSRQ_75_55_Num = 0;		//RSRQ[-7.5,-5.5)
	m_ulRSRQ_55_35_Num = 0;		//RSRQ[-5.5,-3.5)
	m_ulRSRQ_35_30_Num = 0;		//RSRQ[-3.5,-3]

	//�ص����Ƕ����ֲ�ͳ��
	m_ulOverCoverDegree_0_Num = 0;		//0
	m_ulOverCoverDegree_1_Num = 0;		//1
	m_ulOverCoverDegree_2_Num = 0;		//2
	m_ulOverCoverDegree_3_Num = 0;		//3
	m_ulOverCoverDegree_4_Num = 0;		//4
	m_ulOverCoverDegree_5_Num = 0;		//5
	m_ulOverCoverDegree_5_10_Num = 0;	//(5,10]
	m_ulOverCoverDegree_10_N_Num = 0;	// >10

	//PHY������
	m_dbPHY_Throughput_DL_Sum = 0;		//PHY����ƽ��������:PHY Throughput DL�ܺ�
	m_ulPHY_Throughput_DL_Num = 0;		//PHY����ƽ��������:PHY Throughput DL����
	m_dbPHY_Cw0_Throughput_DL_Sum = 0;	//����0ƽ��������(Kbps):PHY Cw0 Throughput DL�ܺ�
	m_ulPHY_Cw0_Throughput_DL_Num = 0;	//����0ƽ��������(Kbps):PHY Cw0 Throughput DL����
	m_dbPHY_Cw1_Throughput_DL_Sum = 0;	//����1ƽ��������(Kbps):PHY Cw1 Throughput DL�ܺ�
	m_ulPHY_Cw1_Throughput_DL_Num = 0;	//����1ƽ��������(Kbps):PHY Cw1 Throughput DL����
	m_dbPHY_Throughput_UL_Sum = 0;		//PHY����ƽ��������:PHY Throughput UL�ܺ�
	m_ulPHY_Throughput_UL_Num = 0;		//PHY����ƽ��������:PHY Throughput UL����

	//��֡����
	m_ulSubFrame_DL_TotalNum = 0;	//���ȸ�UE��������֡���ܺ�
	m_ulSubFrame_UL_TotalNum = 0;	//���ȸ�UE��������֡���ܺ�

	//MCSͳ��, ͨ����ϸ�ֲ�ͳ���Լ�����
	//CQIͳ��, ͨ����ϸ�ֲ�ͳ���Լ�����

	//Rankͳ��,ֻ����DL Code0 MCSΪ����,ͬʱ����DL Code0 MCS��DL Code1 MCSΪ˫��
	m_ulRank1_ReportNum = 0;	//RI=1�ϱ�����
	m_ulRank2_ReportNum = 0;	//RI=2�ϱ�����
	m_dbSingleFlowTime = 0;		//����ʱ��
	m_dbDoubleFlowTime = 0;		//˫��ʱ��
	m_dbSingleFlowData = 0;		//���������
	m_dbDoubleFlowData = 0;		//˫�������

	//����ģʽʱ��ռ��(%)
	m_dbTM1ModeTime = 0;	//TM1ʱ��
	m_dbTM2ModeTime = 0;	//TM2ʱ��
	m_dbTM3ModeTime = 0;	//TM3ʱ��
	m_dbTM4ModeTime = 0;	//TM4ʱ��
	m_dbTM5ModeTime = 0;	//TM5ʱ��
	m_dbTM6ModeTime = 0;	//TM6ʱ��
	m_dbTM7ModeTime = 0;	//TM7ʱ��
	m_dbTM8ModeTime = 0;	//TM8ʱ��

	//���Ʒ�ʽ�ֲ�ͳ��
	m_ulDL_Code0_QPSK_Num = 0;	//��������0���Ʒ�ʽQPSK
	m_ulDL_Code0_16QAM_Num = 0;	//��������0���Ʒ�ʽ16QAM
	m_ulDL_Code0_64QAM_Num = 0;	//��������0���Ʒ�ʽ64QAM
	m_ulDL_Code1_QPSK_Num = 0;	//��������1���Ʒ�ʽQPSK
	m_ulDL_Code1_16QAM_Num = 0;	//��������1���Ʒ�ʽ16QAM
	m_ulDL_Code1_64QAM_Num = 0;	//��������1���Ʒ�ʽ64QAM
	m_ulUL_QPSK_Num = 0;		//���е��Ʒ�ʽQPSK
	m_ulUL_16QAM_Num = 0;		//���е��Ʒ�ʽ16QAM
	m_ulUL_64QAM_Num = 0;		//���е��Ʒ�ʽ64QAM

	//����MCS����0��ϸ�ֲ����(%)
	m_ulDL_Code0_MCS0_Num = 0;	//DL Code0 MCS == 0 �ĸ���
	m_ulDL_Code0_MCS1_Num = 0;
	m_ulDL_Code0_MCS2_Num = 0;
	m_ulDL_Code0_MCS3_Num = 0;
	m_ulDL_Code0_MCS4_Num = 0;
	m_ulDL_Code0_MCS5_Num = 0;
	m_ulDL_Code0_MCS6_Num = 0;
	m_ulDL_Code0_MCS7_Num = 0;
	m_ulDL_Code0_MCS8_Num = 0;
	m_ulDL_Code0_MCS9_Num = 0;
	m_ulDL_Code0_MCS10_Num = 0;
	m_ulDL_Code0_MCS11_Num = 0;
	m_ulDL_Code0_MCS12_Num = 0;
	m_ulDL_Code0_MCS13_Num = 0;
	m_ulDL_Code0_MCS14_Num = 0;
	m_ulDL_Code0_MCS15_Num = 0;
	m_ulDL_Code0_MCS16_Num = 0;
	m_ulDL_Code0_MCS17_Num = 0;
	m_ulDL_Code0_MCS18_Num = 0;
	m_ulDL_Code0_MCS19_Num = 0;
	m_ulDL_Code0_MCS20_Num = 0;
	m_ulDL_Code0_MCS21_Num = 0;
	m_ulDL_Code0_MCS22_Num = 0;
	m_ulDL_Code0_MCS23_Num = 0;
	m_ulDL_Code0_MCS24_Num = 0;
	m_ulDL_Code0_MCS25_Num = 0;
	m_ulDL_Code0_MCS26_Num = 0;
	m_ulDL_Code0_MCS27_Num = 0;
	m_ulDL_Code0_MCS28_Num = 0;
	m_ulDL_Code0_MCS29_Num = 0;
	m_ulDL_Code0_MCS30_Num = 0;
	m_ulDL_Code0_MCS31_Num = 0;

	//����MCS����1��ϸ�ֲ����(%)
	m_ulDL_Code1_MCS0_Num = 0;	//DL Code1 MCS == 0 �ĸ���
	m_ulDL_Code1_MCS1_Num = 0;
	m_ulDL_Code1_MCS2_Num = 0;
	m_ulDL_Code1_MCS3_Num = 0;
	m_ulDL_Code1_MCS4_Num = 0;
	m_ulDL_Code1_MCS5_Num = 0;
	m_ulDL_Code1_MCS6_Num = 0;
	m_ulDL_Code1_MCS7_Num = 0;
	m_ulDL_Code1_MCS8_Num = 0;
	m_ulDL_Code1_MCS9_Num = 0;
	m_ulDL_Code1_MCS10_Num = 0;
	m_ulDL_Code1_MCS11_Num = 0;
	m_ulDL_Code1_MCS12_Num = 0;
	m_ulDL_Code1_MCS13_Num = 0;
	m_ulDL_Code1_MCS14_Num = 0;
	m_ulDL_Code1_MCS15_Num = 0;
	m_ulDL_Code1_MCS16_Num = 0;
	m_ulDL_Code1_MCS17_Num = 0;
	m_ulDL_Code1_MCS18_Num = 0;
	m_ulDL_Code1_MCS19_Num = 0;
	m_ulDL_Code1_MCS20_Num = 0;
	m_ulDL_Code1_MCS21_Num = 0;
	m_ulDL_Code1_MCS22_Num = 0;
	m_ulDL_Code1_MCS23_Num = 0;
	m_ulDL_Code1_MCS24_Num = 0;
	m_ulDL_Code1_MCS25_Num = 0;
	m_ulDL_Code1_MCS26_Num = 0;
	m_ulDL_Code1_MCS27_Num = 0;
	m_ulDL_Code1_MCS28_Num = 0;
	m_ulDL_Code1_MCS29_Num = 0;
	m_ulDL_Code1_MCS30_Num = 0;
	m_ulDL_Code1_MCS31_Num = 0;

	//����MCS ��ϸ�ֲ����(%)
	m_ulUL_MCS0_Num = 0;	//UL MCS == 0 �ĸ���
	m_ulUL_MCS1_Num = 0;
	m_ulUL_MCS2_Num = 0;
	m_ulUL_MCS3_Num = 0;
	m_ulUL_MCS4_Num = 0;
	m_ulUL_MCS5_Num = 0;
	m_ulUL_MCS6_Num = 0;
	m_ulUL_MCS7_Num = 0;
	m_ulUL_MCS8_Num = 0;
	m_ulUL_MCS9_Num = 0;
	m_ulUL_MCS10_Num = 0;
	m_ulUL_MCS11_Num = 0;
	m_ulUL_MCS12_Num = 0;
	m_ulUL_MCS13_Num = 0;
	m_ulUL_MCS14_Num = 0;
	m_ulUL_MCS15_Num = 0;
	m_ulUL_MCS16_Num = 0;
	m_ulUL_MCS17_Num = 0;
	m_ulUL_MCS18_Num = 0;
	m_ulUL_MCS19_Num = 0;
	m_ulUL_MCS20_Num = 0;
	m_ulUL_MCS21_Num = 0;
	m_ulUL_MCS22_Num = 0;
	m_ulUL_MCS23_Num = 0;
	m_ulUL_MCS24_Num = 0;
	m_ulUL_MCS25_Num = 0;
	m_ulUL_MCS26_Num = 0;
	m_ulUL_MCS27_Num = 0;
	m_ulUL_MCS28_Num = 0;
	m_ulUL_MCS29_Num = 0;
	m_ulUL_MCS30_Num = 0;
	m_ulUL_MCS31_Num = 0;

	//����0��CQI��ϸ�ֲ����(%)
	m_ulWideband_Code0_CQI0_Num = 0;	//Wideband Code0 CQI == 0 �ĸ���
	m_ulWideband_Code0_CQI1_Num = 0;
	m_ulWideband_Code0_CQI2_Num = 0;
	m_ulWideband_Code0_CQI3_Num = 0;
	m_ulWideband_Code0_CQI4_Num = 0;
	m_ulWideband_Code0_CQI5_Num = 0;
	m_ulWideband_Code0_CQI6_Num = 0;
	m_ulWideband_Code0_CQI7_Num = 0;
	m_ulWideband_Code0_CQI8_Num = 0;
	m_ulWideband_Code0_CQI9_Num = 0;
	m_ulWideband_Code0_CQI10_Num = 0;
	m_ulWideband_Code0_CQI11_Num = 0;
	m_ulWideband_Code0_CQI12_Num = 0;
	m_ulWideband_Code0_CQI13_Num = 0;
	m_ulWideband_Code0_CQI14_Num = 0;
	m_ulWideband_Code0_CQI15_Num = 0;

	//����1��CQI��ϸ�ֲ����(%)
	m_ulWideband_Code1_CQI0_Num = 0;	//Wideband Code1 CQI == 0 �ĸ���
	m_ulWideband_Code1_CQI1_Num = 0;
	m_ulWideband_Code1_CQI2_Num = 0;
	m_ulWideband_Code1_CQI3_Num = 0;
	m_ulWideband_Code1_CQI4_Num = 0;
	m_ulWideband_Code1_CQI5_Num = 0;
	m_ulWideband_Code1_CQI6_Num = 0;
	m_ulWideband_Code1_CQI7_Num = 0;
	m_ulWideband_Code1_CQI8_Num = 0;
	m_ulWideband_Code1_CQI9_Num = 0;
	m_ulWideband_Code1_CQI10_Num = 0;
	m_ulWideband_Code1_CQI11_Num = 0;
	m_ulWideband_Code1_CQI12_Num = 0;
	m_ulWideband_Code1_CQI13_Num = 0;
	m_ulWideband_Code1_CQI14_Num = 0;
	m_ulWideband_Code1_CQI15_Num = 0;

	//PDCCH CFI�ֲ�ͳ��(%)
	m_ulPDCCH_CFI1_Num = 0; //CFI1 Count == 1 �ĸ���
	m_ulPDCCH_CFI2_Num = 0;
	m_ulPDCCH_CFI3_Num = 0;
	m_ulPDCCH_CFI4_Num = 0;

	//LTE��֡����ʱ���ֲ�ͳ��(%):subframe_Assignment
	m_dbSubFrameAssign_Format0_Time = 0;	//��ʽ0
	m_dbSubFrameAssign_Format1_Time = 0;	//��ʽ1(1:1)
	m_dbSubFrameAssign_Format2_Time = 0;	//��ʽ2(3:1)
	m_dbSubFrameAssign_Format3_Time = 0;	//��ʽ3
	m_dbSubFrameAssign_Format4_Time = 0;	//��ʽ4
	m_dbSubFrameAssign_Format5_Time = 0;	//��ʽ5
	m_dbSubFrameAssign_Format6_Time = 0;	//��ʽ6

	//LTE����ʱ϶����ʱ���ֲ�ͳ��(%):special_Subframe_Patterns
	m_dbSpecialSubframePatterns_0_Time = 0;	//0
	m_dbSpecialSubframePatterns_1_Time = 0;	//1
	m_dbSpecialSubframePatterns_2_Time = 0;	//2
	m_dbSpecialSubframePatterns_3_Time = 0;	//3
	m_dbSpecialSubframePatterns_4_Time = 0;	//4
	m_dbSpecialSubframePatterns_3_9_2_Time = 0;	//5
	m_dbSpecialSubframePatterns_6_Time = 0;	//6
	m_dbSpecialSubframePatterns_10_2_2_Time = 0;	//7
	m_dbSpecialSubframePatterns_8_Time = 0;	//8
	m_dbSpecialSubframePatterns_Other_Time = 0;	//����

	//LTE CP����ʱ���ֲ�ͳ��(%):UL_CP_Type
	m_dbLTE_Normal_CP_Time = 0;		//Normal CP
	m_dbLTE_Extended_CP_Time = 0;	//Extended CP

	//LTE ���߶˿�����ʱ���ֲ�ͳ��(%):eNB_Tx_Antenna_Num
	m_dbLTE_AN_1_Time = 0;	//an1
	m_dbLTE_AN_2_Time = 0;	//an2
	m_dbLTE_AN_4_Time = 0;	//an4

	//LTE ��Ƶ��ռ��ʱ���ֲ�ͳ��(%):Band
	m_dbLTE_Band_D_Time = 0;	//DƵ��
	m_dbLTE_Band_E_Time = 0;	//EƵ��
	m_dbLTE_Band_F_Time = 0;	//FƵ��

	m_ulSubFrame_DL_Count = 0;	//���ȸ�UE��������֡���ܸ���
	m_ulSubFrame_UL_Count = 0;	//���ȸ�UE��������֡���ܸ���

	m_ullFTP_DL_PRB_Sum = 0;
	m_ullFTP_DL_PRB_Count = 0;
	m_ullFTP_UL_PRB_Sum = 0;
	m_ullFTP_UL_PRB_Count = 0;
}