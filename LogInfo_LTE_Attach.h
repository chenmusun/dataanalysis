#pragma once
#include "LogInfoBase.h"
#include<list>
class CLogInfo_LTE_Attach:
	public CLogInfoBase
{
public:
	CLogInfo_LTE_Attach(void);
	~CLogInfo_LTE_Attach(void);

	//virtual CString GetInsertSQL();

//	void AddTroubleRoad(CLogInfo_TD_TroubleRoad* TroubleRoad);
	void InitPara();

public:
	UINT64 RecSeqNo;		//��¼���к�, ȫ��ֵΨһ,����

	//���ҵ��ͳ��ָ��	//104
	//PHY������		// [5/27/2015 liangdongxu]
	double m_dbPHY_Throughput_DL_Sum_ID;	//PHY����ƽ��������:PHY Throughput DL�ܺ�(������)
	double m_dbPHY_Throughput_DL_Sum_NID;	//PHY����ƽ��������:PHY Throughput DL�ܺ�(��������)
	double m_dbPHY_Throughput_UL_Sum_ID;	//PHY����ƽ��������:PHY Throughput UL�ܺ�(������)
	double m_dbPHY_Throughput_UL_Sum_NID;	//PHY����ƽ��������:PHY Throughput UL�ܺ�(��������)
	UINT32 m_ulPHY_Throughput_DL_Num_ID;	//PHY����ƽ��������:PHY Throughput DL����(������)
	UINT32 m_ulPHY_Throughput_DL_Num_NID;	//PHY����ƽ��������:PHY Throughput DL����(��������)
	UINT32 m_ulPHY_Throughput_UL_Num_ID;	//PHY����ƽ��������:PHY Throughput UL����(������)
	UINT32 m_ulPHY_Throughput_UL_Num_NID;	//PHY����ƽ��������:PHY Throughput UL����(��������)
	//FTP����ҵ��֮����γ��Դ���,�ɹ�����,���ߴ���
	UINT32 m_ulFtp_DL_TDL_Request_Num;
	UINT32 m_ulFtp_DL_TDS_Request_Num;
	UINT32 m_ulFtp_DL_GSM_Request_Num;
	UINT32 m_ulFtp_DL_TDL_Success_Num;
	UINT32 m_ulFtp_DL_TDS_Success_Num;
	UINT32 m_ulFtp_DL_GSM_Success_Num;
	UINT32 m_ulFtp_DL_TDL_Drop_Num;
	UINT32 m_ulFtp_DL_TDS_Drop_Num;
	UINT32 m_ulFtp_DL_GSM_Drop_Num;
	//FTP����ҵ��֮��������������(���ڼ�����ݵ��߱�)
	double  m_dbFTP_DL_TOTALDATA_TDL_ID;	
	double  m_dbFTP_DL_TOTALDATA_TDS_ID;
	double  m_dbFTP_DL_TOTALDATA_GSM_ID;
	double  m_dbFTP_DL_TOTALDATA_TDL_NID;
	double  m_dbFTP_DL_TOTALDATA_TDS_NID;
	double  m_dbFTP_DL_TOTALDATA_GSM_NID;
	//FTP����ҵ��֮�����פ��ʱ��
	double m_dbFTP_DL_TotalTime_LTE_NID;	//(FTP����ִ��ʱ����,ռ��LTE���ʱ��(��������))
	double m_dbFTP_DL_TOTALTIME_S_NID;
	double m_dbFTP_DL_TOTALTIME_G_NID;
	double m_dbFTP_DL_TotalTime_LTE_ID;		//(FTP����ִ��ʱ����,ռ��LTE���ʱ��(������))
	double m_dbFTP_DL_TOTALTIME_S_ID;
	double m_dbFTP_DL_TOTALTIME_G_ID;
	//FTP����ҵ��֮Ӧ�ò�����ʱ��	�����౨�?��
	double m_dbFTP_DL_TotalTime_ID;			//(FTP������ʱ��(������))
	double m_dbFTP_DL_TotalTime_NID;		//(FTP������ʱ��(��������))		
	//FTP����ҵ��֮ÿRBƽ��������	�����౨�?��
	UINT64 m_ullFTP_DL_PRB_ID;				//(ÿRBƽ��������(������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(������)==����ҵ�����PRB�����ܺ�)		
	UINT64 m_ullFTP_DL_PRB_NID;				//(ÿRBƽ��������(��������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(��������))		
	//FTP����ҵ��֮��ԵPDCP����������
	double m_dbPDCP_DL_Edge_Throught_ID;	
	double m_dbPDCP_DL_Edge_Throught_NID;
	//FTP����ҵ��֮��ԵӦ�ò�����������
	double m_dbFTP_DL_Edge_Throught_ID;	
	double m_dbFTP_DL_Edge_Throught_NID;
	//FTP����ҵ��֮PDCP���е�������ռ��
	UINT32 m_ulPDCP_DL_LowThroughput_Sum;	//(����ʱ����PDCP�������������)	
	UINT32 m_ulPDCP_DL_TotalThroughput_Sum;	//(����ʱ����PDCP�������ܲ����)	
	//FTP����ҵ��֮Ӧ�ò����е�������ռ��
	UINT32 m_ulFTP_DL_LowThroughput_Sum;	//(Ӧ�ò�������������)
	UINT32 m_ulFTP_DL_TotalThroughput_Sum;	//(Ӧ�ò��������ܲ����)
	//FTP����ҵ��֮�����˲ʱ�����������(kbps)
	double  m_dbDL_MaxSPeed;
	//FTP�ϴ�ҵ��֮����γ��Դ���,�ɹ�����,���ߴ���
	UINT32 m_ulFtp_UL_TDL_Request_Num;
	UINT32 m_ulFtp_UL_TDS_Request_Num;	
	UINT32 m_ulFtp_UL_GSM_Request_Num;
	UINT32 m_ulFtp_UL_TDL_Success_Num;	
	UINT32 m_ulFtp_UL_TDS_Success_Num;	
	UINT32 m_ulFtp_UL_GSM_Success_Num;
	UINT32 m_ulFtp_UL_TDL_Drop_Num;	
	UINT32 m_ulFtp_UL_TDS_Drop_Num;	
	UINT32 m_ulFtp_UL_GSM_Drop_Num;
	//FTP�ϴ�ҵ��֮������ϴ������(���ڼ�����ݵ��߱�)
	double  m_dbFTP_UL_TotalData_TDL_ID;
	double  m_dbFTP_UL_TotalData_TDS_ID;
	double  m_dbFTP_UL_TotalData_GSM_ID;
	double  m_dbFTP_UL_TotalData_TDL_NID;
	double  m_dbFTP_UL_TotalData_TDS_NID;
	double  m_dbFTP_UL_TotalData_GSM_NID;
	//FTP�ϴ�ҵ��֮�����פ��ʱ��
	double m_dbFTP_UL_TotalTime_LTE_NID;	//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)//FTP_UL_TotalTime_L_NID(FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)�����౨���Ѵ洢���ֶ�)
	double m_dbFTP_UL_TotalTime_S_NID;		//FTP�ϴ�ִ��ʱ����,ռ��SCDMA���ʱ��(��������))
	double m_dbFTP_UL_TotalTime_G_NID;		//FTP�ϴ�ִ��ʱ����,ռ��GSM���ʱ��(��������))
	double m_dbFTP_UL_TotalTime_LTE_ID;		//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)//FTP_UL_TotalTime_L_ID(FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)�����౨���Ѵ洢���ֶ�)
	double m_dbFTP_UL_TotalTime_S_ID;		//FTP�ϴ�ִ��ʱ����,ռ��SCDMA���ʱ��(������))
	double m_dbFTP_UL_TotalTime_G_ID;		//FTP�ϴ�ִ��ʱ����,ռ��GSM���ʱ��(������))
	//FTP�ϴ�ҵ��֮Ӧ�ò��ϴ�ʱ��	�����౨�?��
	double m_dbFTP_UL_TotalTime_NID;	//(FTP�ϴ���ʱ��(��������))		
	double m_dbFTP_UL_TotalTime_ID;		//(FTP�ϴ���ʱ��(������))		
	//FTP�ϴ�ҵ��֮ÿRBƽ���ϴ���(�ϴ�ʱ���ڵ��ȵ�����PRB������)�����౨�?��
	UINT64 m_ullFTP_UL_PRB_NID;			//(ÿRBƽ���ϴ���(��������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(��������))		
	UINT64 m_ullFTP_UL_PRB_ID;			//(ÿRBƽ���ϴ���(������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(������)==����ҵ�����PRB�����ܺ�)				
	//FTP�ϴ�ҵ��֮��ԵPDCP����������
	double m_dbPDCP_UL_Edge_Throught_ID;
	double m_dbPDCP_UL_Edge_Throught_NID;	
	//FTP�ϴ�ҵ��֮��ԵӦ�ò�����������
	double m_dbFTP_UL_Edge_Throught_ID;
	double m_dbFTP_UL_Edge_Throught_NID;
	//FTP�ϴ�ҵ��֮PDCP���е�������ռ��
	UINT32 m_ulPDCP_UL_LowThroughput_Sum;	//(��ʱ����PDCP�������������)
	UINT32 m_ulPDCP_UL_TotalThroughput_Sum;	//(����ʱ����PDCP�������ܲ����)
	//FTP�ϴ�ҵ��֮Ӧ�ò����е�������ռ��	
	UINT32 m_ulFTP_UL_LowThroughput_Sum;	//(Ӧ�ò�������������)
	UINT32 m_ulFTP_UL_TotalThroughput_Sum;	//(Ӧ�ò��������ܲ����)
	//FTP�ϴ�ҵ��֮�����˲ʱ�����������(kbps)
	double  m_dbUL_MaxSPeed;//UL_MaxSPeed
	//HTTP���ҵ��
	UINT32 m_ulHTTP_LoginRequestNum;
	UINT32 m_ulHTTP_LoginSuccNum;
	UINT32 m_ulHTTP_OnloadOverNum;
	double m_dbHTTP_LoginTotalDelay;	//(��¼ʱ�Ӻ�(s))
	double m_dbHTTP_BrowseTotalTime;	//(���ʱ����(s))
	double m_dbHTTP_DL_Data;			//(���������)	
	//HTTP����ҵ��
	UINT32 m_ulHTTP_DL_RequestNum;
	UINT32 m_ulHTTP_DL_SuccNum;		
	UINT32 m_ulHTTP_DL_DropNum;
	double m_dbHTTP_DownloadData_ID;	//(Ӧ�ò���������(������)(KB))	
	double m_dbHTTP_DownloadData_NID;	//(Ӧ�ò���������(��������)(KB))
	double m_dbHTTP_DownloadTime_ID;	//(Ӧ�ò�����ʱ��(������)(s))	
	double m_dbHTTP_DownloadTime_NID;	//(Ӧ�ò�����ʱ��(��������)(s))
	//��ý��ҵ��
	UINT32 m_ulStreamRequestNum;
	UINT32 m_ulStreamSuccNum;
	double m_dbStreamOnloadDelay;		//(����ʱ�Ӻ�(s))
	double m_dbStreamTimes;
	double m_dbStreamPauseTime;	
	double m_dbStreamPlayTotalTime;		//(��ý�岥����ʱ����(s))
	UINT32 m_ulStreamPlayPauseNum;
	double m_dbStreamDownloadData_NID;	//(���������)
	double m_dbStreamDownloadTime_NID;	//(����ʱ��)
	double m_dbStreamOnloadData;		//(C_StreamRealPlay��ĵ�һ���������)
	double m_dbStreamOnloadTime;		//(C_StreamRealPlay��S_APPServiceConnect��ʱ��)
	//�ʼ�����ҵ��
	//SQL_AppendUInt(strSQL, 0);//MailSendRequestNum	
	//SQL_AppendUInt(strSQL, 0);//MailSendSuccNum
	//SQL_AppendFlt(strSQL, 0);//MailSendDelay(ʱ�Ӻ�(s))
	//SQL_AppendFlt(strSQL, 0);//MailUploadData
	//SQL_AppendFlt(strSQL, 0);//MailUploadTime
	//������
	double m_dbRSRP_Sum;		//ƽ��RSRP(dBm):RSRP�ܺ�
	double m_dbRSRP_Edge;		//��ԵRSRP(dBm):RSRP�����CDF(�ۻ���ʷֲ�)5%��Ӧ��ֵ
	UINT32 m_ulRSRP_Meet110Num;	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR > -3dB
	UINT32 m_ulRSRP_Meet103Num;	//LTE�����������:�����������Ķ���ΪRSRP>-103dBm , ��SINR > -4dB
	UINT32 m_ulRSRP_Meet101Num;	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR > -5dB
	double m_dbLTETestDistance;	//TESTLOG_ITEM�������и��ֶ�(DISTANCE:��λ��)	�����౨�?��
	double m_dbTDSTestDistance;
	double m_dbGSMTestDistance;
	double m_dbLTEOutNetworkDistance;	//LTEOutNetworkDistance
	double m_dbOutNetworkTime;			//OutNetworkTime
	double m_dbTDLTestTime;				//TDLTestTime
	double m_dbTDSTestTime;				//TDSTestTime
	double m_dbGSMTestTime;				//GSMTestTime
	double m_dbLTEWeakCoverDistance;
	double m_dbLTENoneCoverDistance;
	//double m_dbLTEHighTxpowerDistance;

	//������
	double m_dbSINR_Sum;		//SINR(dB)�ܺ�,Ϊ�˻�ȡƽ��SINR
	double m_dbSINR_Edge;		//��ԵSINR(dB):SINR�����CDF(�ۼƸ��ʷֲ�)5%��Ӧ��ֵ
	UINT32 m_ulSINR_3_3_Num;	//TBD SINR>-3����:Ϊ������ռ��
	UINT32 m_ulSINR_0_0_Num;	//TBD SINR>0����:Ϊ������ռ��

	//ƽ��RSRQ
	double m_dbRSRQ_Sum;		//RSRQ(dB)�ܺ�
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

	//����SINR�ʲ����ռ��(SINRС��-1)(%)  ����SINR�ʲ����ռ��(SINRС��-3)(%)
	double m_dbLowSINRDistance;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-1dB������·��
	double m_dbLow3SINRDistance;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-3dB������·��

	//PDSCH BLERƽ��ֵ
	UINT32 m_ulFtp_DL_TotalTB;				//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��
	UINT32 m_ulFtp_DL_TotalErrorTB;			//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��

	//���г�ʼHARQ�ش�����
	UINT32 m_ulPDSCH_first_rx_success_cnt;		//(���ν��մ���)
	UINT32 m_ulPDSCH_multi_retrans_success_cnt;	//(���ش�����)

	//�ص�������(�ص����Ƕ�>=3)(%)
	UINT32 m_ulOverCoverMeetNum;		//(�ص����Ƕ�>=3�Ĳ����)
	//�ص��������ռ��(�ص����Ƕ�>=3)(%)
	double m_dbOverCoverDistance;		//�ص����Ƕ�>=3�Ĳ������:�ص����Ƕ�:·��������ǿС��RSRP�Ĳ�ֵ����-6dB�ĵ�ƽ������ ͬʱ��ǿС��RSRP>=-105dB
	//�ص�������(�ص����Ƕ�>=4)(%)	
	UINT32 m_ulOverCoverMeet4Num;		//(�ص����Ƕ�>=4�Ĳ����)
	//�ص��������ռ��(�ص����Ƕ�>=4)(%)
	double m_dbOverCover4Distance;		//(�����ص����Ƕ�>=4�����)
	UINT32 m_ulSamplingPoint_Num;		//(�ܲ������)

	//////////////////////////////////////////////////////////////////////////
	// ���¸�ָ��˳��δ���� [5/27/2015 liangdongxu]
	
	//�������Ӧ�ò���������(��������)
	//	UINT32 m_ulFtp_DL_Speed_0_0M_Num;	//����0
	UINT32 m_ulFtp_DL_Speed_0_1M_Num;	//[0,1M)
	UINT32 m_ulFtp_DL_Speed_1_2M_Num;	//[1,2M)
	UINT32 m_ulFtp_DL_Speed_2_4M_Num;	//[2,4M)
	UINT32 m_ulFtp_DL_Speed_4_5M_Num;	//[4,5M)
	UINT32 m_ulFtp_DL_Speed_5_8M_Num;	//[5,8M)
	UINT32 m_ulFtp_DL_Speed_8_10M_Num;	//[8,10M)
	UINT32 m_ulFtp_DL_Speed_10_12M_Num;	//[10,12M)
	UINT32 m_ulFtp_DL_Speed_12_15M_Num;	//[12,15M)
	UINT32 m_ulFtp_DL_Speed_15_20M_Num;	//[15,20M)
	UINT32 m_ulFtp_DL_Speed_20_25M_Num;	//[20,25M)
	UINT32 m_ulFtp_DL_Speed_25_30M_Num;	//[25,30M)
	UINT32 m_ulFtp_DL_Speed_30_35M_Num;	//[30,35M)
	UINT32 m_ulFtp_DL_Speed_35_40M_Num;	//[35,40M)
	UINT32 m_ulFtp_DL_Speed_40_NM_Num;	//���ڵ���40M

	//�������Ӧ�ò��ϴ�����(��������)
	//	UINT32 m_ulFtp_UL_Speed_0_0K_Num;		//����0
	UINT32 m_ulFtp_UL_Speed_0_256K_Num;		//(0,256K)
	UINT32 m_ulFtp_UL_Speed_256K_1M_Num;	//[256K,1M)
	UINT32 m_ulFtp_UL_Speed_1_3p5M_Num;		//[1,3.5M)
	UINT32 m_ulFtp_UL_Speed_3p5_6M_Num;		//[3.5,6M)
	UINT32 m_ulFtp_UL_Speed_6_9M_Num;		//[6,9M)
	UINT32 m_ulFtp_UL_Speed_9_12M_Num;		//[9,12M)
	UINT32 m_ulFtp_UL_Speed_12_15M_Num;		//[12,15M)
	UINT32 m_ulFtp_UL_Speed_15_20M_Num;		//[15,20M)
	UINT32 m_ulFtp_UL_Speed_20_NM_Num;		//���ڵ���20M

	//������
	//Attachͳ��
	UINT32 m_ulEPS_Attach_Request_NUM;	//Attch���Դ���:EPS Attach Request�¼��ϱ�����
	UINT32 m_ulEPS_Attach_Success_NUM;	//Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
	double m_dbEPS_Attach_Total_Delay;	//Attachʱ�Ӻ�(s):EPS Attach Request�¼���EPS Attach Success�¼���ʱ���ܺ�

	//Serviceͳ��
	UINT32 m_ulSERVICE_Request_NUM;	//Service�������:SERVICE REQUEST�¼��ϱ�����
	UINT32 m_ulSERVICE_Success_NUM;	//Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
	double m_dbSERVICE_Total_Delay;	//Service����ʱ�Ӻ�(s):SERVICE REQUEST�¼���SERVICE SUCCESS�¼���ʱ���ܺ�

	double m_dbLTE_Band_D_Time;
	double m_dbLTE_Band_E_Time;
	double m_dbLTE_Band_F_Time;

	//�ƶ���		��һЩ������˵ADC��־û��,Ŀǰ������ͳ�� [5/7/2015 liangdongxu]
	UINT32 m_ulLTE_LTE_Handover_Start_NUM;	//�����л����Դ���:Handover Start�¼��ϱ�����
	UINT32 m_ulLTE_LTE_Handover_Success_NUM;//�����л��ɹ�����:Handover Success�¼��ϱ�����
	double m_dbLTE_LTE_Handover_Total_Delay;//�����л�ʱ�Ӻ�(s):Handover Start�¼���Handover Success�¼���ʱ���ܺ�

	UINT32 m_ulLTE_intraHandover_Start_NUM;//LTEͬƵ�л����Դ��� Intrafreq Handover Start�¼�
	UINT32 m_ulLTE_intraHandover_Success_NUM;//LTEͬƵ�л��ɹ����� Intrafreq Handover Success�¼�
	double m_abLTE_intraHandover_Total_Delay;//LTEͬƵ�л�ʱ�Ӻ�(s)Intrafreq Handover Start�¼���Intrafreq Handover Success�¼���ʱ���ܺ�

	UINT32 m_ulLTE_interHandover_Start_NUM;//LTE��Ƶ�л����Դ���	Interfreq Handover Start�¼�
	UINT32 m_ulLTE_interHandover_Success_NUM;//LTE��Ƶ�л��ɹ�����	Interfreq Handover Success�¼�
	double m_abLTE_interHandover_Total_Delay;//LTE��Ƶ�л�ʱ�Ӻ�(s)Interfreq Handover Start�¼���Interfreq Handover Success�¼���ʱ���ܺ�

	//LTE-TDSCDMA��ѡ
	UINT32 m_ulLTE_TD_Resel_Start_NUM;	//LTE-TD��ѡ����:TDSCDMA from LTE Resel Start�¼��ϱ�����
	UINT32 m_ulLTE_TD_Resel_Success_NUM;//LTE-TD��ѡ�ɹ�����:TDSCDMA from LTE Resel Success�¼��ϱ�����
	double m_dbLTE_TD_Resel_Total_Delay;//LTE-TD��ѡʱ�Ӻ�(s):TDSCDMA from LTE Resel Start�¼���TDSCDMA from LTE Resel Success�¼���ʱ���ܺ�

	//TDSCDMA-LTE��ѡ
	UINT32 m_ulTD_LTE_Resel_Start_NUM;	//TD-LTE��ѡ����:TDSCDMA to LTE Resel Start�¼��ϱ�����
	UINT32 m_ulTD_LTE_Resel_Success_NUM;//TD-LTE��ѡ�ɹ�����:TDSCDMA to LTE Resel Success�¼��ϱ�����
	double m_dbTD_LTE_Resel_Total_Delay;//TD-LTE��ѡʱ�Ӻ�(s):TDSCDMA to LTE Resel Start�¼���TDSCDMA to LTE Resel Success�¼���ʱ���ܺ�

	//�����޶�Ӧ�¼�
	//TDL-GSM��ѡ���Դ���
	//TDL-GSM��ѡ�ɹ�����
	//TDL-GSM��ѡʱ��(s)
	//GSM-TDL��ѡ���Դ���
	//GSM-TDL��ѡ�ɹ�����
	//GSM-TDL��ѡʱ��(s)
	
	UINT32 m_ulLTE_TD_RD_Start_NUM;	//TDL-TDS�ض����Դ��� LTE To TDSCDMA Redirection Start
	UINT32 m_ulLTE_TD_RD_Success_NUM;//TDL-TDS�ض���ɹ�����	LTE To TDSCDMA Redirection End
	double m_abLTE_TD_RD_Total_Delay;//TDL-TDS�ض���ʱ�Ӻ�LTE To TDSCDMA Redirection Start��LTE To TDSCDMA Redirection End�¼�ʱ���ܺ�

	//�����޶�Ӧ�¼�
	//TDL-GSM�ض����Դ���		
	//TDL-GSM�ض���ɹ�����
	//TDL-GSM�ض���ƽ��ʱ��(s)
	//TDS-TDL�ض����Դ���
	//TDS-TDL�ض���ɹ�����	
	//TDS-TDL�ض���ʱ��

	//TAU LTE���������ͳ��
	UINT32 m_ulTAU_Request_NUM;	//TA���³��Դ���:TAU Request�¼��ϱ�����
	UINT32 m_ulTAU_Success_NUM;	//TA���³ɹ�����:TAU Success�¼��ϱ�����
	double m_dbTAU_Total_Delay;	//TA����ʱ�Ӻ�(s):(TAU Success-TAU Request)��ʱ���ܺ�

	//������ //����ָ��
	//1.����ƽ��ÿʱ϶����PRB���� 2.������֡������ 3.����ƽ��ÿ�����PRB����
	UINT32 m_ulSubFrame_DL_TotalNum;		//(���ȸ�UE��������֡���ܺ�)			
	UINT32 m_ulSubFrame_DL_Count;	//���ȸ�UE��������֡���ܸ���
	UINT32 m_ulSubFrame_UL_Count;	//���ȸ�UE��������֡���ܸ���

	//1.��������0MCSƽ��ֵ 2.��������0���Ƶ��MCS
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

	//1.��������1MCSƽ��ֵ 2.��������1���Ƶ��MCS
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

	//1.��������0CQIƽ��ֵ 2.��������0���Ƶ��CQI
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

	//1.��������1CQIƽ��ֵ 2.��������1���Ƶ��CQI
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

	//��������0 64QAM����//��������0 16QAM����//��������0 QPSK����
	//��������1 64QAM����//��������1 16QAM����//��������1 QPSK����
	//���Ʒ�ʽ�ֲ�ͳ��
	UINT32 m_ulDL_Code0_QPSK_Num;	//��������0���Ʒ�ʽQPSK
	UINT32 m_ulDL_Code0_16QAM_Num;	//��������0���Ʒ�ʽ16QAM
	UINT32 m_ulDL_Code0_64QAM_Num;	//��������0���Ʒ�ʽ64QAM
	UINT32 m_ulDL_Code1_QPSK_Num;	//��������1���Ʒ�ʽQPSK
	UINT32 m_ulDL_Code1_16QAM_Num;	//��������1���Ʒ�ʽ16QAM
	UINT32 m_ulDL_Code1_64QAM_Num;	//��������1���Ʒ�ʽ64QAM

	//����ָ��
	//1.����ƽ��ÿʱ϶����PRB���� 2.������֡������ 3.����ƽ��ÿ�����PRB����
	UINT32 m_ulSubFrame_UL_TotalNum;	//���ȸ�UE��������֡���ܺ�

	//1.��������0MCSƽ��ֵ 2.��������0���Ƶ��MCS
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

	//1.��������0 64QAM����	2.��������0 16QAM���� 2.��������0 QPSK����
	//���Ʒ�ʽ�ֲ�ͳ��
	UINT32 m_ulUL_QPSK_Num;			//���е��Ʒ�ʽQPSK
	UINT32 m_ulUL_16QAM_Num;		//���е��Ʒ�ʽ16QAM
	UINT32 m_ulUL_64QAM_Num;		//���е��Ʒ�ʽ64QAM

	//1.�ϱ�RANK1����ռ�� 2.�ϱ�RANK2����ռ��
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

	//////////////////////////////////////////////////////////////////////////
	// ���縲����ֶ�ռ�� [5/14/2015 liangdongxu]
	//RSRP���ֲ�ͳ��
	UINT32 m_ulRSRP_141_110_Num;	//RSRP[-141,-110)
	UINT32 m_ulRSRP_110_105_Num;	//RSRP[-110,-105)
	UINT32 m_ulRSRP_105_100_Num;	//RSRP[-105,-100)
	UINT32 m_ulRSRP_100_95_Num;		//RSRP[-100,-95)
	UINT32 m_ulRSRP_95_85_Num;		//RSRP[-95,-85)
	UINT32 m_ulRSRP_85_75_Num;		//RSRP[-85,-75)
	UINT32 m_ulRSRP_75_40_Num;		//RSRP[-75,-40)

	//SINR���ֲ�ͳ��
	UINT32 m_ulSINR_50_3_Num;	//SINR[-50,-3)
	UINT32 m_ulSINR_3_0_Num;	//SINR[-3,0)
	UINT32 m_ulSINR_0_3_Num;	//SINR[0,3)
	UINT32 m_ulSINR_3_6_Num;	//SINR[3,6)
	UINT32 m_ulSINR_6_9_Num;	//SINR[6,9)
	UINT32 m_ulSINR_9_15_Num;	//SINR[9,15)
	UINT32 m_ulSINR_15_50_Num;	//SINR[15,50]

	//////////////////////////////////////////////////////////////////////////
	std::list<CLogInfo_TD_TroubleRoad*> m_TroubleRoadList;  //����·���б�

	//�м������ֶβ����
	//һ�²����㷨����������Ҫ��μ�����������,����ָ�������ȡ��Ӧ�ֶ�������ͳ�ƺ��ж�,Ҳ�����
	//double m_dbLTEWeakCoverDistance;		//LTE�������������:����10��70%�Ĳ����·������RSRP<-105dBm,��CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
	//double m_dbLTENoneCoverDistance;		//LTE�����޸������:����10��70%�Ĳ����·������RSRP<-115dBm,CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
	//double m_dbLTEHighTxpowerDistance;	//UE�߹��ʷ������:UE��PUSCH�ŵ����书�ʳ���10��70%�����>16dBm������·��

};

