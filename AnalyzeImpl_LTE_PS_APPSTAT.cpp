//#include "StdAfx.h"
//#include "AnalyzeImpl_LTE.h"
#include "AnalyzeImpl_LTE_PS_APPSTAT.h"


CAnalyzeImpl_LTE_PS_APPSTAT::CAnalyzeImpl_LTE_PS_APPSTAT(void)
{
	m_ucRAT = RAT_NULL;
	m_ucOldRAT = RAT_NULL;

	//���浱ǰftp״̬��0δ��ҵ��1�����У�2�ϴ���
	m_ucFtpState = 0;

	//����������
	m_dLongitude = ANA_IMPL_INVALID_LOCATION;
	m_dLatitude = ANA_IMPL_INVALID_LOCATION;

	//�����������ʱ��
	m_dbFTP_DL_StartTime = ANA_IMPL_INVALID_TIME;
	m_dbFTP_DL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
	m_dbFTP_DL_LastTime_LTE = 0;
	m_dbFTP_DL_LastTime_HSPA = 0;
	m_dbFTP_DL_LastTime_R4 = 0;

	//��������ϴ�ʱ��
	m_dbFTP_UL_StartTime = ANA_IMPL_INVALID_TIME;
	m_dbFTP_UL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
	m_dbFTP_UL_LastTime_LTE = 0;
	m_dbFTP_UL_LastTime_HSPA = 0;
	m_dbFTP_UL_LastTime_R4 = 0;

	//�������������
	m_dbDownLoadData_All = 0;
	m_dbDownLoadData_LTE = 0;
	m_dbDownLoadData_HSPA = 0;
	m_dbDownLoadData_R4 = 0;
	m_bIsDownSuccessForStatisticsDownLoadData = false;
	m_bIsDownSuccessForLTEHSPAR4 = false;

	//��������ϴ���
	m_dbUpLoadData_All = 0;
	m_dbUpLoadData_LTE = 0;
	m_dbUpLoadData_HSPA = 0;
	m_dbUpLoadData_R4 = 0;

	//���ȵ�PRB��
	m_ullFTP_DL_PRB_Num = 0;
	m_ullFTP_UL_PRB_Num = 0;

	//Ӧ�ò���������(��������)
	m_ulFtp_DL_Speed_0_0M_Num = 0;		//����0
	m_ulFtp_DL_Speed_0_1M_Num = 0;		//(0,1M)
	m_ulFtp_DL_Speed_1_2M_Num = 0;		//[1,2M)
	m_ulFtp_DL_Speed_2_3M_Num = 0;		//[2,3M)
	m_ulFtp_DL_Speed_3_4M_Num = 0;		//[3,4M)
	m_ulFtp_DL_Speed_4_5M_Num = 0;		//[4,5M)
	m_ulFtp_DL_Speed_5_10M_Num = 0;		//[5,10M)
	m_ulFtp_DL_Speed_10_15M_Num = 0;	//[10,15M)
	m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
	m_ulFtp_DL_Speed_20_30M_Num = 0;	//[20,30M)
	m_ulFtp_DL_Speed_30_50M_Num = 0;	//[30,50M)
	m_ulFtp_DL_Speed_50_NM_Num = 0;		//���ڵ���50M

	//Ӧ�ò��ϴ�����(��������)
	m_ulFtp_UL_Speed_0_0K_Num = 0;		//����0
	m_ulFtp_UL_Speed_0_256K_Num = 0;	//(0,256K)
	m_ulFtp_UL_Speed_256K_512K_Num = 0;	//[256K,512K)
	m_ulFtp_UL_Speed_512K_1M_Num = 0;	//[512K,1M)
	m_ulFtp_UL_Speed_1_2M_Num = 0;		//[1,2M)
	m_ulFtp_UL_Speed_2_3M_Num = 0;		//[2,3M)
	m_ulFtp_UL_Speed_3_4M_Num = 0;		//[3,4M)
	m_ulFtp_UL_Speed_4_5M_Num = 0;		//[4,5M)
	m_ulFtp_UL_Speed_5_10M_Num = 0;		//[5,10M)
	m_ulFtp_UL_Speed_10_15M_Num = 0;	//[10,15M)
	m_ulFtp_UL_Speed_15_20M_Num = 0;	//[15,20M)
	m_ulFtp_UL_Speed_20_30M_Num = 0;	//[20,30M)
	m_ulFtp_UL_Speed_30_50M_Num = 0;	//[30,50M)

	//�������pdcp���������

	m_dbPDCP_DL_Longitude = ANA_IMPL_INVALID_LOCATION;
	m_dbPDCP_DL_Latitude = ANA_IMPL_INVALID_LOCATION;
	m_vIR_DL_PDCP_Vetcor.clear(); //intermediate result
	m_vDL_PDCP_Vetcor_NID.clear();
	m_vDL_PDCP_Vetcor_ID.clear();
	m_dbPDCP_UL_Longitude = ANA_IMPL_INVALID_LOCATION;
	m_dbPDCP_UL_Latitude = ANA_IMPL_INVALID_LOCATION;
	m_vIR_UL_PDCP_Vetcor.clear(); //intermediate result
	m_vUL_PDCP_Vetcor_NID.clear();
	m_vUL_PDCP_Vetcor_ID.clear();
}

CAnalyzeImpl_LTE_PS_APPSTAT::~CAnalyzeImpl_LTE_PS_APPSTAT(void)
{

}

int CAnalyzeImpl_LTE_PS_APPSTAT::DoAnalyzeOneData(DTANASTATDATAITEM& dtitem)
{
	int nResult = 0;

	 //todo ע���Ƿ�������Ƿ�ֵ

	//��¼��̣�DATASTAT�������ټ�����
	//�������������ھ�γ�ȸ��µĵط������ԭ��������ֻͳ�Ʊ�ǩ�ڵ�
	double dbDis = CalcDistanceLTE(fLon_new, fLat_new, m_dLongitude, m_dLatitude);
	m_dLongitude = fLon_new;
	m_dLatitude = fLat_new;
	if (dbDis < 100)
	{
		m_pLogInfoBase->Distance += dbDis;
	}

	//PRINTFEX(SOURCE_LOCATION, CMC_LOG_NAME, "zxh %f, %f, %f!!", dbDis, fLon_new, fLat_new);

	//��ȡ��ʽ  
	/*
	0��LTE 	RAT_LTE
	1��TD	RAT_TD_HSPA
	2��GSM	RAT_GSM
	3��TD   RAT_TD_R4,
	4��     RAT_NULL = 0xff
	*/
	if(dtitem.ucRAT != INVALIDVALUE_UINT8)
	{
		m_ucRAT = dtitem.ucRAT - 6; //������ϱ�����6 7 8 ��Ӧ 0 1 2
	}
	if (dtitem.ulDlBLER != INVALIDVALUE_UINT32)
	{
		if (dtitem.ulDlBLER == 0)
		{
			assert(m_ucRAT == RAT_TD_HSPA || m_ucRAT == RAT_TD_R4);
			m_ucRAT = RAT_TD_HSPA;
		}
		else if (dtitem.ulDlBLER == 1)
		{
			assert(m_ucRAT == RAT_TD_HSPA || m_ucRAT == RAT_TD_R4);
			m_ucRAT = RAT_TD_R4;
		}
	}

	//��ȡ���ҵ�������
	//ֻ��¼���һ�ε���ݣ�����Ǵ洢������
	if(IE_LTE_APPBYTESRECEIVED_LTE == dtitem.uiIENumber)
	{
		m_dbDownLoadData_LTE = dtitem.llIEValue2/1000.0;
	}
	if(IE_LTE_APPBYTESRECEIVED_HSDPA == dtitem.uiIENumber)
	{
		m_dbDownLoadData_HSPA = dtitem.llIEValue2/1000.0;	
	}
	if(IE_LTE_APPBYTESRECEIVED_R4 == dtitem.uiIENumber)
	{
		m_dbDownLoadData_R4 = dtitem.llIEValue2/1000.0;
	}
	if (m_bIsDownSuccessForLTEHSPAR4)
	{
		m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_LTE_NID += m_dbDownLoadData_LTE;
		m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_HSPA_NID += m_dbDownLoadData_HSPA;
		m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_R4_NID +=	m_dbDownLoadData_R4;
		m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_LTE_ID += m_dbDownLoadData_LTE;
		m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_HSPA_ID += m_dbDownLoadData_HSPA;
		m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_R4_ID +=	m_dbDownLoadData_R4;

		m_dbDownLoadData_LTE = 0;
		m_dbDownLoadData_HSPA = 0;
		m_dbDownLoadData_R4 = 0;
		m_bIsDownSuccessForLTEHSPAR4 = false;
	}
	if(IE_LTE_APPBYTESRECEIVED_TOTAL == dtitem.uiIENumber)
	{
		m_dbDownLoadData_All = dtitem.llIEValue2/1000.0;

		if (m_bIsDownSuccessForStatisticsDownLoadData)
		{
			m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_NID += m_dbDownLoadData_All;
			m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_ID += m_dbDownLoadData_All;
			m_dbDownLoadData_All = 0;
			m_bIsDownSuccessForStatisticsDownLoadData = false;
			m_bIsDownSuccessForLTEHSPAR4 = true;
		}
	}

	if(IE_LTE_APPBYTESEND_TOTAL == dtitem.uiIENumber)
	{
		m_dbUpLoadData_All = dtitem.llIEValue2/1000.0;
	}
	if(IE_LTE_APPBYTESSEND_LTE == dtitem.uiIENumber)
	{
		m_dbUpLoadData_LTE = dtitem.llIEValue2/1000.0;
	}
	if(IE_LTE_APPBYTESSEND_HSUPA == dtitem.uiIENumber)
	{
		m_dbUpLoadData_HSPA = dtitem.llIEValue2/1000.0;	
	}
	if(IE_LTE_APPBYTESSEND_R4 == dtitem.uiIENumber)
	{
		m_dbUpLoadData_R4 = dtitem.llIEValue2/1000.0;
	}

	//ͳ�Ƶ��ȵ�PRB��
	if (dtitem.uiDLPRBNUM != INVALIDVALUE_UINT32)
	{
		m_ullFTP_DL_PRB_Num += dtitem.uiDLPRBNUM;

		m_pLogInfoLTEPS->m_ullFTP_DL_PRB_Sum += dtitem.uiDLPRBNUM;
		m_pLogInfoLTEPS->m_ullFTP_DL_PRB_Count++;
	}
	if (dtitem.uiULPRBNUM != INVALIDVALUE_UINT32)
	{
		m_ullFTP_UL_PRB_Num += dtitem.uiULPRBNUM;

		m_pLogInfoLTEPS->m_ullFTP_UL_PRB_Sum += dtitem.uiULPRBNUM;
		m_pLogInfoLTEPS->m_ullFTP_UL_PRB_Count++;
	}

	//ͳ����·������BLER
	if (dtitem.ulTestPointSN != INVALIDVALUE_INT32)
	{
		m_pLogInfoLTEPS->m_ulFtp_DL_TotalTB += dtitem.ulTestPointSN;
	}
	if (dtitem.ulLastAltitude != INVALIDVALUE_INT32)
	{
		m_pLogInfoLTEPS->m_ulFtp_DL_TotalErrorTB += dtitem.ulLastAltitude;
	}

	//ͳ��Ӧ�ò�����(��������)
	if (IE_LTE_APP_CURRENTTHROUGHPUT_DL == dtitem.uiIENumber)
	{
		double dbTemp = (dtitem.llIEValue2/1000.0)/1024.0;  //��λM
		if (dbTemp > -0.0000001 && dbTemp < 0.0000001)
		{
			m_ulFtp_DL_Speed_0_0M_Num++;
		}
		else if (dbTemp > 0 && dbTemp < 1)
		{
			m_ulFtp_DL_Speed_0_1M_Num++;
		}
		else if (dbTemp >= 1 && dbTemp < 2)
		{
			m_ulFtp_DL_Speed_1_2M_Num++;
		}
		else if (dbTemp >= 2 && dbTemp < 3)
		{
			m_ulFtp_DL_Speed_2_3M_Num++;
		}
		else if (dbTemp >= 3 && dbTemp < 4)
		{
			m_ulFtp_DL_Speed_3_4M_Num++;
		}
		else if (dbTemp >= 4 && dbTemp < 5)
		{
			m_ulFtp_DL_Speed_4_5M_Num++;
		}
		else if (dbTemp >= 5 && dbTemp < 10)
		{
			m_ulFtp_DL_Speed_5_10M_Num++;
		}
		else if (dbTemp >= 10 && dbTemp < 15)
		{
			m_ulFtp_DL_Speed_10_15M_Num++;
		}
		else if (dbTemp >= 15 && dbTemp < 20)
		{
			m_ulFtp_DL_Speed_15_20M_Num++;
		}
		else if (dbTemp >= 20 && dbTemp < 30)
		{
			m_ulFtp_DL_Speed_20_30M_Num++;
		}
		else if (dbTemp >= 30 && dbTemp < 50)
		{
			m_ulFtp_DL_Speed_30_50M_Num++;
		}
		else if (dbTemp >= 50)
		{
			m_ulFtp_DL_Speed_50_NM_Num++;
		}
	}
	if (IE_LTE_APP_CURRENTTHROUGHPUT_UL == dtitem.uiIENumber)
	{
		double dbTemp = dtitem.llIEValue2/1000.0;	//��λK
		if (dbTemp > -0.0000001 && dbTemp < 0.0000001)
		{
			m_ulFtp_UL_Speed_0_0K_Num++;
		}
		else if (dbTemp > 0 && dbTemp < 256)
		{
			m_ulFtp_UL_Speed_0_256K_Num++;
		}
		else if (dbTemp >= 256 && dbTemp < 512)
		{
			m_ulFtp_UL_Speed_256K_512K_Num++;
		}
		else if (dbTemp >= 512 && dbTemp < 1024)
		{
			m_ulFtp_UL_Speed_512K_1M_Num++;
		}
		else if (dbTemp >= 1024 && dbTemp < 2048)
		{
			m_ulFtp_UL_Speed_1_2M_Num++;
		}
		else if (dbTemp >= 2048 && dbTemp < 3072)
		{
			m_ulFtp_UL_Speed_2_3M_Num++;
		}
		else if (dbTemp >= 3072 && dbTemp < 4096)
		{
			m_ulFtp_UL_Speed_3_4M_Num++;
		}
		else if (dbTemp >= 4096 && dbTemp < 5120)
		{
			m_ulFtp_UL_Speed_4_5M_Num++;
		}
		else if (dbTemp >= 5120 && dbTemp < 10240)
		{
			m_ulFtp_UL_Speed_5_10M_Num++;
		}
		else if (dbTemp >= 10240 && dbTemp < 15*1024)
		{
			m_ulFtp_UL_Speed_10_15M_Num++;
		}
		else if (dbTemp >= 15*1024 && dbTemp < 20*1024)
		{
			m_ulFtp_UL_Speed_15_20M_Num++;
		}
		else if (dbTemp >= 20*1024 && dbTemp < 30*1024)
		{
			m_ulFtp_UL_Speed_20_30M_Num++;
		}
		else if (dbTemp >= 30*1024 && dbTemp < 50*1024)
		{
			m_ulFtp_UL_Speed_30_50M_Num++;
		}
	}

	//ͳ����·��ƽ�������� ����
	if(IE_LTE_RLC_THROUGHPUT_DL == dtitem.uiIENumber) //FTP����ִ��ʱ����,RLC Throughput DL��ƽ��ֵ
	{
		m_pLogInfoLTEPS->m_dbFtp_DL_RLCThroughputDL_Sum += dtitem.llIEValue2/1000.0;
		m_pLogInfoLTEPS->m_ulFtp_DL_RLCThroughputDL_Num++;
	}

	//ͳ����·��ƽ�������� ����
	if(IE_LTE_RLC_THROUGHPUT_UL == dtitem.uiIENumber) //FTP�ϴ�ִ��ʱ����,RLC Throughput UL��ƽ��ֵ
	{
		m_pLogInfoLTEPS->m_dbFtp_UL_RLCThroughputUL_Sum += dtitem.llIEValue2/1000.0;
		m_pLogInfoLTEPS->m_ulFtp_UL_RLCThroughputUL_Num++;
	}

	//����pdcp��������� ����
	if(IE_LTE_PDCP_THROUGHPUT_DL == dtitem.uiIENumber)
	{
		double dbTempRdcpThroughtDL = dtitem.llIEValue2/1000.0;
		m_vIR_DL_PDCP_Vetcor.push_back(dbTempRdcpThroughtDL);//��λΪKbps
		m_pLogInfoLTEPS->m_dbPDCP_DL_Throughput_Sum_ID += dbTempRdcpThroughtDL;
		m_pLogInfoLTEPS->m_ulPDCP_DL_Throughput_Num_ID++;

		double dbDis = CalcDistanceLTE(fLon_new, fLat_new, m_dbPDCP_DL_Longitude, m_dbPDCP_DL_Latitude);
		m_dbPDCP_DL_Longitude = fLon_new;
		m_dbPDCP_DL_Latitude = fLat_new;
		if (dbDis < 100)
		{
			m_pLogInfoLTEPS->m_dbFtp_DL_PDCPThroughtDistance += dbDis;
		}
	}

	//����pdcp��������� ����
	if(IE_LTE_PDCP_THROUGHPUT_UL == dtitem.uiIENumber)
	{
		double dbTempRdcpThroughtUL = dtitem.llIEValue2/1000.0;
		m_vIR_UL_PDCP_Vetcor.push_back(dbTempRdcpThroughtUL);//��λΪKbps
		m_pLogInfoLTEPS->m_dbPDCP_UL_Throughput_Sum_ID += dbTempRdcpThroughtUL;
		m_pLogInfoLTEPS->m_ulPDCP_UL_Throughput_Num_ID++;

		double dbDis = CalcDistanceLTE(fLon_new, fLat_new, m_dbPDCP_UL_Longitude, m_dbPDCP_UL_Latitude);
		m_dbPDCP_UL_Longitude = fLon_new;
		m_dbPDCP_UL_Latitude = fLat_new;
		if (dbDis < 100)
		{
			m_pLogInfoLTEPS->m_dbFtp_UL_PDCPThroughtDistance += dbDis;
		}
	}

	UINT32 unEventID = dtitem.ulEventID;
	if(unEventID != INVALIDVALUE_UINT32)
	{
		switch(unEventID)
		{
		case FTP_START_DOWN_EVENT:
			{
				m_ucFtpState = 1;

				//ͳ������ʱ��
				m_dbFTP_DL_StartTime = dTime_new;
				m_dbFTP_DL_RatSwitchStartTime = dTime_new;
				m_dbFTP_DL_LastTime_LTE = 0;
				m_dbFTP_DL_LastTime_HSPA = 0;
				m_dbFTP_DL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ�����������
				m_dbDownLoadData_All = 0;
				m_dbDownLoadData_LTE = 0;
				m_dbDownLoadData_HSPA = 0;
				m_dbDownLoadData_R4 = 0;
				m_bIsDownSuccessForStatisticsDownLoadData = false;
				m_bIsDownSuccessForLTEHSPAR4 = false;

				//ͳ�����س��Դ���
				m_pLogInfoLTEPS->m_ulFtp_DL_Attempt_Num += 1;

				//ͳ�Ƶ��ȵ�PRB��
				m_ullFTP_DL_PRB_Num = 0;

				//Ӧ�ò���������(��������)
				m_ulFtp_DL_Speed_0_0M_Num = 0;		//����0
				m_ulFtp_DL_Speed_0_1M_Num = 0;		//(0,1M)
				m_ulFtp_DL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_DL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_DL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_DL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_DL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_DL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_DL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_DL_Speed_30_50M_Num = 0;	//[30,50M)
				m_ulFtp_DL_Speed_50_NM_Num = 0;		//���ڵ���50M

				//�������pdcp���������
				m_dbPDCP_DL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_DL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_DL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_SUCCESS_DOWN_EVENT:
			{
				m_ucFtpState = 0;

				//ͳ������ʱ��
				switch(m_ucRAT)
				{
				case RAT_LTE:
					{
						m_dbFTP_DL_LastTime_LTE += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_HSPA:
					{
						m_dbFTP_DL_LastTime_HSPA += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_R4:
					{
						m_dbFTP_DL_LastTime_R4 += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				default:
					{
						m_dbFTP_DL_LastTime_LTE += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				}
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_LTE_NID += m_dbFTP_DL_LastTime_LTE;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_HSPA_NID += m_dbFTP_DL_LastTime_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_R4_NID += m_dbFTP_DL_LastTime_R4;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_LTE_ID += m_dbFTP_DL_LastTime_LTE;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_HSPA_ID += m_dbFTP_DL_LastTime_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_R4_ID += m_dbFTP_DL_LastTime_R4;
				
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_NID += GetTimeLast(m_dbFTP_DL_StartTime, dTime_new);
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_ID += GetTimeLast(m_dbFTP_DL_StartTime, dTime_new);

				m_dbFTP_DL_StartTime = ANA_IMPL_INVALID_TIME; 
				m_dbFTP_DL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
				m_dbFTP_DL_LastTime_LTE = 0;
				m_dbFTP_DL_LastTime_HSPA = 0;
				m_dbFTP_DL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ�����������
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_NID += m_dbDownLoadData_All;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_LTE_NID += m_dbDownLoadData_LTE;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_HSPA_NID += m_dbDownLoadData_HSPA;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_R4_NID +=	m_dbDownLoadData_R4;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_ID += m_dbDownLoadData_All;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_LTE_ID += m_dbDownLoadData_LTE;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_HSPA_ID += m_dbDownLoadData_HSPA;
				//m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_R4_ID +=	m_dbDownLoadData_R4;

				//m_dbDownLoadData_All = 0;
				m_bIsDownSuccessForStatisticsDownLoadData = true;
				//m_dbDownLoadData_LTE = 0;
				//m_dbDownLoadData_HSPA = 0;
				//m_dbDownLoadData_R4 = 0;

				//ͳ�����سɹ�����
				m_pLogInfoLTEPS->m_ulFtp_DL_Success_Num += 1;

				//ͳ�Ƶ��ȵ�PRB��
				m_pLogInfoLTEPS->m_ullFTP_DL_PRB_NID += m_ullFTP_DL_PRB_Num;
				m_pLogInfoLTEPS->m_ullFTP_DL_PRB_ID += m_ullFTP_DL_PRB_Num;
				m_ullFTP_DL_PRB_Num = 0;

				//Ӧ�ò���������(��������)
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_0_0M_Num += m_ulFtp_DL_Speed_0_0M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_0_1M_Num += m_ulFtp_DL_Speed_0_1M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_1_2M_Num += m_ulFtp_DL_Speed_1_2M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_2_3M_Num += m_ulFtp_DL_Speed_2_3M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_3_4M_Num += m_ulFtp_DL_Speed_3_4M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_4_5M_Num += m_ulFtp_DL_Speed_4_5M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_5_10M_Num += m_ulFtp_DL_Speed_5_10M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_10_15M_Num += m_ulFtp_DL_Speed_10_15M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_15_20M_Num += m_ulFtp_DL_Speed_15_20M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_20_30M_Num += m_ulFtp_DL_Speed_20_30M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_30_50M_Num += m_ulFtp_DL_Speed_30_50M_Num;
				m_pLogInfoLTEPS->m_ulFtp_DL_Speed_50_NM_Num += m_ulFtp_DL_Speed_50_NM_Num;

				m_ulFtp_DL_Speed_0_0M_Num = 0;		//����0
				m_ulFtp_DL_Speed_0_1M_Num = 0;		//(0,1M)
				m_ulFtp_DL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_DL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_DL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_DL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_DL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_DL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_DL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_DL_Speed_30_50M_Num = 0;	//[30,50M)
				m_ulFtp_DL_Speed_50_NM_Num = 0;		//���ڵ���50M

				//�������pdcp���������
				m_vDL_PDCP_Vetcor_NID.insert(m_vDL_PDCP_Vetcor_NID.end(), m_vIR_DL_PDCP_Vetcor.begin(), m_vIR_DL_PDCP_Vetcor.end());
				m_vDL_PDCP_Vetcor_ID.insert(m_vDL_PDCP_Vetcor_ID.end(), m_vIR_DL_PDCP_Vetcor.begin(), m_vIR_DL_PDCP_Vetcor.end());
				m_dbPDCP_DL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_DL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_DL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_FAILURE_DOWN_EVENT:
			{
				m_ucFtpState = 0;

				//ͳ������ʧ�ܴ���
				switch(m_ucRAT)
				{
				case RAT_LTE:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Fail_LTE_Num += 1;
						break;
					}
				case RAT_TD_HSPA:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Fail_HSPA_Num += 1;
						break;
					}
				case RAT_TD_R4:
					{

						m_pLogInfoLTEPS->m_ulFtp_DL_Fail_R4_Num += 1;
						break;
					}
				default:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Fail_LTE_Num += 1;
						break;
					}
				}

				//ͳ������ʱ��
				m_dbFTP_DL_StartTime = ANA_IMPL_INVALID_TIME; 
				m_dbFTP_DL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
				m_dbFTP_DL_LastTime_LTE = 0;
				m_dbFTP_DL_LastTime_HSPA = 0;
				m_dbFTP_DL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ�����������
				m_dbDownLoadData_All = 0;
				m_dbDownLoadData_LTE = 0;
				m_dbDownLoadData_HSPA = 0;
				m_dbDownLoadData_R4 = 0;

				//ͳ�Ƶ��ȵ�PRB��
				m_ullFTP_DL_PRB_Num = 0;

				//Ӧ�ò���������(��������)
				m_ulFtp_DL_Speed_0_0M_Num = 0;		//����0
				m_ulFtp_DL_Speed_0_1M_Num = 0;		//(0,1M)
				m_ulFtp_DL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_DL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_DL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_DL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_DL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_DL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_DL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_DL_Speed_30_50M_Num = 0;	//[30,50M)
				m_ulFtp_DL_Speed_50_NM_Num = 0;		//���ڵ���50M

				//�������pdcp���������
				m_dbPDCP_DL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_DL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_DL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_DROP_DOWN_EVENT:
			{
				m_ucFtpState = 0;

				//ͳ�����ص��ߴ��������ʱ��
				switch(m_ucRAT)
				{
				case RAT_LTE:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Drop_LTE_Num += 1;

						m_dbFTP_DL_LastTime_LTE += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_HSPA:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Drop_HSPA_Num += 1;

						m_dbFTP_DL_LastTime_HSPA += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_R4:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Drop_R4_Num += 1;

						m_dbFTP_DL_LastTime_R4 += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				default:
					{
						m_pLogInfoLTEPS->m_ulFtp_DL_Drop_LTE_Num += 1;

						m_dbFTP_DL_LastTime_LTE += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
						break;
					}
				}

				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_LTE_ID += m_dbFTP_DL_LastTime_LTE;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_HSPA_ID += m_dbFTP_DL_LastTime_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_R4_ID += m_dbFTP_DL_LastTime_R4;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalTime_ID += GetTimeLast(m_dbFTP_DL_StartTime, dTime_new);

				m_dbFTP_DL_StartTime = ANA_IMPL_INVALID_TIME; 
				m_dbFTP_DL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
				m_dbFTP_DL_LastTime_LTE = 0;
				m_dbFTP_DL_LastTime_HSPA = 0;
				m_dbFTP_DL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ�����������
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_ID += m_dbDownLoadData_All;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_LTE_ID += m_dbDownLoadData_LTE;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_HSPA_ID += m_dbDownLoadData_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_DL_TotalData_R4_ID +=	m_dbDownLoadData_R4;

				m_dbDownLoadData_All = 0;
				m_dbDownLoadData_LTE = 0;
				m_dbDownLoadData_HSPA = 0;
				m_dbDownLoadData_R4 = 0;

				//ͳ�Ƶ��ȵ�PRB��
				m_pLogInfoLTEPS->m_ullFTP_DL_PRB_ID += m_ullFTP_DL_PRB_Num;
				m_ullFTP_DL_PRB_Num = 0;

				//Ӧ�ò���������(��������)
				m_ulFtp_DL_Speed_0_0M_Num = 0;		//����0
				m_ulFtp_DL_Speed_0_1M_Num = 0;		//(0,1M)
				m_ulFtp_DL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_DL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_DL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_DL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_DL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_DL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_DL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_DL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_DL_Speed_30_50M_Num = 0;	//[30,50M)
				m_ulFtp_DL_Speed_50_NM_Num = 0;		//���ڵ���50M

				//�������pdcp���������
				m_vDL_PDCP_Vetcor_ID.insert(m_vDL_PDCP_Vetcor_ID.end(), m_vIR_DL_PDCP_Vetcor.begin(), m_vIR_DL_PDCP_Vetcor.end());
				m_dbPDCP_DL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_DL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_DL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_START_UP_EVENT:
			{
				m_ucFtpState = 2;

				//ͳ���ϴ�ʱ��
				m_dbFTP_UL_StartTime = dTime_new; 
				m_dbFTP_UL_RatSwitchStartTime = dTime_new;
				m_dbFTP_UL_LastTime_LTE = 0;
				m_dbFTP_UL_LastTime_HSPA = 0;
				m_dbFTP_UL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ���ϴ������
				m_dbUpLoadData_All = 0;
				m_dbUpLoadData_LTE = 0;
				m_dbUpLoadData_HSPA = 0;
				m_dbUpLoadData_R4 = 0;

				//ͳ���ϴ����Դ���
				m_pLogInfoLTEPS->m_ulFtp_UL_Attempt_Num += 1;

				//ͳ�Ƶ��ȵ�PRB��
				m_ullFTP_UL_PRB_Num = 0;

				//Ӧ�ò��ϴ�����(��������)
				m_ulFtp_UL_Speed_0_0K_Num = 0;		//����0
				m_ulFtp_UL_Speed_0_256K_Num = 0;	//(0,256K)
				m_ulFtp_UL_Speed_256K_512K_Num = 0;	//[256K,512K)
				m_ulFtp_UL_Speed_512K_1M_Num = 0;	//[512K,1M)
				m_ulFtp_UL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_UL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_UL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_UL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_UL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_UL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_UL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_UL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_UL_Speed_30_50M_Num = 0;	//[30,50M)

				//�������pdcp���������
				m_dbPDCP_UL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_UL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_UL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_SUCCESS_UP_EVENT:
			{
				m_ucFtpState = 0;

				//ͳ���ϴ�ʱ��
				switch(m_ucRAT)
				{
				case RAT_LTE:
					{
						m_dbFTP_UL_LastTime_LTE += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_HSPA:
					{
						m_dbFTP_UL_LastTime_HSPA += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_R4:
					{
						m_dbFTP_UL_LastTime_R4 += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				default:
					{
						m_dbFTP_UL_LastTime_LTE += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				}
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_LTE_NID += m_dbFTP_UL_LastTime_LTE;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_HSPA_NID += m_dbFTP_UL_LastTime_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_R4_NID += m_dbFTP_UL_LastTime_R4;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_LTE_ID += m_dbFTP_UL_LastTime_LTE;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_HSPA_ID += m_dbFTP_UL_LastTime_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_R4_ID += m_dbFTP_UL_LastTime_R4;

				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_NID += GetTimeLast(m_dbFTP_UL_StartTime, dTime_new);
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_ID += GetTimeLast(m_dbFTP_UL_StartTime, dTime_new);

				m_dbFTP_UL_StartTime = ANA_IMPL_INVALID_TIME; 
				m_dbFTP_UL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
				m_dbFTP_UL_LastTime_LTE = 0;
				m_dbFTP_UL_LastTime_HSPA = 0;
				m_dbFTP_UL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ���ϴ������
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_NID += m_dbUpLoadData_All;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_LTE_NID += m_dbUpLoadData_LTE;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_HSPA_NID += m_dbUpLoadData_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_R4_NID +=	m_dbUpLoadData_R4;

				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_ID += m_dbUpLoadData_All;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_LTE_ID += m_dbUpLoadData_LTE;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_HSPA_ID += m_dbUpLoadData_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_R4_ID +=	m_dbUpLoadData_R4;

				m_dbUpLoadData_All = 0;
				m_dbUpLoadData_LTE = 0;
				m_dbUpLoadData_HSPA = 0;
				m_dbUpLoadData_R4 = 0;

				//ͳ���ϴ��ɹ�����
				m_pLogInfoLTEPS->m_ulFtp_UL_Success_Num += 1;

				//ͳ�Ƶ��ȵ�PRB��
				m_pLogInfoLTEPS->m_ullFTP_UL_PRB_NID += m_ullFTP_UL_PRB_Num;
				m_pLogInfoLTEPS->m_ullFTP_UL_PRB_ID += m_ullFTP_UL_PRB_Num;
				m_ullFTP_UL_PRB_Num = 0;

				//Ӧ�ò��ϴ�����(��������)
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_0_0K_Num += m_ulFtp_UL_Speed_0_0K_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_0_256K_Num += m_ulFtp_UL_Speed_0_256K_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_256K_512K_Num += m_ulFtp_UL_Speed_256K_512K_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_512K_1M_Num += m_ulFtp_UL_Speed_512K_1M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_1_2M_Num += m_ulFtp_UL_Speed_1_2M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_2_3M_Num += m_ulFtp_UL_Speed_2_3M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_3_4M_Num += m_ulFtp_UL_Speed_3_4M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_4_5M_Num += m_ulFtp_UL_Speed_4_5M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_5_10M_Num += m_ulFtp_UL_Speed_5_10M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_10_15M_Num += m_ulFtp_UL_Speed_10_15M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_15_20M_Num += m_ulFtp_UL_Speed_15_20M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_20_30M_Num += m_ulFtp_UL_Speed_20_30M_Num;
				m_pLogInfoLTEPS->m_ulFtp_UL_Speed_30_50M_Num += m_ulFtp_UL_Speed_30_50M_Num;

				m_ulFtp_UL_Speed_0_0K_Num = 0;		//����0
				m_ulFtp_UL_Speed_0_256K_Num = 0;	//(0,256K)
				m_ulFtp_UL_Speed_256K_512K_Num = 0;	//[256K,512K)
				m_ulFtp_UL_Speed_512K_1M_Num = 0;	//[512K,1M)
				m_ulFtp_UL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_UL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_UL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_UL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_UL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_UL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_UL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_UL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_UL_Speed_30_50M_Num = 0;	//[30,50M)

				//�������pdcp���������
				m_vUL_PDCP_Vetcor_NID.insert(m_vUL_PDCP_Vetcor_NID.end(), m_vIR_UL_PDCP_Vetcor.begin(), m_vIR_UL_PDCP_Vetcor.end());
				m_vUL_PDCP_Vetcor_ID.insert(m_vUL_PDCP_Vetcor_ID.end(), m_vIR_UL_PDCP_Vetcor.begin(), m_vIR_UL_PDCP_Vetcor.end());
				m_dbPDCP_UL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_UL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_UL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_FAILURE_UP_EVENT:
			{
				m_ucFtpState = 0;

				//ͳ���ϴ�ʧ�ܴ���
				switch(m_ucRAT)
				{
				case RAT_LTE:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Fail_LTE_Num += 1;
						break;
					}
				case RAT_TD_HSPA:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Fail_HSPA_Num += 1;
						break;
					}
				case RAT_TD_R4:
					{

						m_pLogInfoLTEPS->m_ulFtp_UL_Fail_R4_Num += 1;
						break;
					}
				default:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Fail_LTE_Num += 1;
						break;
					}
				}

				//ͳ���ϴ�ʱ��
				m_dbFTP_UL_StartTime = ANA_IMPL_INVALID_TIME; 
				m_dbFTP_UL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
				m_dbFTP_UL_LastTime_LTE = 0;
				m_dbFTP_UL_LastTime_HSPA = 0;
				m_dbFTP_UL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ���ϴ������
				m_dbUpLoadData_All = 0;
				m_dbUpLoadData_LTE = 0;
				m_dbUpLoadData_HSPA = 0;
				m_dbUpLoadData_R4 = 0;

				//ͳ�Ƶ��ȵ�PRB��
				m_ullFTP_UL_PRB_Num = 0;

				//Ӧ�ò��ϴ�����(��������)
				m_ulFtp_UL_Speed_0_0K_Num = 0;		//����0
				m_ulFtp_UL_Speed_0_256K_Num = 0;	//(0,256K)
				m_ulFtp_UL_Speed_256K_512K_Num = 0;	//[256K,512K)
				m_ulFtp_UL_Speed_512K_1M_Num = 0;	//[512K,1M)
				m_ulFtp_UL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_UL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_UL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_UL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_UL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_UL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_UL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_UL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_UL_Speed_30_50M_Num = 0;	//[30,50M)

				//�������pdcp���������
				m_dbPDCP_UL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_UL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_UL_PDCP_Vetcor.clear();

				break;
			}
		case FTP_DROP_UP_EVENT:
			{
				m_ucFtpState = 0;

				//ͳ���ϴ����ߴ�����ϴ�ʱ��
				switch(m_ucRAT)
				{
				case RAT_LTE:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Drop_LTE_Num += 1;

						m_dbFTP_UL_LastTime_LTE += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_HSPA:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Drop_HSPA_Num += 1;

						m_dbFTP_UL_LastTime_HSPA += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				case RAT_TD_R4:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Drop_R4_Num += 1;

						m_dbFTP_UL_LastTime_R4 += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				default:
					{
						m_pLogInfoLTEPS->m_ulFtp_UL_Drop_LTE_Num += 1;

						m_dbFTP_UL_LastTime_LTE += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
						break;
					}
				}

				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_LTE_ID += m_dbFTP_UL_LastTime_LTE;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_HSPA_ID += m_dbFTP_UL_LastTime_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_R4_ID += m_dbFTP_UL_LastTime_R4;

				m_pLogInfoLTEPS->m_dbFTP_UL_TotalTime_ID += GetTimeLast(m_dbFTP_UL_StartTime, dTime_new);

				m_dbFTP_UL_StartTime = ANA_IMPL_INVALID_TIME; 
				m_dbFTP_UL_RatSwitchStartTime = ANA_IMPL_INVALID_TIME;
				m_dbFTP_UL_LastTime_LTE = 0;
				m_dbFTP_UL_LastTime_HSPA = 0;
				m_dbFTP_UL_LastTime_R4 = 0;
				m_ucOldRAT = m_ucRAT;

				//ͳ���ϴ������
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_ID += m_dbUpLoadData_All;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_LTE_ID += m_dbUpLoadData_LTE;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_HSPA_ID += m_dbUpLoadData_HSPA;
				m_pLogInfoLTEPS->m_dbFTP_UL_TotalData_R4_ID +=	m_dbUpLoadData_R4;

				m_dbUpLoadData_All = 0;
				m_dbUpLoadData_LTE = 0;
				m_dbUpLoadData_HSPA = 0;
				m_dbUpLoadData_R4 = 0;

				//ͳ�Ƶ��ȵ�PRB��
				m_pLogInfoLTEPS->m_ullFTP_UL_PRB_ID += m_ullFTP_UL_PRB_Num;
				m_ullFTP_UL_PRB_Num = 0;

				//Ӧ�ò��ϴ�����(��������)
				m_ulFtp_UL_Speed_0_0K_Num = 0;		//����0
				m_ulFtp_UL_Speed_0_256K_Num = 0;	//(0,256K)
				m_ulFtp_UL_Speed_256K_512K_Num = 0;	//[256K,512K)
				m_ulFtp_UL_Speed_512K_1M_Num = 0;	//[512K,1M)
				m_ulFtp_UL_Speed_1_2M_Num = 0;		//[1,2M)
				m_ulFtp_UL_Speed_2_3M_Num = 0;		//[2,3M)
				m_ulFtp_UL_Speed_3_4M_Num = 0;		//[3,4M)
				m_ulFtp_UL_Speed_4_5M_Num = 0;		//[4,5M)
				m_ulFtp_UL_Speed_5_10M_Num = 0;		//[5,10M)
				m_ulFtp_UL_Speed_10_15M_Num = 0;	//[10,15M)
				m_ulFtp_UL_Speed_15_20M_Num = 0;	//[15,20M)
				m_ulFtp_UL_Speed_20_30M_Num = 0;	//[20,30M)
				m_ulFtp_UL_Speed_30_50M_Num = 0;	//[30,50M)

				//�������pdcp���������
				m_vUL_PDCP_Vetcor_ID.insert(m_vUL_PDCP_Vetcor_ID.end(), m_vIR_UL_PDCP_Vetcor.begin(), m_vIR_UL_PDCP_Vetcor.end());
				m_dbPDCP_UL_Longitude = ANA_IMPL_INVALID_LOCATION;
				m_dbPDCP_UL_Latitude = ANA_IMPL_INVALID_LOCATION;
				m_vIR_UL_PDCP_Vetcor.clear();

				break;
			}
		default:
			{
				break;
			}
		}
	}

	//if (m_ucFtpState != 0)
	//{
	//	double dbDis = CalcDistance(fLon_new, fLat_new, m_dLongitude, m_dLatitude);
	//	m_dLongitude = fLon_new;
	//	m_dLatitude = fLat_new;
	//	m_pLogInfoBase->Distance += dbDis;
	//}
	//else
	//{
	//	m_dLongitude = ANA_IMPL_INVALID_LOCATION;
	//	m_dLatitude = ANA_IMPL_INVALID_LOCATION;
	//}

	if (m_ucFtpState == 1) //������
	{
		//ͳ������ʱ��
		if(m_ucOldRAT != m_ucRAT)
		{
			switch(m_ucOldRAT)
			{
			case RAT_LTE:
				{
					m_dbFTP_DL_LastTime_LTE += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
					m_dbFTP_DL_RatSwitchStartTime = dTime_new;
					break;
				}
			case RAT_TD_HSPA:
				{
					m_dbFTP_DL_LastTime_HSPA += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
					m_dbFTP_DL_RatSwitchStartTime = dTime_new;
					break;
				}
			case RAT_TD_R4:
				{
					m_dbFTP_DL_LastTime_R4 += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
					m_dbFTP_DL_RatSwitchStartTime = dTime_new;
					break;
				}
			default:
				{
					m_dbFTP_DL_LastTime_LTE += GetTimeLast(m_dbFTP_DL_RatSwitchStartTime, dTime_new);
					m_dbFTP_DL_RatSwitchStartTime = dTime_new;
					break;
				}
			}

			m_ucOldRAT = m_ucRAT;
		}
	}
	else if (m_ucFtpState == 2) //�ϴ���
	{
		//ͳ���ϴ�ʱ��
		if(m_ucOldRAT != m_ucRAT)
		{
			switch(m_ucOldRAT)
			{
			case RAT_LTE:
				{
					m_dbFTP_UL_LastTime_LTE += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
					m_dbFTP_UL_RatSwitchStartTime = dTime_new;
					break;
				}
			case RAT_TD_HSPA:
				{
					m_dbFTP_UL_LastTime_HSPA += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
					m_dbFTP_UL_RatSwitchStartTime = dTime_new;
					break;
				}
			case RAT_TD_R4:
				{
					m_dbFTP_UL_LastTime_R4 += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
					m_dbFTP_UL_RatSwitchStartTime = dTime_new;
					break;
				}
			default:
				{
					m_dbFTP_UL_LastTime_LTE += GetTimeLast(m_dbFTP_UL_RatSwitchStartTime, dTime_new);
					m_dbFTP_UL_RatSwitchStartTime = dTime_new;
					break;
				}
			}

			m_ucOldRAT = m_ucRAT;
		}
	}

	return nResult;
}

int CAnalyzeImpl_LTE_PS_APPSTAT::DoConclusion()
{
	int nResult = 0;

	CAnalyzeImplBase::DoConclusion();	//������־����ʱ�䣬CAnalyzeImpl_LTE_PS_DATASTAT��������ˣ���Ϊ������Ķ���ָ��ͬһ��ǰ̨��

	m_pLogInfoLTEPS->m_dbFtp_DL_Edge_Throught_NID = CalcCdf(m_vDL_PDCP_Vetcor_NID, 150000);
	m_pLogInfoLTEPS->m_dbFtp_DL_Edge_Throught_ID = CalcCdf(m_vDL_PDCP_Vetcor_ID, 150000);
	m_pLogInfoLTEPS->m_dbFtp_UL_Edge_Throught_NID = CalcCdf(m_vUL_PDCP_Vetcor_NID, 80000);
	m_pLogInfoLTEPS->m_dbFtp_UL_Edge_Throught_ID = CalcCdf(m_vUL_PDCP_Vetcor_ID, 80000);

	return nResult;
}

int CAnalyzeImpl_LTE_PS_APPSTAT::DoAnalyzeImpl(DTANASTATDATAITEM& dtitem, int nCsOrPs)
{
	int nResult = 0;

	AnaUpdateLocation(dtitem);
	AnaUpdateTime(dtitem,nCsOrPs);
	//AnaUpdateUafcnAndCPI(dtitem);
	//AnaUpdateLACandCI(dtitem);

	if (nCsOrPs != 0)
	{
		//�麯�����ʵ��
		try
		{
			nResult = DoAnalyzeOneData(dtitem);
		}
		catch (...)
		{
		}
	}
	//else
	//{
	//	m_dLongitude = ANA_IMPL_INVALID_LOCATION;
	//	m_dLatitude = ANA_IMPL_INVALID_LOCATION;
	//}

	return nResult;
}