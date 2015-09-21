//#include "StdAfx.h"
#include "LogInfoBase.h"


CLogInfoBase::CLogInfoBase(void)
{
	m_strTableName ="";

	RecSeqNo = -1;   //��¼���к�, ȫ��ֵΨһ,����  
	TaskID = -1;   //����ID  
	ResultID = -1;   //������ID  
	TerminalGroup = "";			//�ն˷���
	BoxID = "";					//BoxID
	TestPlanName = "";				//���Լƻ����
	OperatorName = "";	//��Ӫ�����
	DTFileName = "";   //·����־�ļ���  
	TEID = 0;   //·���豸ID  
	UEID = 0;   //·��UEID  
	IMSI = 0;   //UE��IMSI  
	StartTime = 0;   //��־��ʼʱ��  
	EndTime = 0;   //��־����ʱ��  
	CallType = 0;   //0:���У�1�����У�2������  
	Distance = 0;   //��־·�̣���λ��
	NetworkType = -1; ;	//������ʽ
	ServiceType = ANA_IMPL_SERVICETYPE_UNKNOWN;  //ҵ������
	//Begin Add wyq
	TestPointSN = 0;	//���Ե����
	//End Add wyq

	StartMinSec = 0;
	EndMinSec = 0;

	m_nStatisticsRet = 2;

    bStartTimeChanged = false;
    bEndTimeChanged = false;

	m_nDTorCQT=0;
	m_LogVer = 0;
}

CLogInfoBase::~CLogInfoBase(void)
{
}

//std::string CLogInfoBase::GetInsertSQL()
//{
//	std::string strSQL = "";

// 	strSQL.Format(_T("insert into %s values ( "), m_strTableName);
// 
// 	SQL_AppendInt(strSQL,RecSeqNo);    //��¼���к�, ȫ��ֵΨһ,����
// 	SQL_AppendInt(strSQL,TaskID);    //����ID
// 	SQL_AppendInt(strSQL,ResultID);    //������ID
// 	SQL_AppendStr(strSQL,TerminalGroup);			//�ն˷���
// 	SQL_AppendStr(strSQL,BoxID);					//BoxID
// 	SQL_AppendStr(strSQL,TestPlanName);				//���Լƻ����
// 	SQL_AppendStr(strSQL,OperatorName);	//��Ӫ�����
// 	SQL_AppendStr(strSQL,DTFileName);    //·����־�ļ���
// 	SQL_AppendInt(strSQL,TEID);    //·���豸ID
// 	SQL_AppendInt(strSQL,UEID);    //·��UEID
// 	SQL_AppendInt(strSQL, IMSI);    //UE��IMSI
// 	SQL_AppendDay(strSQL,StartTime);    //��־��ʼʱ��
// 	SQL_AppendDay(strSQL, EndTime);    //��־����ʱ��
// 	SQL_AppendInt(strSQL,CallType);    //0:���У�1�����У�2������
// 	SQL_AppendFlt(strSQL,Distance);    //��־·�̣���λ��
// 	SQL_AppendFlt(strSQL,NetworkType) ;	//������ʽ
// 	SQL_AppendFlt(strSQL,ServiceType); //ҵ������
// 
// 
// 	strSQL.TrimRight(_T(", "));
// 	strSQL.AppendFormat(_T(" )"));


	//дǰ̨��ݱ�
//	strSQL.Format(_T(" update %s "), (std::string)TESTLOG_ITEM.c_str());
//
//	std::string strTemp = _T("");
//	SQL_AppendDay(strTemp,StartTime, StartMinSec);
//	strSQL.AppendFormat(_T(" Set START_DATE = %s  "), strTemp);			//��ʼʱ��
//
//	strTemp = _T("");
//	SQL_AppendDay(strTemp,EndTime, EndMinSec);
//	strSQL.AppendFormat(_T(" END_DATE = %s  "), strTemp);			//����ʱ��
//
//	strSQL.AppendFormat(_T(" DISTANCE = %f , "), Distance);			//����
//
//	strSQL.AppendFormat(_T(" CALL_TYPE = %d, "), CallType);			//��������
//
//	strSQL.AppendFormat(_T(" SERVICE_TYPE = %d, "), ServiceType);			//ҵ������
//
//	strSQL.AppendFormat(_T(" TESTFILE_STATUS = %d, "), m_nStatisticsRet);			//״̬
//
//	strSQL.AppendFormat(_T(" DTCQT_TYPE = %d "), m_nDTorCQT);			//DT��CQT
//
//	strSQL.AppendFormat(_T(" where RECSEQNO = %d "), RecSeqNo);			//����
//
//
//	return strSQL;
//}


//void CLogInfoBase::SQL_AppendInt(std::string& strSQL, int value)
//{
//// 	if( INVALIDVALUE_UINT16 == value)
//// 	{
//// 		strSQL.AppendFormat(_T(" 0, "));
//// 	}
//// 	else
//	{
//		strSQL.AppendFormat(_T(" %d, "),value);  //��¼���к�, ȫ��
//	}
//}
//
//void CLogInfoBase::SQL_AppendUInt(std::string& strSQL, UINT32 value)
//{
//	strSQL.AppendFormat(_T(" %u, "),value);
//}

//void CLogInfoBase::SQL_AppendLONGLONG(std::string& strSQL, INT64 value)
//{
//	strSQL.AppendFormat(_T(" %I64d, "),value);
//}
//
//void CLogInfoBase::SQL_AppendULONGLONG(std::string& strSQL, UINT64 value)
//{
//	strSQL.AppendFormat(_T(" %I64u, "),value);
//}
//
//void CLogInfoBase::SQL_AppendFlt(std::string& strSQL, float value)
//{
//// 	if(/* -255 >= value*/FALSE)
//// 	{
//// 		strSQL.AppendFormat(_T(" 0, "));
//// 	}
//// 	else
//	{
//		strSQL.AppendFormat(_T(" %f, "),value);  //��¼���к�, ȫ��
//	}
//}
//
//void CLogInfoBase::SQL_AppendStr(std::string& strSQL, std::string value)
//{
//	if( _T("") == value)
//	{
//		strSQL.AppendFormat(_T(" , "));
//	}
//	else
//	{
//		strSQL.AppendFormat(_T(" '%s', "),value);  //��¼���к�, ȫ��
//	}
//}
//
//void CLogInfoBase::SQL_AppendDay(std::string& strSQL, long value, long ms)
//{
//	CTime ctime(value);
//	
//	int nYear = ctime.GetYear();
//	int nMonth = ctime.GetMonth();
//	int nDay = ctime.GetDay();
//	int Hour = ctime.GetHour();
//	int nMin = ctime.GetMinute();
//	int nSec = ctime.GetSecond();
//
//	strSQL.AppendFormat(_T(" to_timestamp('%.2d-%.2d-%.4d  %.2d:%.2d:%.2d.%.3d ', 'MM-DD-YYYY HH24:MI:SS.ff'), "),
//		nMonth,nDay, nYear, 
//		Hour,nMin,  nSec, ms);
//
//
//}