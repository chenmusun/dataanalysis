//#include "StdAfx.h"
#include "AnalyzeImplBase.h"
#define MAX_UE_NUM	16 

CAnalyzeImplBase::CAnalyzeImplBase(void)
{
	m_pLogInfoBase = NULL;
	
	//�����ʱ���
	ClearVars();
}

CAnalyzeImplBase::~CAnalyzeImplBase(void)
{
	m_pLogInfoBase = NULL;
}

double CAnalyzeImplBase::dBmTomW(double dBm)
{
	double mW = INVALIDVALUE_INT32;  // ����ֵ

	// ��������Ч
	if (INVALIDVALUE_INT32 != dBm)
	{
		// ��dBmת���ɺ���
		mW = pow((double)10, (dBm / (double)10));
	} // End of if (INVALIDVALUE != dBm)

	// ����
	return mW;
}

double CAnalyzeImplBase::mWTodBm(double mW)
{
	double dBm = INVALIDVALUE_INT32;  // ����ֵ

	// ��������Ч
	if (INVALIDVALUE_INT32 != mW && mW > 0)
	{
		// ������ת����dBm
		dBm = (double)10 * log10(mW);
	} // End of if (INVALIDVALUE != mW)

	// ����
	return dBm;
}

void CAnalyzeImplBase::ClearVars()
{
	//λ��
	fLon_new = ANA_IMPL_INVALID_LOCATION;
	fLat_new = ANA_IMPL_INVALID_LOCATION;
	fLon_old = ANA_IMPL_INVALID_LOCATION;
	fLat_old = ANA_IMPL_INVALID_LOCATION;
	bLocationChanged = FALSE;

	//ʱ��
	dTime_new = ANA_IMPL_INVALID_TIME;
	dTime_old = ANA_IMPL_INVALID_TIME;
	bTimeChanged = FALSE;

	m_dbCurrentPcTime = 0;
	m_llLastTimeStamp = 0;
	bIsUsePcTime = true;

	//Ƶ��
	nUarfcn = INVALIDVALUE_UINT16;

	m_ucCPI = INVALIDVALUE_UINT8;
	m_usLAC = INVALIDVALUE_UINT16;
	m_usCellID = INVALIDVALUE_INT32;
	m_bGpsLockOrLostStatus = false;

	m_oldlable = 0;
}


void CAnalyzeImplBase::Init(CLogInfoBase* pLogInfoBase)
{
	m_pLogInfoBase = pLogInfoBase;
}

int CAnalyzeImplBase::DoAnalyzeOneData(DTANASTATDATAITEM& dtitem)
{
	int nResult = 0;

	return nResult;
}

int CAnalyzeImplBase::DoConclusion()
{
	int nResult = 0;

	if (dTime_new > 100000000 && m_pLogInfoBase->m_nDTorCQT != 2 && !m_pLogInfoBase->bEndTimeChanged)
	{
		m_pLogInfoBase->EndTime = dTime_new;
		m_pLogInfoBase->EndMinSec = (dTime_new - m_pLogInfoBase->EndTime)*1000;
        m_pLogInfoBase->bEndTimeChanged = true;
	}
	
	return nResult;
}

double CAnalyzeImplBase::ConverTime(DTANASTATDATAITEM& input)
{	
	double dbsecond = input.ullPCTime >> 32; //ȡ��32����
	double dbms = ((int)input.ullPCTime)/1000.0;
	double dbtime = dbsecond + dbms;
	return dbtime;
}

int CAnalyzeImplBase::DoAnalyzeImpl(DTANASTATDATAITEM& dtitem, int nCsOrPs)
{
	int nResult = 0;

	AnaUpdateLocation(dtitem);
	AnaUpdateTime(dtitem,nCsOrPs);
	AnaUpdateUafcnAndCPI(dtitem);
//	AnaUpdateLACandCI(dtitem);

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

	return nResult;
}

void CAnalyzeImplBase::AnaUpdateUafcnAndCPI(DTANASTATDATAITEM& dtitem)
{
	if(INVALIDVALUE_UINT16 != dtitem.usUARFCN)
	{
		nUarfcn = dtitem.usUARFCN;
	}

	if (INVALIDVALUE_UINT8 != dtitem.ucCPI)
	{
		m_ucCPI = dtitem.ucCPI;
	}
	
}

//void CAnalyzeImplBase::AnaUpdateLACandCI(DTANASTATDATAITEM& dtitem)
//{
//	if(INVALIDVALUE_UINT16 !=  dtitem.usLAC)
//	{
//		m_usLAC = dtitem.usLAC;
//	}
//
//	//���TD��GSM
//	if (dtitem.ucRAT == ANA_IMPL_RAT_TD)
//	{
//		if(dtitem.usCellID != INVALIDVALUE_UINT16)
//		{
//			if (dtitem.usCellID != INVALIDVALUE_UINT16-1) //�������ֵ
//			{
//				if (dtitem.usRNCID != INVALIDVALUE_UINT16 && dtitem.usRNCID != INVALIDVALUE_UINT16-1) //TD
//				{
//					m_usCellID = dtitem.usRNCID * 65536 + dtitem.usCellID;
//				}
//			}
//			else //���ֵ�Ļ�����������Ե�����ͬCPI��UARFCN��С��CI��
//			{
//				if (nUarfcn != INVALIDVALUE_UINT16 && nUarfcn != INVALIDVALUE_UINT16-1 && m_ucCPI != INVALIDVALUE_UINT8 && m_ucCPI != INVALIDVALUE_UINT8-1)
//				{
//					stCellInfo pstructCellInfo;
//					if (CCellReader::Instance().GetSCCellInfo(m_pLogInfoBase->TerminalGroup, nUarfcn, m_ucCPI,INT32(fLon_new*1000000),INT32(fLat_new*1000000),pstructCellInfo))
//					{
//						m_usCellID = pstructCellInfo.usCI;
//					}
//				}
//				else
//				{
//					m_usCellID = INVALIDVALUE_INT32;
//				}
//			}
//		}
//	}
//	else if (dtitem.ucRAT == ANA_IMPL_RAT_GSM)
//	{
//		if(dtitem.usCellID != INVALIDVALUE_UINT16)
//		{
//			if (dtitem.usCellID != INVALIDVALUE_UINT16-1) //�������ֵ
//			{
//				m_usCellID = dtitem.usCellID;
//			}
//		}
//	}
//}

int CAnalyzeImplBase::GetGSMBand(int BCCH)
{
	int nBand = ANA_IMPL_GSM_BAND_900;

	if( (BCCH >=1) && (BCCH<=124) )
	{
		nBand = ANA_IMPL_GSM_BAND_900;
	}
	else if( (BCCH >=512) && (BCCH <= 885) )
	{
		nBand = ANA_IMPL_GSM_BAND_1800;
	}
	else if( (BCCH >=975) && (BCCH <= 1023) )
	{
		nBand = ANA_IMPL_GSM_BAND_E900;
	}
	else
	{

	}

	return nBand;
}

void CAnalyzeImplBase::AnaUpdateLocation(DTANASTATDATAITEM& dtitem)
{
	if(dtitem.lLongitude != INVALIDVALUE_INT32 && dtitem.lLatitude != INVALIDVALUE_INT32)
	{
		double dbLong = (double)dtitem.lLongitude/1000000;
		double dbLati = (double)dtitem.lLatitude/1000000;

		if(abs(dbLong-fLon_new)<0.000000001 && abs(dbLati-fLat_new)<0.000000001 )	//Ϊ�ı�
		{
			bLocationChanged = FALSE;
		}
		else
		{	
			bLocationChanged = TRUE;
			fLon_old = fLon_new;
			fLat_old = fLat_new;
			fLon_new = dbLong;
			fLat_new = dbLati;
			//��¼���
			//m_pLogInfoBase->Distance += CalcDistance(fLon_new, fLat_new,fLon_old,fLat_old);
		}

		m_bGpsLockOrLostStatus = true;
	}
	else
	{
		m_bGpsLockOrLostStatus = false;
	}
}

void CAnalyzeImplBase::AnaUpdateTime(DTANASTATDATAITEM& dtitem, int nCsOrPs)
{

	//����PCʱ��
	if (dtitem.ullPCTime != INVALIDVALUE_UINT64)
	{
		double dTime = ConverTime(dtitem);
		if (dTime > 100000000)
		{
			m_dbCurrentPcTime = dTime;
		}
	}

	if (bIsUsePcTime)
	{
		if (abs(m_dbCurrentPcTime - 0) > 0.000001)
		{
			if(abs(m_dbCurrentPcTime - dTime_new) < 0.000001)	//δ�ı�
			{
				bTimeChanged = FALSE;
			}
			else
			{
				dTime_old = dTime_new;
				dTime_new = m_dbCurrentPcTime;
				bTimeChanged = TRUE;
			}

			if (dtitem.ulTimeStamp != INVALIDVALUE_UINT32)
			{
				m_llLastTimeStamp = dtitem.ulTimeStamp;
				bIsUsePcTime = false;
			}
		}
	}
	else
	{
		assert(dTime_new > 100000000);
		assert(m_llLastTimeStamp >= 0);

		if (dtitem.ulTimeStamp != INVALIDVALUE_UINT32)
		{
			LONGLONG nSub = (LONGLONG)dtitem.ulTimeStamp - m_llLastTimeStamp;

			if (nSub == 0)
			{
				bTimeChanged = FALSE;
			}
			else if (nSub > 0)
			{
				if (nSub >= 5000)
				{
					dTime_old = m_dbCurrentPcTime;
					dTime_new = m_dbCurrentPcTime;
					bTimeChanged = FALSE;

					m_llLastTimeStamp = dtitem.ulTimeStamp;
				}
				else
				{
					dTime_old = dTime_new;
					dTime_new = dTime_new + nSub/1000.0;
					bTimeChanged = TRUE;
					m_llLastTimeStamp = dtitem.ulTimeStamp;
				}
			}
			else
			{
				if (nSub <= -5000)
				{
					dTime_old = m_dbCurrentPcTime;
					dTime_new = m_dbCurrentPcTime;
					bTimeChanged = FALSE;

					m_llLastTimeStamp = dtitem.ulTimeStamp;
				}
			}
		}
	}

	if (nCsOrPs != 0 && m_oldlable == 0)
	{
		if (dTime_new > 100000000 && m_pLogInfoBase->m_nDTorCQT != 2 && !m_pLogInfoBase->bStartTimeChanged)
		{
			m_pLogInfoBase->StartTime = dTime_new;
			m_pLogInfoBase->StartMinSec = (dTime_new - m_pLogInfoBase->StartTime)*1000;
            m_pLogInfoBase->bStartTimeChanged = true;
		}

		m_oldlable = nCsOrPs;
	}
}

int CAnalyzeImplBase::GetMediumValue(std::vector<int>& vecData)
{
	int nResult = -1;

	long nCount = (long)vecData.size();
	if(nCount <= 0)
	{
		return nResult;
	}

	std::sort(vecData.begin(), vecData.end());

	long nMedium = nCount/2;

	nResult = vecData[nMedium];

	return nResult;
}

bool CAnalyzeImplBase::IsValidLont(double dbLont)
{
	return (dbLont >= -180.0f && dbLont <= 180.0f);
}

// γ���Ƿ���Ч
bool CAnalyzeImplBase::IsValidLati(double dbLati)
{
	return (dbLati>= -90.0f && dbLati <= 90.0f);
}

double CAnalyzeImplBase::CalcDistance(double dbLont1,double dbLati1, double dbLont2, double dbLati2)
{
	if(IsValidLont(dbLont1) && IsValidLont(dbLont2) && IsValidLati(dbLati1) && IsValidLati(dbLati2))
	{
		const double PI = 3.14159265; //Բ����

		const double EARTH_RADIUS = 6.371229 * 1e6; //����뾶

		double x = (dbLont2 - dbLont1) * PI * EARTH_RADIUS * cos(((dbLati1 + dbLati2) / 2) * PI / 180) / 180;

		double y = (dbLati2 - dbLati1) * PI * EARTH_RADIUS / 180;

		return hypot(x, y);
	}
	return 0;
}

double CAnalyzeImplBase::GetTimeLast(double TimeOld, double TimeNew)
{
	double TimeLast = 0;

	if(abs(TimeOld-ANA_IMPL_INVALID_TIME) < 0.000001 
		|| abs(TimeNew-ANA_IMPL_INVALID_TIME) < 0.000001 )
	{
		return 0;
	}

	// ������λС�� [6/24/2015 liangdongxu]
	char tempNew[255]={0};
	char tempOld[255]={0};
	snprintf(tempNew,255,"%.3f",TimeNew);
	snprintf(tempOld,255,"%.3f",TimeOld);

	TimeNew = atof(tempNew);
	TimeOld = atof(tempOld);

	TimeLast = TimeNew - TimeOld;

	return TimeLast;
}


