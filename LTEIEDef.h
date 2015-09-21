#pragma once

#include "CommIEDef.h"
namespace	AUTOTEST
{

//SCELL Info
#define		IE_LTE_SCELLINFO_BASE					(IE_LTE_BASE + 10)				//132010
#define		IE_LTE_TAC								(IE_LTE_SCELLINFO_BASE + 1)
#define		IE_LTE_CI								(IE_LTE_SCELLINFO_BASE + 2)
#define		IE_LTE_S_EARFCN							(IE_LTE_SCELLINFO_BASE + 3)
#define		IE_LTE_S_PCI							(IE_LTE_SCELLINFO_BASE + 4)
#define		IE_LTE_RAT								(IE_LTE_SCELLINFO_BASE + 5)
#define		IE_LTE_TDTYPE							(IE_LTE_SCELLINFO_BASE + 6)
#define		IE_LTE_BANDWIDTH						(IE_LTE_SCELLINFO_BASE + 7)

//Power Info
#define		IE_LTE_POWERINFO_BASE					(IE_LTE_SCELLINFO_BASE + 10)	//132020
#define		IE_LTE_PRACH_POWER						(IE_LTE_POWERINFO_BASE + 1)
#define		IE_LTE_PUSCH_POWER						(IE_LTE_POWERINFO_BASE + 2)
#define		IE_LTE_PUCCH_POWER						(IE_LTE_POWERINFO_BASE + 3)
#define		IE_LTE_SRS_POWER						(IE_LTE_POWERINFO_BASE + 4)
#define		IE_LTE_PA								(IE_LTE_POWERINFO_BASE + 5)
#define		IE_LTE_PB								(IE_LTE_POWERINFO_BASE + 6)
#define		IE_LTE_RSEPRE							(IE_LTE_POWERINFO_BASE + 7)

//State Info
#define		IE_LTE_STATEINFO_BASE					(IE_LTE_POWERINFO_BASE + 10)	//132030
#define		IE_LTE_SERVICE							(IE_LTE_STATEINFO_BASE + 1)
#define		IE_LTE_TM								(IE_LTE_STATEINFO_BASE + 2)
#define		IE_LTE_SUBFRAME_ASSIGNMENT				(IE_LTE_STATEINFO_BASE + 3)
#define		IE_LTE_SPECIAL_SUBFRAME_PATTERNS		(IE_LTE_STATEINFO_BASE + 4)
#define		IE_LTE_UL_CP_TYPE						(IE_LTE_STATEINFO_BASE + 5)
#define		IE_LTE_ENB_TX_ANTENNA_NUM				(IE_LTE_STATEINFO_BASE + 6)
#define		IE_LTE_BAND								(IE_LTE_STATEINFO_BASE + 7)

//Resource Info
#define		IE_LTE_RESOURCE_BASE					(IE_LTE_STATEINFO_BASE + 20)	//132050
#define		IE_LTE_DL_RB_NUM						(IE_LTE_RESOURCE_BASE + 1)
#define		IE_LTE_UL_RB_NUM						(IE_LTE_RESOURCE_BASE + 2)
#define		IE_LTE_PDCCH_DL_GRANT_COUNT				(IE_LTE_RESOURCE_BASE + 3)
#define		IE_LTE_PDCCH_UL_GRANT_COUNT				(IE_LTE_RESOURCE_BASE + 4)

//SCELL MEAS
#define		IE_LTE_SCELLMEAS_BASE					(IE_LTE_RESOURCE_BASE + 10)		//132060
#define		IE_LTE_S_RSRP							(IE_LTE_SCELLMEAS_BASE + 1)
#define		IE_LTE_RSRQ								(IE_LTE_SCELLMEAS_BASE + 2)
#define		IE_LTE_SINR								(IE_LTE_SCELLMEAS_BASE + 3)
#define		IE_LTE_RANK1_SINR						(IE_LTE_SCELLMEAS_BASE + 4)
#define		IE_LTE_RANK2_SINR1						(IE_LTE_SCELLMEAS_BASE + 5)
#define		IE_LTE_RANK2_SINR2						(IE_LTE_SCELLMEAS_BASE + 6)
#define		IE_LTE_RANK								(IE_LTE_SCELLMEAS_BASE + 7)
#define		IE_LTE_WIDEBAND_CODE0_CQI				(IE_LTE_SCELLMEAS_BASE + 8)
#define		IE_LTE_WIDEBAND_CODE1_CQI				(IE_LTE_SCELLMEAS_BASE + 9)
#define		IE_LTE_CFI1_COUNT						(IE_LTE_SCELLMEAS_BASE + 10)
#define		IE_LTE_CFI2_COUNT						(IE_LTE_SCELLMEAS_BASE + 11)
#define		IE_LTE_CFI3_COUNT						(IE_LTE_SCELLMEAS_BASE + 12)
#define		IE_LTE_CFI4_COUNT						(IE_LTE_SCELLMEAS_BASE + 13)

//NCELL MEAS
#define		IE_LTE_NCELLMEAS_BASE					(IE_LTE_SCELLMEAS_BASE + 30)	//132090
#define		IE_LTE_N_EARFCN0						(IE_LTE_NCELLMEAS_BASE + 1)
#define		IE_LTE_N_EARFCN(x)						(IE_LTE_N_EARFCN0 + x)
#define		IE_LTE_N_PCI0							(IE_LTE_NCELLMEAS_BASE + 41)						
#define		IE_LTE_N_PCI(x)							(IE_LTE_N_PCI0 + x)
#define		IE_LTE_N_RSRP0							(IE_LTE_NCELLMEAS_BASE + 81)
#define		IE_LTE_N_RSRP(x)						(IE_LTE_N_RSRP0 + x)

//THROUGHPUT Info
#define		IE_LTE_THROUGHPUT_BASE					(IE_LTE_NCELLMEAS_BASE + 200)	//132290
#define		IE_LTE_TB_ERR							(IE_LTE_THROUGHPUT_BASE + 1)
#define		IE_LTE_TB_SEND							(IE_LTE_THROUGHPUT_BASE + 2)
#define		IE_LTE_PHY_THROUGHPUT_DL				(IE_LTE_THROUGHPUT_BASE + 3)
#define		IE_LTE_PHY_CW0_THROUGHPUT_DL			(IE_LTE_THROUGHPUT_BASE + 4)
#define		IE_LTE_PHY_CW1_THROUGHPUT_DL			(IE_LTE_THROUGHPUT_BASE + 5)
#define		IE_LTE_PHY_THROUGHPUT_UL				(IE_LTE_THROUGHPUT_BASE + 6)
#define		IE_LTE_PDCP_THROUGHPUT_DL				(IE_LTE_THROUGHPUT_BASE + 7)
#define		IE_LTE_PDCP_THROUGHPUT_UL				(IE_LTE_THROUGHPUT_BASE + 8)
#define		IE_LTE_RLC_THROUGHPUT_DL				(IE_LTE_THROUGHPUT_BASE + 9)
#define		IE_LTE_RLC_THROUGHPUT_UL				(IE_LTE_THROUGHPUT_BASE + 10)
#define		IE_LTE_MAC_THROUGHPUT_DL				(IE_LTE_THROUGHPUT_BASE + 11)
#define		IE_LTE_MAC_THROUGHPUT_UL				(IE_LTE_THROUGHPUT_BASE + 12)

//HARQ Info
#define		IE_LTE_HARQ_BASE						(IE_LTE_THROUGHPUT_BASE + 20)	//132310
#define		IE_LTE_PDSCH_FIRST_RX_SUCCESS_CNT		(IE_LTE_HARQ_BASE + 1)
#define		IE_LTE_PDSCH_MULTI_RETRANS_SUCCESS_CNT	(IE_LTE_HARQ_BASE + 2)
#define		IE_LTE_HARQ_UL_1ST_TX_SUCC_NUM			(IE_LTE_HARQ_BASE + 3)
#define		IE_LTE_HARQ_UL_1ST_RETX_SUCC_NUM		(IE_LTE_HARQ_BASE + 4)
#define		IE_LTE_HARQ_UL_2ND_RETX_SUCC_NUM		(IE_LTE_HARQ_BASE + 5)
#define		IE_LTE_HARQ_UL_3RD_RETX_SUCC_NUM		(IE_LTE_HARQ_BASE + 6)
#define		IE_LTE_HARQ_UL_4TH_RETX_SUCC_NUM		(IE_LTE_HARQ_BASE + 7)
#define		IE_LTE_HARQ_UL_MUTIL_RETX_SUCC_NUM		(IE_LTE_HARQ_BASE + 8)
#define		IE_LTE_HARQ_DL_C0_ACK_COUNT				(IE_LTE_HARQ_BASE + 9)
#define		IE_LTE_HARQ_DL_C0_NACK_COUNT			(IE_LTE_HARQ_BASE + 10)
#define		IE_LTE_HARQ_DL_C1_ACK_COUNT				(IE_LTE_HARQ_BASE + 11)
#define		IE_LTE_HARQ_DL_C1_NACK_COUNT			(IE_LTE_HARQ_BASE + 12)
#define		IE_LTE_HARQ_UL_ACK_COUNT				(IE_LTE_HARQ_BASE + 13)
#define		IE_LTE_HARQ_UL_NACK_COUNT				(IE_LTE_HARQ_BASE + 14)
#define		IE_LTE_HARQ_DL_RETX_FAILED_NUM			(IE_LTE_HARQ_BASE + 15)
#define		IE_LTE_HARQ_UL_RETX_FAILED_NUM			(IE_LTE_HARQ_BASE + 16)

//BLER Info
#define		IE_LTE_BLER_BASE						(IE_LTE_HARQ_BASE + 30)		//132340
#define		IE_LTE_DL_CODE0_BLER					(IE_LTE_BLER_BASE + 1)
#define		IE_LTE_DL_CODE1_BLER					(IE_LTE_BLER_BASE + 2)
#define		IE_LTE_DL_CODE0_IBLER					(IE_LTE_BLER_BASE + 3)
#define		IE_LTE_DL_CODE0_RBLER					(IE_LTE_BLER_BASE + 4)
#define		IE_LTE_DL_CODE1_IBLER					(IE_LTE_BLER_BASE + 5)
#define		IE_LTE_DL_CODE1_RBLER					(IE_LTE_BLER_BASE + 6)
#define		IE_LTE_UL_BLER							(IE_LTE_BLER_BASE + 7)
#define		IE_LTE_UL_IBLER							(IE_LTE_BLER_BASE + 8)
#define		IE_LTE_UL_RBLER							(IE_LTE_BLER_BASE + 9)

//MCS Info
#define		IE_LTE_MCS_BASE							(IE_LTE_BLER_BASE + 20)	//132360
#define		IE_LTE_DL_CODE0_MCS_MODULATION_QPSK		(IE_LTE_MCS_BASE + 1)
#define		IE_LTE_DL_CODE0_MCS_MODULATION_16QAM	(IE_LTE_MCS_BASE + 2)
#define		IE_LTE_DL_CODE0_MCS_MODULATION_32QAM	(IE_LTE_MCS_BASE + 3)
#define		IE_LTE_DL_CODE1_MCS_MODULATION_QPSK		(IE_LTE_MCS_BASE + 4)
#define		IE_LTE_DL_CODE1_MCS_MODULATION_16QAM	(IE_LTE_MCS_BASE + 5)
#define		IE_LTE_DL_CODE1_MCS_MODULATION_32QAM	(IE_LTE_MCS_BASE + 6)
#define		IE_LTE_UL_MCS_MODULATION_QPSK			(IE_LTE_MCS_BASE + 7)
#define		IE_LTE_UL_MCS_MODULATION_16QAM			(IE_LTE_MCS_BASE + 8)
#define		IE_LTE_UL_MCS_MODULATION_32QAM			(IE_LTE_MCS_BASE + 9)
#define		IE_LTE_DL_CODE0_MCS0					(IE_LTE_MCS_BASE + 10)
#define		IE_LTE_DL_CODE0_MCS(x)					(IE_LTE_DL_CODE0_MCS0 + x)
#define		IE_LTE_DL_CODE1_MCS0					(IE_LTE_MCS_BASE + 45)
#define		IE_LTE_DL_CODE1_MCS(x)					(IE_LTE_DL_CODE1_MCS0 + x)
#define		IE_LTE_UL_MCS0							(IE_LTE_MCS_BASE + 80)
#define		IE_LTE_UL_MCS(x)						(IE_LTE_UL_MCS0 + x)

// 此处根据协议文档定义10几个枚举 [5/15/2015 liangdongxu]
#define		IE_AppBytes_BASE						(IE_LTE_MCS_BASE + 200) //132560
#define		IE_AppBytesReceived_Total				(IE_AppBytes_BASE + 1)
#define		IE_AppBytesReceived_LTE					(IE_AppBytes_BASE + 2)
#define		IE_AppBytesReceived_HSPA_PLUS			(IE_AppBytes_BASE + 3)
#define		IE_AppBytesReceived_HSDPA				(IE_AppBytes_BASE + 4)
#define		IE_AppBytesReceived_R4					(IE_AppBytes_BASE + 5)
#define		IE_AppBytesReceived_EVDO				(IE_AppBytes_BASE + 6)
#define		IE_AppBytesReceived_1x					(IE_AppBytes_BASE + 7)
#define		IE_AppBytesReceived_GPRS_EDGE			(IE_AppBytes_BASE + 8)
#define		IE_AppBytesend_Total					(IE_AppBytes_BASE + 9)
#define		IE_AppBytesSend_LTE						(IE_AppBytes_BASE + 10)
#define		IE_AppBytesSend_HSPA_PLUS				(IE_AppBytes_BASE + 11)
#define		IE_AppBytesSend_HSUPA					(IE_AppBytes_BASE + 12)
#define		IE_AppBytesSend_R4						(IE_AppBytes_BASE + 13)
#define		IE_AppBytesSend_EVDO					(IE_AppBytes_BASE + 14)
#define		IE_AppBytesSend_1x						(IE_AppBytes_BASE + 15)
#define		IE_AppBytesSend_GPRS_EDGE				(IE_AppBytes_BASE + 16)
#define		IE_App_currentThroughput_dl				(IE_AppBytes_BASE + 17)
#define		IE_App_currentThroughput_ul				(IE_AppBytes_BASE + 18)
// 添加HTTP STREAM协议定义 [5/29/2015 liangdongxu]
#define		IE_AppBytesReceived_Total_HTTP				(IE_AppBytes_BASE + 19)
#define		IE_AppBytesReceived_LTE_HTTP				(IE_AppBytes_BASE + 20)
#define		IE_AppBytesReceived_HSPA_PLUS_HTTP			(IE_AppBytes_BASE + 21)
#define		IE_AppBytesReceived_HSDPA_HTTP				(IE_AppBytes_BASE + 22)
#define		IE_AppBytesReceived_R4_HTTP					(IE_AppBytes_BASE + 23)
#define		IE_AppBytesReceived_EVDO_HTTP				(IE_AppBytes_BASE + 24)
#define		IE_AppBytesReceived_1x_HTTP					(IE_AppBytes_BASE + 25)
#define		IE_AppBytesReceived_GPRS_EDGE_HTTP			(IE_AppBytes_BASE + 26)
#define		IE_AppBytesend_Total_HTTP					(IE_AppBytes_BASE + 27)
#define		IE_AppBytesSend_LTE_HTTP					(IE_AppBytes_BASE + 28)
#define		IE_AppBytesSend_HSPA_PLUS_HTTP				(IE_AppBytes_BASE + 29)
#define		IE_AppBytesSend_HSUPA_HTTP					(IE_AppBytes_BASE + 30)
#define		IE_AppBytesSend_R4_HTTP						(IE_AppBytes_BASE + 31)
#define		IE_AppBytesSend_EVDO_HTTP					(IE_AppBytes_BASE + 32)
#define		IE_AppBytesSend_1x_HTTP						(IE_AppBytes_BASE + 33)
#define		IE_AppBytesSend_GPRS_EDGE_HTTP				(IE_AppBytes_BASE + 34)
#define		IE_App_currentThroughput_dl_HTTP			(IE_AppBytes_BASE + 35)
#define		IE_App_currentThroughput_ul_HTTP			(IE_AppBytes_BASE + 36)

#define		IE_AppBytesReceived_Total_STREAM				(IE_AppBytes_BASE + 37)
#define		IE_AppBytesReceived_LTE_STREAM					(IE_AppBytes_BASE + 38)
#define		IE_AppBytesReceived_HSPA_PLUS_STREAM			(IE_AppBytes_BASE + 39)
#define		IE_AppBytesReceived_HSDPA_STREAM				(IE_AppBytes_BASE + 40)
#define		IE_AppBytesReceived_R4_STREAM					(IE_AppBytes_BASE + 41)
#define		IE_AppBytesReceived_EVDO_STREAM					(IE_AppBytes_BASE + 42)
#define		IE_AppBytesReceived_1x_STREAM					(IE_AppBytes_BASE + 43)
#define		IE_AppBytesReceived_GPRS_EDGE_STREAM			(IE_AppBytes_BASE + 44)
#define		IE_AppBytesend_Total_STREAM						(IE_AppBytes_BASE + 45)
#define		IE_AppBytesSend_LTE_STREAM						(IE_AppBytes_BASE + 46)
#define		IE_AppBytesSend_HSPA_PLUS_STREAM				(IE_AppBytes_BASE + 47)
#define		IE_AppBytesSend_HSUPA_STREAM					(IE_AppBytes_BASE + 48)
#define		IE_AppBytesSend_R4_STREAM						(IE_AppBytes_BASE + 49)
#define		IE_AppBytesSend_EVDO_STREAM						(IE_AppBytes_BASE + 50)
#define		IE_AppBytesSend_1x_STREAM						(IE_AppBytes_BASE + 51)
#define		IE_AppBytesSend_GPRS_EDGE_STREAM				(IE_AppBytes_BASE + 52)
#define		IE_App_currentThroughput_dl_STREAM				(IE_AppBytes_BASE + 53)
#define		IE_App_currentThroughput_ul_STREAM				(IE_AppBytes_BASE + 54)

//APP Info
#define		IE_LTE_APP_BASE							(IE_LTE_MCS_BASE + 300)	//132660
#define		IE_LTE_APPBYTESRECEIVED_TOTAL			(IE_LTE_APP_BASE + 1)
#define		IE_LTE_APPBYTESRECEIVED_HSDPA			(IE_LTE_APP_BASE + 2)
#define		IE_LTE_APPBYTESRECEIVED_R4				(IE_LTE_APP_BASE + 3)
#define		IE_LTE_APPBYTESRECEIVED_LTE				(IE_LTE_APP_BASE + 4)
#define		IE_LTE_APPBYTESEND_TOTAL				(IE_LTE_APP_BASE + 5)
#define		IE_LTE_APPBYTESSEND_HSUPA				(IE_LTE_APP_BASE + 6)
#define		IE_LTE_APPBYTESSEND_R4					(IE_LTE_APP_BASE + 7)
#define		IE_LTE_APPBYTESSEND_LTE					(IE_LTE_APP_BASE + 8)
#define		IE_LTE_APP_CURRENTTHROUGHPUT_DL			(IE_LTE_APP_BASE + 9)
#define		IE_LTE_APP_CURRENTTHROUGHPUT_UL			(IE_LTE_APP_BASE + 10)
#define		IE_APPLAYER_TEXT						(IE_LTE_APP_BASE + 11)
#define		IE_LTE_TOTAL_PHYTHROUGHPUT_DL			(IE_LTE_APP_BASE + 12)

//CodeWord Info
#define		IE_LTE_CODEWORD_BASE					(IE_LTE_APP_BASE + 20) //132680
#define		IE_LTE_CODEWORD_NUM						(IE_LTE_CODEWORD_BASE + 1)
#define		IE_LTE_TBSIZECW0						(IE_LTE_CODEWORD_BASE + 2)
#define		IE_LTE_TBSIZECW1						(IE_LTE_CODEWORD_BASE + 3)

// 新添加LTEIE [6/16/2015 liangdongxu]-12个
#define		IE_LTE_RETRX_BASE						(IE_LTE_CODEWORD_BASE + 10) //132690
#define		IE_GSM_L1_NCell_Rxlev_0					(IE_LTE_RETRX_BASE + 1)
#define		IE_TD_L1_SCell_P_CCPCH_RSCP				(IE_LTE_RETRX_BASE + 2)
#define		IE_LTE_code0_1st_retx_succ				(IE_LTE_RETRX_BASE + 3)
#define		IE_LTE_code0_2nd_retx_succ				(IE_LTE_RETRX_BASE + 4)
#define		IE_LTE_code0_3rd_retx_succ				(IE_LTE_RETRX_BASE + 5)
#define		IE_LTE_code0_4th_retx_succ				(IE_LTE_RETRX_BASE + 6)
#define		IE_LTE_code1_1st_retx_succ				(IE_LTE_RETRX_BASE + 7)
#define		IE_LTE_code1_2nd_retx_succ				(IE_LTE_RETRX_BASE + 8)
#define		IE_LTE_code1_3rd_retx_succ				(IE_LTE_RETRX_BASE + 9)
#define		IE_LTE_code1_4th_retx_succ				(IE_LTE_RETRX_BASE + 10)
#define		IE_LTE_code0_1st_tx_succ				(IE_LTE_RETRX_BASE + 11)
#define		IE_LTE_code1_1st_tx_succ				(IE_LTE_RETRX_BASE + 12)
}