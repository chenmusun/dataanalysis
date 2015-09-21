//#include "StdAfx.h"
#include "LogInfo_LTE_CS_CSFB.h"

CLogInfo_LTE_CS_CSFB::CLogInfo_LTE_CS_CSFB(void)
{
	InitPara();
}


CLogInfo_LTE_CS_CSFB::~CLogInfo_LTE_CS_CSFB(void)
{

}

//CString CLogInfo_LTE_CS_CSFB::GetInsertSQL()
//{
//	CString strSQL = _T("");
//
//	strSQL.Format(_T("insert into %s values ( "), m_strTableName);
//
//	SQL_AppendULONGLONG(strSQL, RecSeqNo);    //��¼���к�, ȫ��ֵΨһ,����
///*	
//	SQL_AppendUInt(strSQL, m_ulCSFB_Start_NUM);		         //CSFB�Ժ�����
//	SQL_AppendUInt(strSQL, m_ulCSFB_End_NUM);				 //CSFB��ͨ����
//	SQL_AppendUInt(strSQL, m_ulCSFB_Success_NUM);			 //CSFB�ɹ�����
//															 
//	SQL_AppendUInt(strSQL, m_ulCSFB_Return_Start_NUM);		 //GSM-LTE���Դ���
//	SQL_AppendUInt(strSQL, m_ulCSFB_Return_End_NUM);		 //GSM-LTE�ɹ�����
//															 
//	SQL_AppendFlt(strSQL, m_dbCSFB_Call_Start_Total_Delay);	 //CSFB���н���ʱ�Ӻ�(s)
//															 
//	SQL_AppendUInt(strSQL, m_ulRRC_G2L_Resel_Start_NUM);	 //GSM2LTE��ѡ���Դ���
//	SQL_AppendUInt(strSQL, m_ulRRC_G2L_Resel_Succ_NUM);		 //GSM2LTE��ѡ�ɹ�����
//	SQL_AppendFlt(strSQL, m_dbG2L_Resel_Total_Delay);		 //GSM2LTE��ѡʱ�Ӻ�(s)
//															 
//	SQL_AppendUInt(strSQL, m_ulRRC_L2G_Resel_Start_NUM);	 //TE2GSM��ѡ���Դ���
//	SQL_AppendUInt(strSQL, m_ulRRC_L2G_Resel_Succ_NUM);		 //TE2GSM��ѡ�ɹ�����
//	SQL_AppendFlt(strSQL, m_dbL2G_Resel_Total_Delay);		 //TE2GSM��ѡʱ�Ӻ�(s)
//	
//	SQL_AppendUInt(strSQL, m_ulMOS_0_2_Num);	//[0,2)
//	SQL_AppendUInt(strSQL, m_ulMOS_2_22_Num);	//[2,2.2)
//	SQL_AppendUInt(strSQL, m_ulMOS_22_24_Num);	//[2.2,2.4)
//	SQL_AppendUInt(strSQL, m_ulMOS_24_26_Num);	//[2.4,2.6)
//	SQL_AppendUInt(strSQL, m_ulMOS_26_28_Num);	//[2.6,2.8)
//	SQL_AppendUInt(strSQL, m_ulMOS_28_30_Num);	//[2.8,3.0)
//	SQL_AppendUInt(strSQL, m_ulMOS_30_32_Num);	//[3.0,3.2)
//	SQL_AppendUInt(strSQL, m_ulMOS_32_34_Num);	//[3.2,3.4)
//	SQL_AppendUInt(strSQL, m_ulMOS_34_36_Num);	//[3.4,3.6)
//	SQL_AppendUInt(strSQL, m_ulMOS_36_38_Num);	//[3.6,3.8)
//	SQL_AppendUInt(strSQL, m_ulMOS_38_40_Num);	//[3.8,4.0)
//	SQL_AppendUInt(strSQL, m_ulMOS_40_50_Num);	//[4.0,5.0]   ---�������ֵ[4,5.1)���Ժ���5.0
//*/
//
//	SQL_AppendUInt(strSQL, m_ulCSFB_Start_NUM_MO);		//CSFB�Ժ��������У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Success_NUM_MO);		//CSFB LTE2GSM�ɹ��������У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Alerting_NUM_MO);		//CSFB����������У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Connect_NUM_MO);		//CSFB��ͨ�������У�
//
//	SQL_AppendUInt(strSQL, m_ulCSFB_Return_Start_NUM_MO);	//GSM-LTE���Դ������У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Return_End_NUM_MO);		//GSM-LTE�ɹ��������У�
//
//	SQL_AppendUInt(strSQL, m_ulCSFB_Drop_NUM_MO);		//CSFB���ߴ������У�
//
//	//--------------����----------------------------------------------
//	SQL_AppendUInt(strSQL, m_ulCSFB_Start_NUM_MT);		//CSFB�Ժ�����У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Success_NUM_MT);		//CSFB LTE2GSM�ɹ�����У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Alerting_NUM_MT);		//CSFB�������У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Connect_NUM_MT);		//CSFB��ͨ����У�
//
//	SQL_AppendUInt(strSQL, m_ulCSFB_Return_Start_NUM_MT);	//GSM-LTE���Դ���У�
//	SQL_AppendUInt(strSQL, m_ulCSFB_Return_End_NUM_MT);		//GSM-LTE�ɹ�����У�
//
//	SQL_AppendUInt(strSQL, m_ulCSFB_Drop_NUM_MT);		//CSFB���ߴ���У�
//
//	//----------------ʱ��----------------------------------------------------
//	SQL_AppendFlt(strSQL, m_dbCSFB_Call_Start_Total_Delay_MO);       //CSFB���н���ʱ�Ӻ�(s) �����У�
//	SQL_AppendFlt(strSQL, m_dbCSFB_Call_Start_Total_Delay_MT);       //CSFB���н���ʱ�Ӻ�(s) �����У�
//
//	SQL_AppendFlt(strSQL, m_dbL2G_Resel_Total_Delay_MO);                //LTE2GSM��ѡʱ�Ӻ�(s)�����У�
//	SQL_AppendFlt(strSQL, m_dbL2G_Resel_Total_Delay_MT);                //LTE2GSM��ѡʱ�Ӻ�(s)�����У�
//
//	SQL_AppendFlt(strSQL, m_dbG2L_Resel_Total_Delay_MO);                //GSM2LTE��ѡʱ�Ӻ�(s)�����У�
//	SQL_AppendFlt(strSQL, m_dbG2L_Resel_Total_Delay_MT);                //GSM2LTE��ѡʱ�Ӻ�(s)�����У�
//
//	SQL_AppendUInt(strSQL, m_ulMOS_0_2_Num);	//[0,2)
//	SQL_AppendUInt(strSQL, m_ulMOS_2_22_Num);	//[2,2.2)
//	SQL_AppendUInt(strSQL, m_ulMOS_22_24_Num);	//[2.2,2.4)
//	SQL_AppendUInt(strSQL, m_ulMOS_24_26_Num);	//[2.4,2.6)
//	SQL_AppendUInt(strSQL, m_ulMOS_26_28_Num);	//[2.6,2.8)
//	SQL_AppendUInt(strSQL, m_ulMOS_28_30_Num);	//[2.8,3.0)
//	SQL_AppendUInt(strSQL, m_ulMOS_30_32_Num);	//[3.0,3.2)
//	SQL_AppendUInt(strSQL, m_ulMOS_32_34_Num);	//[3.2,3.4)
//	SQL_AppendUInt(strSQL, m_ulMOS_34_36_Num);	//[3.4,3.6)
//	SQL_AppendUInt(strSQL, m_ulMOS_36_38_Num);	//[3.6,3.8)
//	SQL_AppendUInt(strSQL, m_ulMOS_38_40_Num);	//[3.8,4.0)
//	SQL_AppendUInt(strSQL, m_ulMOS_40_50_Num);	//[4.0,5.0]   ---�������ֵ[4,5.1)���Ժ���5.0
//
//	strSQL.TrimRight(_T(", "));
//	strSQL.AppendFormat(_T(" )"));
//
//	return strSQL;
//}

void CLogInfo_LTE_CS_CSFB::InitPara()
{
	m_strTableName = "";

	RecSeqNo = -1;						//��¼���к�, ȫ��ֵΨһ,����
	/*m_ulCSFB_Start_NUM = 0;				//CSFB�Ժ�����
	m_ulCSFB_End_NUM = 0;				//CSFB��ͨ����
	m_ulCSFB_Success_NUM = 0;			//CSFB�ɹ�����

	m_ulCSFB_Return_Start_NUM = 0;		//GSM-LTE���Դ���
	m_ulCSFB_Return_End_NUM = 0;		//GSM-LTE�ɹ�����

	m_dbCSFB_Call_Start_Total_Delay = 0;//CSFB���н���ʱ�Ӻ�(s)

	m_ulRRC_G2L_Resel_Start_NUM = 0;	//GSM2LTE��ѡ���Դ���
	m_ulRRC_G2L_Resel_Succ_NUM = 0;		//GSM2LTE��ѡ�ɹ�����
	m_dbG2L_Resel_Total_Delay = 0;		//GSM2LTE��ѡʱ�Ӻ�(s)

	m_ulRRC_L2G_Resel_Start_NUM = 0;	//TE2GSM��ѡ���Դ���
	m_ulRRC_L2G_Resel_Succ_NUM = 0;		//TE2GSM��ѡ�ɹ�����
	m_dbL2G_Resel_Total_Delay = 0;      //TE2GSM��ѡʱ�Ӻ�(s)
*/

	m_ulCSFB_Start_NUM_MO = 0;		//CSFB�Ժ��������У�
	m_ulCSFB_Success_NUM_MO = 0;		//CSFB LTE2GSM�ɹ��������У�
	m_ulCSFB_Alerting_NUM_MO = 0;		//CSFB����������У�
	m_ulCSFB_Connect_NUM_MO = 0;		//CSFB��ͨ�������У�

	m_ulCSFB_Return_Start_NUM_MO = 0;	//GSM-LTE���Դ������У�
	m_ulCSFB_Return_End_NUM_MO = 0;		//GSM-LTE�ɹ��������У�

	m_ulCSFB_Drop_NUM_MO = 0;		//CSFB���ߴ������У�

	//--------------����----------------------------------------------
	m_ulCSFB_Start_NUM_MT = 0;		//CSFB�Ժ�����У�
	m_ulCSFB_Success_NUM_MT = 0;		//CSFB LTE2GSM�ɹ�����У�
	m_ulCSFB_Alerting_NUM_MT = 0;		//CSFB�������У�
	m_ulCSFB_Connect_NUM_MT = 0;		//CSFB��ͨ����У�

	m_ulCSFB_Return_Start_NUM_MT = 0;	//GSM-LTE���Դ���У�
	m_ulCSFB_Return_End_NUM_MT = 0;		//GSM-LTE�ɹ�����У�

	m_ulCSFB_Drop_NUM_MT = 0;		//CSFB���ߴ���У�

	//----------------ʱ��----------------------------------------------------
	m_dbCSFB_Call_Start_Total_Delay_MO = 0;       //CSFB���н���ʱ�Ӻ�(s) �����У�
	m_dbCSFB_Call_Start_Total_Delay_MT = 0;       //CSFB���н���ʱ�Ӻ�(s) �����У�

	m_dbL2G_Resel_Total_Delay_MO = 0;                //LTE2GSM��ѡʱ�Ӻ�(s)�����У�
	m_dbL2G_Resel_Total_Delay_MT = 0;                //LTE2GSM��ѡʱ�Ӻ�(s)�����У�

	m_dbG2L_Resel_Total_Delay_MO = 0;                //GSM2LTE��ѡʱ�Ӻ�(s)�����У�
	m_dbG2L_Resel_Total_Delay_MT = 0;                //GSM2LTE��ѡʱ�Ӻ�(s)�����У�

	//MOSռ��
	m_ulMOS_0_2_Num = 0;		//[0,2)
	m_ulMOS_2_22_Num = 0;		//[2,2.2)
	m_ulMOS_22_24_Num = 0;		//[2.2,2.4)
	m_ulMOS_24_26_Num = 0;		//[2.4,2.6)
	m_ulMOS_26_28_Num = 0;		//[2.6,2.8)
	m_ulMOS_28_30_Num = 0;		//[2.8,3.0)
	m_ulMOS_30_32_Num = 0;		//[3.0,3.2)
	m_ulMOS_32_34_Num = 0;		//[3.2,3.4)
	m_ulMOS_34_36_Num = 0;		//[3.4,3.6)
	m_ulMOS_36_38_Num = 0;		//[3.6,3.8)
	m_ulMOS_38_40_Num = 0;		//[3.8,4.0)
	m_ulMOS_40_50_Num = 0;		//[4.0,5.0]   ---�������ֵ[4,5.1)���Ժ���5.0

}