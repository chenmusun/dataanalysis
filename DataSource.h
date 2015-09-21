#pragma once
#include<string>
#include<string.h>
#include<float.h>
#include"DataTypeDefine.h"
//��Чֵ����
#define INVALIDVALUE_SINT64  0x7fffffffffffffff
#define INVALIDVALUE_UINT64  0xffffffffffffffff
#define INVALIDVALUE_UINT32  0xffffffff
#define INVALIDVALUE_INT32   0x7fffffff
#define INVALIDVALUE_UINT16  0xffff
#define INVALIDVALUE_INT16   0x7fff
#define INVALIDVALUE_UINT8   0xff
#define INVALIDVALUE_INT8    0x7f
#define INVALIDVALUE_STRING  ""
#define INVALIDVALUE_FLOAT	FLT_MAX

//���ֵ����
#define CLEARVALUE_UINT64  0xfffffffffffffffe
#define CLEARVALUE_UINT32  0xfffffffe
#define CLEARVALUE_INT32   0x7ffffffe
#define CLEARVALUE_UINT16  0xfffe
#define CLEARVALUE_INT16   0x7ffe
#define CLEARVALUE_UINT8   0xfe
#define CLEARVALUE_INT8    0x7e

// �ַ���󳤶ȶ���
#define CDLMR_PRIMMSG_MAXLEN    800
#define AUTODT_PRIMMSG_MAXLEN   4000

//С��״̬��������
#define  CELLSTATE_NORMAL         0  //��
#define  CELLSTATE_FAILURE        1  //����
#define  CELLSTATE_RESTRICTED     2  //����
#define  CELLSTATE_UNACTIVATED    3  //δ����

// �Ʊ��
#define TAB_STRING string("\t")
#define ULDIR	string("(↑)")
#define DLDIR	string("(↓)")

#define TRUE 1
#define FALSE 0

enum AnalysisTypeEnum
{
	E_InvalidAnysis = -1,	//��Ч����
	E_CallFailureAnalysis = 0, //����ʧ�ܷ���
	E_CallDropAnalysis	//���е�������
};

//DT��Ϣ�Ľṹ
typedef struct struct_DTMsgDataItem
{
	UINT64  ullMsgGid; //��Ϣȫ��ID
	UINT16 usTEID;	//����ģ��ID
	UINT32 ulLogID;	//��־���
	UINT8 ucUEID;	//�ն�ID
	UINT64 ullPCTime;  //¼����Ϣ��PCʱ��(ms)
	UINT32 ulTimeStamp;	//��Ϣʱ���
	INT32 lLongitude;	//����
	INT32 lLatitude;	//γ��
	UINT8 ucUEType;		//�ն�����
	UINT8 ucRAT;		//������ʽ 0--GSM; 1--TD
	UINT8 ucProtocolVer; //Э���
	std::string strIMSI; 	//����ƶ��û�ʶ����
	std::string strMSISDN;	//MSISDN
	UINT16 usMCC;		//�ƶ������
	UINT16 usMNC;		//�ƶ�������
	UINT16 usLAC;		//λ����
	UINT8  ucRAC;		//·����
	UINT32 ulTMSI;		//��ʱ�ƶ��û�ʶ����--ʵ�����ʱ16�����ַ�
	UINT32 ulPTMSI;		//PTMSI--ʵ�����ʱ16�����ַ�
	UINT16 usRNCID;		//RNDID
	UINT16 usCellID;	//С��ID
	UINT8 ucCPI;		//����
	UINT16 usUARFCN;	//��Ƶ��
	UINT16 usWorkFreq;	//����Ƶ��
	UINT32 ulEventID;	//�¼�ID
	UINT8  ucMould;		//
	UINT8  ucMouldState; //
	UINT8  ucPCCPCHRSCP; //��Ϊԭʼֵ--ʵ��ʱע��-116
	UINT8  ucPCCPCHCIR;	//
	UINT32 ulDlBLER;	//����BLER
	UINT32 ulUpBLER;	//����BLER
	UINT8  ucSYNCULTxpower; //
	UINT8  ucPRACHTxpower;	//
	UINT8  ucTxpower;	//
	UINT8  ucDPCHRSCP;	//
	UINT8  ucDlSIR;		//����SIR
	UINT8  ucTSORSSI;	//
	UINT8  ucPathLoss;	//
	UINT8  ucULBRU;
	UINT8  ucDLBRU;
	UINT8  ucUUMsgPro;	// �տ���ϢЭ���
	UINT32 ulUUMsgID;	//UU����ϢID
	UINT32 ulDecodeMsgParam;	//������Ϣ����
	UINT8   uiChannelMode;	//channelMode
	UINT32  uiIENumber;		//IE���
	UINT32  uiIEValue;		//IEֵ
	UINT16  usMsgLen;	//��Ϣ������

	UINT16  usMsgNameLen;	//��Ϣ������

	UINT8   ucPrimMsgName[AUTODT_PRIMMSG_MAXLEN];	//��ϢԴ�봮

	UINT16  usNCellParaLen;	//wcdma��С���

	UINT8   ucNCellPara[AUTODT_PRIMMSG_MAXLEN];	//wcdma��С����Ϣ��


	UINT8   ucPrimMsg[AUTODT_PRIMMSG_MAXLEN];	//��ϢԴ�봮
	//Begin Add wyq
	INT32 ulTestPointSN;	//���Ե����
	INT32 ulLastLongitude;	//���ľ���
	INT32 ulLastLatitude;	//����γ��
	INT32 ulLastAltitude;	//���ĸ߶�
	INT32 ulNorthShift;	//����ƫ��
	INT32 ulEastShift;	    //����ƫ��
	INT32 ulHeightShift;	//�߶�ƫ��
	std::string strTESTIMAGE; 	//ͼƬ���
	INT32 ulFloor;	        //¥��
	std::string strKEYPPOINTID; 	//�ؼ�����к�
	std::string strKEYPOINTINFO;	//�ؼ����Ϣ
	std::string strALIGNPOINT; 	//У׼��
	std::string strFLOORCHANGE;	//¥��ı���Ϣ
	//End Add wyq
	bool	m_bIsLastItem;

	std::string strDLMCS0;	//����MCS����0
	std::string strDLMCS1;	//����MCS����1
	std::string strULMCS;	//����MCS

	INT32 lCodeWordNum;
	INT32 lTbsizeCW0;
	INT32 lTbsizeCW1;

	INT64  llIEValue2;		//IEֵ

	INT32	siPRACH_Power;
	INT32	siPUSCH_Power;
	INT32	siPUCCH_Power;
	INT32	siSRS_POWER;

	UINT32	uiLTECI;
	UINT16	usPCI;

	UINT32	uiULPRBNUM;
	UINT32  uiDLPRBNUM;

	struct_DTMsgDataItem()
	{
		initialize();
	}

	virtual void initialize()
	{
		ullMsgGid = INVALIDVALUE_UINT64;
		usTEID = INVALIDVALUE_UINT16;
		ulLogID = INVALIDVALUE_UINT32;
		ucUEID = INVALIDVALUE_UINT8;
		ullPCTime = INVALIDVALUE_UINT64;
		ulTimeStamp = INVALIDVALUE_UINT32;
		lLongitude = INVALIDVALUE_INT32;
		lLatitude = INVALIDVALUE_INT32;
		ucUEType = INVALIDVALUE_UINT8;
		ucRAT = INVALIDVALUE_UINT8;
		ucProtocolVer = INVALIDVALUE_UINT8;
		strIMSI = INVALIDVALUE_STRING;
		strMSISDN = INVALIDVALUE_STRING;
		usMCC = INVALIDVALUE_UINT16;
		usMNC = INVALIDVALUE_UINT16;
		usLAC = INVALIDVALUE_UINT16;
		ucRAC = INVALIDVALUE_UINT8;
		ulTMSI = INVALIDVALUE_UINT32;
		ulPTMSI = INVALIDVALUE_UINT32;
		usRNCID = INVALIDVALUE_UINT16;
		usCellID = INVALIDVALUE_UINT16;
		ucCPI = INVALIDVALUE_UINT8;
		usUARFCN = INVALIDVALUE_UINT16;
		usWorkFreq = INVALIDVALUE_UINT16;
		ulEventID = INVALIDVALUE_UINT32;
		ucMould = INVALIDVALUE_UINT8;
		ucMouldState = INVALIDVALUE_UINT8;
		ucPCCPCHRSCP = INVALIDVALUE_UINT8;
		ucPCCPCHCIR = INVALIDVALUE_UINT8;
		ulDlBLER = INVALIDVALUE_UINT32;
		ulUpBLER = INVALIDVALUE_UINT32;
		ucSYNCULTxpower = INVALIDVALUE_UINT8;
		ucPRACHTxpower = INVALIDVALUE_UINT8;
		ucTxpower = INVALIDVALUE_UINT8;
		ucDPCHRSCP = INVALIDVALUE_UINT8;
		ucDlSIR = INVALIDVALUE_UINT8;
		ucTSORSSI = INVALIDVALUE_UINT8;
		ucPathLoss = INVALIDVALUE_UINT8;
		ucULBRU = INVALIDVALUE_UINT8;
		ucDLBRU = INVALIDVALUE_UINT8;
		ucUUMsgPro = INVALIDVALUE_UINT8;
		ulUUMsgID = INVALIDVALUE_UINT32;
		ulDecodeMsgParam = INVALIDVALUE_UINT32;
		uiChannelMode = INVALIDVALUE_UINT8;
		uiIENumber = INVALIDVALUE_UINT32;		//IE���
		uiIEValue = INVALIDVALUE_UINT32;		//IEֵ
		usMsgNameLen = 0;
		memset(ucPrimMsgName, 0, AUTODT_PRIMMSG_MAXLEN);
		usMsgLen = 0;
		memset(ucPrimMsg, 0, AUTODT_PRIMMSG_MAXLEN);
		usNCellParaLen = 0;
		memset(ucNCellPara, 0, AUTODT_PRIMMSG_MAXLEN);
		//Begin Add wyq
		ulTestPointSN = INVALIDVALUE_INT32;	
		ulLastLongitude = INVALIDVALUE_INT32;	
		ulLastLatitude = INVALIDVALUE_INT32;	
		ulLastAltitude = INVALIDVALUE_INT32;	
		ulNorthShift = INVALIDVALUE_INT32;	
		ulEastShift = INVALIDVALUE_INT32;	    
		ulHeightShift = INVALIDVALUE_INT32;	
		strTESTIMAGE = INVALIDVALUE_STRING; 	
		ulFloor = INVALIDVALUE_INT32;	        
		strKEYPPOINTID = INVALIDVALUE_STRING; 	
		strKEYPOINTINFO = INVALIDVALUE_STRING;	
		strALIGNPOINT = INVALIDVALUE_STRING; 	
		strFLOORCHANGE = INVALIDVALUE_STRING;	
		//End Add wyq
		m_bIsLastItem = false;

		strDLMCS0 = INVALIDVALUE_STRING;
		strDLMCS1 = INVALIDVALUE_STRING;
		strULMCS = INVALIDVALUE_STRING;

		lCodeWordNum = INVALIDVALUE_INT32;
		lTbsizeCW0 = INVALIDVALUE_INT32;
		lTbsizeCW1 = INVALIDVALUE_INT32;

		llIEValue2 = INVALIDVALUE_SINT64;

		siPRACH_Power = INVALIDVALUE_INT32;
		siPUSCH_Power = INVALIDVALUE_INT32;
		siPUCCH_Power = INVALIDVALUE_INT32;
		siSRS_POWER = INVALIDVALUE_INT32;

		uiLTECI = INVALIDVALUE_UINT32;
		usPCI = INVALIDVALUE_UINT16;

		uiULPRBNUM = INVALIDVALUE_UINT32;
		uiDLPRBNUM = INVALIDVALUE_UINT32;
	}

	//����0 -- ���У�1 -- ���У����� -- �Ƿ�
	INT8 GetUUMsgDir() const
	{
		UINT16 unDecParam = ulDecodeMsgParam & 0xffff;
		if(ucRAT == 1)//td
		{
			if(unDecParam == 2 || unDecParam == 4)
			{
				return 0;//ul
			}
			else if(unDecParam == 1 || unDecParam == 3 
				|| unDecParam == 5 || unDecParam == 8 
				|| unDecParam == 9 || unDecParam == 10 
				|| unDecParam == 11)
			{
				return 1;//dl
			}
		}
		else if(ucRAT == 0)//gsm
		{
			return (unDecParam & 0x01);
		}
		return -1;
	}


	INT32 GetCIR() const
	{
		if(ucPCCPCHCIR == INVALIDVALUE_UINT8 || ucPCCPCHRSCP == INVALIDVALUE_UINT8)
		{
			return INVALIDVALUE_UINT8 + 1;
		}
		else if(ucPCCPCHCIR == CLEARVALUE_UINT8 || ucPCCPCHRSCP == CLEARVALUE_UINT8)
		{
			return  INVALIDVALUE_UINT8 + 1 ;
		}
		else
		{
			return (INT32)ucPCCPCHRSCP - (INT32)ucPCCPCHCIR;
		}
	}

	float GetSIR() const
	{
		if(ucDlSIR == INVALIDVALUE_UINT8 || ucDlSIR == CLEARVALUE_UINT8)
		{
			return -255;
		}
		else
		{
			return (float)(ucDlSIR-23)/2;
		}
	}

	float GetDLBLER() const
	{
		if(ulDlBLER == INVALIDVALUE_UINT32 || ulDlBLER == CLEARVALUE_UINT32)
		{
			return -255;
		}
		else
		{
			return (float)ulDlBLER/1000;
		}
	}

	bool IsLastItem() const 
	{
		return m_bIsLastItem;
	}
}DTMSGDATAITEM;

//DT·������ͳ�ƵĽ�����
struct DTANASTATDATAITEM : public struct_DTMsgDataItem
{
	INT8 cRxlev;
	INT8 cDpchCIR; 
	UINT32 uiFTPDLLoadThroughput;
	UINT32 uiL2DLThroughput; 
	UINT16 usMOSScore;
	UINT16 usTotalB_D;
	UINT16 usErrB_D;
	UINT16 usTotalB_H;
	UINT16 usErrB_H;
	float	fRxAGC;
	float	fEC2IO;
	float	fTxPower;
	UINT32	ulDRCRATEINST;
	UINT32	ulRLP_RX_THR_INST;
	FLOAT	fPERINST;
	UINT32	ulRLP_RX_THR;
	DTANASTATDATAITEM()
	{
		initialize();
	}
	void initialize()
	{
		struct_DTMsgDataItem::initialize();
		cRxlev = INVALIDVALUE_INT8;
		cDpchCIR = INVALIDVALUE_INT8;
		uiFTPDLLoadThroughput = INVALIDVALUE_UINT32;
		uiL2DLThroughput = INVALIDVALUE_UINT32;
		usMOSScore = INVALIDVALUE_UINT16;
		usTotalB_D = INVALIDVALUE_UINT16;
		usErrB_D = INVALIDVALUE_UINT16;
		usTotalB_H = INVALIDVALUE_UINT16;
		usErrB_H = INVALIDVALUE_UINT16;
		fRxAGC = -255;
		fEC2IO = INVALIDVALUE_FLOAT;
		fTxPower = INVALIDVALUE_FLOAT;
		ulDRCRATEINST = INVALIDVALUE_UINT32;
		ulRLP_RX_THR_INST = INVALIDVALUE_UINT32;
		fPERINST = INVALIDVALUE_FLOAT;
		ulRLP_RX_THR = INVALIDVALUE_UINT32;
	}
};

//Begin Add wyq
#define TESTIMAGE_MAXLEN        30
#define KEYPPOINTID_MAXLEN      30
#define KEYPOINTINFO_MAXLEN     30
#define ALIGNPOINT_MAXLEN       30
#define FLOORCHANGE_MAXLEN      30
//End Add wyq
#define SSID_HP_MAXLEN          32
#define MACADDRESS_HP_MAXLEN    20
#define WLANCHANNEL_HP_MAXLEN   100
#define SPEEDINFO_MAXLEN        200
#define SSID_M_MAXLEN           32
#define IPADDRESS_M_MAXLEN      20
#define MACADDRESS_M_MAXLEN     20
#define SSID_S_MAXLEN           32
#define MACADDRESS_S            20
#define WLANCHANNEL_S           100

