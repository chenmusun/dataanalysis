#pragma once
#include "LogInfoBase.h"
#include "DataSource.h"
#include<vector>
#include<math.h>
#include<assert.h>
#include<algorithm>
class CAnalyzeImplBase
{
public:
	CAnalyzeImplBase(void);
	virtual ~CAnalyzeImplBase(void);

public:
	void Init(CLogInfoBase* pLogInfoBase);

	void ClearVars();

	int DoAnalyzeImpl(DTANASTATDATAITEM& dtitem, int nCsOrPs = 3);

	virtual int DoAnalyzeOneData(DTANASTATDATAITEM& dtitem);

	virtual int DoConclusion();

	double dBmTomW(double dBm);

	double mWTodBm(double mW);

protected:
	int GetGSMBand(int BCCH);

	void AnaUpdateLocation(DTANASTATDATAITEM& dtitem);
	virtual void AnaUpdateTime(DTANASTATDATAITEM& dtitem, int nCsOrPs);
	void AnaUpdateUafcnAndCPI(DTANASTATDATAITEM& dtitem);

	//void AnaUpdateLACandCI(DTANASTATDATAITEM& dtitem);

	double ConverTime(DTANASTATDATAITEM& input);
	int GetMediumValue(std::vector<int>& vecData);	//ȡ��ֵ


	bool IsValidLont(double dbLont);
	bool IsValidLati(double dbLati);
	double CalcDistance(double dbLont1,double dbLati1, double dbLont2, double dbLati2);

	double GetTimeLast(double TimeOld, double TimeNew);


public:
	CLogInfoBase* m_pLogInfoBase;



protected:
	//ͳ�ƹ������Ҫ�ı���
	//λ��
	double fLon_new;
	double fLat_new;
	double fLon_old;
	double fLat_old;
	BOOL bLocationChanged;

	//ʱ��
	double dTime_new;
	double dTime_old;
	BOOL bTimeChanged;

	//���浱ǰPCʱ��
	double m_dbCurrentPcTime;
	//������һ��ʱ���
	LONGLONG m_llLastTimeStamp;
	//��ǰ��ʹ��PCʱ�仹��ʱ���
	bool bIsUsePcTime;

	//Ƶ��
	int nUarfcn;
	//����
	UINT8 m_ucCPI;

	//LAC CI
	int m_usLAC;
	int m_usCellID;

	//Gps status
	bool m_bGpsLockOrLostStatus;

	//�ϵı�ǩ��ʶΪ��Ϊ���ж��Ƿ�Ϊ��һ����ǩ֮���ʱ���
	int m_oldlable;
};
