#pragma once
#include"DataTypeDefine.h"
#include"PreDefine.h"
#include<string>
//����Ϣ��

class CLogInfoBase
{
public:
	CLogInfoBase(void);
	virtual ~CLogInfoBase(void);

//public:
//	virtual std::string GetInsertSQL();
//
//
//protected:
//	void SQL_AppendInt(std::string& strSQL, int value);
//	void SQL_AppendUInt(std::string& strSQL, UINT32 value);
//	void SQL_AppendLONGLONG(std::string& strSQL, INT64 value);
//	void SQL_AppendULONGLONG(std::string& strSQL, UINT64 value);
//	void SQL_AppendFlt(std::string& strSQL, float value);
//	void SQL_AppendStr(std::string& strSQL, std::string value);
//	void SQL_AppendDay(std::string& strSQL, long value, long ms);
	

public:
	std::string m_strTableName;

public:
		UINT64  RecSeqNo;    //��¼���к�, ȫ��ֵΨһ,����
		INT32  TaskID;    //����ID
		INT32  ResultID;    //������ID
		std::string TerminalGroup;			//�ն˷���
		std::string BoxID;					//BoxID
		std::string TestPlanName;				//���Լƻ����
		std::string OperatorName;	//��Ӫ�����
		std::string  DTFileName;    //·����־�ļ���
		UINT64  TEID;    //·���豸ID
		UINT64  UEID;    //·��UEID
		UINT64  IMSI;    //UE��IMSI
		UINT64  StartTime;    //��־��ʼʱ��
		UINT64  EndTime;    //��־����ʱ��
		UINT8  CallType;    //0:���У�1�����У�2������
		float  Distance;    //��־·�̣���λ��
		INT8  NetworkType;	//������ʽ
		INT8  ServiceType; //ҵ������
		//Begin Add wyq
		UINT32 TestPointSN;	//���Ե����
		//End Add wyq

		//Other
		UINT32 StartMinSec;	//��ʼ�ĺ���
		UINT32 EndMinSec;	//����ĺ���

		//ͳ�ƽ��
		int m_nStatisticsRet;

		bool bStartTimeChanged;
		bool bEndTimeChanged;

		int m_nDTorCQT;//DT:1, CQT:2, ��Ч:0
		// ��־�汾 [5/20/2015 liangdongxu]
		UINT16 m_LogVer;

};

enum EnumServiceType
{
	ServiceType_Unknow=0,
	ServiceType_CS_Call,
	ServiceType_FTP
};

enum EnumTroubleRoad
{
	TroubleRoad_Unknow=0,       //δ֪
	TroubleRoad_WeakCover,      //������
	TroubleRoad_OverCover,      //���
	TroubleRoad_NoSCCover,      //��������
	TroubleRoad_SmallCover,     //��⸲��
	TroubleRoad_Interfere,      //���и���
	TroubleRoad_FTPLowSpeed,    //�������ʵ�
	TroubleRoad_GSMCover,       //ռ��GSM����
	TroubleRoad_IndoorCover,    //�ҷ�й©
	TroubleRoad_WeakBLER,        //BLER��
	TroubleRoad_OverCover_Detail //�����ϸ
};

enum EnumGPSStatus
{
	GPSStatus_Unknow=0,         //δ֪
	GPSStatus_PreLostLock,      //GPSǰʧ��
	GPSStatus_AfterLostLock,    //GPS��ʧ��
	GPSStatus_BothLostLock,     //GPSǰ���ʧ��
	GPSStatus_BothLock          //GPS��
};

class CLogInfo_TD_TroubleRoad
{
public:
	CLogInfo_TD_TroubleRoad(void);
	virtual ~CLogInfo_TD_TroubleRoad(void);

//public:
//	virtual std::string GetInsertSQL(UINT64 nRecSeqNo,EnumServiceType nServiceType);
//
//protected:
//	void SQL_AppendInt(std::string& strSQL, int value);
//	void SQL_AppendFlt(std::string& strSQL, float value);
//	void SQL_AppendStr(std::string& strSQL, std::string value);
//	void SQL_AppendDay(std::string& strSQL, long value);

public:
	UINT64  RecSeqNo;    //��¼���к�

	EnumServiceType   SERVICE_TYPE;   //ҵ������
	EnumTroubleRoad   TYPE;     //�������
	SINT32  LONGITUDE_START;    //·����ʼ����
	SINT32  LATITUDE_START;     //·����ʼγ��
	SINT32  LONGITUDE_END;      //·�ν����
	SINT32  LATITUDE_END;       //·�ν���γ��
	UINT64  BEGIN_TIME;         //����·�β��Կ�ʼʱ��
	UINT64  END_TIME;           //����·�β��Խ���ʱ��
	float   DISTANCE;           //����·�γ���(��)
	SINT32  LONGITUDE_CENTER;   //·�����ĵ㾭��
	SINT32  LATITUDE_CENTER;    //·�����ĵ�γ��
	UINT16  LAC;                //·�����ĵ����С��LAC
	int  CI;                 //·�����ĵ����С��CI
	float   DIRECTION_SC;       //·�����ĵ������С����
	float   DISTANCE_SC;        //·�����ĵ������С�����(��)
	EnumGPSStatus   GPS_STATUS; //����·��GPS״ָ̬ʾ
};
