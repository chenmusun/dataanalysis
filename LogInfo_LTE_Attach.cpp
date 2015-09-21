//#include "stdafx.h"
#include "LogInfo_LTE_Attach.h"

CLogInfo_LTE_Attach::CLogInfo_LTE_Attach(void)
{
	InitPara();
}

CLogInfo_LTE_Attach::~CLogInfo_LTE_Attach(void)
{

}

//CString CLogInfo_LTE_Attach::GetInsertSQL()
//{
//	CString strSQL = _T("");
//
//	strSQL.Format(_T("insert into %s values ( "), m_strTableName);
//	SQL_AppendULONGLONG(strSQL, RecSeqNo);    //��¼���к�, ȫ��ֵΨһ,����		//1
//
//	//���ҵ��ͳ��ָ��	//104
//	//LTE�����������
//	SQL_AppendFlt(strSQL, m_dbPHY_Throughput_DL_Sum_ID);//PHY_DL_THROUGHPUT_SUM_ID
//	SQL_AppendFlt(strSQL, m_dbPHY_Throughput_DL_Sum_NID);//PHY_DL_THROUGHPUT_SUM_NID
//	SQL_AppendFlt(strSQL, m_dbPHY_Throughput_UL_Sum_ID);//PHY_UL_THROUGHPUT_SUM_ID
//	SQL_AppendFlt(strSQL, m_dbPHY_Throughput_UL_Sum_NID);//PHY_UL_THROUGHPUT_SUM_NID
//	SQL_AppendUInt(strSQL, m_ulPHY_Throughput_DL_Num_ID);//PHY_DL_THROUGHPUT_NUM_ID
//	SQL_AppendUInt(strSQL, m_ulPHY_Throughput_DL_Num_NID);//PHY_DL_THROUGHPUT_NUM_NID
//	SQL_AppendUInt(strSQL, m_ulPHY_Throughput_UL_Num_ID);//PHY_UL_THROUGHPUT_NUM_ID
//	SQL_AppendUInt(strSQL, m_ulPHY_Throughput_UL_Num_NID);//PHY_UL_THROUGHPUT_NUM_NID
//	//FTP����ҵ��֮����γ��Դ���,�ɹ�����,���ߴ���
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TDL_Request_Num);//Ftp_DL_TDL_Request_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TDS_Request_Num);//Ftp_DL_TDS_Request_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_GSM_Request_Num);//Ftp_DL_GSM_Request_Num
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TDL_Success_Num);//Ftp_DL_TDL_Success_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TDS_Success_Num);//Ftp_DL_TDS_Success_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_GSM_Success_Num);//Ftp_DL_GSM_Success_Num
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TDL_Drop_Num);//Ftp_DL_TDL_Drop_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TDS_Drop_Num);//Ftp_DL_TDS_Drop_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_GSM_Drop_Num);//Ftp_DL_GSM_Drop_Num
//	//FTP����ҵ��֮��������������(���ڼ�����ݵ��߱�)
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALDATA_TDL_ID);//FTP_DL_TOTALDATA_TDL_ID	
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALDATA_TDS_ID);//FTP_DL_TOTALDATA_TDS_ID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALDATA_GSM_ID);//FTP_DL_TOTALDATA_GSM_ID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALDATA_TDL_NID);//FTP_DL_TOTALDATA_TDL_NID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALDATA_TDS_NID);//FTP_DL_TOTALDATA_TDS_NID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALDATA_GSM_NID);//FTP_DL_TOTALDATA_GSM_NID
//	//FTP����ҵ��֮�����פ��ʱ��
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_LTE_NID);	//FTP����ִ��ʱ����,ռ��LTE���ʱ��(��������)//FTP_DL_TOTALTIME_L_NID	�����౨�?��
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALTIME_S_NID);//FTP_DL_TOTALTIME_S_NID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALTIME_G_NID);//FTP_DL_TOTALTIME_G_NID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_LTE_ID);		//FTP����ִ��ʱ����,ռ��LTE���ʱ��(������)//FTP_DL_TOTALTIME_L_ID	�����౨�?��
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALTIME_S_ID);//FTP_DL_TOTALTIME_S_ID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TOTALTIME_G_ID);//FTP_DL_TOTALTIME_G_ID
//	//FTP����ҵ��֮Ӧ�ò�����ʱ��	�����౨�?��
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_ID);			//FTP������ʱ��(������)//FTP_DL_TOTALTIME_ID
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_TotalTime_NID);		//FTP������ʱ��(��������)//FTP_DL_TOTALTIME_NID
//	//FTP����ҵ��֮ÿRBƽ��������	�����౨�?��
//	SQL_AppendUInt(strSQL, m_ullFTP_DL_PRB_ID);	//SQL_AppendULONGLONG//ÿRBƽ��������(������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(������)==����ҵ�����PRB�����ܺͣ�
//	SQL_AppendUInt(strSQL, m_ullFTP_DL_PRB_NID);//SQL_AppendULONGLONG	//ÿRBƽ��������(��������)(bit/RB):����ʱ���ڵ��ȵ�����PRB������(��������)
//	//FTP����ҵ��֮��ԵPDCP����������
//	SQL_AppendFlt(strSQL, m_dbPDCP_DL_Edge_Throught_ID);//PDCP_DL_Edge_Throught_ID	
//	SQL_AppendFlt(strSQL, m_dbPDCP_DL_Edge_Throught_NID);//PDCP_DL_Edge_Throught_NID	
//	//FTP����ҵ��֮��ԵӦ�ò�����������
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_Edge_Throught_ID);//FTP_DL_Edge_Throught_ID	
//	SQL_AppendFlt(strSQL, m_dbFTP_DL_Edge_Throught_NID);//FTP_DL_Edge_Throught_NID
//	//FTP����ҵ��֮PDCP���е�������ռ��
//	SQL_AppendUInt(strSQL, m_ulPDCP_DL_LowThroughput_Sum);//PDCP_DL_LowThroughput_Sum(����ʱ����PDCP�������������)	
//	SQL_AppendUInt(strSQL, m_ulPDCP_DL_TotalThroughput_Sum);//PDCP_DL_TotalThroughput_Sum(����ʱ����PDCP�������ܲ����)	
//	//FTP����ҵ��֮Ӧ�ò����е�������ռ��
//	SQL_AppendUInt(strSQL, m_ulFTP_DL_LowThroughput_Sum);//FTP_DL_LowThroughput_Sum(Ӧ�ò�������������)
//	SQL_AppendUInt(strSQL, m_ulFTP_DL_TotalThroughput_Sum);//FTP_DL_TotalThroughput_Sum(Ӧ�ò��������ܲ����)
//	//FTP����ҵ��֮�����˲ʱ�����������(kbps)
//	SQL_AppendFlt(strSQL, m_dbDL_MaxSPeed);//DL_MaxSPeed
//	//FTP�ϴ�ҵ��֮����γ��Դ���,�ɹ�����,���ߴ���
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_TDL_Request_Num);//Ftp_UL_TDL_Request_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_TDS_Request_Num);//Ftp_UL_TDS_Request_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_GSM_Request_Num);//Ftp_UL_GSM_Request_Num
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_TDL_Success_Num);//Ftp_UL_TDL_Success_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_TDS_Success_Num);//Ftp_UL_TDS_Success_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_GSM_Success_Num);//Ftp_UL_GSM_Success_Num
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_TDL_Drop_Num);//Ftp_UL_TDL_Drop_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_TDS_Drop_Num);//Ftp_UL_TDS_Drop_Num	
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_GSM_Drop_Num);//Ftp_UL_GSM_Drop_Num
//	//FTP�ϴ�ҵ��֮������ϴ������(���ڼ�����ݵ��߱�)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_TDL_ID);		//FTP_UL_TotalData_TDL_ID(TDL�ϴ����������������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_TDS_ID);		//FTP_UL_TotalData_TDS_ID(TDS�ϴ����������������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_GSM_ID);		//FTP_UL_TotalData_GSM_ID(GSM�ϴ����������������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_TDL_NID);	//FTP_UL_TotalData_TDL_NID(TDL�ϴ������������������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_TDS_NID);	//FTP_UL_TotalData_TDS_NID(TDL�ϴ������������������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalData_GSM_NID);	//FTP_UL_TotalData_GSM_NID(TDL�ϴ������������������))
//	//FTP�ϴ�ҵ��֮�����פ��ʱ��
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_LTE_NID);	//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)//FTP_UL_TotalTime_L_NID(FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(��������)�����౨���Ѵ洢���ֶ�)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_S_NID);		//FTP_UL_TotalTime_S_NID(FTP�ϴ�ִ��ʱ����,ռ��SCDMA���ʱ��(��������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_G_NID);		//FTP_UL_TotalTime_G_NID(FTP�ϴ�ִ��ʱ����,ռ��GSM���ʱ��(��������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_LTE_ID);		//FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)//FTP_UL_TotalTime_L_ID(FTP�ϴ�ִ��ʱ����,ռ��LTE���ʱ��(������)�����౨���Ѵ洢���ֶ�)
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_S_ID);		//FTP_UL_TotalTime_S_ID(FTP�ϴ�ִ��ʱ����,ռ��SCDMA���ʱ��(������))
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_G_ID);		//FTP_UL_TotalTime_G_ID(FTP�ϴ�ִ��ʱ����,ռ��GSM���ʱ��(������))
//	//FTP�ϴ�ҵ��֮Ӧ�ò��ϴ�ʱ��	�����౨�?��
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_ID);	//FTP�ϴ���ʱ��(������)//"FTP_UL_TOTALTIME_NID"	FLOAT(126),
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_TotalTime_NID);//FTP�ϴ���ʱ��(��������)	//"FTP_UL_TOTALTIME_ID"		FLOAT(126),
//	//FTP�ϴ�ҵ��֮ÿRBƽ���ϴ���(�ϴ�ʱ���ڵ��ȵ�����PRB������)�����౨�?��
//	SQL_AppendUInt(strSQL, m_ullFTP_UL_PRB_ID);//ÿRBƽ���ϴ���(������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(������)"FTP_UL_PRB_ID"             NUMBER(19,0),
//	SQL_AppendUInt(strSQL, m_ullFTP_UL_PRB_NID);//ÿRBƽ���ϴ���(��������)(bit/RB):�ϴ�ʱ���ڵ��ȵ�����PRB������(��������)"FTP_UL_PRB_NID"            NUMBER(19,0),
//	//FTP�ϴ�ҵ��֮��ԵPDCP����������
//	SQL_AppendFlt(strSQL, m_dbPDCP_UL_Edge_Throught_ID);	//PDCP_UL_Edge_Throught_ID	
//	SQL_AppendFlt(strSQL, m_dbPDCP_UL_Edge_Throught_NID);	//PDCP_UL_Edge_Throught_NID	
//	//FTP�ϴ�ҵ��֮��ԵӦ�ò�����������
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_Edge_Throught_ID);	//FTP_UL_Edge_Throught_ID
//	SQL_AppendFlt(strSQL, m_dbFTP_UL_Edge_Throught_NID);	//FTP_UL_Edge_Throught_NID
//	//FTP�ϴ�ҵ��֮PDCP���е�������ռ��
//	SQL_AppendUInt(strSQL, m_ulPDCP_UL_LowThroughput_Sum);//PDCP_UL_LowThroughput_Sum(��ʱ����PDCP�������������)
//	SQL_AppendUInt(strSQL, m_ulPDCP_UL_TotalThroughput_Sum);//PDCP_UL_TotalThroughput_Sum(����ʱ����PDCP�������ܲ����)
//	//FTP�ϴ�ҵ��֮Ӧ�ò����е�������ռ��	
//	SQL_AppendUInt(strSQL, m_ulFTP_UL_LowThroughput_Sum);//FTP_UL_LowThroughput_Sum(Ӧ�ò�������������)
//	SQL_AppendUInt(strSQL, m_ulFTP_UL_TotalThroughput_Sum);//FTP_UL_TotalThroughput_Sum(Ӧ�ò��������ܲ����)
//	//FTP�ϴ�ҵ��֮�����˲ʱ�������(kbps)
//	SQL_AppendFlt(strSQL, m_dbUL_MaxSPeed);//UL_MaxSPeed
//	//HTTP���ҵ��
//	SQL_AppendUInt(strSQL, m_ulHTTP_LoginRequestNum);//HTTP_LoginRequestNum	
//	SQL_AppendUInt(strSQL, m_ulHTTP_LoginSuccNum);//HTTP_LoginSuccNum	
//	SQL_AppendUInt(strSQL, m_ulHTTP_OnloadOverNum);//HTTP_OnloadOverNum
//	SQL_AppendFlt(strSQL, m_dbHTTP_LoginTotalDelay);//HTTP_LoginTotalDelay(��¼ʱ�Ӻ�(s))
//	SQL_AppendFlt(strSQL, m_dbHTTP_BrowseTotalTime);//HTTP_BrowseTotalTime(���ʱ����(s))
//	SQL_AppendFlt(strSQL, m_dbHTTP_DL_Data);//HTTP_DL_Data(���������)	
//	//HTTP����ҵ��
//	SQL_AppendUInt(strSQL, m_ulHTTP_DL_RequestNum);//HTTP_DL_RequestNum	
//	SQL_AppendUInt(strSQL, m_ulHTTP_DL_SuccNum);//HTTP_DL_SuccNum		
//	SQL_AppendUInt(strSQL, m_ulHTTP_DL_DropNum);//HTTP_DL_DropNum
//	SQL_AppendFlt(strSQL, m_dbHTTP_DownloadData_ID);//HTTP_DownloadData_ID(Ӧ�ò���������(������)(KB))	
//	SQL_AppendFlt(strSQL, m_dbHTTP_DownloadData_NID);//HTTP_DownloadData_NID(Ӧ�ò���������(��������)(KB))
//	SQL_AppendFlt(strSQL, m_dbHTTP_DownloadTime_ID);//HTTP_DownloadTime_ID(Ӧ�ò�����ʱ��(������)(s))	
//	SQL_AppendFlt(strSQL, m_dbHTTP_DownloadTime_NID);//HTTP_DownloadTime_NID(Ӧ�ò�����ʱ��(��������)(s))
//	//��ý��ҵ��
//	SQL_AppendUInt(strSQL, m_ulStreamRequestNum);//StreamRequestNum	
//	SQL_AppendUInt(strSQL, m_ulStreamSuccNum);//StreamSuccNum
//	SQL_AppendFlt(strSQL, m_dbStreamOnloadDelay);//StreamOnloadDelay(����ʱ�Ӻ�(s))
//	SQL_AppendFlt(strSQL, m_dbStreamTimes);		//��ý��ʱ��(s)
//	SQL_AppendFlt(strSQL, m_dbStreamPauseTime);//StreamPauseTime	
//	SQL_AppendFlt(strSQL, m_dbStreamPlayTotalTime);//StreamPlayTotalTime(��ý�岥����ʱ����(s))
//	SQL_AppendUInt(strSQL, m_ulStreamPlayPauseNum);//StreamPlayPauseNum
//	SQL_AppendFlt(strSQL, m_dbStreamDownloadData_NID);//StreamDownloadData_NID(���������)	//δ����
//	SQL_AppendFlt(strSQL, m_dbStreamDownloadTime_NID);//StreamDownloadTime_NID(����ʱ��)		//δ����
//	SQL_AppendFlt(strSQL, m_dbStreamOnloadData);//StreamOnloadData(C_StreamRealPlay��ĵ�һ���������)
//	SQL_AppendFlt(strSQL, m_dbStreamOnloadTime);//StreamOnloadTime(C_StreamRealPlay��S_APPServiceConnect��ʱ��)
//	//�ʼ�����ҵ��
//	SQL_AppendUInt(strSQL, 0);//MailSendRequestNum		//δ����	
//	SQL_AppendUInt(strSQL, 0);//MailSendSuccNum			//δ����	
//	SQL_AppendFlt(strSQL, 0);//MailSendDelay(ʱ�Ӻ�(s))	//δ����
//	SQL_AppendFlt(strSQL, 0);//MailUploadData			//δ����
//	SQL_AppendFlt(strSQL, 0);//MailUploadTime			//δ����
//
//	//�����౨��	//16
//	SQL_AppendFlt(strSQL, m_dbRSRP_Sum);			//ƽ��RSRP(dBm):RSRP�ܺ�
//	SQL_AppendFlt(strSQL, m_dbRSRP_Edge);			//��ԵRSRP(dBm):RSRP�����CDF(�ۻ���ʷֲ�)5%��Ӧ��ֵ
//	SQL_AppendUInt(strSQL, m_ulRSRP_Meet110Num);	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR > -3dB
//	SQL_AppendUInt(strSQL, m_ulRSRP_Meet103Num);	//LTE�����������:�����������Ķ���ΪRSRP>-103dBm , ��SINR > -4dB
//	SQL_AppendUInt(strSQL, m_ulRSRP_Meet101Num);	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR > -5dB
//
//	SQL_AppendFlt(strSQL, m_dbLTETestDistance);	//TESTLOG_ITEM�������и��ֶ�(DISTANCE:��λ��)	�����౨�?��
//	SQL_AppendFlt(strSQL, m_dbTDSTestDistance);	//TDSTestDistance
//	SQL_AppendFlt(strSQL, m_dbGSMTestDistance);	//GSMTestDistance
//	SQL_AppendFlt(strSQL, m_dbLTEOutNetworkDistance);//LTEOutNetworkDistance
//
//	SQL_AppendFlt(strSQL, m_dbOutNetworkTime);//OutNetworkTime
//	SQL_AppendFlt(strSQL, m_dbTDLTestTime);//TDLTestTime
//	SQL_AppendFlt(strSQL, m_dbTDSTestTime);//TDSTestTime
//	SQL_AppendFlt(strSQL, m_dbGSMTestTime);//GSMTestTime
//	SQL_AppendFlt(strSQL, m_dbLTEWeakCoverDistance);//LTEWeakCoverDistance	LTE�������������:����10��70%�Ĳ����·������RSRP<-105dBm,��CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
//	SQL_AppendFlt(strSQL, m_dbLTENoneCoverDistance/*m_dbLTENoneCoverDistance*/);//LTENoneCoverDistance LTE�����޸������:����10��70%�Ĳ����·������RSRP<-115dBm,CRS-RSRPΪȡR0 CRS(��/��R1 CRS)RE�����ŵ����Ʋ������������R1����������R1 RSRP�����ͼ��㣬��RSRPȡMAX(R0,R1)
//	SQL_AppendFlt(strSQL, 0);//LTEHighTxpowerDistance UE�߹��ʷ������:UE��PUSCH�ŵ����书�ʳ���10��70%�����>16dBm������·��
//
//	//�����౨��	//25
//	SQL_AppendFlt(strSQL, m_dbSINR_Sum);			//SINR(dB)�ܺ�,Ϊ�˻�ȡƽ��SINR
//	SQL_AppendFlt(strSQL, m_dbSINR_Edge);			//��ԵSINR(dB):SINR�����CDF(�ۼƸ��ʷֲ�)5%��Ӧ��ֵ
//	SQL_AppendUInt(strSQL, m_ulSINR_3_3_Num);		//TBD SINR>-3����:Ϊ������ռ��
//	SQL_AppendUInt(strSQL, m_ulSINR_0_0_Num);		//TBD SINR>0����:Ϊ������ռ��
//
//	//RSRQ���ֲ�ͳ��
//	SQL_AppendFlt(strSQL, m_dbRSRQ_Sum);			//RSRQ(dB)�ܺ�
//	SQL_AppendUInt(strSQL, m_ulRSRQ_196_175_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_175_155_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_155_135_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_135_115_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_115_95_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_95_75_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_75_55_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_55_35_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRQ_35_30_Num);
//
//	SQL_AppendFlt(strSQL, m_dbLowSINRDistance);//double m_dbLowSINRDistance;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-1dB������·��
//	SQL_AppendFlt(strSQL, m_dbLow3SINRDistance);//double m_dbLow3SINRDistance;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-3dB������·��
//	//PDSCH BLERƽ��ֵ
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TotalErrorTB);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_TotalTB);
//	//���г�ʼHARQ�ش�����
//	SQL_AppendUInt(strSQL, m_ulPDSCH_first_rx_success_cnt);
//	SQL_AppendUInt(strSQL, m_ulPDSCH_multi_retrans_success_cnt);
//
//	SQL_AppendUInt(strSQL, m_ulOverCoverMeetNum);		//(�ص����Ƕ�>=3�Ĳ����)
//	SQL_AppendFlt(strSQL, m_dbOverCoverDistance);		//(�ص����Ƕ�>=3�����)
//	SQL_AppendUInt(strSQL, m_ulOverCoverMeet4Num);		//(�ص����Ƕ�>=4�Ĳ����)
//	SQL_AppendFlt(strSQL, m_dbOverCover4Distance);		//(�����ص����Ƕ�>=4�����)
//	SQL_AppendUInt(strSQL, m_ulSamplingPoint_Num);		//SamplingPoint_Num(�ܲ������)
//
//	//�����౨��	//153
//	SQL_AppendUInt(strSQL, m_ulSubFrame_DL_TotalNum);	//���ȸ�UE��������֡���ܺ�
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
//	//���Ʒ�ʽ�ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_64QAM_Num);	//��������0���Ʒ�ʽ64QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_16QAM_Num);	//��������0���Ʒ�ʽ16QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code0_QPSK_Num);	//��������0���Ʒ�ʽQPSK
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_64QAM_Num);	//��������1���Ʒ�ʽ64QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_16QAM_Num);	//��������1���Ʒ�ʽ16QAM
//	SQL_AppendUInt(strSQL, m_ulDL_Code1_QPSK_Num);	//��������1���Ʒ�ʽQPSK
//
//	SQL_AppendUInt(strSQL, m_ulSubFrame_UL_TotalNum);	//���ȸ�UE��������֡���ܺ�
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
//	//���Ʒ�ʽ�ֲ�ͳ��
//	SQL_AppendUInt(strSQL, m_ulUL_64QAM_Num);		//���е��Ʒ�ʽ64QAM
//	SQL_AppendUInt(strSQL, m_ulUL_16QAM_Num);		//���е��Ʒ�ʽ16QAM
//	SQL_AppendUInt(strSQL, m_ulUL_QPSK_Num);		//���е��Ʒ�ʽQPSK
//
//	SQL_AppendUInt(strSQL, m_ulRank1_ReportNum);	//RI=1�ϱ�����
//	SQL_AppendUInt(strSQL, m_ulRank2_ReportNum);	//RI=2�ϱ�����
//
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
//	//�ƶ��౨��	//33
//	SQL_AppendUInt(strSQL, m_ulLTE_LTE_Handover_Start_NUM);	//�����л����Դ���:Handover Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulLTE_LTE_Handover_Success_NUM);//�����л��ɹ�����:Handover Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbLTE_LTE_Handover_Total_Delay);//�����л�ʱ�Ӻ�(s):Handover Start�¼���Handover Success�¼���ʱ���ܺ�
//	SQL_AppendUInt(strSQL, m_ulLTE_intraHandover_Start_NUM);//LTEͬƵ�л����Դ��� Intrafreq Handover Start�¼�
//	SQL_AppendUInt(strSQL, m_ulLTE_intraHandover_Success_NUM);//LTEͬƵ�л��ɹ����� Intrafreq Handover Success�¼�
//	SQL_AppendFlt(strSQL, m_abLTE_intraHandover_Total_Delay);//LTEͬƵ�л�ʱ�Ӻ�(s)Intrafreq Handover Start�¼���Intrafreq Handover Success�¼���ʱ���ܺ�
//	SQL_AppendUInt(strSQL, m_ulLTE_interHandover_Start_NUM);//LTE��Ƶ�л����Դ���	Interfreq Handover Start�¼�
//	SQL_AppendUInt(strSQL, m_ulLTE_interHandover_Success_NUM);//LTE��Ƶ�л��ɹ�����	Interfreq Handover Success�¼�
//	SQL_AppendFlt(strSQL, m_abLTE_interHandover_Total_Delay);//LTE��Ƶ�л�ʱ�Ӻ�(s)Interfreq Handover Start�¼���Interfreq Handover Success�¼���ʱ���ܺ�
//
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_Resel_Start_NUM);//LTE-TD��ѡ����:TDSCDMA from LTE Resel Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_Resel_Success_NUM);//LTE-TD��ѡ�ɹ�����:TDSCDMA from LTE Resel Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbLTE_TD_Resel_Total_Delay);//LTE-TD��ѡʱ�Ӻ�(s):TDSCDMA from LTE Resel Start�¼���TDSCDMA from LTE Resel Success�¼���ʱ���ܺ�
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_Resel_Start_NUM);//TD-LTE��ѡ����:TDSCDMA to LTE Resel Start�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulTD_LTE_Resel_Success_NUM);//TD-LTE��ѡ�ɹ�����:TDSCDMA to LTE Resel Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbTD_LTE_Resel_Total_Delay);//TD-LTE��ѡʱ�Ӻ�(s):TDSCDMA to LTE Resel Start�¼���TDSCDMA to LTE Resel Success�¼���ʱ���ܺ�
//
//	SQL_AppendUInt(strSQL, 0);//TDL-GSM��ѡ���Դ���
//	SQL_AppendUInt(strSQL, 0);//TDL-GSM��ѡ�ɹ�����
//	SQL_AppendFlt(strSQL, 0);//TDL-GSM��ѡʱ��(s)
//	SQL_AppendUInt(strSQL, 0);//GSM-TDL��ѡ���Դ���
//	SQL_AppendUInt(strSQL, 0);//GSM-TDL��ѡ�ɹ�����
//	SQL_AppendFlt(strSQL, 0);//GSM-TDL��ѡʱ��(s)
//
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_RD_Start_NUM);//TDL-TDS�ض����Դ��� LTE To TDSCDMA Redirection Start
//	SQL_AppendUInt(strSQL, m_ulLTE_TD_RD_Success_NUM);//TDL-TDS�ض���ɹ�����	LTE To TDSCDMA Redirection End
//	SQL_AppendFlt(strSQL, m_abLTE_TD_RD_Total_Delay);//TDL-TDS�ض���ʱ�Ӻ�LTE To TDSCDMA Redirection Start��LTE To TDSCDMA Redirection End�¼�ʱ���ܺ�
//	SQL_AppendUInt(strSQL, 0);//TDL-GSM�ض����Դ���	
//	SQL_AppendUInt(strSQL, 0);//TDL-GSM�ض���ɹ�����
//	SQL_AppendFlt(strSQL, 0);//TDL-GSM�ض���ƽ��ʱ��(s)
//	SQL_AppendUInt(strSQL, 0);//TDS-TDL�ض����Դ���
//	SQL_AppendUInt(strSQL, 0);//TDS-TDL�ض���ɹ�����	
//	SQL_AppendFlt(strSQL, 0);//TDS-TDL�ض���ʱ��
//
//	SQL_AppendUInt(strSQL, m_ulTAU_Request_NUM);//TA���³��Դ���:TAU Request�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulTAU_Success_NUM);//TA���³ɹ�����:TAU Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbTAU_Total_Delay);//TA����ʱ�Ӻ�(s):(TAU Success-TAU Request)��ʱ���ܺ�
//
//	//�����౨��	//9
//	//Attachͳ��
//	SQL_AppendUInt(strSQL, m_ulEPS_Attach_Request_NUM);	//Attch���Դ���:EPS Attach Request�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulEPS_Attach_Success_NUM);	//Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbEPS_Attach_Total_Delay);	//Attachʱ�Ӻ�(s):EPS Attach Request�¼���EPS Attach Success�¼���ʱ���ܺ�
//	//Serviceͳ��
//	SQL_AppendUInt(strSQL, m_ulSERVICE_Request_NUM);	//Service�������:SERVICE REQUEST�¼��ϱ�����
//	SQL_AppendUInt(strSQL, m_ulSERVICE_Success_NUM);	//Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
//	SQL_AppendFlt(strSQL, m_dbSERVICE_Total_Delay);		//Service����ʱ�Ӻ�(s):SERVICE REQUEST�¼���SERVICE SUCCESS�¼���ʱ���ܺ�
//	SQL_AppendFlt(strSQL, m_dbLTE_Band_D_Time);//L_Band_D_Time	
//	SQL_AppendFlt(strSQL, m_dbLTE_Band_E_Time);//L_Band_E_Time	
//	SQL_AppendFlt(strSQL, m_dbLTE_Band_F_Time);//L_Band_F_Time
//
//	//Ӧ�ò�FTP���ʷֶ�ռ��ͳ��		//23
//	//Ӧ�ò���������(��������)
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_0_1M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_1_2M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_2_4M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_4_5M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_5_8M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_8_10M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_10_12M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_12_15M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_15_20M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_20_25M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_25_30M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_30_35M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_35_40M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_DL_Speed_40_NM_Num);
//	//Ӧ�ò��ϴ�����
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_0_256K_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_256K_1M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_1_3p5M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_3p5_6M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_6_9M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_9_12M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_12_15M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_15_20M_Num);
//	SQL_AppendUInt(strSQL, m_ulFtp_UL_Speed_20_NM_Num);
//
//	//���縲����ֶ�ռ��	//14
//	SQL_AppendUInt(strSQL, m_ulRSRP_141_110_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRP_110_105_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRP_105_100_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRP_100_95_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRP_95_85_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRP_85_75_Num);
//	SQL_AppendUInt(strSQL, m_ulRSRP_75_40_Num);
//
//	SQL_AppendUInt(strSQL, m_ulSINR_50_3_Num);
//	SQL_AppendUInt(strSQL, m_ulSINR_3_0_Num);
//	SQL_AppendUInt(strSQL, m_ulSINR_0_3_Num);
//	SQL_AppendUInt(strSQL, m_ulSINR_3_6_Num);
//	SQL_AppendUInt(strSQL, m_ulSINR_6_9_Num);
//	SQL_AppendUInt(strSQL, m_ulSINR_9_15_Num);
//	SQL_AppendUInt(strSQL, m_ulSINR_15_50_Num);
//
//	//ͣ������	//7��
//	//SQL_AppendUInt(strSQL, 0);	//TestTime(����ʱ��:UTCʱ�����ֵ)
//	//SQL_AppendUInt(strSQL, 0);	//ParkBeginTime(UTCʱ�����ֵ)	
//	//SQL_AppendUInt(strSQL, 0);	//ParkEndTime(UTCʱ�����ֵ)		
//	//SQL_AppendFlt(strSQL, 0);	//ParkBeginLng	
//	//SQL_AppendFlt(strSQL, 0);	//ParkBeginLat	
//	//SQL_AppendFlt(strSQL, 0);	//ParkEndLng	
//	//SQL_AppendFlt(strSQL, 0);	//ParkEndLat
//
//	strSQL.TrimRight(_T(", "));
//	strSQL.AppendFormat(_T(" )"));
//
//	return strSQL;
//}

void CLogInfo_LTE_Attach::InitPara()
{
	m_strTableName = "";

	RecSeqNo = -1;						//��¼���к�, ȫ��ֵΨһ,����

	m_dbPHY_Throughput_DL_Sum_ID = 0;
	m_dbPHY_Throughput_DL_Sum_NID = 0;
	m_dbPHY_Throughput_UL_Sum_ID = 0;
	m_dbPHY_Throughput_UL_Sum_NID = 0;
	m_ulPHY_Throughput_DL_Num_ID = 0;
	m_ulPHY_Throughput_DL_Num_NID = 0;
	m_ulPHY_Throughput_UL_Num_ID = 0;
	m_ulPHY_Throughput_UL_Num_NID = 0;

	m_ulFtp_DL_TDL_Request_Num = 0;
	m_ulFtp_DL_TDS_Request_Num = 0;
	m_ulFtp_DL_GSM_Request_Num = 0;
	m_ulFtp_DL_TDL_Success_Num = 0;
	m_ulFtp_DL_TDS_Success_Num = 0;
	m_ulFtp_DL_GSM_Success_Num = 0;
	m_ulFtp_DL_TDL_Drop_Num = 0;
	m_ulFtp_DL_TDS_Drop_Num = 0;
	m_ulFtp_DL_GSM_Drop_Num = 0;

	m_ulFtp_UL_TDL_Request_Num = 0;
	m_ulFtp_UL_TDS_Request_Num = 0;
	m_ulFtp_UL_GSM_Request_Num = 0;
	m_ulFtp_UL_TDL_Success_Num = 0;
	m_ulFtp_UL_TDS_Success_Num = 0;
	m_ulFtp_UL_GSM_Success_Num = 0;
	m_ulFtp_UL_TDL_Drop_Num = 0;	
	m_ulFtp_UL_TDS_Drop_Num = 0;	
	m_ulFtp_UL_GSM_Drop_Num = 0;

	//�������Ӧ�ò���������(��������)
	m_ulFtp_DL_Speed_0_1M_Num = 0;	//[0,1M)
	m_ulFtp_DL_Speed_1_2M_Num = 0;	//[1,2M)
	m_ulFtp_DL_Speed_2_4M_Num = 0;	//[2,4M)
	m_ulFtp_DL_Speed_4_5M_Num = 0;	//[4,5M)
	m_ulFtp_DL_Speed_5_8M_Num = 0;	//[5,8M)
	m_ulFtp_DL_Speed_8_10M_Num = 0;	//[8,10M)
	m_ulFtp_DL_Speed_10_12M_Num = 0;	//[10,12M)
	m_ulFtp_DL_Speed_12_15M_Num = 0;	//[12,15M)
	m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
	m_ulFtp_DL_Speed_20_25M_Num = 0;	//[20,25M)
	m_ulFtp_DL_Speed_25_30M_Num = 0;	//[25,30M)
	m_ulFtp_DL_Speed_30_35M_Num = 0;	//[30,35M)
	m_ulFtp_DL_Speed_35_40M_Num = 0;	//[35,40M)
	m_ulFtp_DL_Speed_40_NM_Num = 0;	//���ڵ���40M

	//�������Ӧ�ò��ϴ�����(��������)
	m_ulFtp_UL_Speed_0_256K_Num = 0;		//(0,256K)
	m_ulFtp_UL_Speed_256K_1M_Num = 0;	//[256K,1M)
	m_ulFtp_UL_Speed_1_3p5M_Num = 0;		//[1,3.5M)
	m_ulFtp_UL_Speed_3p5_6M_Num = 0;		//[3.5,6M)
	m_ulFtp_UL_Speed_6_9M_Num = 0;		//[6,9M)
	m_ulFtp_UL_Speed_9_12M_Num = 0;		//[9,12M)
	m_ulFtp_UL_Speed_12_15M_Num = 0;		//[12,15M)
	m_ulFtp_UL_Speed_15_20M_Num = 0;		//[15,20M)
	m_ulFtp_UL_Speed_20_NM_Num = 0;		//���ڵ���20M

	//Attachͳ��
	m_ulEPS_Attach_Request_NUM = 0;	//Attch���Դ���:EPS Attach Request�¼��ϱ�����
	m_ulEPS_Attach_Success_NUM = 0;	//Attach�ɹ�����:EPS Attach Success�¼��ϱ�����
	m_dbEPS_Attach_Total_Delay = 0;	//Attachʱ�Ӻ�(s):EPS Attach Request�¼���EPS Attach Success�¼���ʱ���ܺ�

	//Serviceͳ��
	m_ulSERVICE_Request_NUM = 0;	//Service�������:SERVICE REQUEST�¼��ϱ�����
	m_ulSERVICE_Success_NUM = 0;	//Service����ɹ�����:SERVICE SUCCESS�¼��ϱ�����
	m_dbSERVICE_Total_Delay = 0;	//Service����ʱ�Ӻ�(s):SERVICE REQUEST�¼���SERVICE SUCCESS�¼���ʱ���ܺ�

	//�ƶ���
	m_ulLTE_LTE_Handover_Start_NUM = 0;
	m_ulLTE_LTE_Handover_Success_NUM = 0;
	m_dbLTE_LTE_Handover_Total_Delay = 0;
	m_ulLTE_intraHandover_Start_NUM = 0;
	m_ulLTE_intraHandover_Success_NUM = 0;
	m_abLTE_intraHandover_Total_Delay = 0;
	m_ulLTE_interHandover_Start_NUM = 0;
	m_ulLTE_interHandover_Success_NUM = 0;
	m_abLTE_interHandover_Total_Delay = 0;

	m_ulLTE_TD_Resel_Start_NUM = 0;
	m_ulLTE_TD_Resel_Success_NUM = 0;
	m_dbLTE_TD_Resel_Total_Delay = 0;

	//LTE-TDSCDMA��ѡ
	m_ulTD_LTE_Resel_Start_NUM = 0;
	m_ulTD_LTE_Resel_Success_NUM = 0;
	m_dbTD_LTE_Resel_Total_Delay = 0;

	//TDSCDMA-LTE��ѡ
	m_ulLTE_TD_RD_Start_NUM = 0;
	m_ulLTE_TD_RD_Success_NUM = 0;
	m_abLTE_TD_RD_Total_Delay = 0;

	//TAU LTE���������ͳ��
	m_ulTAU_Request_NUM = 0;
	m_ulTAU_Success_NUM = 0;
	m_dbTAU_Total_Delay = 0;

	//������
	m_ulSubFrame_DL_TotalNum = 0;	
	m_ullFTP_DL_PRB_NID = 0;			
	m_ullFTP_DL_PRB_ID = 0;			
	m_dbFTP_DL_TotalTime_LTE_NID = 0;
	m_dbFTP_DL_TotalTime_LTE_ID = 0;	
	m_dbFTP_DL_TotalTime_NID = 0;	
	m_dbFTP_DL_TotalTime_ID = 0;		

	m_ulSubFrame_DL_Count = 0;	//��
	m_ulSubFrame_UL_Count = 0;	//��

	m_ulDL_Code0_MCS0_Num = 0;
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

	m_ulDL_Code1_MCS0_Num = 0;
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

	m_ulWideband_Code0_CQI0_Num = 0;	
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

	m_ulWideband_Code1_CQI0_Num = 0;	
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

	m_ulDL_Code0_QPSK_Num = 0;
	m_ulDL_Code0_16QAM_Num = 0;
	m_ulDL_Code0_64QAM_Num = 0;
	m_ulDL_Code1_QPSK_Num = 0;
	m_ulDL_Code1_16QAM_Num = 0;
	m_ulDL_Code1_64QAM_Num = 0;

	m_ulSubFrame_UL_TotalNum = 0;	
	m_ullFTP_UL_PRB_NID = 0;			
	m_ullFTP_UL_PRB_ID = 0;			
	m_dbFTP_UL_TotalTime_LTE_NID = 0;
	m_dbFTP_UL_TotalTime_LTE_ID = 0;	
	m_dbFTP_UL_TotalTime_NID = 0;	
	m_dbFTP_UL_TotalTime_ID = 0;		

	m_ulUL_MCS0_Num = 0;	
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

	m_ulUL_QPSK_Num = 0;	
	m_ulUL_16QAM_Num = 0;
	m_ulUL_64QAM_Num = 0;

	m_ulRank1_ReportNum = 0;
	m_ulRank2_ReportNum = 0;

	m_dbSingleFlowTime = 0;	
	m_dbDoubleFlowTime = 0;	
	m_dbSingleFlowData = 0;	
	m_dbDoubleFlowData = 0;	

	m_dbTM1ModeTime = 0;
	m_dbTM2ModeTime = 0;
	m_dbTM3ModeTime = 0;
	m_dbTM4ModeTime = 0;
	m_dbTM5ModeTime = 0;
	m_dbTM6ModeTime = 0;
	m_dbTM7ModeTime = 0;
	m_dbTM8ModeTime = 0;

	// [5/20/2015 liangdongxu]
	// ���縲����ֶ�ռ��
	//RSRP���ֲ�ͳ��
	m_ulRSRP_141_110_Num = 0;	//RSRP[-141,-110)
	m_ulRSRP_110_105_Num = 0;	//RSRP[-110,-105)
	m_ulRSRP_105_100_Num = 0;	//RSRP[-105,-100)
	m_ulRSRP_100_95_Num = 0;	//RSRP[-100,-95)
	m_ulRSRP_95_85_Num = 0;		//RSRP[-95,-85)
	m_ulRSRP_85_75_Num = 0;		//RSRP[-85,-75)
	m_ulRSRP_75_40_Num = 0;		//RSRP[-75,-40)

	//SINR���ֲ�ͳ��
	m_ulSINR_50_3_Num = 0;	//SINR[-50,-3)
	m_ulSINR_3_0_Num = 0;	//SINR[-3,0)
	m_ulSINR_0_3_Num = 0;	//SINR[0,3)
	m_ulSINR_3_6_Num = 0;	//SINR[3,6)
	m_ulSINR_6_9_Num = 0;	//SINR[6,9)
	m_ulSINR_9_15_Num = 0;	//SINR[9,15)
	m_ulSINR_15_50_Num = 0;	//SINR[15,50]


	//////////////////////////////////////////////////////////////////////////
	//������
	m_dbSINR_Sum = 0;		//SINR(dB)�ܺ�,Ϊ�˻�ȡƽ��SINR
	m_dbSINR_Edge = 0;		//��ԵSINR(dB):SINR�����CDF(�ۼƸ��ʷֲ�)5%��Ӧ��ֵ
	m_ulSINR_3_3_Num = 0;	//TBD SINR>-3����:Ϊ������ռ��
	m_ulSINR_0_0_Num = 0;	//TBD SINR>0����:Ϊ������ռ��

	//ƽ��RSRQ
	m_dbRSRQ_Sum = 0;		//RSRQ(dB)�ܺ�
	//RSRQ���ֲ�ͳ��
	m_ulRSRQ_196_175_Num = 0;	//RSRQ[-19.6,-17.5)
	m_ulRSRQ_175_155_Num = 0;	//RSRQ[-17.5,-15.5)
	m_ulRSRQ_155_135_Num = 0;	//RSRQ[-15.5,-13.5)
	m_ulRSRQ_135_115_Num = 0;	//RSRQ[-13.5,-11.5)
	m_ulRSRQ_115_95_Num = 0;		//RSRQ[-11.5,-9.5)
	m_ulRSRQ_95_75_Num = 0;		//RSRQ[-9.5,-7.5)
	m_ulRSRQ_75_55_Num = 0;		//RSRQ[-7.5,-5.5)
	m_ulRSRQ_55_35_Num = 0;		//RSRQ[-5.5,-3.5)
	m_ulRSRQ_35_30_Num = 0;		//RSRQ[-3.5,-3]

	//PDSCH BLERƽ��ֵ
	m_ulFtp_DL_TotalTB = 0;				//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��
	m_ulFtp_DL_TotalErrorTB = 0;			//��·������BLER=�����ܴ���TB��/�����ܴ���TB��:�����ܴ���TB��

	//���г�ʼHARQ�ش�����
	m_ulPDSCH_first_rx_success_cnt = 0;		//(���ν��մ���)
	m_ulPDSCH_multi_retrans_success_cnt = 0;	//(���ش�����)

	//�ص����Ƕ����ֲ�ͳ��
	//m_ulOverCoverDegree_0_Num = 0;		//0
	//m_ulOverCoverDegree_1_Num = 0;		//1
	//m_ulOverCoverDegree_2_Num = 0;		//2
	//m_ulOverCoverDegree_3_Num = 0;		//3
	//m_ulOverCoverDegree_4_Num = 0;		//4
	//m_ulOverCoverDegree_5_Num = 0;		//5
	//m_ulOverCoverDegree_5_10_Num = 0;	//(5,10]
	//m_ulOverCoverDegree_10_N_Num = 0;	// >10

	//�ص�������(�ص����Ƕ�>=3)(%)
	m_ulOverCoverMeetNum = 0;		//(�ص����Ƕ�>=3�Ĳ����)
	//�ص��������ռ��(�ص����Ƕ�>=3)(%)
	m_dbOverCoverDistance = 0;		//�ص����Ƕ�>=3�Ĳ������:�ص����Ƕ�:·��������ǿС��RSRP�Ĳ�ֵ����-6dB�ĵ�ƽ������ ͬʱ��ǿС��RSRP>=-105dB
	//�ص�������(�ص����Ƕ�>=4)(%)	
	m_ulOverCoverMeet4Num = 0;		//(�ص����Ƕ�>=4�Ĳ����)
	//�ص��������ռ��(�ص����Ƕ�>=4)(%)
	m_dbOverCover4Distance = 0;		//(�����ص����Ƕ�>=4�����)

	//(�ܲ������)	???ʲôָ��
	//SamplingPoint_Num;
	m_dbLTEOutNetworkDistance = 0;

	//////////////////////////////////////////////////////////////////////////
	//������
	m_dbRSRP_Sum = 0;		//ƽ��RSRP(dBm):RSRP�ܺ�
	m_dbRSRP_Edge = 0;		//��ԵRSRP(dBm):RSRP�����CDF(�ۻ���ʷֲ�)5%��Ӧ��ֵ
	m_ulRSRP_Meet110Num = 0;	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR > -3dB
	m_ulRSRP_Meet103Num = 0;	//LTE�����������:�����������Ķ���ΪRSRP>-103dBm , ��SINR > -4dB
	m_ulRSRP_Meet101Num = 0;	//LTE�����������:�����������Ķ���ΪRSRP>-110dBm , ��SINR > -5dB

	m_dbStreamTimes = 0;
	m_ulStreamPlayPauseNum = 0;
	//����SINR�ʲ����ռ��(SINRС��-1)(%)  ����SINR�ʲ����ռ��(SINRС��-3)(%)
	m_dbLowSINRDistance = 0;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-1dB������·��
	m_dbLow3SINRDistance = 0;	//����SINR�ʲ����:����10����70%�Ĳ����CRS-SINR<-3dB������·��
}

//void CLogInfo_LTE_Attach::AddTroubleRoad(CLogInfo_TD_TroubleRoad* TroubleRoad)
//{
	//if(NULL != TroubleRoad)
	//	m_TroubleRoadList.push_back(TroubleRoad);
//}