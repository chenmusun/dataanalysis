#pragma once
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef  char INT8;
typedef  short INT16;
typedef  int INT32;
typedef long long INT64;
typedef int SINT32;
typedef bool BOOL;
typedef long long LONGLONG;
typedef float FLOAT;


// 无效值定义
#define INVALIDVALUE_SINT64     0x7fffffffffffffff
#define INVALIDVALUE_UINT64     0xffffffffffffffff
#define INVALIDVALUE_UINT32     0xffffffff
#define INVALIDVALUE_UINT16     0xffff
#define INVALIDVALUE_UINT8      0xff
#define INVALIDVALUE_SINT32     0x7fffffff
#define INVALIDVALUE_SINT16     0x7fff
#define INVALIDVALUE_SINT8      0x7f
#define INVALIDVALUE_FLOAT      FLT_MAX
#define INVALIDVALUE_DOUBLE     DBL_MAX
#define INVALIDVALUE_STRING     ""

// 字符串最大长度定义
#define LOG_MAXLEN				300
#define DESC_MAXLEN				255
#define TASKNAME_MAXLEN			255
#define TENAME_MAXLEN           100

//唯一性任务的任务id
#define   AUTOIMP_CDLLOG_TASKID             1//自动导入CDL日志
#define   AUTOIMP_DTLOG_TASKID              2//自动导入Outum日志
#define   AUTOIMP_ADTLOG_TASKID             3//自动导入自动路测日志
#define   AUTOIMP_ODGDATA_TASKID            4//自动导入ODG日志

#define   AUTOGET_RNCLOG_TASKID             5//自动获取CDL、ODG文件、RNC系统日志

#define   AUTOCLEAR_SYSINFO_TASKID          6//自动清除数据、已导入日志文件

#define   EXTRACTLOG_TASKID                 7//截取日志任务
#define   AUTOIMP_SYSLOG_TASKID             8//自动导入RNC系统日志

#define   AUTOIMP_ANRLOG_TASKID             9//anr日志导入

#define   AUTOCDLANA_TASKID					10 //自动CDL分析
#define   AUTOSCALLANA_TASKID				11 //自动单通分析
#define   AUTOIDLEANA_TASKID				12 //自动IDLE分析(部分用户感知功能)
#define   AUTOMRANA_TASKID					13 //自动MR分析
