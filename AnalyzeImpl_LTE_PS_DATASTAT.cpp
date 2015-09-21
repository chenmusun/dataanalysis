//#include "StdAfx.h"
#include "AnalyzeImpl_LTE_PS_DATASTAT.h"


CAnalyzeImpl_LTE_PS_DATASTAT::CAnalyzeImpl_LTE_PS_DATASTAT(void)
{
	m_dbCurSINR = -100;

	m_lOldCodeWordNum = 0;
	m_dbStartCodeWordTime = ANA_IMPL_INVALID_TIME;

	//��������ص����Ƕ����
	m_dLongitude = ANA_IMPL_INVALID_LOCATION;
	m_dLatitude = ANA_IMPL_INVALID_LOCATION;

	m_nLastRSRP = INVALIDVALUE_INT32;
}

CAnalyzeImpl_LTE_PS_DATASTAT::~CAnalyzeImpl_LTE_PS_DATASTAT(void)
{
	CPSDataStatBase_LTE* pDataStat=NULL;
	for(std::map<int,CPSDataStatBase_LTE*>::iterator it = m_MapPSDataStat.begin(); it != m_MapPSDataStat.end(); it++)
	{
		pDataStat=it->second;
		delete pDataStat;
		pDataStat=NULL;
	}

}


void CAnalyzeImpl_LTE_PS_DATASTAT::Init(CLogInfoBase* pLogInfoBase, CLogInfo_LTE_PS* pLogInfoLTEPS)
{
	CAnalyzeImpl_LTE::Init(pLogInfoBase,pLogInfoLTEPS);
	
	//1.1��IENumber-IEValue  ����IEֵ�ۼ�
	//CPSDataStatBase_LTE
	//PDCP����ƽ��������Kbps(������)	PDCP����ƽ��������Kbps(������) IE_LTE_PDCP_THROUGHPUT_DL
	//m_MapPSDataStat.insert(make_pair(IE_LTE_PDCP_THROUGHPUT_DL, new CPSDataStatBase_LTE(IE_LTE_PDCP_THROUGHPUT_DL,&pLogInfoLTEPS->m_ulPDCP_DL_Throughput_Num_ID,&pLogInfoLTEPS->m_dbPDCP_DL_Throughput_Sum_ID,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//PDCP����ƽ��������Kbps(������)	PDCP����ƽ��������Kbps(������) IE_LTE_PDCP_THROUGHPUT_UL
	//m_MapPSDataStat.insert(make_pair(IE_LTE_PDCP_THROUGHPUT_UL, new CPSDataStatBase_LTE(IE_LTE_PDCP_THROUGHPUT_UL,&pLogInfoLTEPS->m_ulPDCP_UL_Throughput_Num_ID,&pLogInfoLTEPS->m_dbPDCP_UL_Throughput_Sum_ID,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//RLC����ƽ��������Kbps(������)	RLC����ƽ��������Kbps(������) IE_LTE_RLC_THROUGHPUT_DL
	//m_MapPSDataStat.insert(make_pair(IE_LTE_RLC_THROUGHPUT_DL, new CPSDataStatBase_LTE(IE_LTE_RLC_THROUGHPUT_DL,&pLogInfoLTEPS->m_ulRLC_DL_Throughput_Num_ID,&pLogInfoLTEPS->m_dbRLC_DL_Throughput_Sum_ID,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//RLC����ƽ��������Kbps(������)	RLC����ƽ��������Kbps(������) IE_LTE_RLC_THROUGHPUT_UL
	//m_MapPSDataStat.insert(make_pair(IE_LTE_RLC_THROUGHPUT_UL, new CPSDataStatBase_LTE(IE_LTE_RLC_THROUGHPUT_UL,&pLogInfoLTEPS->m_ulRLC_UL_Throughput_Num_ID,&pLogInfoLTEPS->m_dbRLC_UL_Throughput_Sum_ID,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//MAC����ƽ��������Kbps(������)	MAC����ƽ��������Kbps(������) IE_LTE_MAC_THROUGHPUT_DL
	m_MapPSDataStat.insert(make_pair(IE_LTE_MAC_THROUGHPUT_DL, new CPSDataStatBase_LTE(IE_LTE_MAC_THROUGHPUT_DL,&pLogInfoLTEPS->m_ulMAC_DL_Throughput_Num_ID,&pLogInfoLTEPS->m_dbMAC_DL_Throughput_Sum_ID,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//MAC����ƽ��������Kbps(������)	MAC����ƽ��������Kbps(������) IE_LTE_MAC_THROUGHPUT_UL
	m_MapPSDataStat.insert(make_pair(IE_LTE_MAC_THROUGHPUT_UL, new CPSDataStatBase_LTE(IE_LTE_MAC_THROUGHPUT_UL,&pLogInfoLTEPS->m_ulMAC_UL_Throughput_Num_ID,&pLogInfoLTEPS->m_dbMAC_UL_Throughput_Sum_ID,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����

	//PHY����������	PHY Throughput DL	IE_LTE_PHY_THROUGHPUT_DL
	m_MapPSDataStat.insert(make_pair(IE_LTE_PHY_THROUGHPUT_DL, new CPSDataStatBase_LTE(IE_LTE_PHY_THROUGHPUT_DL,&pLogInfoLTEPS->m_ulPHY_Throughput_DL_Num,&pLogInfoLTEPS->m_dbPHY_Throughput_DL_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//����0������(Kbps)	PHY Cw0 Throughput DL	IE_LTE_PHY_CW0_THROUGHPUT_DL
	m_MapPSDataStat.insert(make_pair(IE_LTE_PHY_CW0_THROUGHPUT_DL, new CPSDataStatBase_LTE(IE_LTE_PHY_CW0_THROUGHPUT_DL,&pLogInfoLTEPS->m_ulPHY_Cw0_Throughput_DL_Num,&pLogInfoLTEPS->m_dbPHY_Cw0_Throughput_DL_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//����1������(Kbps)	PHY Cw1 Throughput DL	IE_LTE_PHY_CW1_THROUGHPUT_DL
	m_MapPSDataStat.insert(make_pair(IE_LTE_PHY_CW1_THROUGHPUT_DL, new CPSDataStatBase_LTE(IE_LTE_PHY_CW1_THROUGHPUT_DL,&pLogInfoLTEPS->m_ulPHY_Cw1_Throughput_DL_Num,&pLogInfoLTEPS->m_dbPHY_Cw1_Throughput_DL_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//PHY����������	PHY Throughput UL	IE_LTE_PHY_THROUGHPUT_UL
	m_MapPSDataStat.insert(make_pair(IE_LTE_PHY_THROUGHPUT_UL, new CPSDataStatBase_LTE(IE_LTE_PHY_THROUGHPUT_UL,&pLogInfoLTEPS->m_ulPHY_Throughput_UL_Num,&pLogInfoLTEPS->m_dbPHY_Throughput_UL_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����


	//PDSCH���ν��ճɹ�����	IE_LTE_PDSCH_FIRST_RX_SUCCESS_CNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_PDSCH_FIRST_RX_SUCCESS_CNT, new CPSDataStatBase_LTE(IE_LTE_PDSCH_FIRST_RX_SUCCESS_CNT,NULL,&pLogInfoLTEPS->m_ulPDSCH_first_rx_success_cnt,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PDSCH����ش��ɹ�����	IE_LTE_PDSCH_MULTI_RETRANS_SUCCESS_CNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_PDSCH_MULTI_RETRANS_SUCCESS_CNT, new CPSDataStatBase_LTE(IE_LTE_PDSCH_MULTI_RETRANS_SUCCESS_CNT,NULL,&pLogInfoLTEPS->m_ulPDSCH_multi_retrans_success_cnt,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PUSCH�����ɹ�����	IE_LTE_HARQ_UL_1ST_TX_SUCC_NUM
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_1ST_TX_SUCC_NUM, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_1ST_TX_SUCC_NUM,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_1st_Tx_Succ_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PUSCH 1���ش��ɹ�����	IE_LTE_HARQ_UL_1ST_RETX_SUCC_NUM
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_1ST_RETX_SUCC_NUM, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_1ST_RETX_SUCC_NUM,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_1st_ReTx_Succ_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PUSCH 2���ش��ɹ�����	IE_LTE_HARQ_UL_2ND_RETX_SUCC_NUM
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_2ND_RETX_SUCC_NUM, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_2ND_RETX_SUCC_NUM,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_2nd_ReTx_Succ_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PUSCH 3���ش��ɹ�����	IE_LTE_HARQ_UL_3RD_RETX_SUCC_NUM
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_3RD_RETX_SUCC_NUM, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_3RD_RETX_SUCC_NUM,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_3rd_ReTx_Succ_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PUSCH 4���ش��ɹ�����	IE_LTE_HARQ_UL_4TH_RETX_SUCC_NUM
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_4TH_RETX_SUCC_NUM, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_4TH_RETX_SUCC_NUM,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_4th_ReTx_Succ_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PUSCH����ش��ɹ�����	IE_LTE_HARQ_UL_MUTIL_RETX_SUCC_NUM
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_MUTIL_RETX_SUCC_NUM, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_MUTIL_RETX_SUCC_NUM,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_mutil_ReTx_Succ_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����

	//------------����Ҫ�������ָ�꣺�ش�ʧ�ܴ���HARQ DL ReTx Failed Num;   HARQ UL ReTx Failed Num-------??????????
	//UINT32 m_ulHARQ_DL_ReTx_Failed_cnt;		//�ش�ʧ�ܴ���:HARQ DL ReTx Failed Num;
	//UINT32 m_ulHARQ_UL_ReTx_Failed_cnt;		//�ش�ʧ�ܴ���:HARQ UL ReTx Failed Num;

	//����0����ACKռ��	HARQ DL C0 ACK Count	IE_LTE_HARQ_DL_C0_ACK_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_DL_C0_ACK_COUNT, new CPSDataStatBase_LTE(IE_LTE_HARQ_DL_C0_ACK_COUNT,NULL,&pLogInfoLTEPS->m_ulHARQ_DL_C0_ACK_Count,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//����0����NACKռ��	HARQ DL C0 NACK Count	IE_LTE_HARQ_DL_C0_NACK_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_DL_C0_NACK_COUNT, new CPSDataStatBase_LTE(IE_LTE_HARQ_DL_C0_NACK_COUNT,NULL,&pLogInfoLTEPS->m_ulHARQ_DL_C0_NACK_Count,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//����1ACKռ��	HARQ DL C1 ACK Count	IE_LTE_HARQ_DL_C1_ACK_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_DL_C1_ACK_COUNT, new CPSDataStatBase_LTE(IE_LTE_HARQ_DL_C1_ACK_COUNT,NULL,&pLogInfoLTEPS->m_ulHARQ_DL_C1_ACK_Count,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//����1NACKռ��	HARQ DL C1 NACK Count	IE_LTE_HARQ_DL_C1_NACK_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_DL_C1_NACK_COUNT, new CPSDataStatBase_LTE(IE_LTE_HARQ_DL_C1_NACK_COUNT,NULL,&pLogInfoLTEPS->m_ulHARQ_DL_C1_NACK_Count,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//����ACKռ��	HARQ UL Ack Count	IE_LTE_HARQ_UL_ACK_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_ACK_COUNT, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_ACK_COUNT,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_Ack_Count,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//����NACKռ��	HARQ UL Nack Count	IE_LTE_HARQ_UL_NACK_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_HARQ_UL_NACK_COUNT, new CPSDataStatBase_LTE(IE_LTE_HARQ_UL_NACK_COUNT,NULL,&pLogInfoLTEPS->m_ulHARQ_UL_NAck_Count,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����

	//��������0Bler(%)	DL Code0 BLER	IE_LTE_DL_CODE0_BLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_BLER, new CPSDataStatBase_LTE(IE_LTE_DL_CODE0_BLER,&pLogInfoLTEPS->m_ulDL_Code0_BLER_Num,&pLogInfoLTEPS->m_dbDL_Code0_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//��������1Bler(%)	DL Code1 BLER	IE_LTE_DL_CODE1_BLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_BLER, new CPSDataStatBase_LTE(IE_LTE_DL_CODE1_BLER,&pLogInfoLTEPS->m_ulDL_Code1_BLER_Num,&pLogInfoLTEPS->m_dbDL_Code1_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//��������0��ʼBler(%)	DL Code0 IBLER	IE_LTE_DL_CODE0_IBLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_IBLER, new CPSDataStatBase_LTE(IE_LTE_DL_CODE0_IBLER,&pLogInfoLTEPS->m_ulDL_Code0_I_BLER_Num,&pLogInfoLTEPS->m_dbDL_Code0_I_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//��������0����Bler(%)	DL Code0 RBLER	IE_LTE_DL_CODE0_RBLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_RBLER, new CPSDataStatBase_LTE(IE_LTE_DL_CODE0_RBLER,&pLogInfoLTEPS->m_ulDL_Code0_R_BLER_Num,&pLogInfoLTEPS->m_dbDL_Code0_R_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//��������1��ʼBler(%)	DL Code1 IBLER	IE_LTE_DL_CODE1_IBLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_IBLER, new CPSDataStatBase_LTE(IE_LTE_DL_CODE1_IBLER,&pLogInfoLTEPS->m_ulDL_Code1_I_BLER_Num,&pLogInfoLTEPS->m_dbDL_Code1_I_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//��������1����Bler(%)	DL Code2 RBLER(DL Code1 RBLER)	IE_LTE_DL_CODE1_RBLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_RBLER, new CPSDataStatBase_LTE(IE_LTE_DL_CODE1_RBLER,&pLogInfoLTEPS->m_ulDL_Code2_R_BLER_Num,&pLogInfoLTEPS->m_dbDL_Code2_R_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//����Bler(%)	UL BLER	IE_LTE_UL_BLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_BLER, new CPSDataStatBase_LTE(IE_LTE_UL_BLER,&pLogInfoLTEPS->m_ulUL_BLER_Num,&pLogInfoLTEPS->m_dbUL_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//���г�ʼBler(%)	UL IBLER	IE_LTE_UL_IBLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_IBLER, new CPSDataStatBase_LTE(IE_LTE_UL_IBLER,&pLogInfoLTEPS->m_ulUL_I_BLER_Num,&pLogInfoLTEPS->m_dbUL_I_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����
	//���в���Bler(%)	UL RBLER	IE_LTE_UL_RBLER
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_RBLER, new CPSDataStatBase_LTE(IE_LTE_UL_RBLER,&pLogInfoLTEPS->m_ulUL_R_BLER_Num,&pLogInfoLTEPS->m_dbUL_R_BLER_Sum,LTE_PSStat_Total_All,LTE_PSStat_Value_Double)));  //����

	//����ҵ���ѵ��ȸ�UE����֡�� IE_LTE_PDCCH_DL_GRANT_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_PDCCH_DL_GRANT_COUNT, new CPSDataStatBase_LTE(IE_LTE_PDCCH_DL_GRANT_COUNT,&pLogInfoLTEPS->m_ulSubFrame_DL_Count,&pLogInfoLTEPS->m_ulSubFrame_DL_TotalNum,LTE_PSStat_Total_All,LTE_PSStat_Value_Int)));  //����
	//����ҵ���ѵ��ȸ�UE����֡��IE_LTE_PDCCH_UL_GRANT_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_PDCCH_UL_GRANT_COUNT, new CPSDataStatBase_LTE(IE_LTE_PDCCH_UL_GRANT_COUNT,&pLogInfoLTEPS->m_ulSubFrame_UL_Count,&pLogInfoLTEPS->m_ulSubFrame_UL_TotalNum,LTE_PSStat_Total_All,LTE_PSStat_Value_Int)));  //����

	//��������0���Ʒ�ʽqpsk	DL Code0  MCS Modulation	IE_LTE_DL_CODE0_MCS_MODULATION_QPSK
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_MCS_MODULATION_QPSK, new CPSDataStatBase_LTE(IE_LTE_DL_CODE0_MCS_MODULATION_QPSK,NULL,&pLogInfoLTEPS->m_ulDL_Code0_QPSK_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//��������0���Ʒ�ʽ16qam	DL Code0  MCS Modulation	IE_LTE_DL_CODE0_MCS_MODULATION_16QAM
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_MCS_MODULATION_16QAM, new CPSDataStatBase_LTE(IE_LTE_DL_CODE0_MCS_MODULATION_16QAM,NULL,&pLogInfoLTEPS->m_ulDL_Code0_16QAM_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//��������0���Ʒ�ʽ32qam	DL Code0  MCS Modulation	IE_LTE_DL_CODE0_MCS_MODULATION_32QAM
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_MCS_MODULATION_32QAM, new CPSDataStatBase_LTE(IE_LTE_DL_CODE0_MCS_MODULATION_32QAM,NULL,&pLogInfoLTEPS->m_ulDL_Code0_64QAM_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//��������1���Ʒ�ʽqpsk	DL Code1  MCS Modulation	IE_LTE_DL_CODE1_MCS_MODULATION_QPSK
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_MCS_MODULATION_QPSK, new CPSDataStatBase_LTE(IE_LTE_DL_CODE1_MCS_MODULATION_QPSK,NULL,&pLogInfoLTEPS->m_ulDL_Code1_QPSK_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//��������1���Ʒ�ʽ16qam	DL Code1  MCS Modulation	IE_LTE_DL_CODE1_MCS_MODULATION_16QAM
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_MCS_MODULATION_16QAM, new CPSDataStatBase_LTE(IE_LTE_DL_CODE1_MCS_MODULATION_16QAM,NULL,&pLogInfoLTEPS->m_ulDL_Code1_16QAM_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//��������1���Ʒ�ʽ32qam	DL Code1  MCS Modulation	IE_LTE_DL_CODE1_MCS_MODULATION_32QAM
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_MCS_MODULATION_32QAM, new CPSDataStatBase_LTE(IE_LTE_DL_CODE1_MCS_MODULATION_32QAM,NULL,&pLogInfoLTEPS->m_ulDL_Code1_64QAM_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//���е��Ʒ�ʽqpsk	UL MCS Modulation	IE_LTE_UL_MCS_MODULATION_QPSK
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_MCS_MODULATION_QPSK, new CPSDataStatBase_LTE(IE_LTE_UL_MCS_MODULATION_QPSK,NULL,&pLogInfoLTEPS->m_ulUL_QPSK_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//���е��Ʒ�ʽ16qam	UL MCS Modulation	IE_LTE_UL_MCS_MODULATION_16QAM
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_MCS_MODULATION_16QAM, new CPSDataStatBase_LTE(IE_LTE_UL_MCS_MODULATION_16QAM,NULL,&pLogInfoLTEPS->m_ulUL_16QAM_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//���е��Ʒ�ʽ32qam	UL MCS Modulation	IE_LTE_UL_MCS_MODULATION_32QAM
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_MCS_MODULATION_32QAM, new CPSDataStatBase_LTE(IE_LTE_UL_MCS_MODULATION_32QAM,NULL,&pLogInfoLTEPS->m_ulUL_64QAM_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����


	//PDCCH CFI=1	CFI1 Count	IE_LTE_CFI1_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_CFI1_COUNT, new CPSDataStatBase_LTE(IE_LTE_CFI1_COUNT,NULL,&pLogInfoLTEPS->m_ulPDCCH_CFI1_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PDCCH CFI=2	CFI2 Count	IE_LTE_CFI2_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_CFI2_COUNT, new CPSDataStatBase_LTE(IE_LTE_CFI2_COUNT,NULL,&pLogInfoLTEPS->m_ulPDCCH_CFI2_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PDCCH CFI=3	CFI3 Count	IE_LTE_CFI3_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_CFI3_COUNT, new CPSDataStatBase_LTE(IE_LTE_CFI3_COUNT,NULL,&pLogInfoLTEPS->m_ulPDCCH_CFI3_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����
	//PDCCH CFI=4	CFI4 Count	IE_LTE_CFI4_COUNT
	m_MapPSDataStat.insert(make_pair(IE_LTE_CFI4_COUNT, new CPSDataStatBase_LTE(IE_LTE_CFI4_COUNT,NULL,&pLogInfoLTEPS->m_ulPDCCH_CFI4_Num,LTE_PSStat_Total_Value,LTE_PSStat_Value_Int)));  //����


	//1.2��IENumber-IEValue  IEȡ���ֵ���ֱ��ÿ��ֵ���ϱ���������ۼӼ���
	//CPSDataStat_LTE_IESingle
	//----------CQI��ϸ�ֲ�ͳ��--------------------
	//����0��CQI Wideband Code0 CQI  IE_LTE_WIDEBAND_CODE0_CQI
	std::vector<void*> vecStatInfoCQI0;
	GetCQICode0Info(vecStatInfoCQI0,pLogInfoLTEPS);
	CPSDataStat_LTE_IESingle* pStatCQI=new CPSDataStat_LTE_IESingle(IE_LTE_WIDEBAND_CODE0_CQI,&vecStatInfoCQI0);
	
	std::vector<int> vecIEValueCQI;
	GetCQICondition(vecIEValueCQI);
	pStatCQI->AddStatCondition(vecIEValueCQI);
	m_MapPSDataStat.insert(make_pair(IE_LTE_WIDEBAND_CODE0_CQI, pStatCQI));  //����

	//����1��CQI Wideband Code1 CQI  IE_LTE_WIDEBAND_CODE1_CQI
	std::vector<void*> vecStatInfoCQI1;
	GetCQICode1Info(vecStatInfoCQI1,pLogInfoLTEPS);
	pStatCQI=new CPSDataStat_LTE_IESingle(IE_LTE_WIDEBAND_CODE1_CQI,&vecStatInfoCQI1);

	pStatCQI->AddStatCondition(vecIEValueCQI);
	m_MapPSDataStat.insert(make_pair(IE_LTE_WIDEBAND_CODE1_CQI, pStatCQI));  //����
	//----------CQI��ϸ�ֲ�ͳ��--------------------
	
	//Rankͳ��:�ϱ�RANK1����ռ�ȡ��ϱ�RANK2����ռ��(%)  IE_LTE_RANK
	std::vector<void*> vecStatInfoRank;
	GetRankInfo(vecStatInfoRank,pLogInfoLTEPS);
	CPSDataStat_LTE_IESingle* pStatRank=new CPSDataStat_LTE_IESingle(IE_LTE_RANK,&vecStatInfoRank);

	std::vector<int> vecIEValueRank;
	GetRankCondition(vecIEValueRank);
	pStatRank->AddStatCondition(vecIEValueRank);
	m_MapPSDataStat.insert(make_pair(IE_LTE_RANK, pStatRank));  //����

	//1.3��IENumber-IEValue  IEȡ���ֵ���ֱ��ÿ��ֵռ��ʱ�������ۼӼ���
	//CPSDataStat_LTE_IE_UseTime

	//LTE��֡����ʱ���ֲ�ͳ��
	std::vector<void*> vecStatInfo;
	GetSubframe_AssignmentInfo(vecStatInfo,pLogInfoLTEPS);
	CPSDataStat_LTE_IE_UseTime* pStatUseTime=new CPSDataStat_LTE_IE_UseTime(IE_LTE_SUBFRAME_ASSIGNMENT,&vecStatInfo,&dTime_new);
	
	std::vector<int> vecIEValue;
	GetSubframe_AssignmentCondition(vecIEValue);
	pStatUseTime->AddStatCondition(vecIEValue);
	m_MapPSDataStat.insert(make_pair(IE_LTE_SUBFRAME_ASSIGNMENT, pStatUseTime));  //����

	//LTE����ʱ϶����ʱ���ֲ�ͳ�� IE_LTE_SPECIAL_SUBFRAME_PATTERNS
	GetSpecial_Subframe_PatternsInfo(vecStatInfo,pLogInfoLTEPS);
	pStatUseTime=new CPSDataStat_LTE_IE_UseTime(IE_LTE_SPECIAL_SUBFRAME_PATTERNS,&vecStatInfo,&dTime_new);

	GetSpecial_Subframe_PatternsCondition(vecIEValue);
	pStatUseTime->AddStatCondition(vecIEValue);
	m_MapPSDataStat.insert(make_pair(IE_LTE_SPECIAL_SUBFRAME_PATTERNS, pStatUseTime));  //����

	//LTECP����ʱ���ֲ�ͳ�� IE_LTE_UL_CP_TYPE
	GetUL_CPInfo(vecStatInfo,pLogInfoLTEPS);
	pStatUseTime=new CPSDataStat_LTE_IE_UseTime(IE_LTE_UL_CP_TYPE,&vecStatInfo,&dTime_new);

	GetUL_CPCondition(vecIEValue);
	pStatUseTime->AddStatCondition(vecIEValue);
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_CP_TYPE, pStatUseTime));  //����

	//LTE ���߶˿�����ʱ���ֲ�ͳ�� IE_LTE_ENB_TX_ANTENNA_NUM
	GetENB_TX_ANTENNAInfo(vecStatInfo,pLogInfoLTEPS);
	pStatUseTime=new CPSDataStat_LTE_IE_UseTime(IE_LTE_ENB_TX_ANTENNA_NUM,&vecStatInfo,&dTime_new);

	GetENB_TX_ANTENNACondition(vecIEValue);
	pStatUseTime->AddStatCondition(vecIEValue);
	m_MapPSDataStat.insert(make_pair(IE_LTE_ENB_TX_ANTENNA_NUM, pStatUseTime));  //����

	//LTE ��Ƶ��ռ��ʱ���ֲ�ͳ�� IE_LTE_BAND
	GetBANDInfo(vecStatInfo,pLogInfoLTEPS);
	pStatUseTime=new CPSDataStat_LTE_IE_UseTime(IE_LTE_BAND,&vecStatInfo,&dTime_new);

	GetBANDCondition(vecIEValue);
	pStatUseTime->AddStatCondition(vecIEValue);
	m_MapPSDataStat.insert(make_pair(IE_LTE_BAND, pStatUseTime));  //����

	//����ģʽʱ��ռ�� IE_LTE_TM
	GetTMInfo(vecStatInfo,pLogInfoLTEPS);
	pStatUseTime=new CPSDataStat_LTE_IE_UseTime(IE_LTE_TM,&vecStatInfo,&dTime_new);

	GetTMCondition(vecIEValue);
	pStatUseTime->AddStatCondition(vecIEValue);
	m_MapPSDataStat.insert(make_pair(IE_LTE_TM, pStatUseTime));  //����

	//2��Event
	CPSDataStat_LTE_Event* pEventStart=NULL;
	CPSDataStat_LTE_Event* pEventEnd=NULL;

	//LTE�����л�
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_LTE_HANDOVER_ATTEMP, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);  //
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_HANDOVER_ATTEMP, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event(PREDEFINE_LTE_HANDOVER_SUCCESS, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_HANDOVER_SUCCESS, pEventEnd));  //����

	//LTE-TDSCDMA�л�
	pEventStart=new CPSDataStat_LTE_Event( PREDEFINE_LTE_HANDOVER_TO_TD_ATTEMP, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);
	m_MapPSDataStat.insert(make_pair( PREDEFINE_LTE_HANDOVER_TO_TD_ATTEMP, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event( PREDEFINE_LTE_HANDOVER_TO_TD_SUCCESS, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_HANDOVER_TO_TD_SUCCESS, pEventEnd));  //����

	//TDSCDMA-LTE�л�
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_LTE_HANDOVER_FROM_TD_ATTEMP, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_HANDOVER_FROM_TD_ATTEMP, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event(PREDEFINE_LTE_HANDOVER_FROM_TD_SUCCESS, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_HANDOVER_FROM_TD_SUCCESS, pEventEnd));  //����

	//LTE-TDSCDMA��ѡ
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_CELLRESEL_ATTEMP_L2T, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);
	m_MapPSDataStat.insert(make_pair(PREDEFINE_CELLRESEL_ATTEMP_L2T, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event(PREDEFINE_CELLRESEL_SUCCESS_L2T, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_CELLRESEL_SUCCESS_L2T, pEventEnd));  //����

	//TDSCDMA-LTE��ѡ
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_CELLRESEL_ATTEMP_T2L, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);
	m_MapPSDataStat.insert(make_pair(PREDEFINE_CELLRESEL_ATTEMP_T2L, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event( PREDEFINE_CELLRESEL_SUCCESS_T2L, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_CELLRESEL_SUCCESS_T2L, pEventEnd));  //����

	//Attachͳ��
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_LTE_ATTACH_ATTEMP, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_ATTACH_ATTEMP, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event(PREDEFINE_LTE_ATTACH_SUCCESS, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_ATTACH_SUCCESS, pEventEnd));  //����

	//Serviceͳ��
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_LTE_SERVICE_ATTEMP, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);  //
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_SERVICE_ATTEMP, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event(PREDEFINE_LTE_SERVICE_SUCCESS, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_SERVICE_SUCCESS, pEventEnd));  //����

	//LTE���������ͳ��
	pEventStart=new CPSDataStat_LTE_Event(PREDEFINE_LTE_TAU_ATTEMP, pLogInfoLTEPS, LTE_PSStat_Event_Start,&dTime_new, NULL);
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_TAU_ATTEMP, pEventStart));  //����

	pEventEnd= new  CPSDataStat_LTE_Event(PREDEFINE_LTE_TAU_SUCCESS, pLogInfoLTEPS, LTE_PSStat_Event_End,&dTime_new, pEventStart);  //����Start�¼�ʵ��
	m_MapPSDataStat.insert(make_pair(PREDEFINE_LTE_TAU_SUCCESS, pEventEnd));  //����

	//3������ֵ����
	//DL Code0 MCS	
	std::vector<int> vecIEValueMCS;
	GetMCSCondition(vecIEValueMCS);
	CPSDataStat_LTE_IE_MCS* pDataStatMCS=NULL;

	pDataStatMCS=new CPSDataStat_LTE_IE_MCS(IE_LTE_DL_CODE0_MCS0,pLogInfoLTEPS,DL_Code0_MCS);
	pDataStatMCS->AddStatCondition(vecIEValueMCS);
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE0_MCS0, pDataStatMCS));  //����

	//DL Code1 MCS
	pDataStatMCS=new CPSDataStat_LTE_IE_MCS(IE_LTE_DL_CODE1_MCS0,pLogInfoLTEPS,DL_Code1_MCS);
	pDataStatMCS->AddStatCondition(vecIEValueMCS);
	m_MapPSDataStat.insert(make_pair(IE_LTE_DL_CODE1_MCS0, pDataStatMCS));  //����

	//UL MCS ��MCS0-MCS31��32��IE��
	pDataStatMCS=new CPSDataStat_LTE_IE_MCS(IE_LTE_UL_MCS0,pLogInfoLTEPS,UL_MCS);
	pDataStatMCS->AddStatCondition(vecIEValueMCS);
	m_MapPSDataStat.insert(make_pair(IE_LTE_UL_MCS0, pDataStatMCS));  //����

	//����С��RSRP
	CPSDataStat_LTE_IEArea* pDataStatIEArea=NULL;
	std::vector<CIEStatArea> vecIEAreaItem;
	GetRSRPCondition(vecIEAreaItem);
	pDataStatIEArea=new CPSDataStat_LTE_IEArea(IE_LTE_S_RSRP,pLogInfoLTEPS,LTE_PSStat_Area_RSRP);
	pDataStatIEArea->AddStatCondition(vecIEAreaItem);
	m_MapPSDataStat.insert(make_pair(IE_LTE_S_RSRP, pDataStatIEArea));  //����

	//SINR
	GetSINRCondition(vecIEAreaItem);
	pDataStatIEArea=new CPSDataStat_LTE_IEArea(IE_LTE_SINR,pLogInfoLTEPS,LTE_PSStat_Area_SINR);
	pDataStatIEArea->AddStatCondition(vecIEAreaItem);
	m_MapPSDataStat.insert(make_pair(IE_LTE_SINR, pDataStatIEArea));  //����

	//RSRQ
	GetRSRQCondition(vecIEAreaItem);
	pDataStatIEArea=new CPSDataStat_LTE_IEArea(IE_LTE_RSRQ,pLogInfoLTEPS,LTE_PSStat_Area_RSRQ);
	pDataStatIEArea->AddStatCondition(vecIEAreaItem);
	m_MapPSDataStat.insert(make_pair(IE_LTE_RSRQ, pDataStatIEArea));  //����

}


int CAnalyzeImpl_LTE_PS_DATASTAT::DoAnalyzeOneData(DTANASTATDATAITEM& dtitem)
{
	int nResult = 0;
	int nType=-1;
	//1��IENumber-IEValue����Map
	if (dtitem.uiIENumber!=INVALIDVALUE_UINT32)
	{
		AnalysisDataItem(dtitem.uiIENumber,dtitem);
	}

	//2��Event
	if (dtitem.ulEventID!=INVALIDVALUE_UINT32)
	{
		AnalysisDataItem(dtitem.ulEventID, dtitem);
	}

	//3������ֵ����
	//DL Code0 MCS
	if (!dtitem.strDLMCS0.empty())
	{
		AnalysisDataItem(IE_LTE_DL_CODE0_MCS0, dtitem);
	}

	//DL Code1 MCS
	if (!dtitem.strDLMCS1.empty())
	{
		AnalysisDataItem(IE_LTE_DL_CODE1_MCS0, dtitem);
	}
	//UL MCS ��MCS0-MCS31��32��IE��
	if (!dtitem.strULMCS.empty())
	{
		AnalysisDataItem(IE_LTE_UL_MCS0, dtitem);
	}

	//4�����ͳ��
	//����С��RSRP
	if (dtitem.ulEastShift != INVALIDVALUE_INT32)
	{
		AnalysisDataItem(IE_LTE_S_RSRP, dtitem);
	}

	//SINR
	if (dtitem.ulHeightShift != INVALIDVALUE_INT32)
	{
		AnalysisDataItem(IE_LTE_SINR, dtitem);
	}
	//RSRQ
	if (dtitem.ulFloor != INVALIDVALUE_INT32)
	{
		AnalysisDataItem(IE_LTE_RSRQ, dtitem);
	}

	AnalysisOther(dtitem);		

	return nResult;
}

void CAnalyzeImpl_LTE_PS_DATASTAT::AnalysisDataItem(int nType, DTANASTATDATAITEM& dtitem)
{
	if (nType==-1)
		return;

	CPSDataStatBase_LTE* pDataStat=NULL;
	map<int,CPSDataStatBase_LTE*>::iterator itFind=m_MapPSDataStat.find(nType);
	if (itFind != m_MapPSDataStat.end())
	{
		pDataStat=itFind->second;
	}
	

	if (pDataStat!=NULL)
	{
		pDataStat->AnalysisData(dtitem);
	}	

}

int CAnalyzeImpl_LTE_PS_DATASTAT::DoConclusion()
{
	int nResult = 0;
	CPSDataStatBase_LTE* pDataStat=NULL;
	for(map<int,CPSDataStatBase_LTE*>::iterator it = m_MapPSDataStat.begin(); it != m_MapPSDataStat.end(); it++)
	{
		pDataStat=it->second;
		pDataStat->DoConclusion();
	}

	m_pLogInfoLTEPS->m_dbSINR_Edge = CalcCdf(m_vSINREdgeAll, 50, -50, 1);
	m_pLogInfoLTEPS->m_dbRSRP_Edge = CalcCdf(m_vRSRPEdgeAll, -44, -141, 1);

	m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_Other_Time = m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_0_Time + m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_1_Time \
		+ m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_2_Time + m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_3_Time + m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_4_Time \
		+ m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_6_Time + m_pLogInfoLTEPS->m_dbSpecialSubframePatterns_8_Time;	//����

	return nResult;
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetMCSCondition(std::vector<int>& vecIEValue)
{
	vecIEValue.clear();
	for (int i=0; i<32; i++)
	{
		vecIEValue.push_back(i);
	}
}

//RSRP���
void CAnalyzeImpl_LTE_PS_DATASTAT::GetRSRPCondition(std::vector<CIEStatArea>& vecIEAreaItem)
{
	vecIEAreaItem.clear();
	vecIEAreaItem.push_back(CIEStatArea(-60,-44));
	vecIEAreaItem.push_back(CIEStatArea(-65,-60));
	vecIEAreaItem.push_back(CIEStatArea(-70,-65));
	vecIEAreaItem.push_back(CIEStatArea(-75,-70));
	vecIEAreaItem.push_back(CIEStatArea(-80,-75));
	vecIEAreaItem.push_back(CIEStatArea(-85,-80));
	vecIEAreaItem.push_back(CIEStatArea(-90,-85));
	vecIEAreaItem.push_back(CIEStatArea(-95,-90));
	vecIEAreaItem.push_back(CIEStatArea(-100,-95));
	vecIEAreaItem.push_back(CIEStatArea(-105,-100));
	vecIEAreaItem.push_back(CIEStatArea(-110,-105));
	vecIEAreaItem.push_back(CIEStatArea(-141,-110));
}

//SINR���
void CAnalyzeImpl_LTE_PS_DATASTAT::GetSINRCondition(std::vector<CIEStatArea>& vecIEAreaItem)
{
	vecIEAreaItem.clear();
	vecIEAreaItem.push_back(CIEStatArea(25,50));
	vecIEAreaItem.push_back(CIEStatArea(20,25));
	vecIEAreaItem.push_back(CIEStatArea(15,20));
	vecIEAreaItem.push_back(CIEStatArea(10,15));
	vecIEAreaItem.push_back(CIEStatArea(6,10));
	vecIEAreaItem.push_back(CIEStatArea(3,6));
	vecIEAreaItem.push_back(CIEStatArea(0,3));
	vecIEAreaItem.push_back(CIEStatArea(-3,0));
	vecIEAreaItem.push_back(CIEStatArea(-6,-3));
	vecIEAreaItem.push_back(CIEStatArea(-10,-6));
	vecIEAreaItem.push_back(CIEStatArea(-50,-10));
}

//RSRQ���
void CAnalyzeImpl_LTE_PS_DATASTAT::GetRSRQCondition(std::vector<CIEStatArea>& vecIEAreaItem)
{
	vecIEAreaItem.clear();
	vecIEAreaItem.push_back(CIEStatArea(-3.5, -3));
	vecIEAreaItem.push_back(CIEStatArea(-5.5, -3.5));
	vecIEAreaItem.push_back(CIEStatArea(-7.5, -5.5));
	vecIEAreaItem.push_back(CIEStatArea(-9.5, -7.5));
	vecIEAreaItem.push_back(CIEStatArea(-11.5, -9.5));
	vecIEAreaItem.push_back(CIEStatArea(-13.5, -11.5));
	vecIEAreaItem.push_back(CIEStatArea(-15.5, -13.5));
	vecIEAreaItem.push_back(CIEStatArea(-17.5, -15.5));
	vecIEAreaItem.push_back(CIEStatArea(-19.6f, -17.5f));
}

//��ȡCQI��ϸ�ֲ�ͳ������
void CAnalyzeImpl_LTE_PS_DATASTAT::GetCQICondition(std::vector<int>& vecIEValue)
{
	vecIEValue.clear();
	for (int i=0; i<16; i++)
	{
		vecIEValue.push_back(i);
	}
}

//��ȡCQI��ϸ�ֲ�ͳ������ֶ�
void CAnalyzeImpl_LTE_PS_DATASTAT::GetCQICode0Info(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS)
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI0_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI1_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI2_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI3_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI4_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI5_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI6_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI7_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI8_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI9_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI10_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI11_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI12_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI13_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI14_Num));	
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code0_CQI15_Num));
}

//��ȡCQI��ϸ�ֲ�ͳ������ֶ�
void CAnalyzeImpl_LTE_PS_DATASTAT::GetCQICode1Info(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS)
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI0_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI1_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI2_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI3_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI4_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI5_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI6_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI7_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI8_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI9_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI10_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI11_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI12_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI13_Num));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI14_Num));	
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulWideband_Code1_CQI15_Num));
}

//��ȡLTE��֡����ͳ������
void CAnalyzeImpl_LTE_PS_DATASTAT::GetSubframe_AssignmentCondition(std::vector<int>& vecIEValue)
{
	vecIEValue.clear();
	vecIEValue.push_back(LTE_Subframe_Assignment_Format0);
	vecIEValue.push_back(LTE_Subframe_Assignment_Format1);
	vecIEValue.push_back(LTE_Subframe_Assignment_Format2);
	vecIEValue.push_back(LTE_Subframe_Assignment_Format3);
	vecIEValue.push_back(LTE_Subframe_Assignment_Format4);
	vecIEValue.push_back(LTE_Subframe_Assignment_Format5);
	vecIEValue.push_back(LTE_Subframe_Assignment_Format6);
}

//��ȡLTE��֡��������ֶ�
void CAnalyzeImpl_LTE_PS_DATASTAT::GetSubframe_AssignmentInfo(std::vector<void*>& vecStatInfo, CLogInfo_LTE_PS* pLogInfoLTEPS)
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format0_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format1_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format2_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format3_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format4_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format5_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSubFrameAssign_Format6_Time));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetSpecial_Subframe_PatternsCondition(std::vector<int>& vecIEValue)//��ȡLTE����ʱ϶����ͳ������
{
	vecIEValue.clear();
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_0);
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_1);
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_2);
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_3);
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_4);
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_392);  //5
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_6);
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_1022);//7
	vecIEValue.push_back(LTE_Special_Subframe_Patterns_8);
}
void CAnalyzeImpl_LTE_PS_DATASTAT::GetSpecial_Subframe_PatternsInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS) //��ȡLTE����ʱ϶��������ֶ�
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_0_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_1_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_2_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_3_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_4_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_3_9_2_Time)); //5
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_6_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_10_2_2_Time)); //7
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbSpecialSubframePatterns_8_Time));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetUL_CPCondition(std::vector<int>& vecIEValue)//��ȡLTECP����ʱ��ͳ������
{
	vecIEValue.clear();
	vecIEValue.push_back(LTE_UL_CP_Normal);
	vecIEValue.push_back(LTE_UL_CP_Extended);
}
void CAnalyzeImpl_LTE_PS_DATASTAT::GetUL_CPInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS) //��ȡLTECP����ʱ������ֶ�
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_Normal_CP_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_Extended_CP_Time));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetENB_TX_ANTENNACondition(std::vector<int>& vecIEValue)//��ȡLTE���߶˿�����ʱ��ͳ������
{
	vecIEValue.clear();
	vecIEValue.push_back(LTE_ENB_TX_ANTENNA_an1);
	vecIEValue.push_back(LTE_ENB_TX_ANTENNA_an2);
	vecIEValue.push_back(LTE_ENB_TX_ANTENNA_an4);
}
void CAnalyzeImpl_LTE_PS_DATASTAT::GetENB_TX_ANTENNAInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS)//��ȡLTE���߶˿�����ʱ������ֶ�
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_AN_1_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_AN_2_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_AN_4_Time));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetBANDCondition(std::vector<int>& vecIEValue)//��ȡLTE��Ƶ��ռ��ʱ��ͳ������
{
	vecIEValue.clear();
	vecIEValue.push_back(LTE_BAND_D);
	vecIEValue.push_back(LTE_BAND_F);
	vecIEValue.push_back(LTE_BAND_E);
}
void CAnalyzeImpl_LTE_PS_DATASTAT::GetBANDInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS)//��ȡLTE��Ƶ��ռ��ʱ������ֶ�
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_Band_D_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_Band_F_Time));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbLTE_Band_E_Time));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetTMCondition(std::vector<int>& vecIEValue)//��ȡ����ģʽʱ��ͳ������
{
	vecIEValue.clear();
	vecIEValue.push_back(LTE_TM_1);
	vecIEValue.push_back(LTE_TM_2);
	vecIEValue.push_back(LTE_TM_3);
	vecIEValue.push_back(LTE_TM_4);
	vecIEValue.push_back(LTE_TM_5);
	vecIEValue.push_back(LTE_TM_6);
	vecIEValue.push_back(LTE_TM_7);
	vecIEValue.push_back(LTE_TM_8);
}
void CAnalyzeImpl_LTE_PS_DATASTAT::GetTMInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS)//��ȡ����ģʽʱ������ֶ�
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM1ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM2ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM3ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM4ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM5ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM6ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM7ModeTime));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_dbTM8ModeTime));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetRankInfo(std::vector<void*>& vecStatInfo,CLogInfo_LTE_PS* pLogInfoLTEPS) //��ȡLTECP����ʱ������ֶ�
{
	vecStatInfo.clear();
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulRank1_ReportNum));
	vecStatInfo.push_back(&(pLogInfoLTEPS->m_ulRank2_ReportNum));
}

void CAnalyzeImpl_LTE_PS_DATASTAT::GetRankCondition(std::vector<int>& vecIEValue)//��ȡLTE���߶˿�����ʱ��ͳ������
{
	vecIEValue.clear();
	vecIEValue.push_back(1);  //Rank==1
	vecIEValue.push_back(2);  //Rank==2
}

void CAnalyzeImpl_LTE_PS_DATASTAT::AnalysisOther(DTANASTATDATAITEM& dtitem)
{
	//����SINR(dB)
	if (dtitem.ulHeightShift != INVALIDVALUE_INT32)
	{
		double dbTempSINR = ((int)dtitem.ulHeightShift)/1000.0;
		m_vSINREdgeAll.push_back(dbTempSINR);  //���������Ե��SINR

		m_dbCurSINR = dbTempSINR;  //��������LTE�����������

		//����SINR(dB)�ܺ�
		m_pLogInfoLTEPS->m_dbSINR_Sum += dbTempSINR;
	}

	//����RSRP(dBm)
	if (dtitem.ulEastShift != INVALIDVALUE_INT32)
	{
		double dbTempRSRP = ((int)dtitem.ulEastShift)/1000.0;
		m_vRSRPEdgeAll.push_back(dbTempRSRP); //���������Ե��RSRP

		if (dbTempRSRP > -110 && m_dbCurSINR >= 0) //LTE�����������Ķ���ΪRSRP>-110dBm , ��SINR >= 0dB
		{
			m_pLogInfoLTEPS->m_ulRSRP_MeetNum++;
		}

		//����RSRP(dBm)�ܺ�
		m_pLogInfoLTEPS->m_dbRSRP_Sum += (dbTempRSRP);

		m_nLastRSRP = dtitem.ulEastShift;
	}

	if (dtitem.usNCellParaLen > 0)
	{
		//�����ص����Ƕ����
		char cBufBig[100];
		char cBufSmall[50];
		int  nNeighbor;
		int  nCount = 0;
		bool bHaveRemove = false;
		int  nMax = -1050000;

		if (m_nLastRSRP != INVALIDVALUE_INT32)
		{
			nMax = m_nLastRSRP;
			m_vRSRPNeighborPara.push_back(m_nLastRSRP);
		}

		for (int i = 1; GetItem((char *)dtitem.ucNCellPara, i, cBufBig, ";"); i++)
		{
			if (GetItem(cBufBig, 3, cBufSmall, ","))
			{
				nNeighbor = atoi(cBufSmall);
				if (nMax < nNeighbor)
				{
					nMax = nNeighbor;   //dbTempRSRP����������ǿRSRP
				}
				m_vRSRPNeighborPara.push_back(nNeighbor);
			}
		}

		if (nMax >= -105000)
		{
			std::vector<int>::iterator ier = m_vRSRPNeighborPara.begin();
			for (;ier != m_vRSRPNeighborPara.end(); ier++)
			{
				if (nMax == *ier)
				{
					if (!bHaveRemove)
					{
						bHaveRemove = true;
						continue;
					}
				}

				if (nMax - *ier < 6000)
				{
					nCount++;
				}
			}

			if (nCount == 0)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_0_Num++;
			}
			else if (nCount == 1)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_1_Num++;
			} 
			else if (nCount == 2)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_2_Num++;
			} 
			else if (nCount == 3)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_3_Num++;
			} 
			else if (nCount == 4)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_4_Num++;
			} 
			else if (nCount == 5)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_5_Num++;
			} 
			else if (nCount <= 10)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_5_10_Num++;
			} 
			else if (nCount > 10)
			{
				m_pLogInfoLTEPS->m_ulOverCoverDegree_10_N_Num++;
			} 

			if (nCount >= 2)
			{
				m_pLogInfoLTEPS->m_ulOverCoverMeetNum++;

				double dbDis = CalcDistanceLTE(fLon_new, fLat_new, m_dLongitude, m_dLatitude);
				m_pLogInfoLTEPS->m_dbOverCoverDistance += dbDis;
			}

			m_dLongitude = fLon_new;
			m_dLatitude = fLat_new;
		}

		m_vRSRPNeighborPara.clear();
	}

	AnalysisDbmParaAvg(dtitem);

	AnalysisSingleorDoubleFlow(dtitem);
}

void CAnalyzeImpl_LTE_PS_DATASTAT::AnalysisDbmParaAvg(DTANASTATDATAITEM& dtitem)
{
	//����RSRQ(dBm)
	if (dtitem.ulFloor != INVALIDVALUE_INT32)
	{
		m_pLogInfoLTEPS->m_dbRSRQ_Sum += (dtitem.ulFloor/1000.0);
	}
	//����PRACHƽ����(dBm)
	if (dtitem.siPRACH_Power != INVALIDVALUE_SINT32)
	{
		m_pLogInfoLTEPS->m_dbPRACH_Power_Sum += (dtitem.siPRACH_Power);
		m_pLogInfoLTEPS->m_ulPRACH_Power_Num++;
	}
	//����PUSCHƽ����(dBm)
	if (dtitem.siPUSCH_Power != INVALIDVALUE_SINT32)
	{
		m_pLogInfoLTEPS->m_dbPUSCH_Power_Sum += (dtitem.siPUSCH_Power);
		m_pLogInfoLTEPS->m_ulPUSCH_Power_Num++;
	}
	//����PUCCHƽ����(dBm)
	if (dtitem.siPUCCH_Power != INVALIDVALUE_SINT32)
	{
		m_pLogInfoLTEPS->m_dbPUCCH_Power_Sum += (dtitem.siPUCCH_Power);
		m_pLogInfoLTEPS->m_ulPUCCH_Power_Num++;
	}
	//����SRSƽ����(dBm)
	if (dtitem.siSRS_POWER != INVALIDVALUE_SINT32)
	{
		m_pLogInfoLTEPS->m_dbSRS_Power_Sum += (dtitem.siSRS_POWER);
		m_pLogInfoLTEPS->m_ulSRS_Power_Num++;
	}
	//����Rank1 SINR(dBm)
	if (IE_LTE_RANK1_SINR == dtitem.uiIENumber)
	{
		m_pLogInfoLTEPS->m_dbRank1_Wideband_Code0_SINR_Sum += (dtitem.llIEValue2/1000.0);
		m_pLogInfoLTEPS->m_ulRank1_Wideband_Code0_SINR_Num++;
	}
	//����Rank2 SINR1(dBm)
	if (IE_LTE_RANK2_SINR1 == dtitem.uiIENumber)
	{
		m_pLogInfoLTEPS->m_dbRank2_Wideband_Code0_SINR_Sum += (dtitem.llIEValue2/1000.0);
		m_pLogInfoLTEPS->m_ulRank2_Wideband_Code0_SINR_Num++;
	}
	//����Rank2 SINR2(dBm)
	if (IE_LTE_RANK2_SINR2 == dtitem.uiIENumber)
	{
		m_pLogInfoLTEPS->m_dbRank2_Wideband_Code1_SINR_Sum += (dtitem.llIEValue2/1000.0);
		m_pLogInfoLTEPS->m_ulRank2_Wideband_Code1_SINR_Num++;
	}
}

void CAnalyzeImpl_LTE_PS_DATASTAT::AnalysisSingleorDoubleFlow(DTANASTATDATAITEM& dtitem)
{
	//���㵥˫��ʱ��������

	//UINT32 unEventID = dtitem.ulEventID;
	//if(unEventID != INVALIDVALUE_UINT32)
	//{
	//	switch(unEventID)
	//	{
	//	case FTP_START_DOWN_EVENT:
	//	case FTP_SUCCESS_DOWN_EVENT:
	//	case FTP_FAILURE_DOWN_EVENT:
	//	case FTP_DROP_DOWN_EVENT:
	//	case FTP_START_UP_EVENT:
	//	case FTP_SUCCESS_UP_EVENT:
	//	case FTP_FAILURE_UP_EVENT:
	//	case FTP_DROP_UP_EVENT:
	//		{
	//			m_lOldCodeWordNum = 0;
	//			m_dbStartCodeWordTime = ANA_IMPL_INVALID_TIME;
	//			break;
	//		}
	//	default:
	//		{
	//			break;
	//		}
	//	}
	//}

	if (dtitem.lCodeWordNum != INVALIDVALUE_INT32)
	{
		if (m_lOldCodeWordNum == 0)
		{
			m_dbStartCodeWordTime = dTime_new;
		}
	 	else if (m_lOldCodeWordNum == 1)
	 	{
			m_pLogInfoLTEPS->m_dbSingleFlowTime += GetTimeLast(m_dbStartCodeWordTime, dTime_new);
			m_dbStartCodeWordTime = dTime_new;
	 	}
	 	else if (m_lOldCodeWordNum == 2)
	 	{
			m_pLogInfoLTEPS->m_dbDoubleFlowTime += GetTimeLast(m_dbStartCodeWordTime, dTime_new);
			m_dbStartCodeWordTime = dTime_new;
	 	}

	 	m_lOldCodeWordNum = dtitem.lCodeWordNum;
	}

	if (dtitem.lTbsizeCW0 != INVALIDVALUE_INT32)
	{
		if (m_lOldCodeWordNum == 1)
		{
			m_pLogInfoLTEPS->m_dbSingleFlowData += dtitem.lTbsizeCW0;
		}
		else if (m_lOldCodeWordNum == 2)
		{
			if (dtitem.lTbsizeCW1 != INVALIDVALUE_INT32)
			{
				m_pLogInfoLTEPS->m_dbDoubleFlowData += (dtitem.lTbsizeCW0 + dtitem.lTbsizeCW1);
			}
		}
	}
}

int CAnalyzeImpl_LTE_PS_DATASTAT::DoAnalyzeImpl(DTANASTATDATAITEM& dtitem, int nCsOrPs)
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

	return nResult;
}