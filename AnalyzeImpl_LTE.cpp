//#include "StdAfx.h"
#include "AnalyzeImpl_LTE.h"

CAnalyzeImpl_LTE::CAnalyzeImpl_LTE(void)
{

}
CAnalyzeImpl_LTE::~CAnalyzeImpl_LTE(void)
{

}

void CAnalyzeImpl_LTE::Init(CLogInfoBase* pLogInfoBase, CLogInfo_LTE_PS* pLogInfoLTEPS)
{
	m_pLogInfoBase = pLogInfoBase;
	m_pLogInfoLTEPS = pLogInfoLTEPS;
}

//����ҿ�,��nMin<= x <nMax;
double CAnalyzeImpl_LTE::CalcCdf(std::vector<double>& vSamplingPoint, int nMax, int nMin, int nInterval, double dbRatio)
{
	double dbResult = 0.0;

	if (vSamplingPoint.empty() || nMax <= nMin || nInterval <= 0 || dbRatio <= 0 || dbRatio > 1)
	{
		return dbResult;
	}

	//�ܲ��������
	int nTotalSamplingPoint = vSamplingPoint.size();

	//�������
	int nIntervalNum = (nMax - nMin + nInterval - 1) / nInterval;

	//��������ÿһ�������ֵ
	std::vector<int> vIntervalSamplingPointNum(nIntervalNum, 0);

	//����ÿ�������������
	std::vector<double>::iterator iter_SamplingPoint = vSamplingPoint.begin();
	for (; iter_SamplingPoint != vSamplingPoint.end(); iter_SamplingPoint++)
	{
		double dbTemp = *iter_SamplingPoint;
		if (dbTemp >= nMax || dbTemp < nMin)
		{
			return dbResult;
		}

		vIntervalSamplingPointNum.at((int)((dbTemp - nMin)/nInterval))++; //��÷������ҿ�
	}

	int nTempTotalPoint = 0, nLeft = 0;

	for (; nLeft < nIntervalNum; nLeft++)
	{
		nTempTotalPoint += vIntervalSamplingPointNum[nLeft];

		if ((double)nTempTotalPoint/nTotalSamplingPoint >= dbRatio && nLeft == 0) //�����һ������ȫ������
		{
			nTempTotalPoint = 0;
			nLeft = -1;
			break;
		}

		if ((double)nTempTotalPoint/nTotalSamplingPoint <= dbRatio && (double)(nTempTotalPoint+vIntervalSamplingPointNum[nLeft+1])/nTotalSamplingPoint >=dbRatio)
		{
			break;
		}
	}

	int Y1 = nMin + nInterval*(nLeft+1);
	double X1 = (double)nTempTotalPoint/nTotalSamplingPoint;
	int Y2 = nMin + nInterval*(nLeft+2);
	double X2 = (double)(nTempTotalPoint+vIntervalSamplingPointNum[nLeft+1])/nTotalSamplingPoint;

	if (dbRatio == X1)
	{
		dbResult = Y1;
	}
	else
	{
		dbResult = (Y2-Y1)*(dbRatio-X1)/(X2-X1) + Y1;
	}

	return dbResult;
}

void CAnalyzeImpl_LTE::AnaUpdateTime(DTANASTATDATAITEM& dtitem, int nCsOrPs)
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

BOOL CAnalyzeImpl_LTE::GetItem(char *inbuffer, unsigned int itemnum, char *outbuffer, const char *separator)
{
	if (inbuffer == NULL || outbuffer == NULL || separator == NULL)
	{
		return FALSE;
	}

	unsigned int i = 0;
	BOOL flag = FALSE;
	char *ch, temp_ch, *begin = inbuffer;

	while (*begin != ('\0'))
	{		
		i++;
		ch = strstr(begin, separator);
		if (ch != NULL)
		{
			temp_ch = *ch;
			*ch = ('\0');
		}
		if (i == itemnum)
		{
			strcpy(outbuffer, begin);
			flag = TRUE;
		}
		if (ch != NULL)
		{
			*ch = temp_ch;
		}
		if (flag)
		{
			break;
		}
		if (ch == NULL)
		{
			break;
		}
		begin = ch + 1;
	} 
	return flag;
}

double rad(double d)
{
	const double PI = 3.1415926535898;
	return d * PI / 180.0;
}

double CAnalyzeImpl_LTE::CalcDistanceLTE(double dbLont1,double dbLati1, double dbLont2, double dbLati2)
{
	if(IsValidLont(dbLont1) && IsValidLont(dbLont2) && IsValidLati(dbLati1) && IsValidLati(dbLati2))
	{
		const float EARTH_RADIUS = 6378.137 * 1000;

		double radLat1 = rad(dbLati1);
		double radLat2 = rad(dbLati2);
		double a = radLat1 - radLat2;
		double b = rad(dbLont1) - rad(dbLont2);
		double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
		s = s * EARTH_RADIUS;
		s = (int)(((int)(s * 10000 + 0.5)) / 10000.0);
		return s;
	}
	return 0;
}

/*
double CAnalyzeImpl_LTE::CalcCdfForPdcp(vector<double>& vSamplingPoint, bool bIsDlorUl, int nMax, int nMin, double dbRatio)
{
	double dbResult = 0.0;

	if (vSamplingPoint.empty() || nMax <= nMin || dbRatio <= 0 || dbRatio > 1)
	{
		return dbResult;
	}

	//�ܲ��������
	int nTotalSamplingPoint = vSamplingPoint.size();

	//�������
	int nIntervalNum = 5;

	//��������ÿһ�������ֵ
	vector<int> vIntervalSamplingPointNum(nIntervalNum, 0);

	//����ÿ�������������
	vector<double>::iterator iter_SamplingPoint = vSamplingPoint.begin();
	for (; iter_SamplingPoint != vSamplingPoint.end(); iter_SamplingPoint++)
	{
		double dbTemp = *iter_SamplingPoint;
		if (dbTemp >= nMax || dbTemp < nMin)
		{
			return dbResult;
		}

		if (bIsDlorUl)
		{
			if (dbTemp < 4000)
			{
				vIntervalSamplingPointNum.at(0)++;
			}
			else if (dbTemp < 20000)
			{
				vIntervalSamplingPointNum.at(1)++;
			}
			else if (dbTemp < 40000)
			{
				vIntervalSamplingPointNum.at(2)++;
			}
			else if (dbTemp < 50000)
			{
				vIntervalSamplingPointNum.at(3)++;
			}
			else if (dbTemp < 150000)
			{
				vIntervalSamplingPointNum.at(4)++;
			}
		} 
		else
		{
			if (dbTemp < 1000)
			{
				vIntervalSamplingPointNum.at(0)++;
			}
			else if (dbTemp < 5000)
			{
				vIntervalSamplingPointNum.at(1)++;
			}
			else if (dbTemp < 10000)
			{
				vIntervalSamplingPointNum.at(2)++;
			}
			else if (dbTemp < 15000)
			{
				vIntervalSamplingPointNum.at(3)++;
			}
			else if (dbTemp < 80000)
			{
				vIntervalSamplingPointNum.at(4)++;
			}
		}
	}

	int nTempTotalPoint = 0, nLeft = 0;

	for (; nLeft < nIntervalNum; nLeft++)
	{
		nTempTotalPoint += vIntervalSamplingPointNum[nLeft];

		if ((double)nTempTotalPoint/nTotalSamplingPoint >= dbRatio && nLeft == 0) //�����һ������ȫ������
		{
			nTempTotalPoint = 0;
			nLeft = -1;
			break;
		}

		if ((double)nTempTotalPoint/nTotalSamplingPoint <= dbRatio && (double)(nTempTotalPoint+vIntervalSamplingPointNum[nLeft+1])/nTotalSamplingPoint >=dbRatio)
		{
			break;
		}
	}

	int Y1 = 0;
	int Y2 = 0;
	switch ((nLeft+1))
	{
	case 0:
		{
			bIsDlorUl ? (Y1 = 0, Y2 = 4000) : (Y1 = 0, Y2 = 1000);
			break;
		}
	case 1:
		{
			bIsDlorUl ? (Y1 = 4000, Y2 = 20000) : (Y1 = 1000, Y2 = 5000);
			break;
		}
	case 2:
		{
			bIsDlorUl ? (Y1 = 20000, Y2 = 40000) : (Y1 = 5000, Y2 = 10000);
			break;
		}
	case 3:
		{
			bIsDlorUl ? (Y1 = 40000, Y2 = 50000) : (Y1 = 10000, Y2 = 15000);
			break;
		}
	case 4:
		{
			bIsDlorUl ? (Y1 = 50000, Y2 = 150000) : (Y1 = 15000, Y2 = 80000);
			break;
		}
	}
	double X1 = (double)nTempTotalPoint/nTotalSamplingPoint;
	double X2 = (double)(nTempTotalPoint+vIntervalSamplingPointNum[nLeft+1])/nTotalSamplingPoint;

	if (dbRatio == X1)
	{
		dbResult = Y1;
	}
	else
	{
		dbResult = (Y2-Y1)*(dbRatio-X1)/(X2-X1) + Y1;
	}

	return dbResult;
}
*/